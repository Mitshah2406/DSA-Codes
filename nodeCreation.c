// #include <stdio.h>
// #include <stdlib.h>
// struct Node
// {
//     int data;
//     struct Node *next;
// };

// int main()
// {
//     struct Node *head = NULL, *newnode, *temp;
//     int choice;
//     while (choice)
//     {

//         newnode = (struct Node *)malloc(sizeof(struct Node));
//         printf("Enter the data: ");
//         scanf("%d", &newnode->data);
//         newnode->next = NULL;
//         if (head == NULL)
//         {
//             head = temp = newnode;
//         }
//         else
//         {
//             temp->next = newnode;
//             temp = newnode;
//         }
//         printf("Do u wanna continue insertions? (0/1): ");
//         scanf("%d", &choice);
//     }
//     temp = head;
//     while (temp != NULL)
//     {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     // int elementBeg;
//     // printf("Enter The element you want to insert at beginnning: ");
//     // scanf("%d", &elementBeg);

//     // newnode = (struct Node *)malloc(sizeof(struct Node));
//     // newnode->data = elementBeg;
//     // newnode->next = head;
//     // head = newnode;

//     // temp = head;
//     // while (temp != NULL)
//     // {
//     //     printf("%d ", temp->data);
//     //     temp = temp->next;
//     // }

//     // int elementEnd;
//     // printf("Enter The element you want to insert at ending: ");
//     // scanf("%d", &elementEnd);

//     // newnode = (struct Node *)malloc(sizeof(struct Node));
//     // newnode->data = elementEnd;
//     // newnode->next = NULL;

//     // temp = head;
//     // while (temp->next != NULL)
//     // {
//     //     temp = temp->next;
//     // }
//     // temp->next = newnode;
//     // temp = head;
//     // while (temp != NULL)
//     // {
//     //     printf("%d ", temp->data);
//     //     temp = temp->next;
//     // }
//     int elementMiddle, pos, counter = 0;
//     printf("Enter The element you want to insert at middle: ");
//     scanf("%d", &elementMiddle);
//     printf("Enter the position in which you want to insert: ");
//     scanf("%d", &pos);

//     newnode = (struct Node *)malloc(sizeof(struct Node));
//     newnode->data = elementMiddle;
//     newnode->next = NULL;

//     temp = head;
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     }
//     temp->next = newnode;
//     temp = head;
//     while (temp != NULL)
//     {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the beginning of the linked list
struct Node *insertAtBeginning(struct Node *head, int elementBeg)
{
    struct Node *newNode = createNode(elementBeg);
    newNode->next = head;
    return newNode;
}

// Function to insert at the end of the linked list
struct Node *insertAtEnd(struct Node *head, int elementEnd)
{
    struct Node *newNode = createNode(elementEnd);
    if (head == NULL)
    {
        return newNode;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to insert at a specified position in the linked list
struct Node *insertAtPosition(struct Node *head, int elementMiddle, int pos)
{
    if (pos < 1)
    {
        printf("Invalid position\n");
        return head;
    }

    struct Node *newNode = createNode(elementMiddle);
    if (pos == 1)
    {
        newNode->next = head;
        return newNode;
    }

    struct Node *temp = head;
    int count = 1;
    while (temp != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        printf("Position out of range\n");
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Function to display the linked list
void displayList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
// Function to delete at the beginning of the linked list
struct Node *deleteAtBeginning(struct Node *head)
{
    struct Node *temp;
    temp = head;
    head = head->next;
    free(temp);
    return head;
}
// Function to delete from the end of the linked list
struct Node *deleteAtEnd(struct Node *head)
{
    struct Node *temp, *prevNode;
    temp = head;
    while (temp->next != NULL)
    {
        prevNode = temp;
        temp = temp->next;
    }
    prevNode->next = NULL;
    free(temp);
    return head;
}
// Function to delete from any position
struct Node *deleteFromPos(struct Node *head, int pos)
{
    printf("exec");
    struct Node *temp, *nextnode;
    int count = 0;
    temp = head;
    // printf("here");
    // while (temp != NULL)
    // {
    //     count++;
    //     temp = temp->next;
    // }
    // printf("count");
    // if (pos <= 0 || pos >= count)
    // {
    //     printf("Invaliud");
    //     return head;
    // }
    // if (pos <= count)
    // {
    int i = 1;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
    // }

    return head;
}
int main()
{
    struct Node *head = NULL;
    int choice = 1;

    while (choice)
    {
        int data;
        printf("Enter the data: ");
        scanf("%d", &data);
        head = insertAtEnd(head, data);

        printf("Do you want to continue insertions? (0/1): ");
        scanf("%d", &choice);
    }

    printf("Current linked list: ");
    displayList(head);

    // Example usage of insert functions
    int elementBeg, elementEnd, elementMiddle, pos;

    // printf("Enter the element you want to insert at beginning: ");
    // scanf("%d", &elementBeg);
    // head = insertAtBeginning(head, elementBeg);
    // printf("Updated linked list after inserting at the beginning: ");
    // displayList(head);

    // printf("Enter the element you want to insert at ending: ");
    // scanf("%d", &elementEnd);
    // head = insertAtEnd(head, elementEnd);
    // printf("Updated linked list after inserting at the end: ");
    // displayList(head);

    // printf("Enter the element you want to insert at middle: ");
    // scanf("%d", &elementMiddle);
    // printf("Enter the position in which you want to insert: ");
    // scanf("%d", &pos);
    // head = insertAtPosition(head, elementMiddle, pos);
    // printf("Updated linked list after inserting at a specified position: ");
    // displayList(head);
    // head = deleteAtBeginning(head);
    // printf("Element is deleted from beginning..\n");
    // displayList(head);
    // head = deleteAtEnd(head);
    // printf("Element is deleted from ending..\n");
    // displayList(head);
    printf("Enter the element's positon to be deleted (starts from 1): ");
    scanf("%d", &pos);
    head = deleteFromPos(head, pos);
    displayList(head);
    return 0;
}
