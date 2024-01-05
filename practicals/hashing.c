#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int hash(int key)
{
    return key % SIZE;
}
int probe(int HT[], int key)
{
    int index = hash(key);
    int i = 0;
    while (i < SIZE - 1 && HT[(index + i) % SIZE] != 0)
    {
        i++;
    }

    return (index + i) % SIZE;
}
void insertIntoHT(int HT[], int key)
{
    int index = hash(key);
    if (HT[index] != 0)
    {
        index = probe(HT, key);
    }
    HT[index] = key;
}
int search(int HT[], int key)
{
    int index = hash(key);
    int i = 0;
    while (HT[(index + i) % SIZE] != 0)
    {
        if (HT[(index + i) % SIZE] == key)
        {
            return (index + i) % SIZE;
        }
        i++;
    }
    return -1;
}
void displayHT(int HT[])
{
    printf("\n Index \t Values:");
    for (int i = 0; i < SIZE; i++)
    {
        printf("\n %d \t %d", i, HT[i]);
    }
}
int main()
{
    int data, choice;
    int HT[10] = {0};
    while (choice != 4)
    {
        printf("\nHash table ops:\n");
        printf("1. Insert \n");
        printf("1. Search   \n");
        printf("3. Display\n");

        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the key to insert: ");
            scanf("%d", &data);
            insertIntoHT(HT, data);

            break;
        case 2:

            printf("Enter the key to search: ");
            scanf("%d", &data);
            int result = search(HT, data);
            if (search(HT, data) != -1)
            {
                printf("The key %d is found at %d", data, result);
            }
            else
            {
                printf("Didnt find");
            }

            break;

        case 3:
            displayHT(HT);
            break;
        case 4:
            choice == 4;
            break;
        default:
            break;
        }
    }
    return 0;
}