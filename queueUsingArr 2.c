#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;
void enqueue(int element)
{
    if (rear == MAX - 1)
    {
        printf("Overlfow\n");
    }
    else if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        queue[rear] = element;
    }
    else
    {
        rear++;
        queue[rear] = element;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Underflow\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("Dequeued %d\n", queue[front]);
        front++;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue Empty\n");
        return;
    }
    printf("Queue Elements: \n");
    for (int i = front; i <= rear; i++)
    {
        printf("%d\n", queue[i]);
    }
}
int main()
{
    enqueue(5);
    enqueue(15);
    enqueue(25);
    display();
    dequeue();
    dequeue();
    display();
}