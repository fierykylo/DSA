#include <stdio.h>
#include <stdlib.h>

// this is the two pointer approach to implementing a queue using array 
// queue is a lifo data structure 
// struct of  a queue

typedef struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
} queue;

// function to create a queue
void create(queue *q, int n)
{
    q->size = n; // size of the queue
    q->Q = (int *) malloc(q->size * sizeof(int)); // allocating the space to store the data
    
    if(q->Q == NULL) // checks if the memory allocation was succesful or not
    {
        printf("memory allocation failed");
        return;
    }
    q->front = q->rear = -1;
}

// enqueue function
void enqueue(queue *q, int x)
{
    // condition to check if the queue is full
    if (q->rear == q->size - 1)
    {
        printf("queue is full \n");
        return;
    }
    // increment and enqueue the element
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}
// deuque function
void dequeue(queue *q)
{
    // check to see if the queue is  empty 
    if (q->front == q->rear)
    {
        printf("queue is empty\n");
        return;
    }
    // increase the front pointer to basically delete the element
    else
    {
        q->front++;
    }
}
// display function 
void display(queue q)
{
    for (int i = q.front + 1; i <= q.rear; i++) // crazy condition
    {
        printf("%d ", q.Q[i]);
    }
    printf("\n");

}
int main(void)
{
    queue q;
    create(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(q);
    dequeue(&q);
    display(q);
    dequeue(&q);
    display(q);
}
