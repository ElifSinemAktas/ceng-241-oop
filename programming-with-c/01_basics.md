## BASIC EXAMPLES OF C

### Hello World:)

```c
#include <stdio.h>  // standard input/output library

int main() {         // the beginning of program
    printf("Hello, Sinem! Welcome to C world.\n");
    return 0;        // finished successfully
}
```

To compile 

```bash
gcc hello.c -o hello
```

To run

```bash
./hello
```

### Notes

A C program is made up of **functions**.  

The computer **always starts executing from the `main` function**.

```c
int main() {
    // Program starts here
}
```

In Python, you can just write

```python
print("Hello")
```
and it runs directly.  


But in C, **everything must be inside a function** — and `main()` is mandatory.   Without it, the program will not run.

```c
int main() {
    ...
    return 0;
}
```

| Part | Meaning |
|------|----------|
| `int` | The return type (integer) |
| `main` | The function name (special name — program entry point) |
| `()` | Parentheses — may contain arguments |
| `{ ... }` | Function body, contains the executable code |
| `return 0;` | Indicates successful program termination |

💡 In Python, functions don’t have to specify a return type,  but in C, **every function must** — even `main()`.


You can define additional helper functions besides `main()`.

```c
#include <stdio.h>

void sayHello() {
    printf("Hello from another function!\n");
}

int main() {
    sayHello();
    return 0;
}
```

Output: 

```
Hello from another function!
```

Here:
- `void` means the function **returns nothing**
- `sayHello()` is a **custom helper function**
- `main()` is still the **entry point**

---

#### How the Compiler Sees It

The C compiler (like `gcc`) processes your code in these steps:
1. Reads the file top to bottom  
2. Includes all headers from `#include` lines  
3. Compiles each function definition  
4. Finds the `main()` function  
5. Starts program execution from there  

---

### Quick Summary

| Concept | Description |
|----------|-------------|
| `#include <stdio.h>` | Imports the Standard Input/Output library (for `printf`, `scanf`, etc.) |
| `int main()` | The **main function** — required entry point of every C program |
| `{ ... }` | Code block (the statements to be executed) |
| `return 0;` | Returns a success signal to the system when the program ends |


---

✅ **In short:**
- Every C program starts from `int main()`.  
- It must return an integer, typically `0`, meaning “Program executed successfully.”