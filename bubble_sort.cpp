void bubble_sort(int A[], int size){
    for (int i = 0; i < size - 1; ++i){
        for (int j = 0; j < size - 1 - i; ++j){
            if (A[j] > A[j + 1]){
                A[j] = A[j] + A[j + 1];
                A[j + 1] = A[j] - A[j + 1];
                A[j] = A[j] - A[j + 1];
            }
        }
    }
}
