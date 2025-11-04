#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
} queue;

void create(queue *q, int size)
{
    q->size = size; // step 1 size of the queue
    q->Q = (int *) malloc(q->size * sizeof(int));
    if (q->Q == NULL)
    {
        printf("memory allocation failed\n");
        return;
    }
    q->front = q->rear = 0;
}

void enqueue(queue *q, int x)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("queue is full\n");
        return;
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

void dequeue(queue * q)
{
    if (q->front == q->rear)
    {
        printf("queue is empty\n");
        return;
    }
    else
    {
        q->front = (q->front + 1) % q->size;
    }  
}

void display(queue *q)
{
    int i = (q->front + 1) % q->size;

    while (i != (q->rear + 1) % q->size)
    {
        printf("%d ", q->Q[i]);
        i = (i + 1) % q->size;
    }
    printf("\n");
}

int main(void)
{
    queue q;
    create(&q, 5); // capacity 5 (effective usable slots = 4 for circular queue)

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    enqueue(&q, 50);
    enqueue(&q, 60); // circular wrap should kick in

    display(&q);
}
