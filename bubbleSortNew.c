#include <stdio.h>
#include <stdlib.h>
// repeatedly swap adjacent element we get max ele at last of array for each iteration
// then 2nd iteration is of n-1 ... n-i
void bubbleSort(int arr[], int n)
{
    int counter = 1;
    while (counter < n)
    {
        for (int i = 0; i < n - counter; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }
        }
        counter++;
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
    bubbleSort(arr, n);
    for (int j = 0; j < n; j++)
    {
        printf("%d ", arr[j]);
    }

    return 0;
}