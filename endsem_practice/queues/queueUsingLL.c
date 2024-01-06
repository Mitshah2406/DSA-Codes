#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}
void enqueue(int element)
{
    struct Node *newNode = createNode(element);
    if (front == NULL && rear == NULL)
    {
        rear = newNode;
        front = rear;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}
void dequeue()
{
    if (front == NULL && rear == NULL)
    {
        printf("\nunderflow");
    }
    else if (front == rear)
    {
        printf("\nDequeued %d ", front->data);
        front = NULL;
        rear = NULL;
    }
    else
    {
        printf("\nDequeued %d ", front->data);
        front = front->next;
    }
}
void display()
{
    if (front == NULL && rear == NULL)
    {
        printf("\nunderflow");
    }
    else
    {
        struct Node *temp = front;
        printf("\nElements\n");
        while (temp != rear->next)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
void main()
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
}