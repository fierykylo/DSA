#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *first = NULL;

int issorted(node *p)
{
    int x = INT_MIN;
    while(p != NULL)
    {
        if(p->data < x)
        {
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
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
    int A[] = {10, 5, 30, 40, 50};
    create(A, 5);
    if(issorted(first))
    {
        printf("sorted");
    }
    else
    {
        printf("not sorted");
    }
}