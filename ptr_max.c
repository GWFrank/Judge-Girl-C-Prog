int max(int *iptr[], int n) {
    int max_val = *(iptr[0]);
    for (int i=0; i<n; i++) {
        if (*(iptr[i]) > max_val) max_val = *(iptr[i]);
    }
    return max_val;
}