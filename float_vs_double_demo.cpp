#include <iostream>
#include <iomanip>  // For precision control
using namespace std;

int main() {
    cout << "=== FLOAT vs DOUBLE DEMONSTRATION ===" << endl;
    cout << fixed << setprecision(15);  // Show 15 decimal places
    
    // 1. Memory size
    cout << "\n1. MEMORY SIZE:" << endl;
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    
    // 2. Precision difference
    cout << "\n2. PRECISION DIFFERENCE:" << endl;
    float f = 3.141592653589793f;   // Note the 'f' suffix
    double d = 3.141592653589793;
    
    cout << "float value:  " << f << endl;
    cout << "double value: " << d << endl;
    
    // 3. Loss of precision example
    cout << "\n3. PRECISION LOSS EXAMPLE:" << endl;
    float bigFloat = 123456789.0f;
    double bigDouble = 123456789.0;
    
    cout << "float (big number):  " << bigFloat << endl;
    cout << "double (big number): " << bigDouble << endl;
    
    // 4. Arithmetic precision
    cout << "\n4. ARITHMETIC PRECISION:" << endl;
    float f1 = 1.0f / 3.0f;
    double d1 = 1.0 / 3.0;
    
    cout << "1/3 as float:  " << f1 << endl;
    cout << "1/3 as double: " << d1 << endl;
    
    // 5. When precision matters
    cout << "\n5. COMPOUND CALCULATION:" << endl;
    float resultF = 0.0f;
    double resultD = 0.0;
    
    for(int i = 0; i < 1000000; i++) {
        resultF += 0.1f;
        resultD += 0.1;
    }
    
    cout << "Adding 0.1 one million times:" << endl;
    cout << "Float result:  " << resultF << " (should be 100000)" << endl;
    cout << "Double result: " << resultD << " (should be 100000)" << endl;
    
    return 0;
}
