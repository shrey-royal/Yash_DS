#include<stdio.h>
#include<stdlib.h>

int linearSearch(int[], int, int);
int binarySearch(int[], int, int);
int sortArray(int[], int);

int main() {
    int n, key;

    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n]; // array declaration

    printf("Printing the array: { ");
    for(int i=0; i<n; i++) {
        arr[i] = rand() % 100;
        printf("%d, ", arr[i]);
    }
    printf("\b\b }\n");

    printf("Enter the key to search: ");
    scanf("%d", &key);

    //linear search
    int linearIndex = linearSearch(arr, n, key);
    
    if(linearIndex == -1) {
        printf("Key not found in array\n");
    }
    else {
        printf("Key found at index %d\n", linearIndex);
    }

    //binary search
    int binaryIndex = binarySearch(arr, n, key);

    if(binaryIndex == -1) {
        printf("Key not found in array\n");
    }
    else {
        printf("Key found at index %d\n", binaryIndex);
    }

    return 0;
}

int linearSearch(int arr[], int n, int key) {   //O(n)
    for(int i=0; i<n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int sortArray(int arr[], int n) {   //O(n^2)
    int temp;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] > arr[j]) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int n, int key) {   //O(log n)
    int low = 0, high = n-1, mid;
    sortArray(arr, n);
    while(low <= high) {
        mid = (low + high) / 2;
        if(arr[mid] == key) {
            return mid;
        }
        else if(arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}



/*
There are two types of searching in array:
1. Linear Search: O(n)
2. Binary Search: O(log n)

*/