#include <stdio.h>
#include <stdlib.h>

// three basic functions of a stack using linked list in a single code
typedef struct node
{
    int data;
    struct node *next;
} node;

node *top = NULL;

void push(int value)
{
    node *t = (node *) malloc(sizeof(node));
    if (t == NULL)
    {
        printf("stack overflow\n");
        return;
    }
    else
    {
        t->data = value;
        t->next = top;
        top = t;
    }
}
void pop()
{
    if (top == NULL)
    {
        printf("stack underflow\n");
        return;
    }
    else
    {
        node *t = top;
        top = top->next;
        free(t);
    }
}

void display()
{
    node *p;
    p = top;
    while (p != NULL)
    {
        printf("%d \n", p->data);
        p = p->next;
    }
}

int main(void)
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display();
    pop();
    pop();
    display();
}
