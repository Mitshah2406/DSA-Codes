
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char ch)
{
    if (top >= MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = ch;
}

char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return '\0'; // Return null character for empty stack
    }
    return stack[top--];
}

int isEmpty()
{
    return top == -1;
}

char getTop()
{
    if (top == -1)
    {
        return '\0'; // Return null character for empty stack
    }
    return stack[top];
}

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

void infixToPostfix(char *exp)
{
    int i = 0;
    int k = 0;
    char postfix[MAX_SIZE];

    while (exp[i] != '\0')
    {
        if (isOperand(exp[i]))
        {
            postfix[k] = exp[i];
            k++;
        }
        else if (exp[i] == '(')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (!isEmpty() && getTop() != '(')
            {
                postfix[k] = pop();
                k++;
            }
            pop(); // Discard '('
        }
        else
        {
            while (!isEmpty() && precedence(exp[i]) <= precedence(getTop())) // incoming - already there
            {
                postfix[k] = pop();
                k++;
            }
            push(exp[i]);
        }
        i++;
    }

    while (!isEmpty())
    {
        postfix[k] = pop();
        k++;
    }

    postfix[k] = '\0';
    printf("Postfix expression: %s\n", postfix);
}

int main()
{
    char exp[] = "K+L-M*N+(O^P)*W/U/V*T+Q";

    infixToPostfix(exp);
    return 0;
}
