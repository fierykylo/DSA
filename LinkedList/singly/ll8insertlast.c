#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int data;
    struct node * next;
} node;

node * first = NULL;
node * last = NULL; // global variable last to take care of everything

void insertlast(node *p , int value)
{
    // consider if the linked list is empty
    node  * t;
    t = (node *) malloc(sizeof(node));
    t->data = value;
    t->next = NULL;
    // checking if the linked list is empty 
    if (first == NULL)
    {
       first = last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}

void display(node *p);
int main(void)
{
    insertlast(first,10);
    display(first);
    insertlast(first,30);
    display(first);

}
//function to display a node
void display(node *p)
{
    while(p != NULL)
    {
        printf("[%d]->",p->data);
        p = p->next;
    }
    printf("\n");
    
}
