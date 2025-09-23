#include <stdio.h>
// arrays are vector variables
// memory allocated to them is contagious
// can differentiate them with the help of indexes
// indexing starts from 0

int main(void)
{
    // declarations 
    int A[5]; // contains gasrbage values
    int B[5] = {1, 2, 3, 4, 5};
    int C[5] = {2,4}; // 2 , 4 , 0, 0, 0 initialised like this
    int D[5] = {0}; // array full of 0s
    int E[] = {2, 4, 6, 8, 10}; // intialises an array of size 5

    // accessing values
    A[0] = 2; // 0th element of the array
    printf("%d \n", A[2]);
    printf("%d \n", 2[A]);
    printf("%d \n", *(A + 2));
}