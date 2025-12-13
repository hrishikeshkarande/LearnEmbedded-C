#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t reg = 0b00001111; // Decimal 15

    printf("Initial register value: %u\n", reg); // Expected output: 15

    reg |= (1 << 4); // Set bit 4

    printf("Register value after setting the 4th bit: %u\n", reg); // Expected output: 31 // 0b00011111

    reg &= (~(1)); // Clear bit 0

    printf("Register value after clearing the 0th bit: %u\n", reg); // Expected output: 30 // 0b00011110

    return 0;
}

// This code demonstrates basic bit manipulation in C by setting and clearing specific bits in an 8-bit register.
// It uses bitwise OR to set a bit and bitwise AND with NOT to clear a bit, printing the register's value after each operation.