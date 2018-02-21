#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <windows.h>

///Global Degiskenler///
int degisken_sayisi;
int satir_sayisi;
int siradaki_sutun;

///Fonksiyonlar///
void yazdir(int tablo[][128]);
int** tablo_olustur();
int** ve(int tablo[30][128]);
int** veya(int tablo[30][128]);
int** ozel_veya(int tablo[30][128]);
int** degil(int tablo[30][128]);
int** ise(int tablo[30][128]);

///Main Fonksiyonu///
int main()
{
    printf("Degisken sayisi girniz: ");
    scanf("%d", &degisken_sayisi);

    siradaki_sutun = degisken_sayisi;
    satir_sayisi = pow(2, degisken_sayisi);

    int **tablo;

    tablo = tablo_olustur();

    int secim;
    while(_getch() != 27){
        system("cls");
        printf("[0] - Tabloyu yazdir");
        printf("\n[1] - VE islemi");
        printf("\n[2] - VEYA islemi");
        printf("\n[3] - OZEL VEYA islemi");
        printf("\n[4] - DEGIL islemi");
        printf("\n[5] - ISE islemi");
        printf("\nBir islem seciniz: ");
        scanf("%d", &secim);

        switch(secim){
            case 0: yazdir(tablo); break;
            case 1: ve(tablo); break;
            case 2: veya(tablo); break;
            case 3: ozel_veya(tablo); break;
            case 4: degil(tablo); break;
            case 5: ise(tablo); break;
        }
        printf("\n\nBir islem seciniz: ");
        printf("\n[ESC] - Programi kapat");
        printf("\n[Diger Tuslar] - Ana Menu");
    }

    return 0;

}

void yazdir(int tablo[30][128])
{
    int i,j;

    for(i = 0; i < siradaki_sutun; i++){
        printf(" [%d]", i);
    }
    printf("\n");

    for(i = 0; i < satir_sayisi; i++){
        printf("\n|");
        for(j = 0; j < siradaki_sutun; j++){
            printf(" %d |", tablo[j][i]);
        }
    }
}

int** tablo_olustur()
{
    int tablo[30][128];

    printf("\nTablo baslangic degerleri olusturuluyor...");

    int i, j;
    for(i = 0; i < degisken_sayisi; i++){
        for(j = 0; j < satir_sayisi; j++){
            if(i == 0 && j<satir_sayisi/2){
                tablo[0][j] = 0;
            }
            else if(i == 0){
                tablo[0][j] = 1;
            }
            else if(i == 1 && j%(satir_sayisi/2) < satir_sayisi/4){
                tablo[1][j] = 0;
            }
            else if(i == 1){
                tablo[1][j] = 1;
            }
            else if(i == 2 && j%(satir_sayisi/4)<satir_sayisi/8){
                tablo[2][j] = 0;
            }
            else if(i == 2){
                tablo[2][j] = 1;
            }
            else if(i == 3 && j%(satir_sayisi/8)<satir_sayisi/16){
                tablo[3][j] = 0;
            }
            else if(i == 3){
                tablo[3][j] = 1;
            }
        }
    }

    printf("\nTablo baslangic degerleri olusturuldu.\n\n");

    return tablo;
}

int** ve(int tablo[30][128])
{
    yazdir(tablo);

    int a,b;
    printf("\n\nHangi sutunlari isleme sokmak istiyorsunuz: ");
    scanf("%d %d", &a, &b);

    int i;
    for(i = 0; i < satir_sayisi; i++){
        if(tablo[a][i] == 1 && tablo[b][i] == 1){
            tablo[siradaki_sutun][i] = 1;
        }
        else{
            tablo[siradaki_sutun][i] = 0;
        }
    }
    printf("\nVE islemi tamamlandi.");
    siradaki_sutun++;

    return tablo;
}

int** veya(int tablo[30][128])
{
    yazdir(tablo);

    int a,b;
    printf("\n\nHangi sutunlari isleme sokmak istiyorsunuz: ");
    scanf("%d %d", &a, &b);

    int i;
    for(i = 0; i < satir_sayisi; i++){
        if(tablo[a][i] == 0 && tablo[b][i] == 0){
            tablo[siradaki_sutun][i] = 0;
        }
        else{
            tablo[siradaki_sutun][i] = 1;
        }
    }
    printf("\nVEYA islemi tamamlandi.");
    siradaki_sutun++;

    return tablo;
}

int** ozel_veya(int tablo[30][128])
{
    yazdir(tablo);

    int a,b;
    printf("\n\nHangi sutunlari isleme sokmak istiyorsunuz: ");
    scanf("%d %d", &a, &b);

    int i;
    for(i = 0; i < satir_sayisi; i++){
        if(tablo[a][i] == tablo[b][i]){
            tablo[siradaki_sutun][i] = 0;
        }
        else{
            tablo[siradaki_sutun][i] = 1;
        }
    }
    printf("\nOZEL VEYA islemi tamamlandi.");
    siradaki_sutun++;

    return tablo;
}

int** degil(int tablo[30][128])
{
    yazdir(tablo);

    int a;
    printf("\n\nHangi sutunu isleme sokmak istiyorsunuz: ");
    scanf("%d", &a);

    int i;
    for(i = 0; i < satir_sayisi; i++){
        if(tablo[a][i] == 1){
            tablo[siradaki_sutun][i] = 0;
        }
        else{
            tablo[siradaki_sutun][i] = 1;
        }
    }
    printf("\nDEGIL islemi tamamlandi.");
    siradaki_sutun++;

    return tablo;
}

int** ise(int tablo[30][128])
{
    yazdir(tablo);

    int a,b;
    printf("\n\nHangi sutunlari isleme sokmak istiyorsunuz: ");
    scanf("%d %d", &a, &b);

    int i;
    for(i = 0; i < satir_sayisi; i++){
        if(tablo[a][i] == 1 && tablo[b][i] == 0){
            tablo[siradaki_sutun][i] = 0;
        }
        else{
            tablo[siradaki_sutun][i] = 1;
        }
    }
    printf("\nISE islemi tamamlandi.");
    siradaki_sutun++;

    return tablo;
}
