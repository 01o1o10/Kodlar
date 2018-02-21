#include <stdio.h>

int main()
{
	char kelime[20];
	
	printf("Bir kelime girin: ");
	scanf("%s", &kelime);
	
	int i;
	
	//tamamini kararkter karakter yazdirirsak girilmemis kisim rasgele olur.
	for(i=0;i<20;i++)
		printf("%c", kelime[i]);
		
	printf("\n\n");
	
	//stringin bittigini anlamak için "\0" karakteri kullanýlýyor.
	//printf %s asagidaki döngü gibi calisiyor.
	for(i=0;kelime[i]!='\0';i++)
		printf("%c", kelime[i]);
		
	printf("\n\n");
	
	return 0;
	
}
