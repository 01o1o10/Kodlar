#include <stdio.h>

int main()
{
	int a=10;
	char yazi[8];
	int b=20;
	
	printf("%p\n%p\n%p", &a, &yazi[0], &b);
	
	printf("\n\na: %d ve b: %d\n\n", a, b);
	
	printf("programi 8 ve ya daha fazla karakter girerek test edin\n");
	printf("yazi girin: ");
	gets(yazi);
	
	//scanf'da da ayný problem var.
	//scanf("%s", yazi);
	
	printf("\n\ngirilen kelime: ");
	puts(yazi);
	
	printf("\n\na: %d ve b: %d", a, b);
	
	return 0;
}
