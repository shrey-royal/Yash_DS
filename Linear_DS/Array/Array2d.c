/*
In 2d Array we have 2 dimensions i.e. rows and columns.
We can declare 2d array in 2 ways:
1. int arr[row_size][column_size];
2. int arr[row_size][column_size] = {0};
*/

#include <stdio.h>

int main() {

    int row, column;
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &column);

    int arr[row][column];

    for (int i = 0; i < row; i++) {
        printf("Enter the elements of row %d: ", i + 1);
        for (int j = 0; j < column; j++) {
            printf("Enter the element %d: ", j + 1);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("The elements of the array are:\n");
    for (int i = 0; i < row; i++) {
        printf("The elements of row %d: ", i + 1);
        for (int j = 0; j < column; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}