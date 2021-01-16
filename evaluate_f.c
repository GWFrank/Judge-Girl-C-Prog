
int evaluate_f(int *iptr[], int n, int *index) {
    int max_val = 4 * (iptr[0][0]) - 6 * (iptr[0][1]);
    *index = 0;

    for (int i=0; i<n; i++) {
        int val = 4 * (iptr[i][0]) - 6 * (iptr[i][1]);
        if (val > max_val) {
            max_val = val;
            *index = i;
        }
    }

    return max_val;
}