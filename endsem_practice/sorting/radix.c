#include <stdio.h>
int getMax(int arr[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}
void countSort(int arr[], int n, int pos)
{
    int count[10] = {0};
    int b[n];

    for (int i = 0; i < n; i++)
    {
        ++count[(arr[i] / pos) % 10];
    }
    for (int j = 1; j < 10; j++)
    {
        count[j] += count[j - 1];
    }
    for (int k = n - 1; k >= 0; k--)
    {
        b[--count[(arr[k] / pos) % 10]] = arr[k];
    }
    for (int m = 0; m < n; m++)
    {
        arr[m] = b[m];
    }
}
void radixSort(int arr[], int n)
{
    int maxElement = getMax(arr, n);
    for (int pos = 1; (maxElement / pos) > 0; pos *= 10)
    {
        countSort(arr, n, pos);
    }
}
int main()
{
    int n;
    printf("Enter length:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter Array:");
    for (int j = 0; j < n; j++)
    {
        scanf("%d", &arr[j]);
    }

    radixSort(arr, n); // Perform radix sort on the entered array

    printf("Sorted:");
    for (int y = 0; y < n; y++)
    {
        printf(" %d ", arr[y]); // Print the sorted array
    }
    return 0;
}