#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *first = NULL;

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
int count(node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
// function to delete an element from linked list
void delete(node *p, int index)
{
    if (index < 1 || index > count(first)) // checking for the validity of the index
    {
        printf("invalid index \n");
        return;
    }
    else
    {
        node *q = NULL;
        if (index == 1) // if u have to delete the first node
        {
            p = first;
            first = first->next;
            free(p);
        }
        else
        {
            for (int i = 0; i < index - 1; i++) // done with the help of a tailing pointer
            {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            free(p);
        }
    }
}
int main(void)
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    display(first);
    delete(first, 0);
    delete(first, 6);
    delete(first, 2);
    display(first);
}
