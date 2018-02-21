#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float i, j;
    int r=15;

    for(i=r;i>=0;i--){
        printf("\n\t\t");
        for(j=r;j>=0;j-=0.5){
            if(round(sqrt(i*i+j*j))==r)
                printf("*");
            else if(i==j)
                printf("**");
            else
                printf(" ");
        }
        for(j=0;j<=r;j+=0.5){
            if(round(sqrt(i*i+j*j))==r)
                printf("*");
            else if(i==j)
                printf("**");
            else
                printf(" ");
        }
    }
    for(i=0;i<=r;i++){
        printf("\n\t\t");
        for(j=r;j>=0;j-=0.5){
            if(round(sqrt(i*i+j*j))==r)
                printf("*");
            else if(i==j)
                printf("**");
            else
                printf(" ");
        }
        for(j=0;j<=r;j+=0.5){
            if(round(sqrt(i*i+j*j))==r)
                printf("*");
            else if(i==j)
                printf("**");
            else
                printf(" ");
        }
    }
    puts("\n\n");
}
