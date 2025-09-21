#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node * prev;
    int data;
    struct node * next;
} node;
node *first = NULL;

void create(int A[], int n)
{
    node *t , *last;
    first = (node *) malloc(sizeof(node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;
    for(int i = 1; i < n; i++)
    {
        t = (node *) malloc(sizeof(node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void display(node * p)
{
    while(p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
int main(void)
{
    int A[] = {10, 20, 30, 40, 50, 60, 69, 80, 90,100};
    create(A,10);
    display(first);
}