#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
} node;
node *first = NULL;

// creates a node for array of elements
void create(int A[], int n)
{
    node * t , *last;
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
// void display
// basically traversing through the linked list
void display(node *p)
{
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main(void)
{
    int A[] = {10, 20, 30, 40, 50};
    create(A,5);

    display(first);

}