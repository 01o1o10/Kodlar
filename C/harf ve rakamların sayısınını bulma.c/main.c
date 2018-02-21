#include <stdio.h>

int main()
{
    char *yazi;

    printf("Bir metin giriniz: ");
    fgets(yazi, 1000000, stdin);

    int i, sayi=0, buyuk_harf=0, kucuk_harf=0, bosluk=0;

    for(i=0;yazi[i]!='\n';i++){
        if(yazi[i]>47 && yazi[i]<58)
            sayi++;
        if(yazi[i]>64 && yazi[i]<91)
            buyuk_harf++;
        if(yazi[i]>96 && yazi[i]<123)
            kucuk_harf++;
        if(yazi[i]==32)
            bosluk++;
    }

    printf("\nYazida:\n%d sayi", sayi)   ;
    printf("\n%d buyuk harf", buyuk_harf);
    printf("\n%d kucuk harf", kucuk_harf);
    printf("\n%d bosluk var.", bosluk);

    return 0;
}
