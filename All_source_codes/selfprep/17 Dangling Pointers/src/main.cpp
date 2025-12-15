#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p;
    {
        int x = 10;
        p = &x;
    } // x goes out of scope here

    *p=20; //dangling pointer

    printf("Trying to access x = %d\n", *p); //This will print the value in x but it is no longer called x, if you try to call it with x name it is not possible

    //So that address and the pointer to that address called p exists, but our identifier to that address has died


    //To overcome this always initialize pointers with NULL, and later after they variable they point to goes out of scope, point the pointer back to null
    //This is a Heap Dangling pointer
    int *ptr = (int *)malloc(sizeof(int));
    free(ptr);

    ptr = NULL;
    *ptr = 5; //Program will crash if you do this, do not derefence a Null Pointer
    printf("Trying to access ptr = %d\n", *ptr); //Program has crashed already, second printf doesnt get printed

    return 0;    
}