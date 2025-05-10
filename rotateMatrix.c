//C program to rotate a matrix 90deg clockwise.

#include <stdio.h>
#include <stdlib.h>

void printMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int val,val1,i0,i,j,count,im=0,jm=0,ord=*matrixColSize;
    while(ord>1){
        i=im;j=jm;count=0;
        val=matrix[i][j];
        while(count<((ord*ord)-((ord-2)*(ord-2)))){
            i0=i;i=j;
            j=((*matrixColSize-1)*(i0+1))%(*matrixColSize);
            val1=matrix[i][j];
            matrix[i][j]=val;
            val=val1;
            count++;
            if(count>0 && i==im && j==jm){
                val=matrix[i][++j];
                jm=j;
            }
        }
        im+=1;jm-=ord-1;jm+=1;
        ord-=2;
    }
}
int main() {
    int size;
    printf("Enter matrix size (NxN): ");
    scanf("%d", &size);

    // Allocate memory for the matrix
    int** matrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int*)malloc(size * sizeof(int));
    }
    // Input matrix elements
    printf("Enter matrix elements:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nOriginal Matrix:\n");
    printMatrix(matrix, size);

    // Rotate the matrix
    rotate(matrix, size, &size);

    printf("Rotated Matrix:\n");
    printMatrix(matrix, size);

    // Free allocated memory
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}