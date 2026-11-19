#include <stdio.h>

#define size_m 8
#define size_n 9

void sort_no_increase(int a[size_m][size_n]){
    int C=0, R=0;
    for(int k=0; k<size_m; k++){        
        for(int i = 1; i < size_n; i++){            
            int T=a[k][i];
            /*count rearrange*/R++;
            int j = i;            
            while (j>0 && a[k][j-1]<T)
            {
                /*count compare*/C++;
                a[k][j]=a[k][j-1];
                /*count rearrange*/R++;
                j--;
            }
            if (j > 0) /*count compare*/C++;
            
            a[k][j]=T;
            /*count rearrange*/R++;
        }
    }
    printf("C=%i; R=%i;\n", C, R);
}

int main(){
    //n-рядок; m-стовбець
    
    // int matrix[size_m][size_n] = {
    // {50, 45, 33, 23, 18, 14,  7,  2,  1},
    // {64, 44, 42, 31, 28, 21, 19, 12,  5},
    // {49, 45, 37, 29, 22, 15, 12,  8,  3},
    // {41, 33, 26, 25, 18, 15, 10,  9,  4},
    // {40, 39, 31, 27, 22, 13, 11,  8,  6},
    // {48, 39, 36, 27, 24, 16, 11,  3,  2},
    // {42, 35, 29, 25, 19, 17, 14,  5,  1},
    // {48, 40, 38, 30, 24, 21, 20, 13,  7}
    // };

    // int matrix[size_m][size_n] = {
    //     {14, 7, 45,  2, 7, 33,  7, 50,  1},
    //     {42,  5, 19, 31, 28, 64, 12, 44, 21},
    //     { 8, 49, 37, 12, 22, 15, 45,  3, 29},
    //     {15, 26,  4, 41, 33,  9, 25, 18, 10},
    //     {39, 11, 22, 40,  6,  8, 31, 27, 13},
    //     { 3, 48, 16, 27, 39, 24,  2, 11, 36},
    //     {25, 29,  1, 19, 42, 14, 35,  5, 17},
    //     {38, 20, 13,  7, 21, 40, 48, 30, 24}
    // };

    int matrix[size_m][size_n] = {
    { 1,  2,  7, 14, 18, 23, 33, 45, 50},
    { 5, 12, 19, 21, 28, 31, 42, 44, 64},
    { 3,  8, 12, 15, 22, 29, 37, 45, 49},
    { 4,  9, 10, 15, 18, 25, 26, 33, 41},
    { 6,  8, 11, 13, 22, 27, 31, 39, 40},
    { 2,  3, 11, 16, 24, 27, 36, 39, 48},
    { 1,  5, 14, 17, 19, 25, 29, 35, 42},
    { 7, 13, 20, 21, 24, 30, 38, 40, 48}
    };


    
    printf("Matrix A[m,n]:\n");
    for(int i=0; i<size_m; i++){
        for(int j=0; j<size_n; j++){
            printf("%i\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    sort_no_increase(matrix);
    printf("\n");
    
    printf("Sorted matrix A[m,n]:\n");
    for(int i=0; i<size_m; i++){
        for(int j=0; j<size_n; j++){
            printf("%i\t", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}