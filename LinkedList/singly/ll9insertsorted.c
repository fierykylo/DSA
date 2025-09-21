#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
} node;

node * first = NULL;

void insertsorted(node *p,int value)
{
    
    node * t = (node *) malloc(sizeof(node));
    t->data = value;
    t->next = NULL;
    if(first == NULL)
    {
        first = t;
        return;
    }
    else
    {
        node * q = NULL;
        while(p && p->data < value)
        {
        q = p;
        p = p->next;
        }
        if(p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }

    }  
}

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
    printf("\n");
}

int main(void)
{
    int A[] = {10, 20, 30, 40, 50};
    create(A,5);
    display(first);
    insertsorted(first,8);
    insertsorted(first,32);
    insertsorted(first,69);
    insertsorted(first,40);
    display(first);

}