#include <stdio.h>

// O(n2)
// k passes give u kth smallest element
// not adaptive or stable

void selection(int A[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int k;
        for(int j = k = i; j < n; j++)
        {
            if (A[j] < A[k])
            {
                k = j;
            }
        }
        int temp = A[i];
        A[i] = A[k];
        A[k] = temp;

    }
}
int main(void)
{
    int A[10] = {57, 12, 89, 23, 45, 67, 5, 91, 34, 76};
    int n = 10;
    selection(A, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}