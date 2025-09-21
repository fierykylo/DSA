#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
} node;

node *head = NULL;

void create(int A[], int n)
{
    node *t, *last;
    head = (node *) malloc(sizeof(node));
    head->data = A[0];
    head->next = head;
    last = head;
    for(int i = 1; i < n; i++)
    {
        t = (node *) malloc(sizeof(node));
        t->data = A[i];
        t->next = head;
        last->next = t;
        last = t;
    }
}
void display(node *p)
{
    do
    {
        printf("%d ",p->data);
        p = p->next;
    } while(p != head);
    printf("\n"); 
}
int main(void)
{
    int A[] = {2,3,4,5,6};
    create(A,5);
    display(head);
}