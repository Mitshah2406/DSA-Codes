#include <stdio.h>
#include <stdlib.h>

typedef struct Data
{
    int data;
    int priority;
} Element;

#define N 5
Element queue[N];

int front = -1, rear = -1;

void enqueue(int data, int priority)
{
    Element ele;
    ele.data = data;
    ele.priority = priority;

    if (rear == N - 1)
    {
        printf("\nQueue is full\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = ele;
    }
    else
    {
        int i;
        for (i = rear; i >= front; i--)
        {
            if (ele.priority > queue[i].priority)
            {
                queue[i + 1] = queue[i];
            }
            else
            {
                break;
            }
        }
        queue[i + 1] = ele;
        rear++;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty\n");
    }
    else if (front == rear)
    {
        printf("Dequeued element %d with priority %d\n", queue[front].data, queue[front].priority);
        front = rear = -1;
    }
    else
    {
        printf("Dequeued element %d with priority %d\n", queue[front].data, queue[front].priority);
        front++;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nElement\t Priority\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t\t%d\n", queue[i].data, queue[i].priority);
        }
    }
}

int peek()
{
    if (front == -1 && rear == -1)
    {
        return -1;
    }
    return front;
}

int main()
{
    int choice, data, priority;

    do
    {
        printf("\nPriority Queue Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element and its priority: ");
            scanf("%d %d", &data, &priority);
            enqueue(data, priority);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            if (peek() == -1)
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Front element index: %d\n", peek());
            }
            break;
        case 5:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid menu option.\n");
            break;
        }
    } while (choice != 5);

    return 0;
}
