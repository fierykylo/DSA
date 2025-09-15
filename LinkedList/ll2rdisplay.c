#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
} node;

node * first = NULL;

void create(int A[] , int n)
{
    node * t, *last;
    first = (node *) malloc(sizeof(node));
    first ->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 0; i < n; i++)
    {
        
    }
}
