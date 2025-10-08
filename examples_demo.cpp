#include <iostream>
using namespace std;

int main() {
    cout << "=== VARIABLES ===" << endl;
    int age = 25;
    cout << "Variable age = " << age << endl;
    cout << "Address of age: " << &age << endl;
    cout << endl;

    cout << "=== STATIC ARRAYS ===" << endl;
    int scores[3] = {85, 92, 78};
    cout << "Static array scores:" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "scores[" << i << "] = " << scores[i] 
             << " (address: " << &scores[i] << ")" << endl;
    }
    cout << "Array name 'scores' points to: " << scores << endl;
    cout << endl;

    cout << "=== POINTERS ===" << endl;
    int value = 42;
    int* ptr = &value;  // ptr stores address of value
    cout << "Variable value = " << value << endl;
    cout << "Address of value (&value) = " << &value << endl;
    cout << "Pointer ptr = " << ptr << endl;
    cout << "Value at pointer (*ptr) = " << *ptr << endl;
    cout << "Address of pointer itself (&ptr) = " << &ptr << endl;
    cout << endl;

    cout << "=== DYNAMIC ARRAYS ===" << endl;
    int* dynamicArr = new int[3];
    dynamicArr[0] = 100;
    dynamicArr[1] = 200;
    dynamicArr[2] = 300;
    
    cout << "Dynamic array:" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "dynamicArr[" << i << "] = " << dynamicArr[i] 
             << " (address: " << &dynamicArr[i] << ")" << endl;
    }
    cout << "Pointer dynamicArr points to: " << dynamicArr << endl;
    cout << endl;

    cout << "=== ARRAY-POINTER RELATIONSHIP ===" << endl;
    cout << "Different ways to access first element:" << endl;
    cout << "scores[0] = " << scores[0] << endl;
    cout << "*scores = " << *scores << endl;
    cout << "*(scores+0) = " << *(scores+0) << endl;
    cout << endl;

    cout << "Different ways to access second element:" << endl;
    cout << "scores[1] = " << scores[1] << endl;
    cout << "*(scores+1) = " << *(scores+1) << endl;
    cout << endl;

    cout << "=== POINTER ARITHMETIC ===" << endl;
    int* p = scores;  // Point to first element
    cout << "p points to: " << p << " (value: " << *p << ")" << endl;
    p++;  // Move to next element
    cout << "p++ points to: " << p << " (value: " << *p << ")" << endl;
    p++;  // Move to next element
    cout << "p++ points to: " << p << " (value: " << *p << ")" << endl;
    cout << endl;

    cout << "=== MEMORY CLEANUP ===" << endl;
    delete[] dynamicArr;
    cout << "Dynamic array memory freed!" << endl;

    return 0;
}
