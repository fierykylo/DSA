#include <stdio.h>
// insertion sort 
// number of passes (n-1)
// no of comparions = O(n2)
// nothinf useful until end
// adaptive and stable by nature 
void insertionsort(int A[],int n)
{
    
    for(int i = 1; i < n; i++)
    {
        int j = i - 1;
        int x = A[i];
        while(j > -1 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

int main(void)
{
    int A[10] = {57, 12, 89, 23, 45, 67, 5, 91, 34, 76};
    int n = 10;
    insertionsort(A, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}