#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *first = NULL;


void removeduplicate(node *p)
{
    node *q = p->next;
    while (q != NULL)
    {
        if (p->data == q->data)
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
        else
        {
            q = q->next;
            p = p->next;
        }

    }
}

void create(int A[], int n)
{
    node *t, *last;
    first = (node *) malloc(sizeof(node));
    first->data = A[0];
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
void display(node *p)
{
    while (p != NULL)
    {
        printf("[%d]->", p->data);
        p = p->next;
    }
    printf("\n");
}
int main(void)
{
    int A[] = {10, 10, 20, 20, 20, 30, 40, 50, 60};
    create(A,9);
    display(first);
    removeduplicate(first);
    display(first);
    
}

