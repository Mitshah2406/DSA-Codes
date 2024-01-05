#include <stdio.h>

void merge(int arr[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int combine[ub - lb + 1];
    while (i <= mid && j <= ub)
    {
        if (arr[i] <= arr[j])
        {
            combine[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            combine[k] = arr[j];
            k++;
            j++;
        }
    }

    if (i > mid)
    {
        while (j <= ub)
        {
            combine[k] = arr[j];
            k++;
            j++;
        }
    }
    else
    {
        while (i <= mid)
        {
            combine[k] = arr[i];
            k++;
            i++;
        }
    }

    for (k = lb; k <= ub; k++)
    {
        arr[k] = combine[k];
    }
}

void mergeSort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid + 1, ub);

        merge(arr, lb, mid, ub);
    }
}
int main()
{
    int arr[9] = {15, 5, 24, 8, 1, 3, 16, 10, 20};
    int n = sizeof(arr) / sizeof(int);

    mergeSort(arr, 0, n - 1);
    for (int m = 0; m < n; m++)
    {
        printf("%d\n", arr[m]);
    }
    return 0;
}