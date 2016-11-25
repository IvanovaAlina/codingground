#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
double * readMatrix(char *filename) {
	FILE * fo;
	fo = fopen(filename,"r+");
	if (!fo) {
		printf("Ошибка чтения файла\n");
		return 0;
	}
	else {
		int i, m, n;
		char c;
		fscanf(fo, "%d,%d\n", &m, &n);
		double * matrix;
		matrix = (double*) malloc((m * n + 2) * sizeof(double));
		matrix += 2;
		matrix[-2] = m;
		matrix[-1] = n;
		for (i = 0; i <= m*n; i++) {
			fscanf(fo, "%lf%c", &matrix[i],&c);
			if(c == '\n'){
			    fprintf(fo,"\n");
			}
		}
		fclose(fo);
		printf("1\n");
		return matrix;
	}
}
double * createMatrix(char *str) { 
    double *matrix; 
    int i; 
    int m = 1; 
    int n = 1; 
    for (i = 0; i < strlen(str) - 1; i++) { 
        if (str[i] == ';') m++; 
        if ((str[i] == ',') && (m == 1)) n++; 
    } 
    matrix = (double*) malloc((m * n + 2)*sizeof(double)); 
    matrix[-2] = m; 
    matrix[-1] = n; 
    int len = (int) (strlen(str) - m - n + 1) / (m * n); 
    int counter = 0; 
    int j; 
    char num[len]; 
    for (i = 0; i < strlen(str); i += len + 1) { 
        for (j = 0; j < len; j++) { 
            num[j] = str[i + j]; 
        } 
        matrix[counter] = atof(num); 
        counter++; 
    } 
    printf("2\n");
    return matrix; 
}
double * zeroMatrix(unsigned int m, unsigned int n){
 	double * matrix;
 	int i;
    matrix = (double*) malloc((m * n + 2) * sizeof(double));
    matrix += 2;
    matrix[-2] = m;
    matrix[-1] = n;
    for (i = 0; i < m*n; i++) {
        matrix[i]=0;
    }
    printf("3\n");
    return matrix;
}
double * oneMatrix(unsigned int m, unsigned int n){
    double * matrix;
 	int i;
    matrix = (double*) malloc((m * n + 2) * sizeof(double));
    matrix += 2;
    matrix[-2] = m;
    matrix[-1] = n;
    for (i = 0; i < m*n; i++) {
        matrix[i]=1;
    }
    printf("4\n");
    return matrix;
}
double * eyeMatrix(unsigned int k){
    double **arr;
	arr = (double**) malloc((k*k) * sizeof(double*));
	int i,j;
	for (i=0;i<=k;i++){
	    arr[i]=(double*) malloc(k * sizeof(double));
        for (i=0;i<=k;i++){
            if (i==j) arr[i][j]=1;
            else arr[i][j]=0;
        }
	}
	int h=0;
    double * matrix;
    matrix = (double*) malloc((k * k + 1) * sizeof(double));
    matrix += 1;
    matrix[-1] = k;
    for (i=0; i<=k*k;i++) {
        for (j=0;j<=k;j++){
            matrix[h]=arr[i][j];
            h++;
        }
    }
    printf("5\n");
    //return matrix;
    return 0;
}
/*double * elemIndex(unsigned int i, unsigned int j, unsigned int n, unsigned int m ){
	int ind1=0,ind,a,b;
	for (a=0;a<=m;a++){
		for(b=0;b<=n;b++){
			ind1++;
			if((a==i)&&(b==j)){
				ind=ind1;
			}
		}
	}
	return ind;
}*/
void printMatrix(double * matrix){
    int i,j,k=0;
    double **arr;
	arr = (double**) malloc((matrix[-2]*matrix[-1]) * sizeof(double*));
    for (i=0;i<=matrix[-2];i++){
	    arr[i]=(double*) malloc(matrix[-2] * sizeof(double));
        for (j=0;j<=matrix[-1];j++){
            arr[i][j]=matrix[k];
            k++;
        }
    }
    for (i=0;i<=matrix[-2];i++){
        for (j=0;j<=matrix[-1];j++){
            printf("%lf ",&arr[i][j]);
        }
    }
}
/*int saveMatrix(double * matrix, char * filename){
	FILE *file;
	int i,j,flag=0;
	file=fopen(*filename, "r");
	double **arr;
	arr=(double**)malloc(a*sizeoff(double*));
	int i,j, k=0;
	for (i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			arr[i][j]=matrix[k];
			k++;
		}
	}

	if(!file) printf("%d\n","r");
	else{
	fprintf("%d,%d\n", m, n);
	for (i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			fprinf("%lf",a[i][j]);
		}
	fprintf("\n");
	flag=1;
	}
	fclose(file);
	printf("%d",flag);
}
int getRowsNum(double * matrix){

}
int getColumnsNum(double * matrix){
	int n=1;
}
double * tranposeMatrix(double * matrix){
	getRowsNum(*matrix);
	getColumnsNum(*matrix);
	double *arr;
	arr=(double**)malloc(a*sizeoff(double*));
	int i,j,k=0;
	double *arr1;
	arr=(double**)malloc(a*sizeoff(double*));
	for (i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			arr[i][j]=matrix[k];
			k++;
		}
	}
	k=0;
	int i1=0,j1=0;
	for(j=0;j<=n;j++){
		for (i=0;i<=m;i++){
			arr1[i1][j1]=arr[i][j];
			i1++;
		}
		j1++;
	}
	for (i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			matrix[k]=arr1[i][j];
			k++;
		}
	}
}
double * multiplyByNumber(double * matrix, double num){
	getRowsNum(*matrix);
	getColumnsNum(*matrix);
	int i,k;
	k=m*n;
	for(i=0;i<=k;i++){
		matrix[i]=num*matrix[i];
	}
}
double * multiplyByMatrix(double * matrix1, double * matrix2){
	getRowsNum(*matrix1);
	getColumnsNum(*matrix1);
	int m1=m, n1=n;
	getRowsNum(*matrix);
	getColumnsNum(*matrix);
	if((m==m1) or (n==n1)) printf("Ошибка");
	else{
		int i,j,k=0;
		double **arr1;
		arr1=(double**)malloc(a*sizeoff(double*));
		for(i=0;i<=m;i++){
			for(j=0;j<=n;j++){
				arr[i][j]=matrix1[k];
				k++;
			}
		}
		k=0;
		double **arr2;
		arr2=(double**)malloc(a*sizeoff(double*));
		for(i=0;i<=m;i++){
			for(j=0;j<=n;j++){
				arr[i][j]=matrix2[k];
				k++;
			}
		}
		k=0;
		int i1,j1, i2=0,j2=0;
		double **arr3;
		arr3=(double**)malloc(a*sizeoff(double*));
		for(i=0;i<=m;i++){
			for(j=0;j<=n;j++){
					arr3[i][j]=arr3[i][j]+arr1[i1][j1]*arr2[i2][j2];
					i2++;
					}
				j2++;
				}
			}
		}
		double **matrix;
		matrix=(double**)malloc(a*sizeoff(double*));
		for(i=0;i<=m;i++){
			for(j=0;j<=n;j++){
				matrix[k]=arr[i][j];
				k++;
			}
		}
	}
}
double * addMatrix(double * matrix1, double * matrix2){
	getRowsNum(*matrix1);
	getColumnsNum(*matrix1);
	int m1=m, n1=n;
	getRowsNum(*matrix);
	getColumnsNum(*matrix);
	if((m==m1) or (n==n1)) printf("Ошибка");
	else{
		int i,j,k=0;
		double **arr1;
		arr1=(double**)malloc(a*sizeoff(double*));
		for(i=0;i<=m;i++){
			for(j=0;j<=n;j++){
				arr[i][j]=matrix1[k];
				k++;
			}
		}
		k=0;
		double **arr2;
		arr2=(double**)malloc(a*sizeoff(double*));
		for(i=0;i<=m;i++){
			for(j=0;j<=n;j++){
				arr[i][j]=matrix2[k];
				k++;
			}
		}
		for(i=0;i<=m;i++){
			for(j=0;j<=n;j++){
				arr1[i][j]=arr1[i][j]+arr2[i][j];
			}
		}
	}
}
double * powMatrix(double * matrix, unsigned int degree){
	int i;
	for(i=0;i<=degree;i++){
		multiplyByMatrix(*matrix,*matrix);
	}
}
*/