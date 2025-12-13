#include <stdio.h>

int main(void) {

    // Demonstrating different char types in C, know that char is also an integer type and can store small integer values
    char c1 = 'A';              // ASCII value 65
    signed char c2 = -10;       // Signed char with value -10
    unsigned char c3 = 250;     // Unsigned char with value 250
    
    printf("c1 = %c, %d\n", c1, c1);    // Use %c to print character and %d for its integer value
    printf("c2 = %d\n", c2);            // Use %d to print signed char as integer
    printf("c3 = %u\n", c3);            // Use %u to print unsigned char as unsigned integer

    //Int Overflow Example, Please know that we are on a 32-bit system
    unsigned int u = 4294967295; // Maximum value for 32-bit unsigned int
    signed int s = 2147483647;   // Maximum value for 32-bit signed int

    u = u + 1; // This will wrap around to 0 becuase range is 0 to 4294967295
    s = s + 1; // This will overflow to -2147483648 because range is -2147483648 to 2147483647

    printf("Unsigned int after overflow: %u\n", u); // Using %u for unsigned int
    printf("Signed int after overflow: %d\n", s); // Using %d for signed int

    //Such behavior is defined in C for unsigned integers (wrap-around), but signed integer overflow leads to undefined behavior.

    //Float Precision issue example, knowing that float has about 7 decimal digits of precision
    float a = 0.1f; // 'f' suffix indicates a float literal
    float b = 0.2f; 
    float c = a + b;

    printf("a + b = %.10f\n", c); // We use %.10f to show more decimal places
    printf("a + b = %.20f\n", c); // Showing even more decimal places to illustrate precision issue

    //Floats are avoided in embedded systems when high precision is required
    //Someimes the MCUs have a limited floating-point unit (FPU) or none at all, making float operations slower.

    //Comparison pitfall with signed and unsigned integers
    unsigned int ui = 1;
    signed int si = -1;

    if (ui > si)  
        printf("Unsigned int %u is greater than signed int %d\n", ui, si); 
    else
        printf("Signed int %d is greater than or equal to unsigned int %u\n", si, ui); //This will be printed

    //In this case, si is converted to an unsigned int for the comparison, resulting in a large positive value.
    //This can lead to unexpected results in comparisons.
    //To avoid such pitfalls, it's advisable to ensure both operands are of the same type before comparison.
    //Explicit casting or using only signed or unsigned types consistently can help prevent such issues.
    //In embedded systems, such pitfalls can lead to critical bugs, especially in resource-constrained environments.

    return 0;
}