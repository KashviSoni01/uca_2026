#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "generator.h"
#include "sorting.h"

double getTimeInMilliseconds(struct timespec start, struct timespec end)
{
    return (end.tv_sec - start.tv_sec) * 1000.0 +
           (end.tv_nsec - start.tv_nsec) / 1000000.0;
}

void testSimpleSort(char *name, void (*sortFunc)(int[], int), int original[], int n)
{
    int *copy = (int *)malloc(n * sizeof(int));

    copyArray(original, copy, n);

    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);

    sortFunc(copy, n);

    clock_gettime(CLOCK_MONOTONIC, &end);

    printf("%-15s : %.3f ms\n", name,
           getTimeInMilliseconds(start, end));

    free(copy);
}

void testQuickSort(int original[], int n)
{
    int *copy = (int *)malloc(n * sizeof(int));

    copyArray(original, copy, n);

    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);

    quickSort(copy, 0, n - 1);

    clock_gettime(CLOCK_MONOTONIC, &end);

    printf("%-15s : %.3f ms\n", "Quick Sort",
           getTimeInMilliseconds(start, end));

    free(copy);
}

void testMergeSort(int original[], int n)
{
    int *copy = (int *)malloc(n * sizeof(int));

    copyArray(original, copy, n);

    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);

    mergeSort(copy, 0, n - 1);

    clock_gettime(CLOCK_MONOTONIC, &end);

    printf("%-15s : %.3f ms\n", "Merge Sort",
           getTimeInMilliseconds(start, end));

    free(copy);
}

int main()
{
    srand(time(NULL));

    int sizes[] = {8000, 12000, 16000, 20000,
                   24000, 28000, 32000, 36000};

    int totalSizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int s = 0; s < totalSizes; s++)
    {
        int n = sizes[s];

        int *original = (int *)malloc(n * sizeof(int));

        printf("\n===========================================\n");
        printf("Array Size : %d\n", n);
        printf("===========================================\n");

        // ---------------- RANDOM ----------------

        printf("\nRandom Array\n");

        generateRandom(original, n);

        testSimpleSort("Bubble Sort", bubbleSort, original, n);
        testSimpleSort("Insertion Sort", insertionSort, original, n);
        testSimpleSort("Selection Sort", selectionSort, original, n);
        testMergeSort(original, n);
        testQuickSort(original, n);
        testSimpleSort("Heap Sort", heapSort, original, n);

        // ---------------- ASCENDING ----------------

        printf("\nAscending Array\n");

        generateAscending(original, n);

        testSimpleSort("Bubble Sort", bubbleSort, original, n);
        testSimpleSort("Insertion Sort", insertionSort, original, n);
        testSimpleSort("Selection Sort", selectionSort, original, n);
        testMergeSort(original, n);
        testQuickSort(original, n);
        testSimpleSort("Heap Sort", heapSort, original, n);

        // ---------------- DESCENDING ----------------

        printf("\nDescending Array\n");

        generateDescending(original, n);

        testSimpleSort("Bubble Sort", bubbleSort, original, n);
        testSimpleSort("Insertion Sort", insertionSort, original, n);
        testSimpleSort("Selection Sort", selectionSort, original, n);
        testMergeSort(original, n);
        testQuickSort(original, n);
        testSimpleSort("Heap Sort", heapSort, original, n);

        free(original);
    }

    return 0;
}
