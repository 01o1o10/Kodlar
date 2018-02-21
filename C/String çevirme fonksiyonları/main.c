//String Cevirme Fonksiyonlarý

//atoi "string"in içeriðini "integer"a çevirrir.
//atol "string"in içeriðini "long"a çevirir.
//atof "string"in içeriðini "double"a çevirir.
//strtod(string, ptr) "string" stringinin içeriðini "double"a çevirir. Çevrilemeyen ilk karakterin adresini "ptr" isimli pointer'a atar.
//strtol(string, ptr) "string" stringinin içeriðini "long"a çevirir. Çevrilmeyen ilk karakterin adresini "ptr" isimli pointer'a atar.


#include <stdio.h>
#include <stdlib.h> //atoi, tof, atol gibi fonksiyonlar stdlib'de.

int main()
{
    char string[100];

    int x;
    long y;
    double z;

    //kucuk sayilarlarla ve 15-20 basamakli sayilarla test edin.
    //Sonra kesirli sayýlarla test edin.
    printf("Sayi girin: ");
    gets(string);

    x=atoi(string); //stringin içerigini integer' çevirir.
    y=atol(string); //stringin degerini long'a çevirir.
    z=atof(string); //string'in degerini double'a çevirir.

    printf("int= %d\n", x);
    printf("long= %ld\n", y);
    printf("double= %lf\n", z);

    double a;

    char *cevrilemeyen_kisim;
    a=strtod(string, cevrilemeyen_kisim);
    printf("a: %lf\n", a);
    printf("Sayidan sonraki: %s\n", cevrilemeyen_kisim);

    printf("\n");

    long b;

    // 10 -> onluk sayi tabanýndan çevirdigimiz için
    b= strtol(string, cevrilemeyen_kisim, 10);

    printf("b: %ld\n", b);
    printf("Cevrilemeyen kisim: %s\n", cevrilemeyen_kisim);

    return 0;
}
