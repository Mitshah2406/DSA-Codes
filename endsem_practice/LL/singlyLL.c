#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
} *head;
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
    }
}
int main()
{
    return 0;
}