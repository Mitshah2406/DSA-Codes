#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int element)
{
    if (rear == MAX - 1)
    {
        printf("\nFull");
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
        printf("\nempty");
    }
    else if (front == rear)
    {
        int e = queue[front];
        front == -1;
        rear == -1;
        printf("dequeued %d", e);
    }
    else
    {
        int e = queue[front];
        front++;
        printf("dequeued %d", e);
    }
}
void display()
{
    if (front == -1 && rear == -1)
    {
        printf("\nempty");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}
int main()
{
    int choice;
    while (choice != 4)
    {
        printf("\n\nQueue Menu: \n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("\n\nEnter the operation you wanna perform:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter The element you want to insert: \n");
            int element;
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            choice = 4;
            break;

        default:
            printf("Invalid Choice..\n");
            break;
        }
    }
    return 0;
}