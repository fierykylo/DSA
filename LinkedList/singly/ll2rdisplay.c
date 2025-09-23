#include<stdio.h>
#include<stdlib.h>
// this is the display function using recursion can also use recursion to print linked list in reverse
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

    for (int i = 1; i < n; i++)
    {
        t = (node *) malloc(sizeof(node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void rdisplay(node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        rdisplay(p->next);
    }
}
void reverse(node *p)
{
    if(p != NULL)
    {
        reverse(p->next);
        printf("%d ", p->data);
    }
}
int main(void)
{
    int A[] = {10,20,30,40,50};
    create(A,5);
    reverse(first);
}