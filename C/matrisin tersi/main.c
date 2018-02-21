#include <stdio.h>
#include <stdlib.h>

int boyut;

void matrisin_tersi(float matris[10][10]);

int main()
{
    float matris[10][10];
    printf("\nMatrisin boyutunu belirleyiniz: ");
    scanf("%d", &boyut);

    printf("\nMatris elemanlarini giriniz: \n");
    int i, j;
    for(i = 0; i < boyut; i++){
        for(j = 0; j < boyut; j++){
            scanf("%f", &matris[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < boyut; i++){
        for(j = 0; j < boyut; j++){
            printf("%f  ", matris[i][j]);
        }
        printf("\n");
    }

    matrisin_tersi(matris);

    return 0;

}

void matrisin_tersi(float matris[10][10])
{
    int sutun, satir;
    float gecici;
    int sayac1, i, j;
    float gecici_dizi[10];
    float birim_matris[10][10]={{1,0,0,0,0,0,0,0,0,0},
                              {0,1,0,0,0,0,0,0,0,0},
                              {0,0,1,0,0,0,0,0,0,0},
                              {0,0,0,1,0,0,0,0,0,0},
                              {0,0,0,0,1,0,0,0,0,0},
                              {0,0,0,0,0,1,0,0,0,0},
                              {0,0,0,0,0,0,1,0,0,0},
                              {0,0,0,0,0,0,0,1,0,0},
                              {0,0,0,0,0,0,0,0,1,0},
                              {0,0,0,0,0,0,0,0,0,1},};

    for(sutun = 0;  sutun < boyut; sutun++){
        for(satir = boyut-1; satir >= 0; satir--){
            printf("\n[%f][%f] eleman için\n", satir, sutun);
            if(satir != sutun){
                gecici = matris[satir][sutun]/matris[sutun][sutun];
                printf("\n gecici degiskenine atanan deger: %f", gecici);
                printf("\n gecici_m-dizi elemanlari: ");
                for(sayac1 = 0; sayac1 < boyut; sayac1 ++){
                    gecici_dizi[sayac1] = gecici*matris[sutun][sayac1];
                    printf("%f  ", gecici_dizi[sayac1]);
                }
                for(sayac1 = 0; sayac1 < boyut; sayac1++){
                    matris[satir][sayac1] = matris[satir][sayac1]-gecici_dizi[sayac1];
                }
                    printf("\n matrisin satiri guncellendikten sonraki hali: \n");
                    for(i = 0; i < boyut; i++){
                        for(j = 0; j < boyut; j++){
                            printf("%f  ", matris[i][j]);
                        }
                        printf("||");
                        for(j = 0; j < boyut; j++){
                            printf("%f  ", birim_matris[i][j]);
                        }
                        printf("\n");
                    }

                printf("\n gecici_m-dizi elemanlari: ");
                for(sayac1 = 0; sayac1 < boyut; sayac1 ++){
                    gecici_dizi[sayac1] = gecici*birim_matris[sutun][sayac1];
                    printf("%f  ", gecici_dizi[sayac1]);
                }
                for(sayac1 = 0; sayac1 < boyut; sayac1++){
                    birim_matris[satir][sayac1] = birim_matris[satir][sayac1]-gecici_dizi[sayac1];
                }
                    printf("\n birim_matrisin satiri guncellendikten sonraki hali: \n");
                    for(i = 0; i < boyut; i++){
                        for(j = 0; j < boyut; j++){
                            printf("%f  ", matris[i][j]);
                        }
                        printf("||");
                        for(j = 0; j < boyut; j++){
                            printf("%f  ", birim_matris[i][j]);
                        }
                        printf("\n");
                    }
            }
            else{
                gecici = matris[sutun][sutun];
                for(sayac1 = 0; sayac1 < boyut; sayac1++){
                    matris[satir][sayac1] = matris[satir][sayac1]/gecici;
                }
                for(sayac1 = 0; sayac1 < boyut; sayac1++){
                    birim_matris[satir][sayac1] = birim_matris[satir][sayac1]/gecici;
                }
                    printf("\n matrisin ve birim_matrisin satiri guncellendikten sonraki hali: \n");
                    for(i = 0; i < boyut; i++){
                        for(j = 0; j < boyut; j++){
                            printf("%f  ", matris[i][j]);
                        }
                        printf("||");
                        for(j = 0; j < boyut; j++){
                            printf("%f  ", birim_matris[i][j]);
                        }
                        printf("\n");
                    }
            }
        }
    }

    printf("\n\n Sonuccccc : \n\n");

    for(satir = 0; satir < boyut; satir++){
        for(sutun = 0; sutun < boyut; sutun++){
            printf("%f  ", birim_matris[satir][sutun]);
        }
        printf("\n");
    }
}
