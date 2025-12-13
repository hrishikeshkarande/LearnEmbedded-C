#include <stdio.h>
#include<stdint.h>

struct A {
    uint8_t a;
    uint32_t b;
    uint16_t c;
}; // 7 bytes padding for alignment

struct B {
    uint32_t b;
    uint16_t c;
    uint8_t a;
}; // 3 bytes padding for alignment


int main(void) {

    printf("Size of struct A: %zu bytes\n", sizeof(A)); // Expected output: Size of struct A: 12 bytes
    printf("Size of struct B: %zu bytes\n", sizeof(B)); // Expected output: Size of struct B: 8 bytes

    // Explanation:
    // Here we see that reordering the members of the struct can reduce the overall size by minimizing padding.
    // Think of the memory alignment requirements of each data type:
    // - uint32_t typically requires 4-byte alignment
    // - uint16_t typically requires 2-byte alignment
    // - uint8_t typically requires 1-byte alignment    
    // The memory we have is like place to store items of different sizes, and each type has its own alignment needs.
    // Padding is added to ensure that data members are aligned in memory according to their types, which can lead to wasted space.
    // By placing larger data types first, we can often reduce the amount of padding needed.
    // This is important for memory efficiency, especially when dealing with large arrays of such structures.

    return 0;
}