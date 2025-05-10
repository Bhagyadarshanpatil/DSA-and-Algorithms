//C program to perform matrix multiplication using two loops,but it's pointless, yet different. Still, has a O(n^3) time complexity.

#include<stdio.h>
#include<stdlib.h>
int main() {
    int A[2][3]={{3,2,4},{6,5,3}};
    int col_A=sizeof(A[0])/sizeof(A[0][0]);
    int n=sizeof(A)/sizeof(A[0][0]);
    int B[3][2]={{5,3},{6,4},{2,8}};
    int col_B=sizeof(B[0])/sizeof(B[0][0]);
    int res[col_B][col_B];
    int i=0,j=0,k=0,l=0;
    for(int j1=0;j1<n;j1++){
        i=j1/col_A;
        j=j1%col_A;
        l=0;
        for(k=j;l<col_B;l++){
            if(j==0){
                (res[i][l])=A[i][j]*B[k][l];
            }
            else{
                (res[i][l])+=A[i][j]*B[k][l];
            }
        }
    }
    for(int i=0;i<col_B;i++){
        printf("\n");
        for (int j=0; j<col_B; j++)
            printf("%d ",res[i][j]);
    }
    return 0;
}