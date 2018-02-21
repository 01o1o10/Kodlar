#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float det(float m[100][100], int n);

int main()
{
	int n, i, j, a;
	srand(time(NULL));

	yeni:
	printf("Matrisin boyutunu giriniz: ");
	scanf("%d", &n);


	float matris[100][100];

	printf("Matrisin elemanlarinin rasgele uretilmesi icin 0'a,\n");
	printf("kendiniz girmek icin 1'e basarak 'Enter' tuslayiniz: ");
	scanf("%d", &a);

	switch(a){
		case 0: for(i=0;i<n;i++)
					for(j=0;j<n;j++)
						matris[i][j]=rand()%5;
				break;

		case 1: for(i=0;i<n;i++){
					printf("Matrisin %d. satir elemanlarini giriniz:\n", i+1);
					for(j=0;j<n;j++)
						scanf("%f", &matris[i][j]);
					printf("\n");
				}
			break;
	}

	ayni:
	printf("Matris:\n");
	for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				printf("\t%.2f", matris[i][j]);
			printf("\n");
		}

	printf("\n\nMatrisin:\n* Determinant islemleri icin 1'i.\n* Minor islemleri icin 2'yi.\n* Kofaktor islemleri icin 3'u.\n* Tersi islemleri icin 4'u.\n* Transpoz islemleri icin 5'i.\n* Baska bir matrisle toplamak icin 6'i.\n\n");
	printf("Seciminizi buradan belirtiniz: ");
	scanf("%d", &a);

	switch(a){
		case 1: printf("\n\nDeterminant: %f\n\n", det(matris, n)); break;
		case 2: printf("\n\nBu kisim yapim asamasindadir.\nBu sebepten dolayi bu isleminizi gerceklestiremiyoruz. :(\n\n"); break;
		case 3: printf("\n\nBu kisim yapim asamasindadir.\nBu sebepten dolayi bu isleminizi gerceklestiremiyoruz. :(\n\n"); break;
		case 4: printf("\n\nBu kisim yapim asamasindadir.\nBu sebepten dolayi bu isleminizi gerceklestiremiyoruz. :(\n\n"); break;
		case 5: printf("\n\nBu kisim yapim asamasindadir.\nBu sebepten dolayi bu isleminizi gerceklestiremiyoruz. :(\n\n"); break;
		case 6: printf("\n\nBu kisim yapim asamasindadir.\nBu sebepten dolayi bu isleminizi gerceklestiremiyoruz. :(\n\n"); break;
	}

	printf("* Yeni matrisle islem yapmak icin 1'i.\n* Ayni matrisle devam etek icin 2'yi.\n* Programi sonlandirmak icin 0'i");
	printf("\n\nSeciminizi buradan belirtiniz: ");
	scanf("%d", &a);

	switch(a){
		case 0: printf("\n\n\n"); break;
		case 1: printf("\n\n\n"); goto yeni; break;
		case 2: printf("\n\n\n"); goto ayni; break;
	}

	return 0;

}

float det(float m[100][100], int n)
{
	int i, j, a, b, c, d, e, f, g=0;
	float k, determinant=1;
	float temp[100];

	for(j=0;j<n-1;j++){
		for(i=n;j<i;i--){
			if(m[j][j]==0)
				determinant*=-1;
			for(c=j+1;m[j][j]==0 &&c<=n;c++){
				for(b=0;b<n;b++){
					temp[b]=m[j][b];
					m[j][b]=m[c][b];
					m[c][b]=temp[b];
				}
			}
			if(m[j][j]==0)
				return 0;
			k=m[i][j]/m[j][j];

			for(a=0;a<n;a++)
				m[i][j+a]=m[i][j+a]-k*m[j][j+a];
		}
		g++;
		printf("%d. sutunun sifirlanmis hali:\n", g);
		for(d=0;d<n;d++){
			for(e=0;e<n;e++)
				printf("\t%.2f", m[d][e]);
			printf("\n");
		}
		printf("\n\n");
	}

	for(f=0;f<n;f++)
		determinant=determinant*m[f][f];

	return determinant;
}
