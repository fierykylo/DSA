#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int data;
    struct node * next;
} node;
node * first = NULL;

// function to create a node
void create(int A[], int n)
{
    node *t , *last;
    first = (node *) malloc(sizeof(struct node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(int i = 1; i < n; i++)
    {
        t = (node *) malloc(sizeof(node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int main(void)
{

}