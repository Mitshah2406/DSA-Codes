
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

char *infixToPostfix(char *exp)
{
    int i = 0;
    int k = 0;
    char *postfix = (char *)malloc((strlen(exp) + 1) * sizeof(char));

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
    return postfix;
}
int isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
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
    char exp[] = "K+L-M*N+(O^P)*W/U/V*T+Q";

    char *postfix = infixToPostfix(exp);
    printf("\npe eval is %d", evaluatePostfix(postfix));
    return 0;
}
