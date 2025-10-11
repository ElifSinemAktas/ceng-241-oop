#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Task 2: Stationery Stock Management with Dynamic 2D Array
// - 10 stores, each with 5 items
// - Use int** dynamic allocation
// - Menu: show store stock, add stock, reduce stock, exit
// - Input validation and proper deletion

/* NOTES / TEACHING POINTS (added inline below):
 - This file demonstrates a dynamic 2D array using raw pointers (int**).
     Each row is separately allocated with new[], and the array of row pointers
     itself is allocated with new[] as well.
 - Memory ownership: the code that creates the structure must also delete it.
 - In modern C++ prefer std::vector or smart pointers; raw int** is shown here
     for educational purposes (to understand pointer-to-pointer and manual
     allocation/deallocation).
 - Key topics covered in comments: indexing, bounds checking, input validation,
     preventing negative stocks, and safe deletion.
*/

const int NUM_STORES = 10;
const int NUM_ITEMS = 5;

int** create_stock() {
    // Allocate an array of pointers (one pointer per store).
    // 'stock' points to the first element of this pointer-array.
    int** stock = new int*[NUM_STORES];
    for (int i = 0; i < NUM_STORES; ++i) {
        // For each store, allocate an array of NUM_ITEMS integers.
        // So memory layout is 'array of pointers' -> each points to an 'array of ints'.
        stock[i] = new int[NUM_ITEMS];
        // Initialize all item quantities to 0 to have a defined starting state.
        for (int j = 0; j < NUM_ITEMS; ++j) stock[i][j] = 0;
    }
    return stock; // Caller receives ownership and must call delete_stock when done.
}

void delete_stock(int** stock) {
    // Free each row first, then free the array of pointers.
    if (!stock) return; // nothing to do
    for (int i = 0; i < NUM_STORES; ++i) {
        // Be careful: each stock[i] was allocated with new[] so we must use delete[]
        // to free it. If stock[i] were nullptr we could skip it, but our create
        // function always initializes them.
        delete[] stock[i];
        stock[i] = nullptr; // defensive: avoid dangling pointers
    }
    delete[] stock;
}

int read_int_in_range(const string& prompt, int low, int high) {
    int x;
    while (true) {
        cout << prompt;
        if (cin >> x && x >= low && x <= high) return x;
        cout << "Invalid input. Please enter a number between " << low << " and " << high << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void show_store(int** stock) {
    // Ask user for store number and print all items for that store.
    int s = read_int_in_range("Enter store number (1-10): ", 1, NUM_STORES) - 1;
    cout << "Stock for store " << (s + 1) << ":\n";
    for (int j = 0; j < NUM_ITEMS; ++j) {
        // Access pattern: stock[s][j] -> go to row s, then column j
        cout << "  Item " << (j + 1) << ": " << stock[s][j] << "\n";
    }
}

void add_stock(int** stock) {
    // Validate store and item indices using helper.
    int s = read_int_in_range("Enter store number (1-10): ", 1, NUM_STORES) - 1;
    int item = read_int_in_range("Enter item number (1-5): ", 1, NUM_ITEMS) - 1;
    int qty;
    cout << "Enter quantity to add (positive integer): ";
    // Quantity must be positive. We also protect against non-integer input.
    while (!(cin >> qty) || qty <= 0) {
        cout << "Invalid quantity. Enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    // Update the in-memory stock. No overflow checks here; in production you'd
    // consider upper bounds or use a larger integer type if needed.
    stock[s][item] += qty;
    cout << "Added " << qty << " to store " << (s+1) << ", item " << (item+1) << ". New stock: " << stock[s][item] << "\n";
}

void reduce_stock(int** stock) {
    int s = read_int_in_range("Enter store number (1-10): ", 1, NUM_STORES) - 1;
    int item = read_int_in_range("Enter item number (1-5): ", 1, NUM_ITEMS) - 1;
    int qty;
    cout << "Enter quantity to reduce (positive integer): ";
    while (!(cin >> qty) || qty <= 0) {
        cout << "Invalid quantity. Enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    // If the requested reduction is larger than current stock, we clamp to 0
    // and inform the user. Another design option is to reject the operation.
    if (qty > stock[s][item]) {
        cout << "Cannot reduce by " << qty << " because current stock is " << stock[s][item] << ". Setting stock to 0.\n";
        stock[s][item] = 0;
    } else {
        stock[s][item] -= qty;
        cout << "Reduced " << qty << " from store " << (s+1) << ", item " << (item+1) << ". New stock: " << stock[s][item] << "\n";
    }
}

int main() {
    cout << "Task 2: Stationery stock management (10 stores x 5 items)\n";
    int** stock = create_stock();

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Show store stock\n";
        cout << "2. Add stock to an item in a store\n";
        cout << "3. Reduce stock from an item in a store\n";
        cout << "4. Exit\n";
        int cmd = read_int_in_range("Choose an option (1-4): ", 1, 4);
        if (cmd == 1) show_store(stock);
        else if (cmd == 2) add_stock(stock);
        else if (cmd == 3) reduce_stock(stock);
        else if (cmd == 4) {
            cout << "Exiting and freeing memory...\n";
            break;
        }
    }

    delete_stock(stock);
    cout << "Memory freed. Goodbye.\n";
    return 0;
}

/*
  Extra notes and modern alternatives:

  1) Using std::vector (recommended):
     std::vector<std::vector<int>> stock(NUM_STORES, std::vector<int>(NUM_ITEMS, 0));
     This automatically handles allocation and deallocation and provides bounds-checked
     access with .at(i) if you want exceptions on out-of-range access.

  2) Single allocation 2D array (more cache-friendly): allocate one block of
     NUM_STORES * NUM_ITEMS ints and compute index as row*NUM_ITEMS + col.

  3) Input validation: current helper read_int_in_range is simple and effective
     for this exercise. For production code consider centralizing error handling
     and adding unit tests for edge cases.

*/
