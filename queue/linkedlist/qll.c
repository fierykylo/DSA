#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node * front = NULL;
node * rear = NULL;

void enqueue(int x)
{
    // check if there is enough space , since this is a linked list it will
    // only run out of spce when no space in heap

    node *t;
    t = (node *) malloc(sizeof(node));
    if (t == NULL)
    {
        printf("queue is full\n");
        return;
    }
    else
    {
        t->data = x;
        t->next = NULL;
        // if the queue is empty
        if (front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

void dequeue()
{
    // check if empty
    if (front == NULL)
    {
        printf("the queue is empty\n");
        return;
    }
    else
    {
        node *t = front;
        front = front->next;
        free(t);
    }
    // if the element being deleted is the last element this helps
    if (front == NULL)
    { 
        rear = NULL;
    }
}

void display()
{
    node *t = front;
    while (t != NULL)
    {
        printf("%d ",t->data);
        t = t->next;
    }
    printf("\n");
}

int main(void)
{
    node que;
    for (int i = 0; i < 10; i++)
    {
        int x = (i + 1) * 10;
        enqueue(x);
    }
    display();
    for (int i = 0; i < 5; i++)
    {
        dequeue();
    }
    display();

}