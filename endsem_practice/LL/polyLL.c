#include <stdio.h>
#include <stdlib.h>
struct Poly
{
    int coefficient;
    int exponent;
    struct Poly *next;
};
struct Poly *createNode(int coe, int expo)
{
    struct Poly *newNode = (struct Poly *)malloc(sizeof(struct Poly));
    newNode->coefficient = coe;
    newNode->exponent = expo;
    newNode->next = NULL;
    return newNode;
}
struct Poly *insertDescending(struct Poly *head, int coe, int exp)
{
    struct Poly *newNode = createNode(coe, exp);
    if (head == NULL || newNode->exponent > head->exponent)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        struct Poly *temp = head;

        while (temp->next != NULL && temp->next->exponent > newNode->exponent)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}
struct Poly *insertAtEnd(struct Poly *head, struct Node *newNode)
{

    struct Poly *temp = head;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}
struct Poly *arithmetic(struct Poly *p1Head, struct Poly *p2Head, struct Poly *resHead, int operation)
{
    struct Poly *temp1 = p1Head;
    struct Poly *temp2 = p2Head;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->exponent == temp2->exponent)
        {
            int coeRes = operation == 0 ? ((temp1->coefficient) + (temp2->coefficient)) : ((temp1->coefficient) - (temp2->coefficient));
            struct Poly *newNode = createNode(coeRes, temp1->exponent);
            resHead = insertAtEnd(resHead, newNode);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->exponent > temp2->exponent)
        {
            struct Poly *newNode = createNode(temp1->coefficient, temp1->exponent);
            resHead = insertAtEnd(resHead, newNode);
            temp1 = temp1->next;
        }
        else if (temp1->exponent < temp2->exponent)
        {
            struct Poly *newNode = createNode(temp2->coefficient, temp2->exponent);
            resHead = insertAtEnd(resHead, newNode);
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL)
    {
        struct Poly *newNode = createNode(temp1->coefficient, temp1->exponent);
        resHead = insertAtEnd(resHead, newNode);
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        struct Poly *newNode = createNode(temp2->coefficient, temp2->exponent);
        resHead = insertAtEnd(resHead, newNode);
        temp2 = temp2->next;
    }
    return resHead;
}
void display(struct Poly *rHead)
{
    if (rHead == NULL)
    {
        printf("\nResult Null");
    }
    else
    {
        struct Poly *temp = rHead;
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
    struct Poly *p1H = NULL, *p2H = NULL, *rH = NULL;
    int terms1, terms2;

    printf("\nEnter no of terms for 1st poly: ");
    scanf("%d", &terms1);

    for (int i = 0; i < terms1; i++)
    {
        int coefficient, expo;
        printf("Enter coefficient for term %d", i + 1);
        scanf("%d", &coefficient);
        printf("Enter expo for term %d", i + 1);
        scanf("%d", &expo);
        p1H = insertDescending(p1H, coefficient, expo);
    }
    printf("\nEnter no of terms for 1st poly: ");
    scanf("%d", &terms2);

    for (int i = 0; i < terms2; i++)
    {
        int coefficient, expo;
        printf("Enter coefficient for term %d", i + 1);
        scanf("%d", &coefficient);
        printf("Enter expo for term %d", i + 1);
        scanf("%d", &expo);
        p2H = insertDescending(p2H, coefficient, expo);
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
            rH = NULL;
            rH = arithmetic(p1H, p2H, rH, 0);
            break;
        case 2:
            rH = NULL;
            rH = arithmetic(p1H, p2H, rH, 1);
            break;
        case 3:
            display(rH);

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