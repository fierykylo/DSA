#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
} queue;

void create(queue *a, int n)
{
    a->size = n;
    a->Q = (int *) malloc(n * sizeof(int));
    if(a->Q == NULL)
    {
        printf("memory allocation failed");
        return;
    }
    a->front = a->rear = -1;
}
void display(queue q)
{
    for(int i = q.front + 1; i <= q.rear; i++)
    {
        printf("%d ",q.Q[i]);
    }
    printf("\n");
}
int main(void)
{

}
