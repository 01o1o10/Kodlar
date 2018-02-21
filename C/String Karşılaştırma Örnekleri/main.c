#include <stdio.h>
int main(){char a[10];int i, j;char temp;fgets(a, 10, stdin);for(i=0;a[i]!='\n';i++)for(j=i;a[j]!='\n';j++)if(a[i]>a[j]){temp=a[i];a[i]=a[j];a[j]=temp;}printf("%s", a);return 0;}
