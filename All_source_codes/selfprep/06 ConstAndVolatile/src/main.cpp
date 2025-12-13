#include <stdio.h>
#include <stdint.h>

#define STATUS_REG_ADDR 0x40000000U

const volatile uint32_t* status_reg =           // Pointer to hardware status register we have done this way to avoid compiler optimizations by using 'volatile'
    (const volatile uint32_t*)STATUS_REG_ADDR;  // (const volatile uint32_t*) is type casting to a pointer to a volatile uint32_t type
 

int main(void)
{   
    // DO NOT RUN ON PC - FOR EMBEDDED TARGETS ONLY leads to segmentation fault as 0x40000000 is not a valid memory address on typical PC systems
    // This access is valid only on embedded targets with memory-mapped IO
    //uint32_t status = *status_reg;  // Always read from hardware
    //printf("Status Register Value: 0x%08X\n", status);

    //const with pointer example
    int a = 10;
    int b = 20;

    const int* ptr1 = &a; // pointer to a constant integer
    // *ptr1 = 15; // Error: cannot modify the value pointed to by ptr1
    ptr1 = &b; // Allowed: can change the pointer to point to another integer

    int* const ptr2 = &a; // constant pointer to an integer
    *ptr2 = 15; // Allowed: can modify the value pointed to by ptr2
    // ptr2 = &b; // Error: cannot change the address stored in ptr2

    const int* const ptr3 = &a; // constant pointer to a constant integer
    // *ptr3 = 15; // Error: cannot modify the value pointed to by ptr3
    // ptr3 = &b; // Error: cannot change the address stored in ptr3

    //volatile with pointer example
    volatile int* vptr1 = &a; // pointer to a volatile integer
    *vptr1 = 25; // Allowed: can modify the value pointed to by vptr1
    vptr1 = &b; // Allowed: can change the pointer to point to another integer

    int* volatile vptr2 = &a; // volatile pointer to an integer
    *vptr2 = 30; // Allowed: can modify the value pointed to by vptr2
    vptr2 = &b; // Allowed: can change the pointer to point to another integer

    volatile int* volatile vptr3 = &a; // volatile pointer to a volatile integer
    *vptr3 = 35; // Allowed: can modify the value pointed to by vptr3
    vptr3 = &b; // Allowed: can change the pointer to point to another integer 

    return 0;

}

//“const volatile is used for read-only hardware registers that can change asynchronously.”
//“volatile const is less common but can be used in similar scenarios; the order does not change the meaning.”