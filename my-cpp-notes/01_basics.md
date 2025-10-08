## BASIC EXAMPLES OF C++

### Hello World 🙂

``` cpp
#include <iostream>   // standard input/output stream library
using namespace std;  // allows us to use names like 'cout' directly

int main() {          // the beginning of the program
    cout << "Hello, Sinem! Welcome to C++ world." << endl;
    return 0;         // finished successfully
}
```

To compile:

``` bash
g++ hello.cpp -o hello
```

To run:

``` bash
./hello
```

------------------------------------------------------------------------

### Notes

A C++ program is made up of **functions** and **classes**.

Like in C, the computer **always starts executing from the `main()`
function**.

``` cpp
int main() {
    // Program starts here
}
```

In Python, you can just write:

``` python
print("Hello")
```

But in C++, **everything must be inside a function or class** --- and
`main()` is mandatory.\
Without it, the program will not run.

``` cpp
int main() {
    ...
    return 0;
}
```

  Part          Meaning
  ------------- ---------------------------------------
  `int`         The return type (integer)
  `main`        The special entry-point function name
  `()`          Parentheses --- may contain arguments
  `{ ... }`     Function body --- executable code
  `return 0;`   Indicates successful termination

💡 In C++, **you still need to declare return types**, but you also have
**features like function overloading**, **default parameters**, and
**classes** that make it more powerful than C.

------------------------------------------------------------------------

### Defining Additional Functions

``` cpp
#include <iostream>
using namespace std;

void sayHello() {
    cout << "Hello from another function!" << endl;
}

int main() {
    sayHello();
    return 0;
}
```

Output:

    Hello from another function!

Here: - `void` means the function **returns nothing** - `sayHello()` is
a **custom helper function** - `main()` is still the **entry point**

------------------------------------------------------------------------

### How the Compiler Sees It

The C++ compiler (`g++`) processes your code in these steps: 1. Reads
the file top to bottom\
2. Includes all headers from `#include` lines\
3. Compiles each function and class definition\
4. Finds the `main()` function\
5. Starts execution from there

------------------------------------------------------------------------

### Quick Summary

  -----------------------------------------------------------------------
  Concept                        Description
  ------------------------------ ----------------------------------------
  `#include <iostream>`          Imports the standard input/output stream
                                 library (`cout`, `cin`, etc.)

  `using namespace std;`         Lets you use names like `cout` without
                                 prefixing `std::`

  `int main()`                   The **main function** --- required entry
                                 point of every C++ program

  `{ ... }`                      Code block (the statements to execute)

  `return 0;`                    Indicates the program executed
                                 successfully
  -----------------------------------------------------------------------

------------------------------------------------------------------------

✅ **In short:** - Every C++ program starts from `int main()`.\
- `cout` and `cin` replace `printf` and `scanf` from C.\
- You can use both **functions** and **classes** to organize your code.\
- Returning `0` means "Program executed successfully."