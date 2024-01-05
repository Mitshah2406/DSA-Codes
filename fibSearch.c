#include <stdio.h>
#include <stdlib.h>
// repeatedly swap adjacent element we get max ele at last of array for each iteration
// then 2nd iteration is of n-1 ... n-i

int min(int a, int b)
{
    return (a < b) ? a : b;
}
int fibonacciSearch(int arr[], int n, int elem)
{
    int offset = -1;
    int fibM2 = 0;
    int fibM1 = 1;
    int fibM = fibM1 + fibM2;

    while (fibM < n)
    {
        fibM2 = fibM1;
        fibM1 = fibM;
        fibM = fibM1 + fibM2;
    }
    while (fibM > 1)
    {
        int i = min(offset + fibM2, n - 1);
        if (arr[i] > elem)
        {
            fibM = fibM2;
            fibM1 = fibM1 - fibM2;
            fibM2 = fibM - fibM1;
        }
        else if (arr[i] < elem)
        {
            fibM = fibM1;
            fibM1 = fibM2;
            fibM2 = fibM - fibM2;
            offset = i;
        }
        else
        {
            return i;
        }
    }
    if (arr[offset + 1] == elem)
    {
        return offset + 1;
    }
    return -1;
}
int main()
{
    int n, elem;
    printf("Enter length:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter Array:");
    for (int j = 0; j < n; j++)
    {
        scanf("%d", &arr[j]);
    }
    printf("Enter element:");
    scanf("%d", &elem);
    printf("\n Res is %d", fibonacciSearch(arr, n, elem));

    return 0;
}
