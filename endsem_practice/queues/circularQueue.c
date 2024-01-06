#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int el)
{
    if ((rear + 1) % MAX == front)
    {
        printf("\nQueue full\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = el;
    }
    else
    {
        rear = (rear + 1) % MAX;
        queue[rear] = el;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("\nempty\n");
    }
    else if (front == rear)
    {
        printf("Dequeued %d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Dequeued %d\n", queue[front]);
        front = (front + 1) % MAX;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("\nempty\n");
    }
    else
    {
        printf("\nElements: ");
        int i = front;
        do
        {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        } while (i != (rear + 1) % MAX);
        printf("\n");
    }
}

int main()
{
    int choice, element;

    do
    {
        printf("\nCircular Queue Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to enqueue: ");
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
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid menu option.\n");
            break;
        }
    } while (choice != 4);

    return 0;
}
