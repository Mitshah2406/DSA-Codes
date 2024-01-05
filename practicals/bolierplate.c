#include <stdio.h>

int main()
{
    int arr[5] = {34, 12, 7, 65, 32};
    int n = sizeof(arr) / sizeof(int);

    for (int m = 0; m < n; m++)
    {
        printf("%d\n", arr[m]);
    }
    return 0;
}