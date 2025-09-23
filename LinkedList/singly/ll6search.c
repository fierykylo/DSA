#include <stdio.h>
#include <stdlib.h>

// improved version of linear search with the move to head technique

typedef struct node
{
    int data;
    struct node * next;
} node;

node * first = NULL;

void create(int A[],int n)
{
    node * t , * last;
    first = (node *) malloc(sizeof(node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(int i = 1; i < n; i++)
    {
        t = (node * ) malloc(sizeof(node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void linearsearch(node * p, int key)
{
    node * q;
    while(p)
    {
        if(key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            printf("Key found : %d\n",p->data);
        }
        q = p;
        p = p->next;
    }
}
int main(void)
{
    int A[] = {10,20,30,40,50};
    create(A,5);
    linearsearch(first,30);
}