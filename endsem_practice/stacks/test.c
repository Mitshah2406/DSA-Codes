#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void revExp(char *str)
{
    int length = strlen(str);
    int start = 0;
    int end = length - 1;
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void infixToPrefix(char *exp)
{
    int i = strlen(exp) - 1;
    int k = 0;
    char prefix[100];
    revExp(exp);
    // printf("exp is %s", strdup(exp));
    while (i >= 0)
    {
        if (isOperand(exp[i]))
        {
            prefix[k] = exp[i];
            k++;
        }
        else if (exp[i] == ')')
        {
            push(exp[i]);
        }
        else if (exp[i] == '(')
        {
            while (!isEmpty() && getTop() != ')')
            {
                prefix[k] = pop();
                k++;
            }
            if (getTop() == ')')
            {
                pop(); // Discard ')'
            }          // Discard ')'
        }
        else
        {
            while (!isEmpty() && precedence(exp[i]) < precedence(getTop()))
            {
                prefix[k] = pop();
                k++;
            }
            push(exp[i]);
        }
        i--;
    }

    while (!isEmpty())
    {
        prefix[k] = pop();
        k++;
    }

    prefix[k] = '\0';
    printf("Prefix is %s", strdup(prefix));
    revExp(prefix);
}

int main()
{
    char exp[] = "K+L-M*N+(O^P)*W/U/V*T+Q";

    infixToPrefix(exp);
    return 0;
}
