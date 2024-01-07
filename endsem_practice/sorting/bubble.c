#include <stdio.h>
void sort()
{
    int arr[] = {40, 20, 60, 10, 50, 30, 67};
    int size = sizeof(arr) / sizeof(int);
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int m = 0; m < size; m++)
    {
        printf("%d ", arr[m]);
    }
}
int main()
{
    sort();
}