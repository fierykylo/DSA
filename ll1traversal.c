#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
} node ;
node * first = NULL;

// code for creating a node 

void createNode(int A[],int n)
{
    int i;
    node * t , *last;
    first = (node * ) malloc(sizeof(node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(i = 1; i < n; i++)
    {
        t = (node *) malloc(sizeof(node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
 // function to display an array through the help of traversal
void display(node * p)
{
    while(p != NULL)
    {
        printf("%d " , p->data);
        p = p->next;
    }
    printf("\n");
}

int main(void)
{
    int A[] = {3,4,5,6,7,8,9,12};
    createNode(A,8);
    display(first);
}