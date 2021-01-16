void fill_array(int *ptr[], int n) {
    int *arr = ptr[0];
    int arr_len = 0;
    while (&arr[arr_len] <= ptr[n-1]) {
        arr[arr_len] = -1;
        arr_len++;
    }

    for (int i=0; i<n; i++)
        *ptr[i] = i;
    
    int val = 0;
    for (int i=0; i<arr_len; i++) {
        if (arr[i] == -1) arr[i] = val;
        else val = arr[i];
    }

    val = -1;
    for (int i=arr_len-1; i>0; i--) {
        if (arr[i] != arr[i-1]) val = arr[i];
        else arr[i] += val;
    }
}