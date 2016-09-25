#include <stdio.h>
#include <stdlib.h>
void main() { 
    int b[10]={0,1,2,3,4,5,6,7,8,9};
    printf ("b[1] = %d \n", b[1]);
    printf ("b[3] = %d \n", *(b+3));
    printf ("b[5] = %d \n", b[5]);
    printf ("b[7] = %d \n", *(b+7));
    printf ("b[9] = %d \n", b[9]);
}