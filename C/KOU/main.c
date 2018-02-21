#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float i, j, a;
    int b=1, n=10;

    a=90/n;
    printf("%f\n\n", a);

    for(i=0; b<=n; i+=a){
        for(j=0; j<round(10-sin(i)*10); j++)
            printf(" ");
        printf("*\n");
        b++;
    }
}
