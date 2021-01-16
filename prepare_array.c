void prepare_array(int buffer[], int *array[], int row, int column[]) {
    int buffer_idx = 0;
    for (int i=0; i<row; i++) {
        array[i] = &buffer[buffer_idx];
        buffer_idx += column[i];
    }
}