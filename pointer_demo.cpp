#include <iostream>
using namespace std;

int main() {
    // Create a simple example
    int* arr = new int[3];
    arr[0] = 100;
    arr[1] = 200;
    arr[2] = 300;
    
    cout << "=== WHAT YOU'LL SEE WHEN PRINTING ===" << endl;
    cout << endl;
    
    cout << "arr = " << arr << endl;
    cout << "^ This prints an ADDRESS (like 0x55a2b4c0e2b0)" << endl;
    cout << endl;
    
    cout << "*arr = " << *arr << endl;
    cout << "^ This prints the VALUE at that address (100)" << endl;
    cout << endl;
    
    cout << "arr[0] = " << arr[0] << endl;
    cout << "^ This also prints the VALUE (100)" << endl;
    cout << endl;
    
    cout << "&arr[0] = " << &arr[0] << endl;
    cout << "^ This prints the SAME ADDRESS as 'arr'" << endl;
    cout << endl;
    
    cout << "=== SUMMARY ===" << endl;
    cout << "Pointer 'arr' CONTAINS: " << arr << " (an address)" << endl;
    cout << "At that address LIVES: " << *arr << " (the actual value)" << endl;
    
    delete[] arr;
    return 0;
}
