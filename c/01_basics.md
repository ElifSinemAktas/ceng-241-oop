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

**Notes** 

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


But in C, **everything must be inside a function** — and `main()` is mandatory.  
Without it, the program will not run.

```c
int main() {
    ...
    return 0;
}
```

