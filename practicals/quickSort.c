#include <stdio.h>
int partition(int arr[], int lb, int ub)
{

    int pivot = arr[0];
    int start = lb;
    int end = ub;

    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }

        while (arr[end] > pivot)
        {
            end--;
        }
        // conditions not satisfied
        if (start < end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    // exchange pivot with end
    int temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;

    return end;
}
void quickSort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int location = partition(arr, lb, ub);
        quickSort(arr, lb, location - 1);
        quickSort(arr, location + 1, ub);
    }
}
int main()
{
    int arr[5] = {34, 12, 7, 65, 32};
    int n = sizeof(arr) / sizeof(int);
    quickSort(arr, 0, n - 1);
    for (int m = 0; m < n; m++)
    {
        printf("%d\n", arr[m]);
    }
    return 0;
}