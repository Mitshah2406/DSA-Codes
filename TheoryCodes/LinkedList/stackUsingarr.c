#include <stdio.h>
#define N 5
int stack[5];
int top = -1;
void push(int e)
{
    if (top == N - 1)
    {
        printf("Full\n");
        return;
    }
    top++;
    printf("Pushed %d\n", e);
    stack[top] = e;
}
void pop()
{
    if (top == -1)
    {
        printf("empty\n");
        return;
    }
    printf("Popped %d\n", stack[top]);
    top--;
}
void display()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d\n", stack[i]);
    }
}
int main()
{
    push(5);
    push(15);
    push(52);
    push(54);
    push(521);
    display();
    pop();
    pop();
    display();
}