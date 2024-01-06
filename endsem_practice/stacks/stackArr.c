#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX];
int top = -1;

void push(int element)
{
    if (top == MAX - 1)
    {
        printf("\nStack Full");
    }
    else
    {
        top++;
        stack[top] = element;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("Stack Empty");
    }
    else
    {
        printf("Popped element %d", stack[top]);
        top--;
    }
}
int getTop()
{
    if (top == -1)
    {
        return -1;
    }
    return stack[top];
}
int isEmpty()
{
    return (top == -1) ? 1 : 0;
}
void display()
{
    if (top == -1)
    {
        printf("\nStack Empty");
    }
    else
    {
        printf("\nElements are : \n");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
    }
}
void displayMenu()
{
    printf("\n----- Stack Menu -----\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Get Top\n");
    printf("4. Check if Empty\n");
    printf("5. Display\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main()
{
    int choice, element;

    do
    {
        displayMenu();
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
            if (isEmpty())
            {
                printf("\nStack is Empty\n");
            }
            else
            {
                printf("Top element: %d\n", getTop());
            }
            break;

        case 4:
            if (isEmpty())
            {
                printf("\nStack is Empty\n");
            }
            else
            {
                printf("\nStack is not Empty\n");
            }
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}