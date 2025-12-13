#include <stdio.h>

void incrementbyvalue (int x){
    x = x + 1; //here x is a copy of the argument passed
    printf("Inside function: %d\n", x);
}

void incrementbyreference(int*x){ //here x is a reference (pointer) to the argument passed
    *x = *x + 1; //here we are dereferencing the pointer to modify the original value
    printf("Inside function: %d\n", *x);
}

int main() {
    int a = 10;
    incrementbyvalue (a); //a copy of 'a' is passed to the function
    printf("Inside main: %d\n", a); // original 'a' remains unchanged

    int b = 20;
    incrementbyreference(&b); //reference to 'b' is passed to the function, we are passing the address of 'b'
    printf("Inside main: %d\n", b); // original 'b' is modified

    return 0;
}

//embedded loves pass by reference because it saves memory and increases performance
//especially when dealing with large data structures.
//pass by value creates a copy of the data, which can be inefficient for large structures.
//pass by reference allows functions to modify the original data without creating a copy.
//saves stack space and reduces overhead, which is crucial in resource-constrained embedded systems.
//however, care must be taken to avoid unintended side effects when modifying data via references.