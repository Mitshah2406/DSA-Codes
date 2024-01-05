#include <stdio.h>
// 1, 2, 3, 4, 5, 6, 7, 8, 9
int binarySearch(int arr[], int size, int element)
{
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else if (arr[mid] > element)
        {
            high = mid - 1;
        }
    }
    printf("iterating\n");
    return -1;
}
int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (element == arr[i])
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int element = 7;
    int size = sizeof(arr) / sizeof(int);

    int linearResult = linearSearch(arr, size, element);
    int binaryResult = linearSearch(arr, size, element);
    printf("The element %d was found at index %d", element, linearResult);
    printf("The element %d was found at index %d", element, binaryResult);
    return 0;
}
