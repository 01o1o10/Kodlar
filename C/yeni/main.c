#include <stdio.h>

int s1son(char *s1)
{
    int i;
    for(i=0;s1[i]!='\n';i++){}
    return i;
}

void birlestir(char *s1, char *s2)
{
    int i,j=0;
    for(i=s1son(s1); s2[j]!='\n'; i++ && j++)
        s1[i]=s2[j];
    s1[i]='\0';
}

int main()
{
    int i;
    char s1[100], s2[100];

    printf("String1: ");
    fgets(s1, 100, stdin);
    printf("String2: ");
    fgets(s2, 100, stdin);

    birlestir(s1, s2);
    printf("Birlestirilmis hali: ");
    puts(s1);

    return 0;
}
