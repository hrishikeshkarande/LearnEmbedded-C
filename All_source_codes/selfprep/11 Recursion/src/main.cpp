#include <stdio.h>

int coundown(int n) {
    if (n == 0){ // Base case
        return n;
    }
    else {
        printf("%d\n", n);
        return coundown(n - 1); // Recursive case
    }
}

int factorial(int n)
{
    if (n <= 1)    // Base case
    {
        return 1;
    }

    return n * factorial(n - 1); // Recursive case
}

int main() {
    int number = 10;
    printf("%d\n", coundown(number)); 
    //Will print numbers from 10 to 1 from inside the function and then 0, returns with 0

    int factNumber = 5;
    printf("Factorial of %d is %d\n", factNumber, factorial(factNumber));
    //Will print Factorial of 5 is 120
    return 0;
}