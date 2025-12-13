#include <stdio.h>

//This code is in the text/code section of memory where the executable instructions reside, it is located in ROM


int global_init = 10;               //Data section in memory located in RAM
int global_uninit;                  //BSS section in memory, BSS full form is Block Started by Symbol, it contains all uninitialized global and static variables
const int global_const = 20;        //Flash/RO section in memory located in ROM, all const variables are stored in read-only memory
static int static_global;           //BSS section in memory located in RAM

void func() {
    // Function to demonstrate local scope
    int local_var = 5;              //Stack section in memory located in RAM
    static int static_var;          //Data or BSS section in memory depending on initialization, here BSS since uninitialized, if initialized would be Data section
    const int local_const = 15;     //Stack section in memory located in RAM
    
    printf("Global Initialized: %d\n", global_init);            // Accessing initialized global variable
    printf("Global Uninitialized: %d\n", global_uninit);        // Accessing uninitialized global variable
    printf("Global Constant: %d\n", global_const);              // Accessing constant global variable
    printf("Static Global: %d\n", static_global);               // Accessing static global variable
    printf("Local Variable: %d\n", local_var);                  // Accessing local variable
    printf("Static Variable: %d\n", static_var);                // Accessing static variable
    printf("Local Constant: %d\n", local_const);                // Accessing local constant
    
    //Uninitilized variables will have default value of 0 why because they are stored in BSS section of memory

}

int main() {

    func(); // Call the function to demonstrate variable scopes and storage classes  

    

    //static and const variables have different storage durations and linkage
    //static variables retain their value between function calls and have internal linkage
    //const variables cannot be modified after initialization
    //global variables have external linkage by default unless declared static
    //local variables have automatic storage duration and are created/destroyed with function calls
    //BSS section is initialized to zero by default ************IMPORTANT**************
    //Data section contains initialized global and static variables
    //Flash/RO section contains constant variables stored in read-only memory
    //Stack section is used for local variables and function call management
    //Heap section is used for dynamic memory allocation (not demonstrated in this code)

    return 0;



}