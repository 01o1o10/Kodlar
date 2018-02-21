#include <stdio.h>

    int a, b, c, d=0;
    char *cumle;
    char *aranan;
    char *yeni;

int karakter_sayisi(char *s)
{
    int i;
    for(i=0;s[i]!='\n';i++){}
        return i;
}

void degistir(char *cumle, char *yeni, int yer)
{
    char *temp;
    int i, j;

    for(i=0;i<a-yer-b;i++)
        temp[i]=cumle[yer+b+i];
    for(j=0;j<c;j++)
        cumle[yer+j]=yeni[j];
    for(j=0;j<i;j++)
        cumle[yer+c+j]=temp[j];
    cumle[yer+c+j]='\0';
    d=1;
}

int bul(char *cumle, char *aranan)
{
    int i, j;

    for(i=0;i<a;i++){
        for ( j=0; cumle[i+j]==aranan[j] && j<b ; j++ ){ }
        if( j==b ) degistir(cumle, yeni, i);
    }
}

int main()
{
    printf("Bir cumle girin: ");
    fgets(cumle, 1000000, stdin);
    printf("Aranacak kelimeyi irin: ");
    fgets(aranan, 1000000, stdin);
    printf("Yeni kelimeyi girin: ");
    fgets(yeni, 1000000, stdin);

    a=karakter_sayisi(cumle);
    b=karakter_sayisi(aranan);
    c=karakter_sayisi(yeni);

    bul(cumle, aranan);
    if(d==0)
        printf("Aradiginiz kelime bu cumlede yok.\n");
    else{
        printf("Degistirilmis cumle: ");
        puts(cumle);}

    return 0;
}
