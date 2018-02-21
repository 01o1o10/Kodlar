#include <stdio.h>

int main()
{
    char *metin;

    int i, j, sayi;

    printf("metin gir:");
    fgets(metin, 100, stdin);

    for(i=0;i<6;i++){
        sayi=0;
        for(j=i;<6;j++){
            if(metin[i]==metin[j])
                sayi++;
        }
        printf("%c: %d tane", metin[i], sayi);
    }
}
