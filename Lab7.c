#include <stdio.h>
#include <stdlib.h>


void bubbleSort(int array[], int n, int swaps[]) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (array[j] > array[j+1]) {
                // Swap arr[j] and arr[j+1]
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;

                // Increment swaps count for the swapped values
                swaps[array[j]]++;
                swaps[array[j+1]]++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int swaps[]) {
    int i, j, min_index, temp;
    for (i = 0; i < n-1; i++) {
        min_index = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // Swap arr[i] and arr[min_idx]
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;

        // Increment swaps count for the swapped values
        swaps[arr[i]]++;
        swaps[arr[min_index]]++;
    }
}

void printSwaps(int arr[], int n, int swaps[]) {
    for (int i = 0; i < n; i++) {
        printf("%d: # of times %d is swapped\n", arr[i], swaps[arr[i]]);
    }

    int totalSwaps = 0;
    for (int i = 0; i < n; i++) {
        totalSwaps += swaps[arr[i]];
    }

    printf("total # of swaps: %d\n\n", totalSwaps);
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);

    int swaps1[100] = {0}; // Assuming values are in the range 0-99
    int swaps2[100] = {0};

    printf("array1:\n");
    bubbleSort(array1, n1, swaps1);
    printSwaps(array1, n1, swaps1);

    printf("array2:\n");
    selectionSort(array2, n2, swaps2);
    printSwaps(array2, n2, swaps2);

    return 0;
}