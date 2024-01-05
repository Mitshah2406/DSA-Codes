#include <stdio.h>

int hashFN(int key, int sizeHT)
{
    return key % sizeHT;
}

void linearProbing(int elems[], int sizeHT, int elemLen, int hashTB[])
{
    for (int k = 0; k < elemLen; k++)
    {
        int index = hashFN(elems[k], sizeHT);
        int originalIndex = index;

        while (hashTB[index] != -1 && index != originalIndex)
        {
            index = (index + 1) % sizeHT;
        }

        if (index == originalIndex && hashTB[index] != -1)
        {
            printf("Hash table is full. Cannot insert more elements.\n");
            return;
        }

        hashTB[index] = elems[k];
    }
}

void quadraticProbing(int elems[], int sizeHT, int elemLen, int hashTB[])
{
    for (int k = 0; k < elemLen; k++)
    {
        int index = hashFN(elems[k], sizeHT);
        int originalIndex = index;
        int step = 1;

        while (hashTB[index] != -1 && index != originalIndex)
        {
            index = (index + step * step) % sizeHT;
            step++;
        }

        if (index == originalIndex && hashTB[index] != -1)
        {
            printf("Hash table is full. Cannot insert more elements.\n");
            return;
        }

        hashTB[index] = elems[k];
    }
}

int main()
{
    int choice;
    int sizeHT;
    int n;

    printf("\nEnter Size of hash table: ");
    scanf("%d", &sizeHT);

    int hashTB[sizeHT];

    printf("\nEnter how many elements to insert: ");
    scanf("%d", &n);

    int elems[n];

    printf("\nEnter elements to insert: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &elems[i]);
    }

    do
    {
        printf("\nOperations Menu:\n");
        printf("1. Linear Probing\n");
        printf("2. Quadratic Probing\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            linearProbing(elems, sizeHT, n, hashTB);
            printf("Hash Table after Linear Probing:\n");
            for (int m = 0; m < sizeHT; m++)
            {
                printf("%d ", hashTB[m]);
            }
            printf("\n");
            break;

        case 2:
            quadraticProbing(elems, sizeHT, n, hashTB);
            printf("Hash Table after Quadratic Probing:\n");
            for (int m = 0; m < sizeHT; m++)
            {
                printf("%d ", hashTB[m]);
            }
            printf("\n");
            break;

        case 3:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
