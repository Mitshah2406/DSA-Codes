#include <stdio.h>
#include <stdbool.h>
#define N 100
char stack[N];
int top = -1;
void push(int e)
{
    if (top == N - 1)
    {
        printf("Full\n");
        return;
    }
    top++;
    stack[top] = e;
}
char pop()
{
    if (top == -1)
    {
        printf("empty\n");
        return '\0';
    }
    return stack[top--];
}
void display()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d\n", stack[i]);
    }
}
bool isEmpty()
{
    return top == -1;
}
bool isBalanced(char str[])
{
    char current;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            push(str[i]);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (isEmpty())
            {
                return false;
            }
            else
            {
                current = pop();
                if (str[i] == ')' && current != '(' || str[i] == ']' && current != '[' || str[i] == '{' && current != '{')
                {
                    return false;
                }
            }
        }
    }
    return isEmpty();
}
int main()
{
    char str[N] = "{[)]}";
    if (isBalanced(str))
    {
        printf("Balance");
    }
    else
    {

        printf("Unbalance");
    }
}