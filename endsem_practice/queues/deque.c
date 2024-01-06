#include <stdio.h>
#include <stdlib.h>

#define N 5
int deque[N];
int front = -1, rear = -1;

void insertRear(int ele)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else if ((front == 0 && rear == N - 1) || (front == rear + 1))
    {
        printf("\n Full\n");
        return;
    }
    else if (rear == N - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    deque[rear] = ele;
}
void deleteFront()
{
    if (front == -1 && rear == -1)
    {
        printf("\n Queue Empty\n");
    }
    else if (front == rear)
    {
        printf("\nDequeued %d", deque[front]);
        front = rear = -1;
    }
    else if (front == N - 1)
    {
        printf("\nDequeued %d", deque[front]);
        front = 0;
    }
    else
    {
        printf("\nDequeued %d", deque[front]);
        front++;
    }
}
void insertFront(int ele)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else if ((front == 0 && rear == N - 1) || (front == rear + 1))
    {
        printf("\nQueue Full\n");
        return;
    }
    else if (front == 0)
    {
        front = N - 1;
    }
    else
    {
        front--;
    }
    deque[front] = ele;
}
void deleteRear()
{
    if (front == -1 && rear == -1)
    {
        printf("\n Queue Empty\n");
    }
    else if (front == rear)
    {
        printf("\nDequeued %d", deque[rear]);
        front = rear = -1;
    }
    else if (rear == 0)
    {
        printf("\nDequeued %d", deque[rear]);
        rear == N - 1;
    }
    else
    {
        printf("\nDequeued %d", deque[rear]);
        rear--;
    }
}
void display()
{
    if (front == -1 && rear == -1)
    {
        printf("\n Queue Empty\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", deque[i]);
        }
    }
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
            printf("1. Insert at Rear\n");
            printf("2. Delete from Front\n");
            printf("3. Delete from Rear\n");
            printf("4. Display\n");
            printf("5. Exit Input-Restricted Deque\n");

            do
            {
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
                    deleteRear();
                    break;
                case 4:
                    display();
                    break;
                case 5:
                    printf("Exiting Input-Restricted Deque menu.\n");
                    break;
                default:
                    printf("Invalid choice! Please enter a valid menu option.\n");
                    break;
                }
            } while (choice != 5);
            break;

        case 2:
            printf("Output-Restricted Deque Operations:\n");
            printf("1. Insert at Front\n");
            printf("2. Insert at Rear\n");
            printf("3. Delete from Front\n");
            printf("4. Display\n");
            printf("5. Exit Output-Restricted Deque\n");

            do
            {
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
                    printf("Enter element to insert at rear: ");
                    scanf("%d", &item);
                    insertRear(item);
                    break;
                case 3:
                    deleteFront();
                    break;
                case 4:
                    display();
                    break;
                case 5:
                    printf("Exiting Output-Restricted Deque menu.\n");
                    break;
                default:
                    printf("Invalid choice! Please enter a valid menu option.\n");
                    break;
                }
            } while (choice != 5);
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