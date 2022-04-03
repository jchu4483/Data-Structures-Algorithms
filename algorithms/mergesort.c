#include <stdio.h>

void mergeSort(int testArray[], int l, int r);
void merge(int testArray[], int l, int midpoint, int r);

int main() {
    int testArray[] = {1, 5, 6, 8, 3, 4, -21, 0, 4};
    int length = sizeof testArray / sizeof testArray[0];
    mergeSort(testArray, 0, length - 1);
    for (int i = 0; i < length; i++) {
        printf("%i ", testArray[i]);
    }
    printf("\n");
}

void mergeSort(int testArray[], int l, int r) {
    if (l < r) {
        int midpoint = (l + r) / 2;
        // call mergesort on left array
        mergeSort(testArray, l, midpoint);
        // call mergesort on right array
        mergeSort(testArray, midpoint + 1, r);
        // merge both sorted arrays;
        merge(testArray, l, midpoint, r);
    }
}

void merge(int testArray[], int l, int midpoint, int r) {
    int left_length = midpoint - l + 1;
    int right_length = r - midpoint;
    int leftArray[left_length];
    int rightArray[right_length];

    for (int i = 0; i < left_length; i++) {
        leftArray[i] = testArray[l + i];
    }

    for (int i = 0; i < right_length; i++) {
        rightArray[i] = testArray[midpoint + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;
    while (i < left_length && j < right_length) {
        if (leftArray[i] < rightArray[j]) {
            testArray[k] = leftArray[i];
            i++;
            k++;
        }
        else {
            testArray[k] = rightArray[j];
            j++;
            k++;
        }
    }

    while (i < left_length) {
        testArray[k] = leftArray[i];
        i++;
        k++;
    }

    while (i < right_length) {
        testArray[k] = rightArray[j];
        j++;
        k++;
    }
}

