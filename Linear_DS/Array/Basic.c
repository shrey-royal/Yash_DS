#include<stdio.h>
/*
void main() {
    //Array Declaration
    //1st way
    // int arr[5];
    //2nd way
    int arr[5] = {0};

    //Array Initialization
    int arr1[5] = {1, 2, 3, 4, 5};
    //2nd way
    int arr2[] = {1, 2, 3, 4, 5};
    //3rd way
    int arr3[5];
    arr3[0] = 1;
    arr3[1] = 2;
    arr3[2] = 3;
    arr3[3] = 4;
    arr3[4] = 5;

    //Accessing Array Elements
    //1st way
    // printf("%d\n", arr1[0]);
    //2nd way
    // printf("%d\n", 0[arr1]);
    //3rd way
    // printf("%d\n", *(arr1 + 0));
    //4th way
    // int *ptr = arr1;
    // printf("%d\n", ptr[0]);

    //Array Traversal
    //1st way
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

}
*/

/*
Types of Arrays:
1. One Dimensional Array
2. Multi Dimensional Array

1. One Dimensional Array: array_name [size];
2. Multi Dimensional Array: 
    1. 2D Array: array_name [row_size][column_size];
    2. 3D Array: array_name [row_size][column_size][depth_size];
    3. nD Array: array_name [row_size][column_size][depth_size]...[n_size];
*/

// 1D Array
void main() {
    // 1d array declaration
    int arr[5];
 
    // 1d array initialization using for loop
    for (int i = 0; i < 5; i++) {
        arr[i] = i * i - 2 * i + 1;
    }
 
    printf("Elements of Array: ");
    // printing 1d array by traversing using for loop
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // creating array of character
    char arr1[6] = { 'R', 'o', 'y', 'a', 'l', '\0' };
 
    // printing string
    int i = 0;
    while (arr1[i]) {
        printf("%c", arr1[i++]);
    }
}