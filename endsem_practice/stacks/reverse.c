#include <stdio.h>
#include <stdlib.h>
#define MAX 100
char stack[MAX];
int top = -1;

void push(char element)
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
int pop()
{
    if (top == -1)
    {
        printf("Stack Empty");
    }
    else
    {
        // printf("Popped element %d", stack[top]);
        int e = stack[top];
        top--;
        return e;
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
void reverseD()
{
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        push(arr[i]);
    }
    for (int m = 0; m < 5; m++)
    {
        printf("%d ", arr[m]);
    }
    printf("\n");
    for (int k = 0; k < 5; k++)
    {
        arr[k] = pop();
    }
    for (int m = 0; m < 5; m++)
    {
        printf("%d ", arr[m]);
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
    printf("6. Reverse\n");
    printf("7. Exit\n");
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
            reverseD();
            break;
        case 7:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (choice != 7);

    return 0;
}