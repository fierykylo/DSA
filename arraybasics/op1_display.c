#include <stdio.h>
#include <stdlib.h>

typedef struct array
{
    int *A;
    int size;   // capacity
    int length; // actual size
} array;

void display(array arr); // display function prototype

int main(void)
{
    array arr;

    // size of array
    printf("Size : ");
    scanf("%d", &arr.size);

    // allocating memory for it and checking if memory allocation was succesful or not

    arr.A = (int *) malloc(arr.size * sizeof(int));
    if (arr.A == NULL)
    {
        printf("Memory allocation failed \n");
        return 1;
    }

    // actual length of numbers along with a check
    printf("how many numbers ? ");
    scanf("%d", &arr.length);
    if (arr.length > arr.size)
    {
        printf("Error : total numbers more than available space : %d \n", arr.size);
        return 1;
    }

    // entering elements
    printf("enter the elements : ");
    for (int i = 0; i < arr.length; i++)
    {
        scanf("%d", &arr.A[i]);
    }

    display(arr);
    free(arr.A);
}

void display(array arr)
{
    printf("The elements of array are : \n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}
