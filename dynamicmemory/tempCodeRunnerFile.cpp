 int first, second;
    first = second = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
    }
    return second;