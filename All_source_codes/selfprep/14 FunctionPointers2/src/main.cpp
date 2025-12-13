#include <stdio.h>

typedef void (*callback_t)(void); 
//Here we have defined a function pointer type 'callback_t' that points to functions taking no parameters and returning void.

void button_pressed(void) 
//This is a callback function that matches the signature defined by 'callback_t'.
{
    printf("Button Pressed!\n");
}

void register_callback(callback_t cb) 
//This function takes a function pointer as an argument and simulates an event by calling the passed-in callback function.
{
    cb(); //here we are calling the function with the name 'cb'
}

int main(void)
{
    register_callback(button_pressed); 
    //Here we are passing the 'button_pressed' function as a callback to 'register_callback'.
    //Since this is being passed like this, we do need to assign it to a variable of type 'callback_t' first.
    return 0;
}

// In this example, when you run the program, it will output "Button Pressed!" to the console,
// demonstrating how function pointers can be used to implement callback functionality in C++.
