#include <stdio.h>

/*
    Multidimensional array demonstration

    Key concepts covered:
    1. Memory layout (row-major order)
    2. Array name decay
    3. Pointer to array
    4. Pointer arithmetic
    5. Passing 2D array to function
*/

/* Function that accepts a 2D array
   IMPORTANT:
   - Column size MUST be known at compile time
   - arr is actually a pointer to an array of 3 ints
*/

void print_matrix(int arr[][3], int row){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < 3; j++){
            printf("%d ", arr[i][j]);
        }
    }
}


int main() {

    /* 2D array declaration
       - 2 rows
       - 3 columns
       - Stored contiguously in memory (row-major order)
    */
    int matrix [2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    /* Access using array indexing */
    printf("Access using array indexing: \n");
    printf("matrix[0][0] = %d\n", matrix[0][0]);
    printf("matrix[1][2] = %d\n", matrix[1][2]);


    /* Array name decay:
       - matrix decays to a pointer to its first row
       - Type of matrix is: int (*)[3]
    */

    int (*ptr)[3] = matrix; // pointer to array of 3 ints, here the pointer needs to be in bracket

    // pointer to array of 3 ints
    printf("Access using pointer to array: \n");
    printf("ptr[0][0] = %d \n", ptr[0][0]);
    printf("ptr[1][2] = %d \n", ptr[1][2]);
    
    /* Pointer arithmetic explanation:
       - ptr + 1 moves to the next ROW
       - Because each row contains 3 integers
    */

    printf("\nPointer arithmetic:\n");
    printf("*(*(ptr + 1) + 1) = %d\n", *(*(ptr + 1) + 1)); // matrix[1][1]
    printf("*(*(ptr + 1) + 2) = %d\n", *(*(ptr + 1) + 2)); // matrix[1][2]
    
    /* sizeof behavior */
    printf("\nSize information:\n");
    printf("Sizeof(matrix)      =    %zu bytes \n", sizeof(matrix)); //Entire matrix
    printf("Sizeof(matrix[0])   =    %zu bytes \n", sizeof(matrix[0])); //One Row
    printf("Sizeof(matrix[0][0])=    %zu bytes \n", sizeof(matrix[0][0])); //One element

    /* Passing 2D array to function */
    printf("\nPrinting matrix using function:\n");
    print_matrix(matrix, 2);

}