#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int coefficient;
    int exponent;
    struct Node *next;
} *p1Head, *p2Head, *resultHead;

struct Node *createNode(int coefficient, int exponent)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}
struct Node *insertDescending(struct Node *head, int coefficient, int exponent)
{
    struct Node *newNode = createNode(coefficient, exponent);
    struct Node *temp;
    if (head == NULL || head->exponent < newNode->exponent)
    {

        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL && temp->next->exponent > newNode->exponent)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
}
struct Node *insertAtEnd(struct Node *head, struct Node *newNode)
{
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
    }
    return head;
}
void add(struct Node *p1Head, struct Node *p2Head)
{
    struct Node *temp1 = p1Head;
    struct Node *temp2 = p2Head;
    int coefficientResult;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->exponent == temp2->exponent)
        {
            coefficientResult = ((temp1->coefficient) + (temp2->coefficient));
            struct Node *newNode = createNode(coefficientResult, temp1->exponent);
            resultHead = insertAtEnd(resultHead, newNode);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->exponent > temp2->exponent)
        {
            struct Node *newNode = createNode(temp1->coefficient, temp1->exponent);
            resultHead = insertAtEnd(resultHead, newNode);
            temp1 = temp1->next;
        }
        else if (temp1->exponent < temp2->exponent)
        {
            struct Node *newNode = createNode(temp2->coefficient, temp2->exponent);
            resultHead = insertAtEnd(resultHead, newNode);
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL)
    {
        struct Node *newNode = createNode(temp1->coefficient, temp1->exponent);
        resultHead = insertAtEnd(resultHead, newNode);
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        struct Node *newNode = createNode(temp2->coefficient, temp2->exponent);
        resultHead = insertAtEnd(resultHead, newNode);
        temp2 = temp2->next;
    }
}
void sub(struct Node *p1Head, struct Node *p2Head)
{
    struct Node *temp1 = p1Head;
    struct Node *temp2 = p2Head;
    int coefficientResult;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->exponent == temp2->exponent)
        {
            coefficientResult = ((temp1->coefficient) - (temp2->coefficient));
            struct Node *newNode = createNode(coefficientResult, temp1->exponent);
            resultHead = insertAtEnd(resultHead, newNode);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->exponent > temp2->exponent)
        {
            struct Node *newNode = createNode(temp1->coefficient, temp1->exponent);
            resultHead = insertAtEnd(resultHead, newNode);
            temp1 = temp1->next;
        }
        else if (temp1->exponent < temp2->exponent)
        {
            struct Node *newNode = createNode(temp2->coefficient, temp2->exponent);
            resultHead = insertAtEnd(resultHead, newNode);
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL)
    {
        struct Node *newNode = createNode(temp1->coefficient, temp1->exponent);
        resultHead = insertAtEnd(resultHead, newNode);
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        struct Node *newNode = createNode(temp2->coefficient, temp2->exponent);
        resultHead = insertAtEnd(resultHead, newNode);
        temp2 = temp2->next;
    }
}
void display()
{
    struct Node *temp = resultHead;
    if (resultHead == NULL)
    {
        printf("No reuslt");
    }
    else
    {
        while (temp != NULL)
        {
            printf("(%dx^%d)", temp->coefficient, temp->exponent);
            temp = temp->next;
            if (temp != NULL)
            {
                printf(" + ");
            }
            else
            {
                printf("\n");
            }
        }
    }
}
int main()
{

    int terms1, terms2;

    printf("Enter the number of terms for 1st polynomial: ");
    scanf("%d", &terms1);
    for (int i = 0; i < terms1; i++)
    {
        int coefficient, exponent;
        printf("Enter the coefficient for term %d: ", i + 1);
        scanf("%d", &coefficient);
        printf("Enter the exponent for term %d: ", i + 1);
        scanf("%d", &exponent);
        p1Head = insertDescending(p1Head, coefficient, exponent);
    }

    printf("Enter the number of terms for 2nd polynomial: ");
    scanf("%d", &terms2);
    for (int i = 0; i < terms2; i++)
    {
        int coefficient, exponent;
        printf("Enter the coefficient for term %d: ", i + 1);
        scanf("%d", &coefficient);
        printf("Enter the exponent for term %d: ", i + 1);
        scanf("%d", &exponent);
        p2Head = insertDescending(p2Head, coefficient, exponent);
    }

    int choice;
    while (choice != 4)
    {
        printf("\n Menu: \n");
        printf("1.Add\n");
        printf("2.Sub\n");
        printf("3.Result\n");
        printf("4.Exit\n");
        printf("\n\nEnter the operation you wanna perform:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            resultHead = NULL;
            add(p1Head, p2Head);
            break;
        case 2:
            resultHead = NULL;
            sub(p1Head, p2Head);
            break;
        case 3:
            display();

            break;
        case 4:
            choice = 4;
            break;
        default:
            printf("Invalid Choice..\n");
            break;
        }
    }
    return 0;
}