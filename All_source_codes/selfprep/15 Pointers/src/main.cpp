#include <stdio.h>

#define NULL 0 //Defining NULL as 0 for demonstration purposes

int main() {
    //Pointer Basics, declaration and dereferencing
    int x = 10;     //Declare an integer variable x and initialize it to 10
    int *p = &x;    //Declare a pointer variable p and assign it the address of x

    printf("Value of x through pointer p: %d\n", *p); //Dereference pointer p to get the value of x

    //Wild Pointer Example and a common interview trap
    int *p1, p2;    //Interview Trap: This declares p1 as a pointer to int and p2 as an int variable
    //Here, p1 is a wild pointer (uninitialized)

    *p1 = 20;       //Dereferencing wild pointer p1 leads to undefined behavior
    printf("Value assigned through wild pointer p1: %d\n", *p1); //Undefined behavior as in p1 is uninitialized will print garbage value or may crash 

    //Safe practice to avoid wild pointers
    int *p3 = NULL;     //Initialize pointer p3 to nullptr
    int p4 = 0;         // Declare an integer variable p4 and initialize it to 0
    p3 = &p4;           // Assign the address of p4 to pointer p3
    *p3 = 40;           // Now it's safe to dereference p3
    printf("Value assigned through initialized pointer p3: %d\n", *p3); //Should print 40

    //Difference between NULL and nullptr
    int *p5 = NULL;     //Using NULL to initialize pointer p5, which is defined as 0 above
    int *p6 = nullptr;  //Using nullptr to initialize pointer p6 (C++11 and later)

    printf("Pointer p5 initialized with NULL: %p\n", (void*)p5); //Prints address stored in p5 (should be 0)
    printf("Pointer p6 initialized with nullptr: %p\n", (void*)p6); //Prints address stored in p6 (should be 0)

    //We will try to assign nullptr to an integer variable
    //int p7 = nullptr; //This line would cause a compilation error as nullptr cannot be assigned to an integer variable but we can assign NULL to an integer variable
    int p7 = NULL;     //This is valid as NULL is defined as 0
    printf("Integer p7 assigned with NULL: %d\n", p7); //Should print 0

    //Pointer Reassignment
    int a = 50;
    int b = 100;
    int *ptr = &a;     //ptr points to a
    printf("Value pointed by ptr: %d\n", *ptr); //Should print 50
    ptr = &b;          //Reassign ptr to point to b
    printf("Value pointed by ptr after reassignment: %d\n", *ptr); //Should print 100

    //Pointer to const and const pointer
    const int *ptrToConst = &a; //Pointer to const int
    //*ptrToConst = 60; //Error: cannot modify value through ptrToConst
    int const *ptrToConst2 = &a; //Another syntax for pointer to const
    // *ptrToConst2 = 65; //Error: cannot modify value through ptrToConst2
    printf("Value of a through ptrToConst: %d\n", *ptrToConst); //Should print 50
    printf("Value of a through ptrToConst2: %d\n", *ptrToConst2); //Should print 50

    int *const constPtr = &a;   //Const pointer to int
    *constPtr = 70;              //Valid: can modify value pointed to
    //constPtr = &b;             //Error: cannot change the address stored in constPtr
    printf("Value of a after modifications: %d\n", a); //Should print 70


    const int *const constPtrToConst = &a; //Const pointer to const int
    //constPtrToConst = &b;       //Error: cannot change address
    // *constPtrToConst = 80;     //Error: cannot modify value through constPtrToConst  
    printf("Value of a through constPtrToConst: %d\n", *constPtrToConst); //Should print 70


    //Pointer and arrays 
    int arr[] = {1, 2, 3, 4, 5};
    int *arrPtr = arr; //Array name acts as a pointer to the first element

    printf("First element of array through pointer: %d\n", *arrPtr); //Just the pointer name acts as pointer to first element
    printf("Second element of array through pointer arithmetic: %d\n", *(arrPtr + 1)); //Access second element using pointer arithmetic
    //We can write *arrPtr + 1 but it gives wrong result as it adds 1 to the value at arrPtr not to the address
    //Ways to write the above line correctly:
    printf("Second element of array through pointer arithmetic (method 2): %d\n", arrPtr[1]); //Using array indexing
    printf("Second element of array through pointer arithmetic (method 3): %d\n", *(arr + 1)); //Using array name with pointer arithmetic
    printf("Second element of array through pointer arithmetic (method 4): %d\n", arr[1]); //Using array indexing with array name 
    

    return 0;
}