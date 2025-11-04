#include <bits/stdc++.h>
using namespace std;

class Queue
{
    private:
    int size;
    int front;
    int rear;
    int *Q;

    public:

    Queue()
    {
        front = rear = -1;
        this->size = 10;
        Q = new int[this->size];
    }

    Queue(int size)
    {
        front = rear = -1;
        Q = new int[size];
    }
    void enqueue(int x);
    void dequeue();
    void display();
};

void Queue :: enqueue(int x)
{
    // condition to check if the queue is full
    if (rear == size - 1)
    {
        cout << "queue is full \n";
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

void Queue :: dequeue()
{
    // checking if the queue is empty or not 
    if (front == rear)
    {
        cout << "queue is empty\n";
    }
    else
    {
        front++;
    }
}

void Queue :: display()
{
    for (int i = front + 1; i <= rear; i++)
    {
        cout << Q[i] << " ";
    }
    cout << "\n";
}

int main(void)
{
    Queue que(10);
    que.enqueue(1);
    que.enqueue(2);
    que.enqueue(3);
    que.enqueue(4);
    que.display();
    que.dequeue();
    que.dequeue();
    que.display();
}