#include <stdio.h>

// Function to find the maximum element in the array
int getMax(int arr[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

// Function to perform counting sort based on digit at a specific position
void countSort(int arr[], int n, int pos)
{
    int count[10] = {0}; // Initialize count array for digits 0 to 9
    int b[n];            // Temporary array to store sorted elements

    // Count the occurrences of each digit at a specific position
    for (int i = 0; i < n; i++)
    {
        ++count[(arr[i] / pos) % 10]; // (677/1)=677%10 = 7 , (677/10)= 67%10 = 7 ,(677/100)=6%10 = 6
    }

    // Modify the count array to indicate the position of each element in the output
    for (int j = 1; j < 10; j++)
    {
        count[j] += count[j - 1];
    }

    // Place elements into the temporary array in sorted order based on digit at 'pos'
    for (int k = 10 - 1; k >= 0; k--)
    {
        b[--count[(arr[k] / pos) % 10]] = arr[k];
    }

    // Copy elements from temporary array back to the original array
    for (int m = 0; m < n; m++)
    {
        arr[m] = b[m];
    }
}

// Function to perform radix sort
void radixSort(int arr[], int n)
{
    int maxElement = getMax(arr, n); // Get the maximum element in the array

    // Iterate through each digit position (ones, tens, hundreds, etc.)
    for (int pos = 1; (maxElement / pos) > 0; pos *= 10) // 667/1 = 677, 677/10 = 67, 677/100 = 6, 677/1000 = 0... (last case wrong)
    {
        countSort(arr, n, pos); // Perform counting sort for each digit position
    }
}

// Main function
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
