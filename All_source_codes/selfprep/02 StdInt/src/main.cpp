#include <stdio.h>
#include <stdint.h>

void func(int arr[])
{
    //When an array is passed to a function, it decays to a pointer to its first element
    printf("Inside func() the size of arr is %zu bytes\n", sizeof(arr)); 
    // Size of pointer will be printed which is typically 4 or 8 bytes depending on the architecture
}

int main(void) {
    //Basics of stdint types
    uint8_t u8 = 255; // Maximum value for uint8_t
    int8_t s8 = -128; // Minimum value for int8_t

    uint16_t u16 = 65535; // Maximum value for uint16_t
    int16_t s16 = -32768; // Minimum value for int16_t

    uint32_t u32 = 4294967295u; // Maximum value for uint32_t, we add 'u' suffix to indicate unsigned
    int32_t s32 = -2147483648; // Minimum value for int32_t

    printf("uint8_t: %u, int8_t: %d\n", u8, s8); // Print uint8_t and int8_t
    printf("uint16_t: %u, int16_t: %d\n", u16, s16); // Print uint16_t and int16_t
    printf("uint32_t: %u, int32_t: %d\n", u32, s32); // Print uint32_t and int32_t  

    //Sizeof example
    printf("Size of char : %zu bytes\n", sizeof(char)); // Size of char
    printf("Size of int : %zu bytes\n", sizeof(int)); // Size of int
    printf("Size of long : %zu bytes\n", sizeof(long)); // Size of long
    printf("Size of long long : %zu bytes\n", sizeof(long long)); // Size of long long
    printf("Size of uint8_t: %zu bytes\n", sizeof(uint8_t)); //We use %zu for size_t which is the return type of sizeof operator 
    printf("Size of int8_t: %zu bytes\n", sizeof(int8_t)); // Size of int8_t
    printf("Size of uint16_t: %zu bytes\n", sizeof(uint16_t));
    printf("Size of int16_t: %zu bytes\n", sizeof(int16_t)); // Size of int16_t
    printf("Size of uint32_t: %zu bytes\n", sizeof(uint32_t)); // Size of uint32_t
    printf("Size of int32_t: %zu bytes\n", sizeof(int32_t)); // Size of int32_t

    //Size of signed or unsigned types is the same as their corresponding standard types
    //We use stdint for poratbility across different platforms in embedded systems
    //For example, uint8_t is guaranteed to be 8 bits on all platforms, whereas 'unsigned char' may vary
    //Using stdint types helps avoid issues related to type sizes when porting code between different architectures


    //Sizeof pitfall
    int arr[10];

    printf("Inside main() the size of arr is %zu bytes\n", sizeof(arr)); // Total size of the array will be printed (10 * size of int)
    func(arr); // Pass array to function

    return 0;
}