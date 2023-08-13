#include<stdio.h>

int main() {
    int row, column, depth;
    
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &column);
    printf("Enter the number of depth: ");
    scanf("%d", &depth);
    
    int arr[row][column][depth];
    
    for (int i = 0; i < row; i++) {
        printf("Enter the elements of row %d: \n", i + 1);
        for (int j = 0; j < column; j++) {
            printf("Enter the element %d: \n", j + 1);
            for (int k = 0; k < depth; k++) {
                printf("Enter the element %d: ", k + 1);
                scanf("%d", &arr[i][j][k]);
            }
        }
    }
    
    printf("The elements of the array are:\n");
    for (int i = 0; i < row; i++) {
        printf("The elements of row %d: \n", i + 1);
        for (int j = 0; j < column; j++) {
            printf("The elements of column %d: ", j + 1);
            for (int k = 0; k < depth; k++) {
                printf("%d ", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}