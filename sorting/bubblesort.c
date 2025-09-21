#include <stdio.h>

// for these scenarios and to keep the code neat and clean ill be using arrays of my own
// also this is bubble sort
// comparisions made - o(n2)
// passes made - o(n2)
// time complexity min - O(n) max - O(n2)
// it is adaptive
// it is stable

void swap(int A[], int j);
void bubbleSort(int A[], int n);

int main(void)
{
    int A[10] = {57, 12, 89, 23, 45, 67, 5, 91, 34, 76};
    int n = 10;
    bubbleSort(A, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void swap(int A[], int j)
{
    int temp = A[j];
    A[j] = A[j + 1];
    A[j + 1] = temp;
}

void bubbleSort(int A[], int n) // bubble sort function
{
    int flag;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0; // makes the code adaptable
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            { // comparision
                swap(A, j);
            }
            flag = 1;
        }
        if (flag == 0)
        {
            return;
        }
    }
}
