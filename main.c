#include <string.h> // memcpy
#include <stdlib.h> // srand, malloc, rand
#include <time.h>   // time, clock
#include <stdio.h>

// Function prototypes
void bubbleSort(int* arr, int size);
void selectionSort(int* arr, int size);
void insertionSort(int* arr, int size);
int linearSearch(int* arr, int size, int target);
int binarySearch(int* arr, int size, int target);
void generateRandomArray(int* arr, int size);
void copyArray(int* dest, int* src, int size);
void evaluateSortAndSearch(int size);
double getElapsedTime(clock_t start, clock_t end);

int main() {
    unsigned int mySeed = 133760126;
    srand(mySeed);

    printf("=================================================================\n");
    printf("Algorithm Performance Evaluation\n");
    printf("=================================================================\n\n");

    // Test sizes as specified
    int sizes[] = {10, 50, 100, 500, 1000, 5000, 10000, 25000, 50000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    // Run evaluation for each size
    for (int i = 0; i < numSizes; i++) {
        evaluateSortAndSearch(sizes[i]);
        printf("\n");
    }

    printf("=================================================================\n");
    printf("Evaluation Complete\n");
    printf("=================================================================\n");

    return 0;
}

// Generates random array of specified size
void generateRandomArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }
}

// Copies array from source to destination
void copyArray(int* dest, int* src, int size) {
    memcpy(dest, src, size * sizeof(int));
}

// Calculates elapsed time in seconds
double getElapsedTime(clock_t start, clock_t end) {
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

// Bubble Sort implementation
void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort implementation
void selectionSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Insertion Sort implementation
void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Linear Search implementation
int linearSearch(int* arr, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // Not found
}

// Binary Search implementation (requires sorted array)
int binarySearch(int* arr, int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Not found
}

// Evaluation function for a given array size
void evaluateSortAndSearch(int size) {
    printf("-----------------------------------------------------------------\n");
    printf("Array Size: %d\n", size);
    printf("-----------------------------------------------------------------\n");

    // Allocate memory for arrays
    int* original = (int*)malloc(size * sizeof(int));
    int* workArray = (int*)malloc(size * sizeof(int));

    if (original == NULL || workArray == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Generate random data
    generateRandomArray(original, size);

    clock_t start, end;
    double elapsed;
    int searchTarget, searchResult;

    // ========== Bubble Sort + Linear Search ==========
    copyArray(workArray, original, size);
    start = clock();
    bubbleSort(workArray, size);
    end = clock();
    elapsed = getElapsedTime(start, end);
    printf("Bubble Sort:     %12.6f seconds\n", elapsed);

    // Linear search on sorted array
    searchTarget = workArray[size / 2]; // Search for middle element
    start = clock();
    searchResult = linearSearch(workArray, size, searchTarget);
    end = clock();
    elapsed = getElapsedTime(start, end);
    printf("  + Linear Search:  %12.6f seconds (found at index %d)\n", elapsed, searchResult);

    // ========== Bubble Sort + Binary Search ==========
    copyArray(workArray, original, size);
    start = clock();
    bubbleSort(workArray, size);
    end = clock();
    elapsed = getElapsedTime(start, end);
    printf("Bubble Sort:     %12.6f seconds\n", elapsed);

    // Binary search on sorted array
    searchTarget = workArray[size / 2];
    start = clock();
    searchResult = binarySearch(workArray, size, searchTarget);
    end = clock();
    elapsed = getElapsedTime(start, end);
    printf("  + Binary Search:  %12.6f seconds (found at index %d)\n", elapsed, searchResult);

    // ========== Selection Sort + Linear Search ==========
    copyArray(workArray, original, size);
    start = clock();
    selectionSort(workArray, size);
    end = clock();
    elapsed = getElapsedTime(start, end);
    printf("Selection Sort:  %12.6f seconds\n", elapsed);

    // Linear search
    searchTarget = workArray[size / 2];
    start = clock();
    searchResult = linearSearch(workArray, size, searchTarget);
    end = clock();
    elapsed = getElapsedTime(start, end);
    printf("  + Linear Search:  %12.6f seconds (found at index %d)\n", elapsed, searchResult);

    // ========== Selection Sort + Binary Search ==========
    copyArray(workArray, original, size);
    start = clock();
    selectionSort(workArray, size);
    end = clock();
    elapsed = getElapsedTime(start, end);
    printf("Selection Sort:  %12.6f seconds\n", elapsed);

    // Binary search
    searchTarget = workArray[size / 2];
    start = clock();
    searchResult = binarySearch(workArray, size, searchTarget);
    end = clock();
    elapsed = getElapsedTime(start, end);
    printf("  + Binary Search:  %12.6f seconds (found at index %d)\n", elapsed, searchResult);

    // ========== Insertion Sort + Linear Search ==========
    copyArray(workArray, original, size);
    start = clock();
    insertionSort(workArray, size);
    end = clock();
    elapsed = getElapsedTime(start, end);
    printf("Insertion Sort:  %12.6f seconds\n", elapsed);

    // Linear search
    searchTarget = workArray[size / 2];
    start = clock();
    searchResult = linearSearch(workArray, size, searchTarget);
    end = clock();
    elapsed = getElapsedTime(start, end);
    printf("  + Linear Search:  %12.6f seconds (found at index %d)\n", elapsed, searchResult);

    // ========== Insertion Sort + Binary Search ==========
    copyArray(workArray, original, size);
    start = clock();
    insertionSort(workArray, size);
    end = clock();
    elapsed = getElapsedTime(start, end);
    printf("Insertion Sort:  %12.6f seconds\n", elapsed);

    // Binary search
    searchTarget = workArray[size / 2];
    start = clock();
    searchResult = binarySearch(workArray, size, searchTarget);
    end = clock();
    elapsed = getElapsedTime(start, end);
    printf("  + Binary Search:  %12.6f seconds (found at index %d)\n", elapsed, searchResult);

    // Free memory
    free(original);
    free(workArray);
}
