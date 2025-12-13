#include <stdio.h>
#include "shared.h"

static int file_var = 100; // static variable at file scope

void func() {
    auto x = 0; // same as: int x = 0;
    printf("Auto declared variable x = %d\n", x);
    x++;
    printf("Auto declared variable x after increment = %d\n", x);

    //auto is rarely used in embedded programming.
    //auto variables are local to a block and allocated on the stack.
}

void counter(){
    static int count = 0; // static variable to retain value between calls
    count++;
    printf("Counter: %d\n", count);

    // static variables are used to maintain state between function calls.
    // They are allocated in the data segment, not on the stack.
    // Useful in embedded systems for tracking state without global variables.
}

void func_global_static(void)
{
    printf("file_var = %d\n", file_var);
}


int main() {
    func();   //function for demonstration of auto
    func();   //calling multiple times to show auto behavior
    func();   //calling multiple times to show auto behavior

    counter(); //function for demonstration of static
    counter(); //calling multiple times to show static behavior
    counter(); //calling multiple times to show static behavior

    func_global_static(); //function to demonstrate file scope static variable

    //Use of extern to access global variable from another file
    print_shared(); //function to demonstrate global shared variable from another file using extern
    //We have written shared_var in shared.c file and declared it in shared.h file.
    //This is useful in embedded programming for sharing variables across multiple files.
    // Global variables are allocated in the data segment.

    register int i; // register variable

    for(i = 0; i < 5; i++) {
        printf("Register variable i = %d\n", i);
    }
    // register keyword is a hint to the compiler to store the variable in CPU register for faster access.
    // However, modern compilers optimize this automatically, so its use is rare in embedded programming.

    printf("%p\n", &i); //address of register variable may not be accessible 
    // %p is used to print address of variable 
    // In many cases, you may not be able to get the address of a register variable.
    // This is because register variables may be stored in CPU registers, which do not have a memory address.

    return 0;
}


/*
| Storage Class   | Scope  | Lifetime | Linkage  | Memory                |
| --------------- | ------ | -------- | -------- | --------------------- |
| auto            | Block  | Block    | None     | Stack                 |
| static (local)  | Block  | Program  | None     | Data/BSS              |
| static (global) | File   | Program  | Internal | Data/BSS              |
| extern          | Global | Program  | External | Data/BSS              |
| register        | Block  | Block    | None     | CPU Register (if any) |
*/