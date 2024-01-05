#include <stdio.h>

int main()
{
    int arr[] = {43, 67, 12, 89, 33};
    int size = sizeof(arr) / sizeof(int);

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int m = 0; m < size; m++)
    {
        printf("%d\n", arr[m]);
    }
}