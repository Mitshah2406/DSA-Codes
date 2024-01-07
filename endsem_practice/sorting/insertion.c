#include <stdio.h>
void insertionSort()
{
    int arr[] = {40, 20, 60, 10, 50, 30, 67};
    int size = sizeof(arr) / sizeof(int);
    for (int j = 1; j < size; j++)
    {
        int key = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }

    for (int m = 0; m < size; m++)
    {
        printf("%d ", arr[m]);
    }
}
int main()
{
    insertionSort();
}