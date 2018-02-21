//Karakter Fonksiyonlarý
//isalnum, isalpha, iscntrl, isdigit, isgraph, islower, isprint, ispunct, isspace, isupper, isxdigit, isascii, isblank#include <stdio.h>

#include <stdio.h>
#include <ctype.h>

int main()
{
    char c1;

    printf("Karakter giriniz: ");
    scanf("%c", &c1);

    if(isdigit(c1))
        printf("\n%c karakteri rakamdýr.", c1);
    else
        printf("\n%c karakteri rakam degildir.", c1);
    if(isalpha(c1))
        printf("\n%c karakteri harftir", c1);
    else
        printf("\n%c karakteri harf degildir.", c1);
    if(ispunct(c1))
        printf("\n%c karakteri noktalama isaretidir.", c1);
    else
        printf("\n%c karakteri noktalama isareti degildir.", c1);
    if(isalpha(c1)){
        if(isupper(c1))
            printf("\nkucuk harf karsiligi %c", tolower(c1));
        if(islower(c1))
            printf("\nbuyuk harf karsiligi %c", toupper(c1));
    }
    return 0;
}
