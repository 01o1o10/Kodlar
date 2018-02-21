#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct ogrenci{//ogrenci kaydini tutan struct yapisi
    struct ogrenci *onceki;
    char ogrno[10];
    char ad[15];
    char soyad[15];
    char kayitsirasi[4];
    char ogrturu[2];
    struct ogrenci *sonraki;
};

void kayit_sil(struct ogrenci *bas);
void kayit_yazdir(struct ogrenci *bas);
void kayit_sirasina_gore_sirala(struct ogrenci *bas, struct ogrenci *son);
void kayit_sirasina_sifir_ekle(struct ogrenci *bas);
void kayit_sira_bilgilerini_guncelle(struct ogrenci *bas);
void ogrno_ata(struct ogrenci *bas);
void kayit_saydir(struct ogrenci *bas, int *kayit_sayisi1, int *kayit_sayisi2);
void sinif_bilgileri_al_ve_dosya_olustur(struct ogrenci *bas);
void dosya_olustur(char *dosyaismi);
int hyt
int * en_az_sinif_dagilimi(int sinif_sayisi, int sinif_kapasiteleri[], int kayit_sayisi, struct ogrenci *bas);
int * sinif_kapasitelerini_sirala(int sinif_sayisi, int sinif_kapasiteleri[]);

int main()
{
    struct ogrenci *bas = NULL;
    struct ogrenci *son = NULL;
    FILE *dosya;
    char kelime[100];
    int c;

    if((dosya = fopen("duzeltilmis_ogrenci_kayit_bilgileri.txt","r+")) == NULL){
        printf("Dosya Acýlamadi!");
        exit(0);
    }

    struct ogrenci *yeni;

    fgets(kelime, 100, dosya);/// satır okuyor-ilk satır atla

    while(1){
        if((c = fgetc(dosya)) != EOF){
            fseek(dosya, ftell(dosya) - 1, SEEK_SET);///1 karakter geri gel.
            yeni = malloc(sizeof(struct ogrenci));///belekten yer ayirik pointer icin
            fscanf(dosya, "%s", yeni->ogrno);
            fscanf(dosya, "%s", yeni->ad);
            fscanf(dosya, "%s", yeni->soyad);
            fscanf(dosya, "%s", yeni->kayitsirasi);
            fscanf(dosya, "%s", yeni->ogrturu);
            if(bas == NULL){
                yeni->onceki = NULL;///
                yeni->sonraki = NULL;
                bas = yeni;
                son = yeni;
            }
            else{
                yeni->sonraki = NULL;
                yeni->onceki = son;
                yeni->onceki->sonraki = yeni;
                son = yeni;
            }
        }
        else{
            break;
        }
    }
    fclose(dosya);

    kayit_sil(bas);
    kayit_sirasina_sifir_ekle(bas);
    kayit_sirasina_gore_sirala(bas, son);
    kayit_sira_bilgilerini_guncelle(bas);
    ogrno_ata(bas);
    kayit_yazdir(bas);
    sinif_bilgileri_al_ve_dosya_olustur(bas);

    struct ogrenci *temp = bas;
    struct ogrenci *temp1;
    while(temp->sonraki != NULL){
        temp1 = temp;
        temp = temp->sonraki;
        free(temp1);
    }

    return 0;
}

void kayit_yazdir(struct ogrenci *bas)
{
    struct ogrenci *temp = bas;
    int sayac = 0;

    printf("\n*************************************************************");
    while(temp->sonraki != NULL){
        printf("\n-------------------------------------------------------------");
        printf("\n| %-10s", temp->ogrno);
        printf("  %-15s", temp->ad);
        printf("  %-15s", temp->soyad);
        printf("  %-5s", temp->kayitsirasi);
        printf("  %-5s|", temp->ogrturu);
        temp = temp->sonraki;
        sayac++;
    }
    printf("\n-------------------------------------------------------------");
    printf("\n*************************************************************");
}

void kayit_sil(struct ogrenci *bas)
{
    struct ogrenci *kayit = bas;
    struct ogrenci *temp;
    while(kayit->sonraki != NULL){
        if(!strcmp(kayit->ad, kayit->sonraki->ad) && !strcmp(kayit->soyad, kayit->sonraki->soyad)){
            temp = kayit;
            kayit->onceki->sonraki = kayit->sonraki;
            kayit->sonraki->onceki = kayit->onceki;
            kayit = kayit->sonraki;
            free(temp);
        }
        else{
            kayit = kayit->sonraki;
        }
    }
    printf("\nBirden fazla bulunan kayitlar silinmistir.");
}

void kayit_sirasina_gore_sirala(struct ogrenci *bas, struct ogrenci *son)
{
    struct ogrenci *i, *j, *temp, *sondangelen = son;
    int durum;

    for(i = bas; i->sonraki != NULL; i = i->sonraki){
        durum = 1;
        for(j = bas; (j->sonraki != sondangelen && j->sonraki->sonraki != NULL); j = j->sonraki){
            if(strcmp(j->kayitsirasi , j->sonraki->kayitsirasi) > 0){
                j = j->sonraki;
                temp = j->onceki;
                temp->sonraki = j->sonraki;
                j->sonraki->onceki = temp;
                j->onceki = temp->onceki;
                temp->onceki->sonraki = j;
                j->sonraki = temp;
                temp->onceki = j;
                durum = 0;
                if(sondangelen->onceki != NULL)
                    sondangelen = sondangelen->onceki;
            }
        }
        if(durum == 1){
            break;
        }
    }
}

void kayit_sirasina_sifir_ekle(struct ogrenci *bas)
{
    char ikisifir[5] = "00";
    char birsifir[5] = "0";
    struct ogrenci *temp;
    for(temp = bas; temp->sonraki != NULL; temp = temp->sonraki){
        if(strlen(temp->kayitsirasi) == 1){
            strcat(ikisifir, temp->kayitsirasi);
            strcpy(temp->kayitsirasi, ikisifir);
            strcpy(ikisifir, "00");
        }
        else if(strlen(temp->kayitsirasi) == 2){
            strcat(birsifir, temp->kayitsirasi);
            strcpy(temp->kayitsirasi, birsifir);
            strcpy(birsifir, "0");
        }
    }
}

void kayit_sira_bilgilerini_guncelle(struct ogrenci *bas)
{
    struct ogrenci *temp;
    char ikisifir[5] = "00";
    char birsifir[5] = "0";
    char str_i[4];
    int i = 0;
    for(temp = bas; temp->sonraki != NULL; temp = temp->sonraki){
        if(strlen(temp->ogrno) < 5){
            itoa(i,str_i,4);
            if(strlen(str_i) == 1){
                strcat(ikisifir, str_i);
                strcpy(temp->kayitsirasi, ikisifir);
                strcpy(ikisifir, "00");
            }
            else if(strlen(str_i) == 2){
                strcat(birsifir, str_i);
                strcpy(temp->kayitsirasi, birsifir);
                strcpy(birsifir, "0");
            }
            i++;
        }
    }
}

void ogrno_ata(struct ogrenci *bas)
{
    struct ogrenci *temp;
    char varsayilan1[10] = "1701";
    char varsayilan2[10] = "1702";

    for(temp = bas; temp->sonraki != NULL; temp = temp->sonraki){
        if(strlen(temp->ogrno) < 2){
            if(!strcmp(temp->ogrturu, "I")){
                strcat(varsayilan1, temp->kayitsirasi);
                strcpy(temp->ogrno, varsayilan1);
                strcpy(varsayilan1, "1701");
            }
            else if(!strcmp(temp->ogrturu, "II")){
                strcat(varsayilan2, temp->kayitsirasi);
                strcpy(temp->ogrno, varsayilan2);
                strcpy(varsayilan2, "1702");
            }
        }
    }
}

void kayit_saydir(struct ogrenci *bas, int *kayit_sayisi1, int *kayit_sayisi2)
{
    struct ogrenci *temp;
    for(temp = bas; temp->sonraki != NULL; temp = temp->sonraki){
        if(!strcmp(temp->ogrturu, "I")){
            (*kayit_sayisi1)++;
        }
        else if(!strcmp(temp->ogrturu, "II")){
            (*kayit_sayisi2)++;
        }
    }
    printf("\nBirinci ogretim sayisi: %d", *kayit_sayisi1);
    printf("\nIkinci ogretim sayisi: %d", *kayit_sayisi2);
}

void sinif_bilgileri_al_ve_dosya_olustur(struct ogrenci *bas)
{
    int sinif_sayisi;
    printf("\nSinif sayisini giriniz: ");
    scanf("%d", &sinif_sayisi);

    int sinif_kapasiteleri[sinif_sayisi];
    int *sinif_kaps; ///siralanmis sinif kapasiteleri.
    int i, toplam_sinif_kapasitesi = 0;
    int kayit_sayisi1 = 0;
    int kayit_sayisi2 = 0;
    kayit_saydir(bas, &kayit_sayisi1, &kayit_sayisi2);

    flag:
    printf("\nSinif kapasitelerini girniz.\n");
    for(i = 0; i < sinif_sayisi; i++){
        printf("%d. sinifin kapasitesini giriniz: ", i+1);
        scanf("%d", &sinif_kapasiteleri[i]);
        toplam_sinif_kapasitesi += sinif_kapasiteleri[i];
    }
    if(toplam_sinif_kapasitesi < kayit_sayisi1 || toplam_sinif_kapasitesi < kayit_sayisi2){
        printf("\nGirilen sinif kapasitelieri yetersizdir!\nLutfen sinif kapasitelerini tekrardan giriniz.");
        goto flag;
    }

    sinif_kaps = sinif_kapasitelerini_sirala(sinif_sayisi, sinif_kapasiteleri);

    int secim;
    secime:
    printf("\n[0] - Esit Dagilim");
    printf("\n[1] - En AZ Sinif Dagilimi");
    printf("\nSinif-Ogrenci dagilim seklini seciniz: ");
    scanf("%d", &secim);
    int *sinif_dagilimi1;
    int *sinif_dagilimi2;
    if(secim == 0){
        printf("\n\nBirinci ogretim sinif dagilimlari: ");
        sinif_dagilimi1 = esit_dagilim(sinif_sayisi, sinif_kaps, kayit_sayisi1, bas);
        printf("\n\nIkinci ogretim sinif dagilimlari: ");
        sinif_dagilimi2 = esit_dagilim(sinif_sayisi, sinif_kaps, kayit_sayisi2, bas);
    }
    else if(secim == 1){
        printf("\n\nBirinci ogretim sinif dagilimlari: ");
        sinif_dagilimi1 = en_az_sinif_dagilimi(sinif_sayisi, sinif_kaps, kayit_sayisi1, bas);
        printf("\n\nIkinci ogretim sinif dagilimlari: ");
        sinif_dagilimi2 = en_az_sinif_dagilimi(sinif_sayisi, sinif_kaps, kayit_sayisi2, bas);
    }
    else{
        printf("\nYanlis secim!\nSeciminizi tekrar yapiniz.\n");
        goto secime;
    }

    /*char birinciogrsinifdosyasi[20];
    char ikinciogrsinifdosyasi[20];
    char str_i[2];

    for(i = 0; i < sinif_sayisi; i++){
        itoa(i+1, str_i, 2);
        strcpy(birinciogrsinifdosyasi, "sinif");
        strcat(birinciogrsinifdosyasi,str_i);
        strcat(birinciogrsinifdosyasi, "ogr1.txt");

        strcpy(ikinciogrsinifdosyasi, "sinif");
        strcat(ikinciogrsinifdosyasi,str_i);
        strcat(ikinciogrsinifdosyasi, "ogr2.txt");

        dosya_olustur(birinciogrsinifdosyasi);
        dosya_olustur(ikinciogrsinifdosyasi);
    }*/

}

/*void dosya_olustur(char *dosyaismi)
{
    FILE *dosya;
    if((dosya = fopen(dosyaismi, "w")) == NULL){
        printf("\nDosya olusturulamadi!");
        exit(0);
    }
    fclose(dosya);
    printf("\nDosya olusturuldu.");
}*/

int * esit_dagilim(int sinif_sayisi, int sinif_kapasiteleri[], int kayit_sayisi, struct ogrenci *bas)
{
    /*
        esit dagilim mantigi ogrenci sayisi sinif sayisina bolunerek her sinifa esit sekilde dagilim yapilir ama
        bu bolumden elde edilen sonuc bazi siniflarin kapasitesinden fazla olabilir buz zaman yapmamiz gereken
        bizim siniflarimiz bu fonksiyona gelirken kapasitesine gore buyukten kucuge sirali oldugu icin ilk once en sondaki sinifin(yani kapasitesi en kucuk olan sinifin)
        kapasitesinin bu sayidan kucuk mu buyuk mu oldugunukontrol etmemiz gerek
        eger kucuk ise derse kayit yaptiran ogrenci sayisindan(yani kayit sayisindan) bu sinifin kapasitesini cikarir ve geri kalan siniflar icin ayni islemi tekrarlariz
        ogrenci sayisinin sinif sayisina bolumunden elde ettigimiz sonuc, yerlestirme yapilmayan sinif kapasitelerinin en kucugunden kucuk ise geri kalan siniflara dogrusal dagilim yani esit dagilim yapilir
        bunun icin her seferinde yerlestirilmeyen ogrenci sayisini yerlesim yapilmayan sinif sayisina bolerek elde edilen sonucu ogrenci sayisindan duser ve sinif dagilimi dizisindeki ilgili sinifa esitleriz.
    */

    int i, bolum;
    int sinif_dagilimi[sinif_sayisi];///sinif dagiliminin tutulacagi dizi
    for(i = sinif_sayisi-1; i >=0; i--){///siniflar buyukten kucuge sirali oldugu icin en kucuk kapasiteye sahip olan siniftan baslamak adina dizinin sonundan basliyoruz.
        bolum = kayit_sayisi/(i+1);///burada kayit sayisi her seferinde guncellendigi icin yerlestirilmeyen ogrenci sayisini tutar aslinda ev i de her seferinde azaldigi icin i+1 yerlesim yapilmayan sinif sayisini tutar aslimnda
        if(bolum > sinif_kapasiteleri[i]){///bollum sonucu yerlesim yapilmayan sinif kapasitelerinin en kucugunden buyuk kaliyor ise
            kayit_sayisi -= sinif_kapasiteleri[i];///kayit sayisini bu sinifin kapasiteis kadar azlat
            sinif_dagilimi[i] = sinif_kapasiteleri[i];///sinifin kapasitesi kadar ogrenciyi bu sinifa yerlestir
        }
        else{///eger bolum sonucu en kucuk sinifin kapasitesinden kucuk ise bundan sonra esit dagilim uygula
            sinif_dagilimi[i] = bolum;///bolumden elde edilen sonuc kadar ogrenciyi sinifina yerlestir
            kayit_sayisi -= bolum;/// ve yerlesmeyen ogrenci sayisini guncelle
        }
    }

    for(i = 0; i < sinif_sayisi; i++){///dagilim sonucunu yazdir
        printf("%d  ", sinif_dagilimi[i]);
    }
    printf("\nTum ogrenciler yerlestirilebilmistir.");

    return sinif_dagilimi; /// dagilim sonucunu dondur.
}

int * en_az_sinif_dagilimi(int sinif_sayisi, int sinif_kapasiteleri[], int kayit_sayisi, struct ogrenci *bas)
{
    /*
        en az sinif dagilimi demek derse kayitli ogrencileri yerlestirirken en az sayida sinifi meskul etmektir amac
        bunun icin ilk once kapasitesi buyuk olan siniflara yerlestirme yapilmali daha sonra kalan ogrencileri diger siniflara gene ayni sekilde
        ilk basta kapasitesi fazla olan sinifa yerlestirerek kalan olursa diger siniflara dagitacak sekilde kodlanmalidir bu fonksiyon
    */

    int i; ///sayac
    int sinif_dagilimi[sinif_sayisi]; ///hangi sinifta kac ogrenci yerlestirildigini bu dizide tutacagiz ve bu dizinin boyutu ise sinif sayisi kadar olacaktir
    for(i = 0; ;i++){ /// dongu i=0 dan basla ve dongu icerisinde belirtilen kosul saglandigi surece doner.
        if(kayit_sayisi > sinif_kapasiteleri[i]){///daha once siniflari kapasitesine gore buyukten kucuge siraladigimiz icin burada listedeki ilk sinif kapasitesi en fazla olan siniftir benzer sekilde ikinci siradaki sinif ise kapasitesi ikinci buyuk olan siniftir. Bu yuzden eger kayit sayisi sinif kapasitesinden fazla ise bu if bloguna girer
            kayit_sayisi -= sinif_kapasiteleri[i];///kayit sayisi sinif kapasitesi kadar azaltilir
            sinif_dagilimi[i] = sinif_kapasiteleri[i];///sinif kapasitesi kadar ogrenci sinif dagilimi dizisindeki ilgili sinifa yerlestirilir.
        }
        else if(kayit_sayisi < sinif_kapasiteleri[i]){///eger kayit sayisi sinif kapasitesinden kucuk ise (yukaridaki if blogunda her seferinde sinif kapasitesi azaltilacagi icin eninde sonunda bu kosul saglanir)
            sinif_dagilimi[i] = kayit_sayisi;///bu sefer sinif dagilimi dizisindeki ilgili sinifa geri kalan kayit sayisi kadar ogrenci yerlestirilir.
            break;/*bu kisimda guncelleme var*/ ///ve son olarak tum ogrenciler yerlestirildigi icin donguden cikilir.

        }
    }

    for(i = 0; i < sinif_sayisi; i++){///sinf dagilimlari ekrana yazdirilir.
        printf("%d  ", sinif_dagilimi[i]);
    }
    printf("\nTum ogrenciler yerlestirilebilmistir.");

    return sinif_dagilimi; /// sinif dagilimlari dizisi fonksiyonun cagrildigi yere geri dondurulur.
}

int * sinif_kapasitelerini_sirala(int sinif_sayisi, int sinif_kapasiteleri[])///girilen sinif kapasitelerini bubble sort algoritmasini kullanarak sirala ve geri dondurur
{
    int i, j, temp; /// dongu sayaclari ve temp ise siralama zamani gecici olarak yerini degistirecegimiz elemanı tutmak icindir
    for(i = 0; i < sinif_sayisi; i++){///dongumuz sifirdan baslar ve sinif sayisi kadar doner
        for(j = 0; j < sinif_sayisi - i - 1; j++){///bubble sort algoritmasi sondan basa dogru siraladigi icin icteki donguyu her dis ongu sonrasinda bir kez az donmesi saglanmistir.
            if(sinif_kapasiteleri[j] < sinif_kapasiteleri[j+1]){///ic dongunun uzerinde bulundugu eleman kendinden sonra gelen elemandan kucuk ise bu elemanlar arasinda yer degistirir.
                temp = sinif_kapasiteleri[j];
                sinif_kapasiteleri[j] = sinif_kapasiteleri[j+1];
                sinif_kapasiteleri[j+1] = temp;
            }
        }
    }

    printf("\nSiralanmis sinif kapasiteleri: ");
    for(i = 0; i < sinif_sayisi; i++){/*bu kisimda guncelleme var*/ ///siralanan sinif kapasitelerini ekrana yazdirir.
        printf("%d    ", sinif_kapasiteleri[i]);
    }
    return sinif_kapasiteleri; /// siralanmis sinif kapasitelerini fonksiyonun cagrildigi yerdeki esitlendigi pointere dondurur.
}
