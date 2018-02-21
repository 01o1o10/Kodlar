#include <stdio.h>

int main()
{
	char s[100];
	//gets fonksiyonu ile cümle okunabilir (boþluklar dahil).
	//scanf %s ile kelime okunabiliyor. scanf %s boþluklarý almýyor.
	
	printf("\n\ncumle girin: ");
	gets(s);
	
	printf("\n\ncumle: ");
	puts(s);
	
	return 0;
}
