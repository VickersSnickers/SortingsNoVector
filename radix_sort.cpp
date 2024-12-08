#include "radix_sort.hpp"

int getMax(int array[], int n) {
    int maximum = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > maximum) maximum = array[i];
    return maximum;
}

void countingSort(int array[], int size, int place) {
    const int max = 10;
    int output[size] = {0};
    int count[max] = {0};

    for (int i = 0; i < size; i++){
        count[(array[i] / place) % 10]++;
    }
    
    for (int i = 1; i < max; i++){
        count[i] += count[i - 1];
    }
    
    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++){
        array[i] = output[i];
    }
}

void RadixSort(int array[], int size) {
    int max = getMax(array, size);
    for (int place = 1; max / place > 0; place *= 10){
        countingSort(array, size, place);
    }
}