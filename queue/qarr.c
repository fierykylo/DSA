#include <stdio.h>
#include <stdlib.h>

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
    q->size = n;
    q->Q = (int *) malloc(q->size * sizeof(int));
    if(q->Q == NULL)
    {
        printf("memory allocation failed");
        return;
    }
    q->front = q->rear = -1;
}

// enqueue function
void enque(queue *q, int x)
{
    if (q->rear == q->size - 1)
    {
        printf("queue is full \n");
        return;
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}
// deuque function
void deque(queue *q)
{
    if (q->front == q->rear)
    {
        printf("queue is empty\n");
        return;
    }
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
    enque(&q, 10);
    enque(&q, 20);
    enque(&q, 30);
    display(q);
    deque(&q);
    display(q);
    deque(&q);
    display(q);
}