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