#include <stdio.h>
#include <stdlib.h>

// code for appending a number at the end of an array
// logic it follows is simple check if array has space if so append the number
// increase the length 

typedef struct array
{
    int *A;
    int size;
    int length;
} array;

void display(struct array arr);
void append(struct array *arr, int n);

int main(void)
{
    // creating the struct and then allocating memory with check and size
    array arr;
    printf("enter size : ");
    scanf("%d", &arr.size);

    arr.A = (int *) malloc(arr.size * sizeof(int));
    if (arr.A == NULL)
    {
        printf("Memory Allocation failed \n");
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

    append(&arr, 5);

    display(arr);
    free(arr.A);
}
// function to display the array
void display(struct array arr)
{
    printf("The elements of array are : \n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}
// function to append since it modifies the array therefore we use call by adress
void append(struct array *arr, int n)
{
    // check
    if (arr->length < arr->size)
    {
        arr->A[arr->length] = n; // be careful with arrows
        arr->length++; // length increased
    }
    else
    {
        printf("No space \n");
    }
}
