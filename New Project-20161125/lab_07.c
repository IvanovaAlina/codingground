#include <stdio.h>
#include "xMatrix.h"
#include <stdlib.h>
void main(){
    readMatrix("file.txt");
    char str[20]={"1,2,3;4,5,6;7,8,9"};
    createMatrix(str);
    int n=3,m=3;
    double  * matrix4;
    matrix4 = malloc ((m * n + 2) * sizeof(double));
    matrix4 = zeroMatrix(m,n);
    double  * matrix5;
    matrix5 = malloc ((m * n + 2) * sizeof(double));
    matrix5 = oneMatrix(m,n);
    int k=3;
    double  * matrix1;
    matrix1 = malloc (11 * sizeof(double));
    matrix1 = eyeMatrix(k);
    int i=2, j=1,ind;
    ind=elemIndex(i,j,n,m);
    printf("%d\n",ind);
    double  * matrix;
    matrix = malloc ((m * n + 2) * sizeof(double));
    matrix[-2]=m;
    matrix[-1]=n;
    i=0;
    for (i=0;i<=m*n;i++){
        matrix[i]=i;
    }
    //printMatrix(matrix);
}