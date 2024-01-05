#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
char stack[MAX];
int top = -1;

void push(char element)
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
    }
}

char pop()
{
    if (top == -1)
    {
        // printf("The stack is empty..\n");
        return '\0'; // Return null character or handle differently based on your application's requirements
    }
    else
    {
        char temp = stack[top];
        top--;
        return temp;
    }
}

char getTop()
{
    if (top == -1)
    {
        // printf("The stack is empty..\n");
        return '\0'; // Return null character or handle differently based on your application's requirements
    }
    else
    {
        return stack[top];
    }
}

int isEmpty()
{
    return top == -1;
}

void display()
{
    if (top == -1)
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The stack elements are as follows: \n");
        for (int i = 0; i <= top; i++)
        {
            printf("%c\n", stack[i]);
        }
    }
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    return 1;
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

char *infixToPostfix(char *infix)
{
    int i = 0;
    int j = 0;
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
            i++;
        }
        else if (infix[i] == ')')
        {
            while (getTop() != '(')
            {
                postfix[j] = pop();
                j++;
            }
            pop();
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(getTop()))
            {
                push(infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop();
                j++;
            }
        }
    }
    while (!isEmpty())
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0'; // Terminate the string properly
    return postfix;
}
int evaluatePostfix(char *postfix)
{

    int i = 0;
    int operand1, operand2, result;
    while (postfix[i] != '\0')
    {
        if (!isOperator(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            operand1 = pop() - '0';
            operand2 = pop() - '0';
            switch (postfix[i])
            {
            case '+':
                push((operand1 + operand2) + '0');
                break;
            case '-':
                push((operand1 - operand2) + '0');
                break;
            case '*':
                push((operand1 * operand2) + '0');
                break;
            case '/':
                push((operand1 / operand2) + '0');
                break;

            default:
                break;
            }
        }
        i++;
    }

    result = pop() - '0';
    return result;
}
int main()
{
    char *infix = "a+b/c";
    printf("Postfix is  %s", infixToPostfix(infix));
    printf("\nPostfix eval  is  %d", evaluatePostfix(infixToPostfix(infix)));
    return 0;
}
