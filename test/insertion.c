#include <stdio.h>
int main()
{
    int arr[] = {23, 45, 11, 67, 55};
    int size = sizeof(arr) / sizeof(int);
    for (int i = 0; i < size; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (arr[j] > current && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }

    for (int m = 0; m < size; m++)
    {
        printf("%d\n", arr[m]);
    }
}