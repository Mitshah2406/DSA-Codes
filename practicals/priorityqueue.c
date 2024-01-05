

#include <stdio.h>
#define MAX 100

typedef struct Data
{
    int element;
    int priority;
} Node;
Node queue[MAX];

int front = -1;
int rear = -1;

void enqueue(int data, int priority)
{
    Node d = {data, priority};
    if (rear == MAX - 1)
    {
        printf("Overflow\n");
    }
    else if (rear == -1 && front == -1)
    {
        front = rear = 0;
        queue[rear] = d;
    }
    else
    {
        int i;
        for (i = rear; i >= front; i--)
        {
            if (d.priority > queue[i].priority)
            {
                queue[i + 1] = queue[i];
            }
            else
            {
                break;
            }
        }
        queue[i + 1] = d;
        rear++;
    }
}
void dequeue()
{
    if (front == -1)
    {
        printf("Underflow\n");
    }
    else if (front == rear)
    {
        Node d = queue[front];
        front = rear = -1;
        printf("%d with priority %d dequeued.. \n", d.element, d.priority);
    }
    else
    {
        Node d = queue[front];
        front++;
        printf("%d with priority %d dequeued.. \n", d.element, d.priority);
    }
}
void display()
{
    if (front == -1)
    {
        printf("Empty");
    }
    else
    {
        printf("Element \t Priority\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d \t\t %d", queue[i].element, queue[i].priority);
            printf("\n");
        }
    }
}
int main()
{
    enqueue(10, 2);
    enqueue(20, 1);
    enqueue(30, 3);

    display();
    dequeue();
    display();

    return 0;
}
