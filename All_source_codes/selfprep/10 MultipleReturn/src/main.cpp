#include <stdio.h>

void calculate(int a, int b, int *sum, int *diff) {
    *sum = a + b;
    *diff = a - b;
}

//here note that the above function doesnt return any value, it uses pointer parameters to return multiple values
//this is a common technique in embedded systems where avoiding the overhead of returning large structures is beneficial.

void print_value(const int * value) { //using const to indicate we won't modify the value
    printf("Value = %d\n", *value); //dereferencing the pointer to get the actual value

    /*
    *value = 20;    //this will cause a compilation error since value is a pointer to const int
    value++;        //this is allowed, we are changing the pointer, not the value it points to
    */
}

int main() {
    int s, d;
    calculate(10,5, &s, &d); //we pass the addresses of s and d to store the results

    printf("Sum = %d and Diff = %d\n", s, d);
    
    int myvar = s + d;

    print_value(&myvar); //passing address of myvar to print_value

    return 0;
}

//Using const with pointers helps prevent accidental modification of data, enhancing code safety and readability.
//Using pointers to return multiple values from functions is a common practice in embedded C.