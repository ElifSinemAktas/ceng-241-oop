#include <iostream>
#include <iomanip>
using namespace std;

// Task 1: Four Operations with Dynamic Array, Pointers, and Functions
// - Read two numbers into a dynamic array
// - Use pointer-based functions to perform add, sub, mul, div
// - Display results and free memory

/* NOTES / TEACHING POINTS (added inline explanations below):
 - This file intentionally uses raw pointers for parameters so you can practice
     with addresses (&), dereference operator (*), and dynamic allocation (new/delete).
 - In production C++ code you'd often prefer returning values or using references
     (double& out) instead of pointer-based out parameters, but pointers are useful
     to learn how memory and addresses work.
 - Key symbols explained in comments where they appear: * (dereference), & (address),
     nullptr checks, and ownership of dynamically allocated memory.
*/

void add(const int* a, const int* b, double* out) {
    // 'a' and 'b' are pointers to int (addresses). Using *a / *b reads the
    // integer values stored at those addresses. We cast to double to avoid
    // integer truncation when adding.
    //
    // 'out' is a pointer to a double where the function will write the result.
    // The caller passes the address of some double variable (e.g. &result).
    // Writing to *out updates the caller's variable directly.
    *out = static_cast<double>(*a) + static_cast<double>(*b);
}

void sub(const int* a, const int* b, double* out) {
    // Subtraction using dereferenced pointer values.
    *out = static_cast<double>(*a) - static_cast<double>(*b);
}

void mul(const int* a, const int* b, double* out) {
    // Multiplication using dereferenced pointer values.
    *out = static_cast<double>(*a) * static_cast<double>(*b);
}

bool divide(const int* a, const int* b, double* out) {
    // Division: first check the divisor (value at address b). We must NOT
    // dereference a null pointer; here we assume 'b' is a valid pointer provided
    // by the caller. In safer code you might check 'if (!b) ...' or use references.
    if (*b == 0) return false; // signal failure (division by zero)
    *out = static_cast<double>(*a) / static_cast<double>(*b);
    return true; // success
}

int main() {
    cout << "Task 1: Two-number operations using dynamic array and pointers\n";

    int size = 2;
    // Create a dynamic array of integers on the heap.
    // 'nums' holds the address of the first element. You can think of it as
    // a pointer to the block of memory holding 'size' ints.
    int* nums = new int[size];

    for (int i = 0; i < size; ++i) {
        cout << "Enter integer number " << (i + 1) << ": ";
        while (!(cin >> nums[i])) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer for number " << (i + 1) << ": ";
        }
    }

    double result;

    // Function call explanation:
    // - &nums[0] is the address of the first element (same as 'nums').
    // - &nums[1] is the address of the second element.
    // - &result is the address of the local variable 'result' where the
    //   function should write the output using *out = ...;
    // Inside 'add', the parameter 'out' points to this same 'result' variable.
    add(&nums[0], &nums[1], &result);
    cout << "Addition: " << nums[0] << " + " << nums[1] << " = " << result << '\n';

    sub(&nums[0], &nums[1], &result);
    cout << "Subtraction: " << nums[0] << " - " << nums[1] << " = " << result << '\n';

    mul(&nums[0], &nums[1], &result);
    cout << "Multiplication: " << nums[0] << " * " << nums[1] << " = " << result << '\n';

    if (divide(&nums[0], &nums[1], &result)) {
        cout << fixed << setprecision(6);
        cout << "Division: " << nums[0] << " / " << nums[1] << " = " << result << '\n';
    } else {
        cout << "Division: Cannot divide by zero." << '\n';
    }

    delete[] nums;
    nums = nullptr;

    // Why delete[] and set to nullptr?
    // - delete[] frees the dynamically allocated array to avoid memory leaks.
    // - Setting 'nums' to nullptr avoids a dangling pointer (pointer that points
    //   to freed memory). Accessing a dangling pointer causes undefined behavior.

    // Alternative implementations (recommended in modern C++):
    // 1) Return values from functions instead of out-params:
    //    double add_val(int a, int b) { return static_cast<double>(a) + b; }
    //    double result = add_val(nums[0], nums[1]);
    // 2) Use references for out-params (clearer syntax):
    //    void add_ref(const int& a, const int& b, double& out) { out = ...; }
    //    add_ref(nums[0], nums[1], result);
    // 3) Use smart containers: std::vector<int> instead of raw new/delete.

    // The pointer-based style above is educational: it demonstrates how to pass
    // addresses and modify caller memory from inside a function. Keep practicing
    // pointers until you're comfortable; then prefer references/return values
    // in real projects for clarity and safety.

    cout << "Memory freed. Program finished.\n";
    return 0;
}
