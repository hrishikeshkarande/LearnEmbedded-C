#include <stdio.h>

void led_on() {
    printf("LED is ON\n");
}

typedef void (*FuncPtrTypedef)(void); 
//typedef for a function pointer that points to functions returning void and taking no parameters

void led_off() {
    printf("LED is OFF\n");
}

int main() {
    void (*func_ptr)(void); //this is how we declare a function pointer
    func_ptr = led_on; //this is how we assign the address of a function to a function pointer
    func_ptr(); //this is how we call a function using a function pointer

    //can we print the address of the function pointer?
    printf("Address of function pointer: %p\n", (void*)func_ptr);

    //can we print the address of the function itself?
    printf("Address of function itself: %p\n", (void*)led_on);

    //can we compare the two addresses?
    if (func_ptr == led_on) {
        printf("The addresses are the same.\n");
    } else {
        printf("The addresses are different.\n");
    }
 
    //using typedef for function pointer
    FuncPtrTypedef func_ptr_typedef; //declare a function pointer using typedef 
    func_ptr_typedef = led_off; //assign the address of led_off to func_ptr_typedef
    func_ptr_typedef(); //call the function through the typedef'd function pointer



    return 0;  
}

// This code demonstrates the use of function pointers in C++. It includes:
// 1. Declaration and assignment of function pointers.
// 2. Calling functions through function pointers.
// 3. Printing and comparing addresses of functions and function pointers.
// 4. Using typedef to simplify function pointer declarations.