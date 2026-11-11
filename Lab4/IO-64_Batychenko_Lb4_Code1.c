#include <stdio.h>

#define size_m 8
#define size_n 9

int search_num( int n, double a[size_m][size_n], double x, double *res, int *res_id){
    int L=0, R=size_m-1, looked, find=0;
    while (L<=R){
        looked=(L+R)/2;
        if(a[looked][n]==x){
            *res=a[looked][n];
            *res_id=looked;
            find=1;
            R=looked-1;
        }
        else if (a[looked][n]<x){
            R=looked-1;
        }else{
            L=looked+1;
        }
    }
    if(find==0){return 0;}
    return 1;
}

int main(){
    // n-рядок; m-стовбець
    int result_id, not_found, glob_nfound=0;
    double result, matrix[size_m][size_n] = {
    {98.5,  88.1,  75.0,  62.4,  50.0,  41.2,  33.0,  20.5,  15.0},
    {91.2,  88.1,  70.2,  60.0,  48.3,  41.2,  30.7,  20.5,  12.3},
    {85.0,  79.3,  64.5,  55.1,  42.0,  35.8,  27.4,  18.0,  10.1},
    {73.4,  70.0,  58.9,  55.1,  39.5,  30.0,  22.0,  14.2,   5.5},
    {62.1,  61.5,  50.0,  43.2,  30.7,  25.4,  18.5,  10.0,   5.5},
    {50.0,  55.0,  42.3,  35.0,  25.0,  20.0,  15.0,   7.3,   5.5},
    {30.7,  40.2,  31.1,  22.8,  18.4,  14.1,  10.2,   5.0,   5.5},
    {21.0,  25.0,  19.5,  10.5,   9.2,   8.0,   4.5,   1.1,   0.2}
    };
    double search;

    printf("Matrix A[m,n]:\n");
    for(int i=0; i<size_m; i++){
        for(int j=0; j<size_n; j++){
            printf("%.1lf\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Enter decimal number in matrix: ");
    scanf("%lf", &search);

    for (int m = 0; m<size_n; m++)
    {
        not_found=search_num(m, matrix, search, &result, &result_id);

        if(not_found==1){
            // Координати матриці вивожу у математичному вигляді, починаючи з 1, 2, 3,...
            printf("A[%i][%d] = %.1lf;\n", result_id+1 ,m+1, result);
            glob_nfound=1;
        }
    }
    if(glob_nfound==0){printf("Not found");}
    return 0;
}