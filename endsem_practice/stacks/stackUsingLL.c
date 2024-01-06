#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(int element, struct Stack *stack)
{
    struct Node *newNode = createNode(element);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("\n%d pushed onto the stack", element);
}

int pop(struct Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("\nStack is empty");
        return -1;
    }
    else
    {
        struct Node *temp = stack->top;
        int data = temp->data;
        stack->top = stack->top->next;
        free(temp);
        return data;
    }
}

void display(struct Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("\nStack Empty");
    }
    else
    {
        struct Node *temp = stack->top;
        printf("\nStack elements: ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    struct Stack stack;
    stack.top = NULL;
    int choice, element;

    do
    {
        printf("\n\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &element);
            push(element, &stack);
            break;

        case 2:
            printf("Popped element: %d", pop(&stack));
            break;

        case 3:
            display(&stack);
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
