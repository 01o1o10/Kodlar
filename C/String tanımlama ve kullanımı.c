#include <stdio.h>

int main()
{
	char ad[20];
	printf("Adinizi giriniz: ");
	scanf("%s", &ad);
	
	printf("\nmerhaba %s\n", ad);
	
	//tanimlarken deger atamak istersek?
	char s1[20]="deneme2";
	printf("%s\n", s1);
	
	//sabit yapmak istersek?
	const char *s2="deneme3";
	printf("%s\n", s2);
	
	//dizinin boyutunu atanan degere göre otomatik belirleme?
	char s3[]="deneme4";
	printf("%s\n", s3);
	
	return 0;
	
}
