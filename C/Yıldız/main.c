#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i, j, k=0, n=40;

    for(i=1; i<=n; i++){
            printf("\n\t\t");
        if(i>2*n/5 && i<n*2/3-1){
            for(j=0; j<k; j++)
                printf(" ");
                k+=2;
            for(; j<n-i; j++)
                printf("*");
        }
        else
            for(j=0; j<n-i; j++)
                printf(" ");
        for(j=2; j<=2*i; j++)
            printf("*");
        if(i>2*n/5 && i<2*n/3-1)
            for(j=k-1; j<n-i; j++)
                printf("*");
    }
}
