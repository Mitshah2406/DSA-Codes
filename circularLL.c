#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *head, *tail, *temp;
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeg(int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        tail = head;
        newNode->next = tail;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        tail->next = newNode;
    }
    printf("Head: %d", head->data);
    printf("Tail: %d", tail->data);
};
void insertAtEnd(int data)
{
    struct Node *newNode = createNode(data);

    if (head == NULL && tail == NULL)
    {
        insertAtBeg(data);
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        newNode->next = head;
    }
    printf("Head: %d", head->data);
    printf("Tail: %d", tail->data);
}
void deleteAtBeg(int data)
{
}
void insertAfterPos(int data)
{
}
void deleteAtEnd(int data)
{
}
void deleteAfterPos(int data)
{
}
void display()
{
    struct Node *temp = head;
    do
    {
        printf("\n%d\n", temp->data);
        temp = temp->next;
    } while (temp != head);
}
int main()
{
    int choice, data, key;

    do
    {

        printf("\nLinked List Menu:\n");
        printf("1. Insert Node At beg\n");
        printf("2. Insert Node At end\n");
        printf("3. Insert Node After pos\n");
        printf("4. delete Node At beg\n");
        printf("5. del Node At end\n");
        printf("6. delete Node After pos\n");
        printf("7. Display List\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAtBeg(data);
            break;
        case 2:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 3:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAfterPos(data);
            break;

        case 7:
            display();
            break;

        case 4:
            printf("Enter data to delete: ");
            scanf("%d", &key);
            deleteAtBeg(key);
            break;
        case 5:
            printf("Enter data to delete: ");
            scanf("%d", &key);
            deleteAtEnd(key);
            break;
        case 6:
            printf("Enter data to delete: ");
            scanf("%d", &key);
            deleteAfterPos(key);
            break;

        case 8:
            printf("Program terminated.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}