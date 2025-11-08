#include <stdio.h>
#include <stdlib.h>

typedef struct array
{
    int *A;
    int size;
    int length;
} array;

// prototypes
void display(struct array arr);
void insert(struct array *arr, int index, int element);

int main(void)
{
    array arr;

    // size allocate check
    printf("Size of array: ");
    scanf("%d", &arr.size);

    arr.A = (int *) malloc(arr.size * sizeof(int));
    if (arr.A == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    // length and entering the elements
    printf("Length of array: ");
    scanf("%d", &arr.length);

    if (arr.length > arr.size)
    {
        printf("Error: length cannot be greater than size (%d)\n", arr.size);
        free(arr.A);
        return 1;
    }

    // taking the elements
    printf("Enter the elements: ");
    for (int i = 0; i < arr.length; i++)
    {
        scanf("%d", &arr.A[i]);
    }

    // test insert
    insert(&arr, 4, 12);

    display(arr);

    free(arr.A);
    return 0;
}

// function to display the array
void display(struct array arr)
{
    printf("The elements of array are: ");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

// function to insert (modifies the array)
void insert(struct array *arr, int index, int element)
{
    if (arr->length == arr->size)
    {
        printf("Error: array is full, cannot insert.\n");
        return;
    }

    if (index < 0 || index > arr->length)
    {
        printf("Error: invalid index %d.\n", index);
        return;
    }

    for (int i = arr->length; i > index; i--)
    { // shifting
        arr->A[i] = arr->A[i - 1];
    }

    arr->A[index] = element;
    arr->length++;
}
