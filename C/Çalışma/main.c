#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *durum;

    printf("\nValize bakacaklar mi?\n");
    scanf("%s", durum);

    if(strcmp(durum, "evet") == 0) {
        printf("Valizi emanet birak.");
    }
    else {
        printf("Valizi de kkendinle götür.");
    }

    printf("Kalamis Cafe bos mu?\nCevap: ");
    scanf("%s", durum);

    if(strcmp(durum, "evet") == 0){
        printf("\nKalamis kafede kal.");
    }
    else {
        printf("\nKalamis kafeden parani al.\nDiger kafelerde kalabilir misin?\nCevap: ");
        scanf("%s", durum);
        if(strcmp(durum, "evet") == 0){
            printf("\nOrda kal.");
        }
        else {
            printf("Ýzmit'e git ve sarj aletini kontrol et. Daha sonra bursaya dön.");
        }
    }
}
