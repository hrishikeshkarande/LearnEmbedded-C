#include <stdio.h>
#include "shared.h"

int shared_var = 50;   // Definition (memory allocated)
// Global variable shared across multiple files
// Useful in embedded programming for sharing state or configuration

void print_shared(void)
{
    printf("shared_var = %d\n", shared_var);
}
