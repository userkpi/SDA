#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // count
    int k_sum=0, k_mins=0, k_mult=0, k_trans=0, k_comp=0, k_assign=0, k_lib=0; 

    double x, y, P = 1, intermediate, C_cos;
    /* count */ k_assign++;

    int n, sign;

    printf("Enter x: ");
    /* count */ k_lib++;

    scanf("%lf", &x);
    /* count */ k_lib++;

    printf("Enter n: ");
    /* count */k_lib++;

    scanf("%i", &n);
    /* count */ k_lib++;

    if (x == 0)
    {
        printf("cos(x) = 1");
        /* count */ k_lib++;

        return 0;
    }
    /* count */ k_comp++;

    y = M_PI * (n + 1);
    /* count */ k_assign++; k_mult++; k_sum++;

    for (int i = -n; i <= n; i++)
    {
        /* count */ k_assign++; k_sum++; k_comp++;

        sign = copysign(1.0, i);
        /* count */ k_lib++; k_assign++; k_trans++;
        

        if (i == 0)
        {
            y = 0;
            /* count */ k_assign++; k_trans++; k_comp++;
        }
        else if (i < 0)
        {
            y -= M_PI;
            /* count */ k_assign++; k_mins++; k_trans++; k_comp=k_comp+2;
        }
        else
        {
            y += M_PI;
            /* count */ k_assign++; k_sum++; k_trans++; k_comp=k_comp+2;
        }

        intermediate = (2 * x - sign * y) / (x + sign * y);
        /* count */ k_assign++; k_trans++; k_mult=k_mult+3; k_sum++; k_mins++;

        P = P * intermediate;
        /* count */ k_assign++; k_trans++; k_mult++;
    }
    P = 0.5 * P;
    /* count */ k_assign++; k_trans++; k_mult++;

    C_cos=cos(x);    
    printf("\nP = %.7lf;\nFunction from a library(C_cos) = %.7lf\nDelta = %.7lf\n", P, C_cos, P-C_cos);
    /* count */ k_lib=k_lib+2;
    
    /* count */
    printf("k_sum=%i ", k_sum);
    printf("k_mins=%i ", k_mins);
    printf("k_mult=%i ", k_mult);
    printf("k_trans=%i ", k_trans);
    printf("k_comp=%i ", k_comp);
    printf("k_assign=%i ", k_assign);
    printf("k_lib=%i \n", k_lib);
    printf("Number of operations = %i\n", k_sum+k_mins+k_mult+k_trans+k_comp+k_assign+k_lib);

    return 0;
}