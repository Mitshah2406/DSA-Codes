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
    int choice, item;

    do
    {
        printf("\nDeque Menu\n");
        printf("1. Input-Restricted Deque\n");
        printf("2. Output-Restricted Deque\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Input-Restricted Deque Operations:\n");
            do
            {
                printf("1. Insert at Rear\n");
                printf("2. Delete from Front\n");
                printf("3. Display\n");
                printf("4. Exit Input-Restricted Deque\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    printf("Enter element to insert at rear: ");
                    scanf("%d", &item);
                    insertRear(item);
                    break;
                case 2:
                    deleteFront();
                    break;
                case 3:
                    display();
                    break;
                case 4:
                    printf("Exiting Input-Restricted Deque menu.\n");
                    break;
                default:
                    printf("Invalid choice! Please enter a valid menu option.\n");
                    break;
                }
            } while (choice != 4);
            break;

        case 2:
            printf("Output-Restricted Deque Operations:\n");
            do
            {
                printf("1. Insert at Front\n");
                printf("2. Delete from Rear\n");
                printf("3. Display\n");
                printf("4. Exit Output-Restricted Deque\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    printf("Enter element to insert at front: ");
                    scanf("%d", &item);
                    insertFront(item);
                    break;
                case 2:
                    deleteRear();
                    break;
                case 3:
                    display();
                    break;
                case 4:
                    printf("Exiting Output-Restricted Deque menu.\n");
                    break;
                default:
                    printf("Invalid choice! Please enter a valid menu option.\n");
                    break;
                }
            } while (choice != 4);
            break;

        case 3:
            printf("Exiting the program. Goodbye!\n");
            break;

        default:
            printf("Invalid choice! Please enter a valid menu option.\n");
            break;
        }
    } while (choice != 3);

    return 0;
}