#include <stdio.h>

int main()
{
    int arr[5] = {34, 12, 7, 65, 32};
    int n = sizeof(arr) / sizeof(int);

    int current, j;
    for (int i = 1; i < n; i++)
    {
        current = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > current)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = current;
    }

    for (int m = 0; m < n; m++)
    {
        printf("%d\n", arr[m]);
    }
    return 0;
}