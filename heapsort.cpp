void MAX_HEAPIFY(int A[], int i, int heapsize){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest;
    if (l < heapsize && A[l] > A[i]){
        largest = l;
    } else {
        largest = i;
    }
    if (r < heapsize && A[r] > A[largest]){
        largest = r;
    } 
    if (largest != i){
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        MAX_HEAPIFY(A, largest, heapsize);
    }
}

void BUILD_MAX_HEAP(int A[], int size){
    for (int i = size/2 - 1; i >= 0; --i){
        MAX_HEAPIFY(A, i, size);
    } 
}

void heapsort(int A[], int size){
    BUILD_MAX_HEAP(A, size);
    for (int i = size; i >= 2; --i){
        int temp = A[0];
        A[0] = A[i-1];
        A[i-1] = temp;
        --size;
        MAX_HEAPIFY(A, 0, size);
    }
}