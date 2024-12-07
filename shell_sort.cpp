void shell_Sort(int arr[], int arrsize, int gaps[], int gapssize){
    int ptr = gapssize - 1;
    for (int gap = gaps[ptr]; gap > 0;) {
        for (int i = gap; i < arrsize; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        gap = gaps[--ptr];
    }
};
