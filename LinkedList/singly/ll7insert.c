#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
} node;

node *first = NULL;

int count(node * p);
void create(int A[], int n);
void insert(node *p , int index , int value);
void display(node *p);

int main(void)
{
    int A[] = {10, 20, 30, 40, 50};
    create(A,5);

    display(first);
    insert(first,0,6);
    display(first);
    insert(first,6,9);
    display(first);

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
void display(node *p)
{
    while(p != NULL)
    {
        printf("[%d]->",p->data);
        p = p->next;
    }
    printf("\n");
    
}
void insert(node *p , int index , int value)
{
    if(index < 0 || index > count(first))
    {
        printf("invalid index\n");
        return;
    }
    else
    {
        node *t;
        t = (node *) malloc(sizeof(node));
        t->data = value;
        t->next = NULL;
        if (index == 0)
        {
            t->next = first;
            first = t;
        }
        else
        {
            node *p;
            p = first;
            for(int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            t->next = p->next;
            p->next = t;
        }
    }
}
int count(node * p)
{
    int count = 0;
    while(p)
    {
        count ++;
        p = p->next;
    }
    return count;
}