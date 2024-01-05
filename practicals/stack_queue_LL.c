#include <stdio.h>
#include <stdlib.h>

// Structure for Node
struct Node
{
    int data;
    struct Node *next;
} *top = NULL, *front = NULL, *rear = NULL;

// Function to create a new Node
struct Node *createNode(int element)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(int element)
{
    struct Node *newNode = createNode(element);
    if (top == NULL)
    {
        top = newNode;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}

// Function to pop an element from the stack
void pop()
{
    if (top == NULL)
    {
        printf("Stack Empty\n");
    }
    else
    {
        top = top->next;
    }
}

// Function to enqueue an element into the queue
void enqueue(int element)
{
    struct Node *newNode = createNode(element);
    if (rear == NULL && front == NULL)
    {
        front = newNode;
        rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

// Function to dequeue an element from the queue
void dequeue()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
    }
}

// Function to display elements in the stack
void displayStack()
{
    struct Node *temp = top;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Function to display elements in the queue
void displayQueue()
{
    struct Node *temp = front;
    while (temp != rear->next)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Main function with menu-driven options
int main()
{
    int choice, element;
    do
    {
        printf("\nMenu\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Enqueue (Queue)\n");
        printf("4. Dequeue (Queue)\n");
        printf("5. Display Stack\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &element);
            push(element);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("Enter element to enqueue: ");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 4:
            dequeue();
            break;
        case 5:
            printf("Stack Elements:\n");
            displayStack();
            break;
        case 6:
            printf("Queue Elements:\n");
            displayQueue();
            break;
        case 7:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 7);

    return 0;
}
