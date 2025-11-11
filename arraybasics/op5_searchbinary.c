#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct array
{
    int *A;
    int size;   // capacity
    int length; // actual size
} array;

int BinarySearch(struct array arr, int key);

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
    int key;
    printf("Enter key : \n");
    scanf("%d", &key);
    printf(" Element found at : %d \n", BinarySearch(arr, key));
    free(arr.A);
}

int BinarySearch(struct array arr, int key)
{
    int mid;
    int low = 0;
    int high = arr.length - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == arr.A[mid])
        {
            return mid;
        }
        else if (key < arr.A[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
