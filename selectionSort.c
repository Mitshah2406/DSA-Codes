#include <stdio.h>
// Selection sort

// repetitively finds the minimum element from unsorted part of array and places it in beginning i.e sorted part of array
int main()
{

    int arr[] = {56, 23, 87, 42, 11};
    int arrLen = sizeof(arr) / sizeof(int);
    // one by one move boundary of unsorted subarray
    for (int i = 0; i < arrLen - 1; i++)
    {
        // find minimum in unsorted subaaray replace with minimum
        for (int j = i + 1; j < arrLen; j++)
        {
            // min greater than current so swap
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
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