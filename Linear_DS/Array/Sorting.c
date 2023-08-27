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
void display(int A[], int n);                       // display Array
void swap(int *x, int *y);                          // helper function for Bubble Sort
void bubbleSort(int A[], int n);                    // Bubble Sort
void selectionSort(int A[], int n);                 // Selection Sort
void insertionSort(int A[], int n);                 // Insertion Sort
void merge(int A[], int low, int mid, int high);    // helper function for merge Sort
void mergeSort(int A[], int low, int high);         // Sort Array using merge Sort
// int partition(int A[], int low, int high);          // helper function for Quick Sort
// void quickSort(int A[], int low, int high);         // Sort Array using Quick Sort
// void swap(int *x, int *y);                          // helper function for Heap Sort
// void heapify(int A[], int n, int i);                // helper function for Heap Sort
// void heapSort(int A[], int n);                      // Sort Array using Heap Sort

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
    display(A, n);

    printf("Following are the Sorting Techniques:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. merge Sort\n");
    printf("5. Quick Sort\n");
    printf("6. Heap Sort\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            bubbleSort(A, n);
            break;
        case 2:
            selectionSort(A, n);
            break;
        case 3:
            insertionSort(A, n);
            break;
        case 4:
            mergeSort(A, 0, n - 1);
            break;
        case 5:
            // quickSort(A, 0, n - 1);
            break;
        case 6:
            // heapSort(A, n);
            break;
        default:
            printf("Invalid Choice\n");
    }

    printf("Array after Sorting: ");
    display(A, n);
    return 0;
}

// display Array
void display(int A[], int n) {
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
void bubbleSort(int A[], int n) {
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
            // display(A, n);
        }
        if(flag == 0) {
            break;
        }
    }
}

// Selection Sort : In selection sort it takes n-1 passes to sort the array
void selectionSort(int A[], int n) {
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
void insertionSort(int A[], int n) {
    int i, j, x;
    for(i = 1; i < n; i++) {
        j = i - 1;
        x = A[i];
        // printf("Pass %d: ", i);
        // display(A, n);
        while(j > -1 && A[j] > x) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

// helper function for merge Sort
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;     // size of left subarray
    int n2 = r - m;         // size of right subarray

    // create temp arrays
    int L[n1], R[n2];

    // copy data to temp arrays L[] and R[]
    for(i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for(j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // merge the temp arrays back into arr[l..r]
    i = 0;      // initial index of first subarray
    j = 0;      // initial index of second subarray
    k = l;      // initial index of merged subarray

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];  // if L[i] is smaller than or equal to R[j] then copy L[i] to arr[k]
            i++;
        }
        else {
            arr[k] = R[j];  // if R[j] is smaller than L[i] then copy R[j] to arr[k]
            j++;
        }
        k++;
    }

    // copy the remaining elements of L[], if there are any
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // copy the remaining elements of R[], if there are any
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Sort Array using merge Sort
void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;

        // sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);    // merge the sorted halves
    }
}