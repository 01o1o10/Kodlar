#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int boyut;

double determinant(int n, double matris[][boyut]);

int main()
{
    double det;

    printf("Matrisin boyutunu giriniz: ");
    scanf("%d", &boyut);

    double matris[boyut][boyut];

    printf("\nMatrisin elemanlarini giriniz: \n");

    int i, j;
    for(i = 0; i < boyut; i++){
        for(j = 0; j < boyut; j++){
            printf("Matrisin %d satir %d sutun elemanini giriniz: ", i, j);
            scanf("%lf", &matris[i][j]);
        }
        printf("\n");
    }

    printf("\nDeterminant Hesaplaniyor...\n");
    det = determinant(boyut, matris);
    printf("\nGirilen matrisin determinanti: %lf\n", det);

    return 0;
}

double determinant(int n, double matris[][boyut])
{
    int i, j, k;
    double temp[n-1][n-1];
    double det = 0;

    if(n == 1){
        return matris[0][0];
    }
    else if(n == 2){
        return (matris[0][0]*matris[1][1] - matris[0][1]*matris[1][0]);
    }
    else{
        for(k = 0; k < n; k++){
            for(i = 1; i < n; i++){
                for(j = 0; j < n; j++){
                    if(j < k){
                        temp[i-1][j] = matris[i][j];
                    }
                    if(j > k){
                        temp[i-1][j-1] = matris[i][j];
                    }
                }
            }
            det += (matris[0][k] * pow(-1, k) * determinant(n-1, temp));
        }
    }
    return det;
}
