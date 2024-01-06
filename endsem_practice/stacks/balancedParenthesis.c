#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
char stack[MAX];
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
char pop()
{
    if (top == -1)
    {
        printf("Stack Empty");
    }
    else
    {
        char el = stack[top];
        top--;
        return el;
    }
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
int check(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            push(str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (isEmpty())
            {
                return 0;
            }
            else
            {
                char current = pop();
                if ((str[i] == ')' && current != '(') ||
                    (str[i] == ']' && current != '[') ||
                    (str[i] == '}' && current != '{'))
                {
                    return 0;
                }
            }
        }
    }
    return isEmpty();
}

int main()
{
    char *str = "{[{()}]}";
    if (check(str))
    {
        printf("\nTrue");
    }
    else
    {

        printf("\nFalse");
    }
    return 0;
}