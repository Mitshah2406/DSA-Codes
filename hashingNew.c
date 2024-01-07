#include <stdio.h>
// int hashFN(int key, int sizeHT)
// {
//     return (key) % sizeHT;
// }
// void linearProbing(int elems[], int sizeHT, int elemLen, int hashTB[])
// {
//     for (int i = 0; i < sizeHT; i++)
//     {
//         hashTB[i] = 0;
//     }
//     for (int k = 0; k < elemLen; k++)
//     {

//         int index = hashFN(elems[k], sizeHT);
//         int originalIndex = index;
//         int probe = 0;
//         while (hashTB[(index) % sizeHT] != 0)
//         {

//             index = (index + probe) % sizeHT;
//             probe++;
//         }
//         hashTB[index] = elems[k];
//     }
// }

// void quadraticProbing(int elems[], int sizeHT, int elemLen, int hashTB[])
// {
//     for (int i = 0; i < sizeHT; i++)
//     {
//         hashTB[i] = 0;
//     }
//     for (int k = 0; k < elemLen; k++)
//     {

//         int index = hashFN(elems[k], sizeHT);
//         int originalIndex = index;
//         int probe = 0;
//         while (hashTB[(index) % sizeHT] != 0)
//         {
//             index = (index + probe * probe) % sizeHT;
//             probe++;
//         }
//         hashTB[index] = elems[k];
//     }
// }

int hashFn(int key, int sizeHT)
{
    return (key % sizeHT);
}

void linearProbing(int hashTB[], int sizeHT, int elems[], int n)
{
    for (int i = 0; i < sizeHT; i++)
    {
        hashTB[i] = 0;
    }
    for (int k = 0; k < n; k++)
    {
        int index = hashFn(elems[k], sizeHT);
        int ogIndex = index;
        int probe = 0;
        while (hashTB[(index % sizeHT)] != 0)
        {
            index = (index + probe) % sizeHT;
            probe++;
        }
        hashTB[index] = elems[k];
    }
}
void quadraticProbing(int hashTB[], int sizeHT, int elems[], int n)
{
    for (int i = 0; i < sizeHT; i++)
    {
        hashTB[i] = 0;
    }
    for (int k = 0; k < n; k++)
    {
        int index = hashFn(elems[k], sizeHT);
        int ogIndex = index;
        int probe = 1;
        while (hashTB[(index % sizeHT)] != 0)
        {
            index = (index + (probe * probe)) % sizeHT;
            probe++;
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
    for (int i = 0; i < sizeHT; i++)
    {
        hashTB[i] = 0;
    }
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
        printf("\n Operations Menu:\n");
        printf("1. Linear Probing\n");
        printf("2. Quadratic Probing\n");

        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            linearProbing(hashTB, sizeHT, elems, n);
            printf("\n");
            for (int m = 0; m < sizeHT; m++)
            {
                printf("%d ", hashTB[m]);
            }

            break;

        case 2:
            quadraticProbing(hashTB, sizeHT, elems, n);
            for (int m = 0; m < sizeHT; m++)
            {
                printf("%d ", hashTB[m]);
            }
            break;

        case 3:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }

    } while (choice != 3);
}