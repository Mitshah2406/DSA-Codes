#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} *head = NULL, *tail = NULL;

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void createLL(int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
void insertAtBeginning(int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = tail = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        printf("here");
        insertAtBeginning(data);
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
void deleteFromBeginning()
{
    if (head == NULL)
    {
        printf("1st");
        return;
    }
    else if (head == tail)
    {
        printf("2st");
        head = tail = NULL;
        free(head);
    }
    else
    {
        printf("3st");
        struct Node *temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}

void deleteFromEnd()
{
    if (head == NULL)
    {
        return;
    }
    else if (head == tail)
    {
        deleteFromBeginning();
    }
    else
    {
        struct Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    }
}
void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
int main()
{
    int n;
    printf("Enter the number of elements in linked list: ");
    scanf("%d", &n);
    while (n != 0)
    {
        int elem;
        printf("Enter the element you want to enter into linkedList: ");
        scanf("%d", &elem);
        createLL(elem);
        n--;
    }
    printf("Elements: \n");
    display(head);
    insertAtBeginning(5);
    insertAtBeginning(15);
    insertAtBeginning(25);
    insertAtBeginning(35);
    printf("Elements: \n");
    display(head);
    insertAtEnd(554);
    insertAtEnd(155);
    insertAtEnd(255);
    insertAtEnd(355);
    printf("Elements: \n");
    display(head);
    printf("till here");
    deleteFromBeginning();
    deleteFromBeginning();
    printf("Elements: \n");
    display(head);
    return 0;
}