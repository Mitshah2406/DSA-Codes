#include <stdio.h>

// Partition function: Rearranges the array elements around a pivot
int partition(int arr[], int lb, int ub)
{
    int pivot = arr[lb]; // Select the pivot element
    int start = lb;      // Initialize start index
    int end = ub;        // Initialize end index

    // Continue until start and end meet or cross each other
    while (start <= end)
    {
        // Move the start index to the right until finding an element greater than pivot
        if (arr[start] <= pivot)
        {
            start++;
        }
        // Move the end index to the left until finding an element smaller or equal to pivot
        else if (arr[end] > pivot)
        {
            end--;
        }
        // Swap arr[start] and arr[end] if start is less than end
        else if (start < end)
        {
            int temp = arr[end];
            arr[end] = arr[start];
            arr[start] = temp;
        }
    }

    // Swap pivot element with the element at the 'end' index
    int temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;

    return end; // Return the partitioning index
}

// QuickSort function: Recursively sorts the array using the partition function
void quickSort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(arr, lb, ub); // Get the partitioning index
        quickSort(arr, lb, loc - 1);      // Sort elements before partition
        quickSort(arr, loc + 1, ub);      // Sort elements after partition
    }
}

// Main function
int main()
{
    int arr[] = {40, 20, 60, 10, 50, 30, 67};
    int size = sizeof(arr) / sizeof(int);
    quickSort(arr, 0, size - 1); // Perform QuickSort on the array
    for (int m = 0; m < size; m++)
    {
        printf("%d ", arr[m]); // Print the sorted array
    }
    return 0;
}
