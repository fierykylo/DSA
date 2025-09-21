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
    for (int i = 1; i < n; i++)
    {
        t = (node *) malloc(sizeof(node));
        t->data = A[i];
        t->next = head;
        last->next = t;
        last = t;
    }
}

void rdisplay(node *p)
{
    static int flag = 0; // a static variable is only initialised once
    if (p != head || flag == 0)
    {
        flag = 1;
        printf("%d ", p->data);
        rdisplay(p->next);
    }
    flag = 0;
    
}
int main(void)
{
    int A[] = {2,3,4,5,6};
    create(A,5);
    rdisplay(head);
}