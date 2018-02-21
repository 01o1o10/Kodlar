#include <stdio.h>

int main()
{
	char str[20];
	int i;
	
	printf("Bir kelime girin: ");
	
	scanf("%s", str);
	
	printf("\ngirilen kelime: %s", str);
		
	for(i=0;str[i]!='\0';i++){}
	
	printf("\n\nKarakter sayisi: %d\n\n", i);
	
	for(i=i-1;i>=0;i--)
		printf("%c", str[i]);
		
	printf("\n\n");
		
	return 0;
	
}
