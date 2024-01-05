#include <stdio.h>
#define N 10
int deque[N];
int front = -1, rear = -1;

void insertFromFront(int element)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[front] = element;
    }
    else if ((front == 0 && rear == N - 1) || (front == rear + 1))
    {
        printf("QUEUE FULL");
    }
    else if (front == 0)
    {
        front = N - 1;
        deque[front] = element;
    }
    else
    {
        front--;
        deque[front] = element;
    }
}
void deleteFromFront()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue Empty");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == N - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}
void insertFromRear(int element)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[rear] = element;
    }
    else if ((front == 0 && rear == N - 1) || (front == rear + 1))
    {
        printf("QUEUE FULL");
    }
    else if (rear == N - 1)
    {
        rear = 0;
        deque[rear] = element;
    }
    else
    {
        rear++;
        deque[rear] = element;
    }
}
void deleteFromRear()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue Empty");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = N - 1;
    }
    else
    {
        rear--;
    }
}
void display()
{
    int i = front;
    while (i != rear)
    {
        printf("%d ", deque[i]);
        i = (i + 1) % N;
    }
    printf("%d\n", deque[rear]);
}
int main()
{
    int data, choice;
    while (choice != 6)
    {
        printf("\nDeque Menu:\n");
        printf("1. Insert front\n");
        printf("1. Insert rear\n");
        printf("3. Delete front\n");
        printf("4. Delete rear\n");
        printf("5. Delete rear\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the node data to insert: ");
            scanf("%d", &data);
            insertFromFront(data);
            display();
            printf("front = %d and rear = %d", front, rear);
            break;
        case 2:

            printf("Enter the node data to insert: ");
            scanf("%d", &data);
            insertFromRear(data);
            display();
            printf("front = %d and rear = %d", front, rear);
            break;
        case 3:
            deleteFromFront();
            display();
            printf("front = %d and rear = %d", front, rear);
            break;
        case 4:
            deleteFromRear();
            display();
            printf("front = %d and rear = %d", front, rear);
            break;
        case 5:
            display();
            break;
        case 6:
            choice == 6;
            break;
        default:
            break;
        }
    }
    return 0;
}