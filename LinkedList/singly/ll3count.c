#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
} node;

node * first = NULL;

void create(int A[], int n)
{
    node * t , * last;
    first = (node *) malloc(sizeof(node));
    first-> data = A[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = (node *) malloc(sizeof(node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int count(node * p)
{
    int count = 0;
    while(p)
    {
        count ++;
        p = p->next;
    }
    return count;
}

int main(void)
{
    int A[] = {10,20,30,40,50};
    create(A,5);
    printf("Total elements are : %d", count(first));
}