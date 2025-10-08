#include <iostream>
using namespace std;

int main(){
    cout << "The 'two number' game" << endl;
    
    /* 
    PURPOSE OF DYNAMIC ARRAYS:
    
    Static array (old way):
    int arr[2];  // Size fixed at compile time
    
    Dynamic array (what we're using):
    int* arr = new int[2];  // Size decided at runtime
    
    WHY DYNAMIC?
    1. Flexibility - size can change based on user input
    2. Memory efficiency - allocate exactly what you need
    3. Professional standard - used in real applications
    4. Required when size is unknown until runtime
    
    SYNTAX BREAKDOWN:
    int*     -> This creates a pointer to integers
    new      -> Allocates memory on the heap
    int[2]   -> Creates space for 2 integers
    delete[] -> Frees the allocated memory
    */
    // Step 0: Get user input for dynamic array size
    int size;
    cout << "Enter the size of the dynamic array you want: " << endl;
    cin >> size;
    // Step 1: Create dynamic array to store the two numbers
    cout << "\nCreating dynamic array for " << size << " numbers..." << endl;
    int* numbers = new int[size];  // Allocate memory for 'size' integers

    // Step 2: Get input directly into dynamic array (I didn't want to use extra variables)
    for (int i = 0; i < size; i++) {
        cout << "Provide your number " << (i + 1) << ": ";
        cin >> numbers[i];  // Direct input - saves memory and is more efficient
    }
   
    // Step 3: Verify our dynamic array works
    cout << "\nNumbers stored in dynamic array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "numbers[" << i << "] = " << numbers[i] << endl;
    }

    // Step 4: POINTER vs VALUE DEMONSTRATION
    cout << "\n=== POINTER vs VALUE DEMONSTRATION ===" << endl;
    cout << "What does the pointer contain?" << endl;
    cout << "numbers (pointer itself) = " << numbers << " <- This is an ADDRESS" << endl;
    cout << "*numbers (value at pointer) = " << *numbers << " <- This is the VALUE" << endl;
    cout << endl;
    
    cout << "Different ways to access first element:" << endl;
    cout << "numbers[0] = " << numbers[0] << endl;
    cout << "*numbers = " << *numbers << endl;
    cout << "*(numbers + 0) = " << *(numbers + 0) << endl;
    cout << "All three show the SAME VALUE!" << endl;
    cout << endl;
    
    cout << "Address comparisons:" << endl;
    cout << "numbers = " << numbers << endl;
    cout << "&numbers[0] = " << &numbers[0] << endl;
    cout << "These two addresses are IDENTICAL!" << endl;
    cout << endl;

    // Step 5: Show memory addresses (advanced concept)
    cout << "\nMemory layout:" << endl;
    for (int i = 0; i < size && i < 3; i++) {  // Limit to first 3 for clarity
        cout << "numbers[" << i << "] = " << numbers[i] 
             << " (stored at address: " << &numbers[i] << ")" << endl;
    }

    // Step 5: CRITICAL - Free the memory when done!
    delete[] numbers;  // This prevents memory leaks!
    cout << "\nMemory freed successfully!" << endl;
    
    return 0;
}