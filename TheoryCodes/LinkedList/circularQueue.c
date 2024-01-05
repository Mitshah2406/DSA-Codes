#include <stdio.h>
#define N 5
int queue[N];
int front = -1, rear = -1;
void enqueue(int e)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = e;
        printf("Enqueued %d\n", queue[rear]);
    }
    else if ((rear + 1) % N == front)
    {
        printf("Overflow");
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = e;
        printf("Enqueued %d\n", queue[rear]);
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Underlfow");
    }
    else if (front == rear)
    {
        printf("Dequeued %d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Dequeued %d\n", queue[front]);
        front = (front + 1) % N;
    }
}
void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty");
        return;
    }
    printf("\nQueue elements: \n");
    while (i != rear)
    {
        printf("%d\n", queue[i]);
        i = (i + 1) % N;
    }
    printf("%d\n", queue[i]);
}
int main()
{
    enqueue(5);
    enqueue(10);
    enqueue(15);
    enqueue(20);
    enqueue(25);
    display();
    dequeue();
    dequeue();
    enqueue(200);
    enqueue(500);
    display();
    dequeue();
    display();

    return 0;
}
