#include <stdio.h>

int main()
{
    int arr[5] = {34, 12, 7, 65, 32};
    int n = sizeof(arr) / sizeof(int);
    printf("Size:%d\n", n);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    for (int m = 0; m < n; m++)
    {
        printf("%d\n", arr[m]);
    }
    return 0;
}