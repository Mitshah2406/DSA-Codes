// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *next;
// };

// struct Node *createNode(int data)
// {
//     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

// void insertAtBeginning(struct Node **headRef, int data)
// {
//     struct Node *newNode = createNode(data);
//     newNode->next = *headRef;
//     *headRef = newNode;
// }

// void insertAtPosition(struct Node **headRef, int data, int position)
// {
//     if (position <= 0)
//     {
//         printf("Invalid position\n");
//         return;
//     }

//     if (position == 1)
//     {
//         insertAtBeginning(headRef, data);
//         return;
//     }

//     struct Node *newNode = createNode(data);
//     struct Node *current = *headRef;
//     int count = 1;

//     while (current != NULL && count < position - 1)
//     {
//         current = current->next;
//         count++;
//     }

//     if (current == NULL)
//     {
//         printf("Position out of range\n");
//         return;
//     }

//     newNode->next = current->next;
//     current->next = newNode;
// }

// void insertAtEnd(struct Node **headRef, int data)
// {
//     struct Node *newNode = createNode(data);
//     struct Node *current = *headRef;

//     if (*headRef == NULL)
//     {
//         *headRef = newNode;
//         return;
//     }

//     while (current->next != NULL)
//     {
//         current = current->next;
//     }

//     current->next = newNode;
// }

// void deleteAtPosition(struct Node **headRef, int position)
// {
//     if (*headRef == NULL)
//     {
//         printf("List is empty\n");
//         return;
//     }

//     struct Node *temp = *headRef;
//     struct Node *prev = NULL;

//     if (position == 1)
//     {
//         *headRef = temp->next;
//         free(temp);
//         return;
//     }

//     int count = 1;
//     while (temp != NULL && count != position)
//     {
//         prev = temp;
//         temp = temp->next;
//         count++;
//     }

//     if (temp == NULL)
//     {
//         printf("Position out of range\n");
//         return;
//     }

//     prev->next = temp->next;
//     free(temp);
// }

// void deleteLastNode(struct Node **headRef)
// {
//     if (*headRef == NULL)
//     {
//         printf("List is empty\n");
//         return;
//     }

//     struct Node *temp = *headRef;
//     struct Node *prev = NULL;

//     while (temp->next != NULL)
//     {
//         prev = temp;
//         temp = temp->next;
//     }

//     if (prev == NULL)
//     {
//         *headRef = NULL;
//     }
//     else
//     {
//         prev->next = NULL;
//     }

//     free(temp);
// }

// void displayList(struct Node *head)
// {
//     struct Node *temp = head;
//     while (temp != NULL)
//     {
//         printf("%d -> ", temp->data);
//         temp = temp->next;
//     }
//     printf("NULL\n");
// }

// void deleteList(struct Node **headRef)
// {
//     struct Node *current = *headRef;
//     struct Node *next;

//     while (current != NULL)
//     {
//         next = current->next;
//         free(current);
//         current = next;
//     }

//     *headRef = NULL;
// }

// int main()
// {
//     struct Node *head = NULL;

//     // Inserting elements into the linked list
//     insertAtBeginning(&head, 5);
//     insertAtBeginning(&head, 10);
//     insertAtBeginning(&head, 15);

//     // Displaying the linked list
//     printf("Linked list: ");
//     displayList(head);

//     // Inserting at a specified position and at the end
//     insertAtPosition(&head, 20, 2);
//     insertAtEnd(&head, 25);

//     printf("Linked list after insertion: ");
//     displayList(head);

//     // Deleting at a specified position and the last node
//     deleteAtPosition(&head, 3);
//     deleteLastNode(&head);

//     printf("Linked list after deletion: ");
//     displayList(head);

//     // Deleting the entire linked list
//     deleteList(&head);

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

    printf("Enter the element you want to insert at beginning: ");
    scanf("%d", &elementBeg);
    head = insertAtBeginning(head, elementBeg);
    printf("Updated linked list after inserting at the beginning: ");
    displayList(head);

    printf("Enter the element you want to insert at ending: ");
    scanf("%d", &elementEnd);
    head = insertAtEnd(head, elementEnd);
    printf("Updated linked list after inserting at the end: ");
    displayList(head);

    printf("Enter the element you want to insert at middle: ");
    scanf("%d", &elementMiddle);
    printf("Enter the position in which you want to insert: ");
    scanf("%d", &pos);
    head = insertAtPosition(head, elementMiddle, pos);
    printf("Updated linked list after inserting at a specified position: ");
    displayList(head);

    return 0;
}
