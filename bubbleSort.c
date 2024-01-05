#include <stdio.h>
// Selection sort

// repetitively compare two adjacent values and replaces their place if in wrong order
int main()
{
    // same can be achieved through while loop also
    int arr[] = {56, 23, 87, 42, 11};
    int arrLen = sizeof(arr) / sizeof(int);
    // here j means counter variable

    //  for (int j = 1; j < arrLen; j++)
    //  {
    //      for (int i = 0; i < arrLen - j; i++)
    //      {
    //          if (arr[i] > arr[i + 1])
    //          {
    //              int temp = arr[i + 1];
    //              arr[i + 1] = arr[i];
    //              arr[i] = temp;
    //          }
    //      }
    //  }
    int j = 1;
    while (j < arrLen)
    {
        for (int i = 0; i < arrLen - j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }
        }
        j++;
    }
    for (int k = 0; k < arrLen; k++)
    {
        printf("%d\n", arr[k]);
    }

    return 0;
}
