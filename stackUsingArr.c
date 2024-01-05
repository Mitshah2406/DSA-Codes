#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int stack[MAX];
int top = -1;
void push(int element)
{
    if (top == MAX - 1)
    {
        printf("Stack is full\n\n");
        return;
    }
    else
    {
        top++;
        stack[top] = element;
        printf("Element Inserted\n");
    }
}

void pop()
{
    if (top == -1)
    {
        printf("The stack is empty..\n");
    }
    else
    {
        printf("Popped element %d\n", stack[top]);
        top--;
    }
}
void display()
{
    if (top == -1)
    {
        printf("The stack is empty");
    }
    else
    {
        printf("The stack elements are as follows: \n\n\n");
        for (int i = 0; i <= top; i++)
        {
            printf("%d\n", stack[i]);
        }
    }
}
int main()
{

    int choice;
    while (choice != 4)
    {
        printf("\n\nStack Menu: \n");
        printf("1.Push\n");
        printf("2.Pop\n");
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
            push(element);
            break;
        case 2:
            pop();
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