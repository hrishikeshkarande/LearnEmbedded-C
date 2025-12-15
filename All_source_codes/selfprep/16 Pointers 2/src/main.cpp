#include <stdio.h>
#include <stdint.h>

typedef struct 
{
    int id;
    char status;
} Device_t;


int main() {
    Device_t devices[2] = {{1,'A'},{2,'B'}};
    Device_t *ptr = devices; //Here we can assign the devices object of the struct to the pointer because both are of the same type, Device_t in this case

    printf("ID: %d\n", ptr->id); //We use the pointer the access the member of the struct
    ptr++; //Incrementing the pointer
    printf("ID: %d\n", ptr->id); //Now it will point to the next ID member 

    //Similarly
    ptr--;
    printf("Status 1: %c\n", (ptr)->status);
    ptr++;
    printf("Status 2: %c\n", (ptr)->status);

    //Here the pointer ptr is moving by the sizeof(Device_t) bytes of the struct, 8 bytes in this case, 4 of int and 1 of char, 3 padding
    
    printf("Size of the struct: %zu\n", sizeof(Device_t));

    //Pointer with RAW MEMORY, Byte level access
    uint32_t value = 0x11223344;        //This is a 32 bit hexadecimal value, 4 bytes
    uint8_t *p = (uint8_t *)&value;     //We will make a 8 bit pointer and assign 8 bit pointer address of value to it, 1 byte

    printf("%X\n",*p); //We are printing in hexadecimal, travelling via the pointer, going from right to left 
    printf("%X\n",*(p+1)); //Here we are incrementing the pointer
    printf("%X\n",*(p+2)); 
    printf("%X\n",*(p+3));

    //Difference between *p++ and (*p)++
    printf("%X\n",*p); //We are printing in hexadecimal 
    printf("%X\n",(*p)+1);  //Here we are incrementing the value inside the pointer
    printf("%X\n",(*p)+2); 
    printf("%X\n",(*p)+3);

    printf("%X", value); //Note that here the value variable will still be unchanged, we havent done any assignment via the pointer, we have only incremented the values 

    //In order to change the value 11223344 to 11223347 we will only need to write an equal to sign in the last line, ie (*p)+=3, now it is an assignment 



    return 0;
}