#include <stdio.h>

// Merge function: Merges two sorted subarrays into a single sorted array
void merge(int arr[], int lb, int mid, int ub)
{
    int i = lb;               // Initial index of first subarray
    int j = mid + 1;          // Initial index of second subarray
    int k = lb;               // Initial index of merged subarray
    int combine[ub - lb + 1]; // Temporary array to store merged elements

    // Merge elements from subarrays into combine[] in sorted order
    while (i <= mid && j <= ub)
    {
        if (arr[i] <= arr[j]) // Compare elements from two halves
        {
            combine[k] = arr[i]; // Place smaller element in combine[]
            i++;
        }
        else
        {
            combine[k] = arr[j]; // Place smaller element in combine[]
            j++;
        }
        k++;
    }

    // Copy remaining elements from the first half, if any
    while (i <= mid)
    {
        combine[k] = arr[i]; // Place remaining elements in combine[]
        i++;
        k++;
    }

    // Copy remaining elements from the second half, if any
    while (j <= ub)
    {
        combine[k] = arr[j]; // Place remaining elements in combine[]
        j++;
        k++;
    }

    // Copy elements from combine[] back to the original array arr[]
    for (k = lb; k <= ub; k++)
    {
        arr[k] = combine[k]; // Copy sorted elements to the original array
    }
}

// MergeSort function: Recursively divides the array into smaller halves and merges them
void mergeSort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2; // Find the middle index of the array

        // Recursively sort the first and second halves
        mergeSort(arr, lb, mid);     // Sort left half
        mergeSort(arr, mid + 1, ub); // Sort right half

        // Merge the sorted halves
        merge(arr, lb, mid, ub); // Merge both halves
    }
}

// Main function
int main()
{
    int arr[] = {40, 20, 60, 10, 50, 30, 67};
    int size = sizeof(arr) / sizeof(int);

    mergeSort(arr, 0, size - 1); // Perform MergeSort on the array

    printf("Sorted array: ");
    for (int m = 0; m < size; m++)
    {
        printf("%d ", arr[m]); // Print the sorted array
    }
    printf("\n");

    return 0;
}
