#include <stdio.h>

int main()
{
	int a=10;
	char s[8];//7 karakter + 1 sonlandırma karakteri sığabilir.
	int b=20;
	
	printf("\na: %d ve b: %d\n", a, b);
	
	printf("\nprogrami 8 veya daha fazla karakter girerek test edin.\n");
	printf("kelime girin: ");
	fgets(s, 8, stdin);//gets yerine bu şekilde kullanabiliriz.
	
	//scanf ile kelime okumak istersek
	//scanf("%7s", s);
	
	printf("\ngirilen kelime: ");
	puts(s);
	
	printf("\na: %d ve b: %d\n", a, b);
	
	return 0;
}
