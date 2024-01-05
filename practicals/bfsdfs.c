#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

int queue[MAX];
int stack[MAX];
int top = -1;
int front = -1;
int rear = -1;
int adjacencyMatrix[MAX][MAX];
int visited[MAX] = {0, 0, 0, 0, 0};

// void dfs(int startNode)
// {
//     push(startNode);
//     visited[startNode] = 1;
//     printf("%d ", startNode);

//     while (!isStackEmpty())
//     {
//         int currentNode = stack[top];
//         int found = 0;

//         for (int i = 1; i <= MAX; ++i)
//         {
//             if (adjacencyMatrix[currentNode][i] == 1 && visited[i] == 0)
//             {
//                 push(i);
//                 visited[i] = 1;
//                 printf("%d ", i);
//                 found = 1;
//                 break;
//             }
//         }

//         if (!found)
//         {
//             pop();
//         }
//     }
// }

void push(int element)
{
    if (top == MAX - 1)
    {
        printf("Overflow");
    }
    else
    {
        top++;
        stack[top] = element;
    }
}
int pop()
{
    int element = 0;
    if (top == -1)
    {
        printf("underflow");
        return -1;
    }
    else
    {
        element = stack[top];
        top--;
        return element;
    }
}
bool isStackEmpty()
{
    return top == -1;
}
void enqueue(int element)
{
    if (rear == MAX - 1)
    {
        printf("Queue Full");
    }
    else if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        queue[rear] = element;
    }
    else
    {
        rear++;
        queue[rear] = element;
    }
}
int dequeue()
{
    int ele = 0;
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else if (front == rear)
    {
        ele = queue[front];
        front = rear = -1;
    }
    else
    {
        ele = queue[front];
        front++;
    }
    return ele;
}
bool isEmpty()
{
    return (front == -1 && rear == -1);
}

// void bfs(int startNode)
// {
//     printf("%d", startNode);
//     visited[startNode] = 1;
//     enqueue(startNode);
//     while (!isEmpty())
//     {
//         int currentNode = dequeue();
//         for (int i = 1; i <= MAX; i++)
//         {
//             if (adjacencyMatrix[currentNode][i] == 1 && visited[i] == 0)
//             {
//                 printf("%d", i);
//                 visited[i] = 1;
//                 enqueue(i);
//             }
//         }
//     }
// }
void bfs(int startNode)
{

    printf("%d", startNode);
    visited[startNode] = 1;
    enqueue(startNode);
    while (!isEmpty())
    {
        int node = dequeue();
        for (int j = 1; j <= 5; j++)
        {
            if (adjacencyMatrix[node][j] == 1 && visited[j] == 0)
            {
                printf("%d", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}
void dfs(int startNode)
{
    for (int i = 0; i < MAX; i++)
    {
        visited[i] = 0;
    }

    printf("%d", startNode);
    push(startNode);
    visited[startNode] = 1;
    while (!isStackEmpty())
    {
        int found = 0;
        int node = stack[top];
        for (int j = 0; j <= 5; ++j)
        {
            if (adjacencyMatrix[node][j] == 1 && visited[j] == 0)
            {
                printf("%d", j);
                push(j);
                found = 1;
                visited[j] = 1;
                return;
            }
        }
        if (!found)
        {
            pop();
        }
    }
}
int main()
{
    int vertices = 0;
    printf("Enter the no of vertices: ");
    scanf("%d", &vertices);

    for (int i = 1; i <= vertices; i++)
    {
        for (int j = 1; j <= vertices; j++)
        {
            printf("Enter 1 if %d has a node with %d else 0: ", i, j);
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }
    printf("The Adjacency Matrix is: \n");
    for (int m = 1; m <= vertices; m++)
    {
        for (int n = 1; n <= vertices; n++)
        {
            printf(" %d", adjacencyMatrix[m][n]);
        }
        printf("\n");
    }
    int startNode = 0;
    printf("Enter the start node: ");
    scanf("%d", &startNode);
    // for (int k = 1; k <= vertices; k++)
    // {
    //     visited[k] = 0;
    // }

    // bfs(startNode);
    printf("\n\n\n");
    dfs(startNode);
    return 0;
}