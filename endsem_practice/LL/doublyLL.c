#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct node *prev;
    struct node *next;
    int data;
};
struct Node *head;
// void insertion_beginning();
// void insertion_last();
// void insertion_specified();
// void deletion_beginning();
// void deletion_last();
// void deletion_specified();
// void display();
// void search();
// struct Node *createNode();
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertion_beginning()
{
    int data = 0;
    printf("\nEnter the data you want to insert?\n");
    scanf("%d", &data);
    struct Node *newNode = createNode(data);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("\n\nNode inserted\n");
}

void insertion_last()
{
    int data = 0;
    printf("\nEnter the data you want to insert?\n");
    scanf("%d", &data);
    struct Node *newNode = createNode(data);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}
void deletion_beginning()
{
    if (head == NULL)
    {
        printf("\nLL empty\n");
    }
    else
    {
        struct Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        temp->prev = NULL;
        free(temp);
    }
}
void deletion_last()
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("\nLL empty\n");
    }
    else if (head->next == NULL)
    {
        head = temp->next;
        free(temp);
    }
    else
    {
        struct Node *prev = NULL;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        temp->prev = NULL;
        prev->next = NULL;
        free(temp);
    }
}
void insertion_specified()
{
    int pos = 0;
    printf("\nEnter the position to insert(starts from 1): \n");
    scanf("%d", &pos);
    int data = 0;
    printf("\nEnter the data you want to insert?\n");
    scanf("%d", &data);
    struct Node *newNode = createNode(data);

    if (pos < 1)
    {
        printf("\nInvalid Position...\n");
    }
    else if (head == NULL && pos == 1)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        int count = 1;
        while (temp->next != NULL && count < pos - 1)
        {
            temp = temp->next;
            count++;
        }
        if (temp == NULL)
        {
            printf("\nPosition not exist\n");
        }
        else
        {
            struct Node *next = temp->next;
            next->prev = newNode;
            newNode->next = next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}
void deletion_specified()
{
    int pos = 0;
    printf("\nEnter the position to insert(starts from 1): \n");
    scanf("%d", &pos);

    if (pos < 1 || head == NULL)
    {
        printf("\nInvalid Position... or list empty\n");
    }

    else if (head->next == NULL && pos == 1)
    {
        struct Node *temp = head;
        head = temp->next;
        free(temp);
    }
    else
    {
        struct Node *temp = head;
        int count = 1;
        while (temp->next != NULL && count < pos - 1)
        {
            temp = temp->next;
            count++;
        }
        if (temp == NULL)
        {
            printf("\nPosition not exist\n");
        }
        else
        {
            struct Node *nextDel = temp->next;
            temp->next = nextDel->next;
            nextDel->prev = NULL;
            nextDel->next = NULL;
            free(nextDel);
        }
    }
}
void display()
{
    if (head == NULL)
    {
        printf("\nLISt empty");
    }
    else
    {
        struct Node *temp = head;
        printf("\nElements: ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
void search()
{
    int ele = 0;
    int flag = 0;
    printf("\nEnter the element to search??");
    scanf("%d", &ele);
    if (head == NULL)
    {
        printf("\nList empty\n");
    }
    else
    {
        struct Node *temp = head;
        int index = 0;
        while (temp != NULL)
        {
            if (ele == temp->data)
            {
                flag = 1;
                printf("\nThe element %d was found at index %d\n", ele, index);
                break;
            }
            index++;
            temp = temp->next;
        }
        if (flag == 0)
        {
            printf("\nelement not found\n");
        }
    }
}
void main()
{
    int choice = 0;
    while (choice != 9)
    {
        printf("\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n  5.Delete from last\n6.Delete the node after the given data\n7.Search\n8.Show\n9.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertion_beginning();
            break;
        case 2:
            insertion_last();
            break;
        case 3:
            insertion_specified();
            break;
        case 4:
            deletion_beginning();
            break;
        case 5:
            deletion_last();
            break;
        case 6:
            deletion_specified();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("\nPlease enter valid choice..\n");
        }
    }
}
