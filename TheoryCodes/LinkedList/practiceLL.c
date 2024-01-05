#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node *insertAtBegin(struct Node *head, int elem)
{
    struct Node *newNode = createNode(elem);
    newNode->next = head;
    head = newNode;
    return head;
}
void display(struct Node *head)
{
    printf("\n\n Elements: ");
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
struct Node *insertAtPosition(struct Node *head, int elem, int pos)
{
    if (pos < 1)
    {
        printf("Invalid");
    }

    struct Node *temp = head;
    struct Node *newNode = createNode(elem);
    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}
struct Node *insertAtEnd(struct Node *head, int elem)
{
    struct Node *temp = head;
    struct Node *newNode = createNode(elem);
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
int main()
{
    struct Node *head = NULL;
    head = insertAtBegin(head, 5);
    head = insertAtBegin(head, 25);
    head = insertAtBegin(head, 15);
    display(head);
    head = insertAtEnd(head, 115);
    display(head);
    head = insertAtPosition(head, 1434, 3);
    display(head);
}