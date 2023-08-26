/*
In Array, We can sort array using different types of methods:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
5. Quick Sort
6. Heap Sort

Time Complexity:
Name        Best        Average     Worst       Memory      Stable      Method Used
Bubble      n           n^2         n^2         1           Yes         Exchanging
Selection   n^2         n^2         n^2         1           No          Selection
Insertion   n           n^2         n^2         1           Yes         Insertion
Merge       nlog(n)     nlog(n)     nlog(n)     n           Yes         Merging
Quick       nlog(n)     nlog(n)     n^2         log(n)      No          Partitioning
Heap        nlog(n)     nlog(n)     nlog(n)     1           No          Selection
*/

#include<stdio.h>
#include<stdlib.h>

// Functions Prototype
void Display(int A[], int n);                       // Display Array
void swap(int *x, int *y);                          // helper function for Bubble Sort
void BubbleSort(int A[], int n);                    // Bubble Sort
void SelectionSort(int A[], int n);                 // Selection Sort
void InsertionSort(int A[], int n);                 // Insertion Sort
// void Merge(int A[], int low, int mid, int high);    // helper function for Merge Sort
// void MergeSort(int A[], int low, int high);         // Sort Array using Merge Sort
// int Partition(int A[], int low, int high);          // helper function for Quick Sort
// void QuickSort(int A[], int low, int high);         // Sort Array using Quick Sort
// void swap(int *x, int *y);                          // helper function for Heap Sort
// void Heapify(int A[], int n, int i);                // helper function for Heap Sort
// void HeapSort(int A[], int n);                      // Sort Array using Heap Sort

int main() {
    int *A;                                        // Pointer to Array
    int n;                                         

    printf("Enter the size of Array: ");
    scanf("%d", &n);

    A = (int *)malloc(n * sizeof(int));            // Dynamically Allocate Memory

    printf("Generating %d random Elements in the array...\n", n);
    for(int i = 0; i < n; i++) {
        A[i] = rand() % 100;                       // Generate Random Numbers
    }

    printf("Array before Sorting: ");
    Display(A, n);

    printf("Following are the Sorting Techniques:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("6. Heap Sort\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            BubbleSort(A, n);
            break;
        case 2:
            SelectionSort(A, n);
            break;
        case 3:
            InsertionSort(A, n);
            break;
        case 4:
            // MergeSort(A, 0, n - 1);
            break;
        case 5:
            // QuickSort(A, 0, n - 1);
            break;
        case 6:
            // HeapSort(A, n);
            break;
        default:
            printf("Invalid Choice\n");
    }

    printf("Array after Sorting: ");
    Display(A, n);
    return 0;
}

// Display Array
void Display(int A[], int n) {
    printf("Printing Array: { ");
    for(int i = 0; i < n; i++) {
        printf("%d, ", A[i]);
    }
    printf("\b\b }\n");
}

// helper function for Bubble Sort
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Bubble Sort : In bubble generally it takes n-1 passes to sort the array
void BubbleSort(int A[], int n) {
    int flag;
    for(int i = 0; i < n - 1; i++) {
        flag = 0;
        for(int j = 0; j < n - 1 - i; j++) {
            // print passes of bubble sort
            // printf("Pass %d: ", i + 1);
            if(A[j] > A[j + 1]) {
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
            // Display(A, n);
        }
        if(flag == 0) {
            break;
        }
    }
}

// Selection Sort : In selection sort it takes n-1 passes to sort the array
void SelectionSort(int A[], int n) {
    int i, j, k;
    for(i = 0; i < n - 1; i++) {
        // j=k=i means we are assuming that the first element is the smallest element
        for(j = k = i; j < n; j++) {
            // if we find any element smaller than the assumed smallest element then we will update the value of k
            if(A[j] < A[k]) {
                k = j;
            }
        }
        // printf("Pass %d: ", i + 1);
        // printf("Swapping %d and %d\n", A[i], A[k]);
        swap(&A[i], &A[k]);
    }
}

// Insertion Sort : In insertion sort it takes n-1 passes to sort the array
void InsertionSort(int A[], int n) {
    int i, j, x;
    for(i = 1; i < n; i++) {
        j = i - 1;
        x = A[i];
        // printf("Pass %d: ", i);
        // Display(A, n);
        while(j > -1 && A[j] > x) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}