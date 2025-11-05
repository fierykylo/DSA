#pragma once
#include <stdio.h>
#include <stdlib.h>

// this is the node that stores the tree
typedef struct node
{
    struct node *rightchild;
    int data;
    struct node *leftchild;   // FIXED: typo "leftchidl" → "leftchild"
} node;

typedef struct queue
{
    int size;
    int front;
    int rear;
    node **Q;
} queue;

void create(queue *q, int size)
{
    q->size = size;
    q->Q = (node **) malloc(q->size * sizeof(node *));
    if (q->Q == NULL)
    {
        printf("memory allocation failed\n");
        return;
    }
    q->front = q->rear = 0;
}

void enqueue(queue *q, node *x)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = x;
}

node *dequeue(queue *q)
{
    node *x = NULL;
    if (q->front == q->rear)
    {
        printf("queue is empty\n");
        return NULL;   // FIXED: function promised pointer
    }

    q->front = (q->front + 1) % q->size;
    x = q->Q[q->front]; // FIXED: actually return dequeued element

    return x;
}

int isEmpty(queue q)
{
    return (q.front == q.rear);
}
