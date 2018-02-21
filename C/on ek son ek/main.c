#include <stdio.h>

int karakter_sayisi(char *string)
{
    int i;
    for(i=0;string[i]!='\n';i++);
    return i;
}

int main()
{
    char kelime[100];
    char aranan[100];
    int i, j, onek=0, sonek=0, a, b;

    printf("\nBir kelime giriniz: ");
    fgets(kelime, 100, stdin);
    printf("\nAranan eki giriniz: ");
    fgets(aranan, 100, stdin);

    a=karakter_sayisi(kelime);
    b=karakter_sayisi(aranan);

    for(i=0;i<a;i++)
        for(j=0;kelime[i+j]==aranan[j] && j<b;j++){}
        if(j==b && i==0)
            onek++;
        if(j==b && i+j==a)
            sonek++;
        if(i==0 && j==a){
            printf("aramak istediğiniz ek kelimenin tamamı");
            return;
        }

    if(onek!=0)
        printf("\non ek");
    if(sonek!=0)
        printf("\nson ek");
    if(onek==0 && sonek==0)
        printf("\non ek veya son ek degildir.\n");

    return 0;
}
