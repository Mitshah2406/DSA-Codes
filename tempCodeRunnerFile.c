 for (int k = n - 1; k >= 0; k--)
    {
        b[--count[(arr[k] / pos) % 10]] = arr[k];
    }