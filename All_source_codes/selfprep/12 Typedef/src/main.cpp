#include <stdio.h>

typedef unsigned char u8_t;  //defining a new type name 'u8_t' for 'unsigned char'
typedef unsigned short u16_t; //defining a new type name 'u16_t' for 'unsigned short'
typedef unsigned int u32_t; //defining a new type name 'u32_t' for 'unsigned int'

typedef struct
{   
    int x;
    int y;
} Point_t;                 //it is conventional to use _t suffix for type definitions


int main() {
    //Using the global typedefs
    u8_t a = 255; //here we dont have to write "unsigned char", we can just use "u8"
    u16_t b = 65535; //here we dont have to write "unsigned short", we can just use "u16"
    u32_t c = 4294967295; //here we dont have to write "unsigned int", we can just use "u32"

    printf("u8: %u, u16: %u, u32: %u\n", a, b, c);


    //Using the typedef struct
    Point_t point = {10, 20}; //here we use the Point_t type to declare a variable called point 
    // Otherwise, we could have declared it as "struct Point point;"
    // But using typedef allows us to omit the 'struct' keyword

    printf("Point coordinates: x = %d, y = %d\n", point.x, point.y); //We access the members of the struct using the dot operator

    //Typedef with pointers
    typedef int *intPtr_t; //defining a new type name 'intPtr_t' for 'int*'
    int value = 42;
    intPtr_t pValue = &value; //here we use 'intPtr_t' to declare a pointer to int
    
    typedef const char* cstr_t; //defining a new type name 'cstr_t' for 'const char*'
    cstr_t message = "Hello, Typedef!"; //here we use 'cstr_t' to declare a constant string pointer
    
    printf("Value: %d, Message: %s\n", *pValue, message);

    
    
    return 0;

} 