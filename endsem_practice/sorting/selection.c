#include <stdio.h>
void sort()
{
    int arr[] = {40, 20, 60, 10, 50, 30, 67};
    int size = sizeof(arr) / sizeof(int);
    for (int i = 0; i < size - 1; i++)
    {

        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
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