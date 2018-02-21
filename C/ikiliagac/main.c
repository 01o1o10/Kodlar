#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <conio/myconio.h>
#include <time.h>

//struct yapilari
struct agac {
    struct agac *sol;
    int deger;
    struct agac *sag;
    int yukseklik;
};

//pointerlar
struct agac *tutucu;
int x = 70;
int y = 20;

//prototypelar
struct agac* ekle(struct agac*, int);
struct agac* sil(struct agac*, int);
struct agac* ikicocuklusil(struct agac*);
int yukseklikhesapla(struct agac*);
int dengefaktoru(struct agac*);
struct agac* soladondur(struct agac*);
struct agac* sagadondur(struct agac*);
void inorder(struct agac*);
void preorder(struct agac*);
int max1(int, int);
void agacyaz(struct agac*);

int main()
{
    srand(time(NULL));
    struct agac *kok = NULL;

    int deger;
    int i = 0, a;

    while(1){
        puts("");
        puts("******  Menu  ******");
        puts("[0] - Sonlandir");
        puts("[1] - Ekle");
        puts("[2] - Otomatik Agac Olustur");
        puts("[3] - Sil");
        puts("[4] - Inorder Sirala");
        puts("[5] - Preorder Sirala");
        puts("[6] - Agac Gosterimi");
        puts("[7] - Agaci Temizle");

        switch(_getch()){
            case '0': clrscr(); exit(1); break;
            case '1': clrscr(); do{printf("Eklenecek degeri giriniz: "); scanf("%d", &deger); if(deger == 0) break; kok = ekle(kok, deger);}while(1); break;
            case '2': clrscr(); printf("Kac elemanli agac olusturmak istiyorsunuz: "); scanf("%d", &a); while(i<a){deger = rand()%100; kok = ekle(kok, deger); i++;} break;
            case '3': clrscr(); printf("Silinenecek degeri giriniz: "); scanf("%d", &deger); sil(kok, deger); break;
            case '4': clrscr(); puts("Inorder dolasma."); inorder(kok); puts(""); break;
            case '5': clrscr(); puts("Preorder dolasma."); preorder(kok); puts(""); break;
            case '6': clrscr(); puts("Agac Gosterimi"); agacyaz(kok); puts(""); break;
            case '7': clrscr(); kok = NULL; break;
        }


    }

    return 0;
}

struct agac* ekle(struct agac *dugum, int deger)
{
    if(dugum == NULL){
        dugum = (struct agac*)malloc(sizeof(struct agac));
        if(dugum != NULL){
            dugum->deger = deger;
            dugum->sol = NULL;
            dugum->sag = NULL;
            dugum->yukseklik = 0;
        }
        else{
            puts("Yer ayrilamadi");
            _getch();
        }
    }
    else if(dugum->deger>deger){
        dugum->sol = ekle(dugum->sol, deger);
    }
    else if(dugum->deger<deger){
        dugum->sag = ekle(dugum->sag, deger);
    }
    else{
        return dugum;
    }

    dugum->yukseklik = (dugum->sag != NULL && dugum->sol != NULL)? 1 : 0 + max1(yukseklikhesapla(dugum->sol), yukseklikhesapla(dugum->sag));

    int denge = dengefaktoru(dugum);

    if(denge>1 && dugum->sol->deger>deger){
        puts("solun solu");
        dugum = sagadondur(dugum);
    }
    if(denge>1 && dugum->sol->deger<deger){
        puts("solun sagi");
        dugum->sol = soladondur(dugum->sol);
        dugum = sagadondur(dugum);
    }
    if(denge<-1 && dugum->sag->deger<deger){
        puts("sagin sagi");
        dugum = soladondur(dugum);
    }
    if(denge<-1 && dugum->sag->deger>deger){
        puts("sagin solu");
        dugum->sag = sagadondur(dugum->sag);
        dugum = soladondur(dugum);
    }
    return dugum;
}

struct agac* sil(struct agac *dugum, int deger)
{
    if(dugum != NULL){
        if(deger == dugum->deger){
            if(dugum->sol == NULL && dugum->sag == NULL){
                free(dugum);
                return NULL;
            }
            else if(dugum->sol == NULL || dugum->sag == NULL){
                if(dugum->sol == NULL){
                    tutucu->sag = dugum->sag;
                    free(dugum);
                    return tutucu->sag;
                }
                else{
                    tutucu->sol = dugum->sol;
                    free(dugum);
                    return tutucu->sol;
                }
            }
            else{
                dugum->sag = ikicocuklusil(dugum->sag);
                tutucu->sag = dugum->sag;
                tutucu->sol = dugum->sol;
                free(dugum);
                return tutucu;
            }
        }
        else if(deger > dugum->deger){
            dugum->sag = sil(dugum->sag, deger);
        }
        else{
            dugum->sol = sil(dugum->sol, deger);
        }
    }
    return dugum;
}

struct agac* ikicocuklusil(struct agac *dugum)
{
    if(dugum->sol == NULL){
        tutucu = dugum;
        if(dugum->sag == NULL){
            return NULL;
        }
        else{
            return dugum->sag;
        }
    }
    else{
        dugum->sol = ikicocuklusil(dugum->sol);
    }
    return dugum;
}

struct agac* soladondur(struct agac *dugum)
{
    tutucu = dugum->sag->sol;
    dugum->sag->sol = dugum;
    dugum = dugum->sag;
    dugum->sol->sag = tutucu;
    return dugum;
}

struct agac* sagadondur(struct agac *dugum)
{
    tutucu = dugum->sol->sag;
    dugum->sol->sag = dugum;
    dugum = dugum->sol;
    dugum->sag->sol = tutucu;
    return dugum;
}

void inorder(struct agac *dugum)
{
    if(dugum != NULL){
        inorder(dugum->sol);
        printf("%4d", dugum->deger);
        inorder(dugum->sag);
    }
}

void preorder(struct agac *dugum)
{
    if(dugum != NULL){
        printf("%4d", dugum->deger);
        preorder(dugum->sol);
        preorder(dugum->sag);
    }
}

int yukseklikhesapla(struct agac *dugum)
{
    if(dugum == NULL){
        return 0;
    }
    else{
        return dugum->yukseklik;
    }
}

int max1(int a, int b)
{
    return (a>b)? a : b;
}

int dengefaktoru(struct agac *dugum)
{
    return (yukseklikhesapla(dugum->sol)-yukseklikhesapla(dugum->sag));
}

void agacyaz(struct agac *dugum)
{
    if(dugum != NULL){
        //gotoxy(x,y);
        printf("%d", dugum->deger);
        if(dugum->yukseklik != 0){
            x-=dugum->yukseklik*5;
            y+=2;
            gotoxy(x,y);
            agacyaz(dugum->sol);
            x+=(dugum->yukseklik*10);
            gotoxy(x,y);
            agacyaz(dugum->sag);
            x-=(dugum->yukseklik*5);
            y-=2;
        }
    }
}












