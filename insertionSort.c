#include <stdio.h>

int main()
{

    int arr[] = {23, 45, 35, 56, 12};
    int arrLen = sizeof(arr) / sizeof(int);

    for (int i = 1; i < arrLen; i++) // 45 ,35
    {
        int currentElement = arr[i];              // 45,25
        int j = i - 1;                            // 0,1
        while (arr[j] > currentElement && j >= 0) // 23>45 && 0>=0, 45>35
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = currentElement;
    }

    for (int m = 0; m < arrLen; m++)
    {
        printf("%d\n", arr[m]);
    }

    return 0;
}

// 11, 56, 23, 87, 42
// 11,23,56,87,42
// 11,23,42,56,87