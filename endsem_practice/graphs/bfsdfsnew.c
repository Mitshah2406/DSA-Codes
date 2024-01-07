#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 6 // Define the maximum size of the graph

// Stack implementation using array
int stack[MAX_SIZE];
int top = -1;

void push(int data)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = data;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int isStackEmpty()
{
    return top == -1;
}

// Queue implementation using array
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int data)
{
    if (rear == MAX_SIZE - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    queue[++rear] = data;
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    else
    {
        int val = queue[front++];
        if (front > rear)
        {
            front = rear = -1;
        }
        return val;
    }
}

int isQueueEmpty()
{
    return front == -1;
}

void dfs(int graph[MAX_SIZE][MAX_SIZE], int visited[MAX_SIZE], int start, int vertices)
{
    printf("DFS: ");
    push(start);
    visited[start] = 1;

    while (!isStackEmpty())
    {
        int current = pop();
        printf("%d ", current);

        for (int i = 0; i < vertices; ++i)
        {
            if (graph[current][i] == 1 && visited[i] == 0)
            {
                push(i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

void bfs(int graph[MAX_SIZE][MAX_SIZE], int visited[MAX_SIZE], int start, int vertices)
{
    printf("BFS: ");
    enqueue(start);
    visited[start] = 1;

    while (!isQueueEmpty())
    {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < vertices; ++i)
        {
            if (graph[current][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

int main()
{
    int vertices = 6; // Number of vertices in the graph

    int graph[MAX_SIZE][MAX_SIZE] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 1, 1},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0}};

    int visited[MAX_SIZE] = {0}; // Initialize visited array

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    dfs(graph, visited, startVertex, vertices);

    // Reset visited array
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        visited[i] = 0;
    }

    bfs(graph, visited, startVertex, vertices);

    return 0;
}
