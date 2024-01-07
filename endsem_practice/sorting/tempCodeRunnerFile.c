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
            i++;
            k++;
        }
        else
        {
            combine[k] = arr[j];
            k++;
            i++;
        }
    }

    if (i > mid)
    {
        while (j <= ub)
        {
            combine[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            combine[k] = arr[i];
            j++;
            i++;
        }
    }

    for (k = lb; k <= ub; k++)
    {
        arr[k] = combine[k];
    }
}