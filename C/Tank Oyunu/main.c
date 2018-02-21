#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <conio/myconio.h>

void tankben(int, int, int);
void sil(int, int);
void ates(int);

int x1=140, y1=20, x2, y2 ,x3, y3;
int a1, b1, a2, b2, a3, b3;
int yon1, yon2, yon3;
int c;

int main()
{
    yon1 = 3;
    gotoxy(x1-1, y1-2);
    printf("* * * *");
    gotoxy(x1-1, y1-1);
    printf("* * * *");
    gotoxy(x1-5, y1);
    printf("* * * * *");
    gotoxy(x1-5, y1+1);
    printf("* * * * *");
    gotoxy(x1-1, y1+2);
    printf("* * * *");
    gotoxy(x1-1, y1+3);
    printf("* * * *");

    while(1){
        c = _getch();
        if(c == 224){
            switch(_getch()){
                case 72: if(y1>3) {yon1 = 0; y1--; tankben(yon1, x1, y1);} break;
                case 80: if(y1<38) {yon1 = 1; y1++; tankben(yon1, x1, y1);} break;
                case 77: if(x1<144) {yon1 = 2; x1+=2; tankben(yon1, x1, y1);} break;
                case 75: if(x1>8) {yon1 = 3; x1-=2; tankben(yon1, x1, y1);} break;
            }
        }
        else if(c == ' '){
            ates(yon1);
        }
    }
    _getch();
    return 0;
}

void tankben(int yon, int x, int y)
{
    switch(yon){
        case 0:{
            sil(x, y+1);
            gotoxy(x-1, y-2);
            printf("* *");
            gotoxy(x-1, y-1);
            printf("* *");
            gotoxy(x-5, y);
            printf("* * * * * *");
            gotoxy(x-5, y+1);
            printf("* * * * * *");
            gotoxy(x-5, y+2);
            printf("* * * * * *");
            gotoxy(x-5, y+3);
            printf("* *     * *");
            break;
        }
        case 1:{
            sil(x, y-1);
            gotoxy(x-5, y-3);
            printf("* *     * *");
            gotoxy(x-5, y-2);
            printf("* * * * * *");
            gotoxy(x-5, y-1);
            printf("* * * * * *");
            gotoxy(x-5, y);
            printf("* * * * * *");
            gotoxy(x-1, y+1);
            printf("* *");
            gotoxy(x-1, y+2);
            printf("* *");
            break;
        }
        case 2:{
            sil(x-1, y);
            gotoxy(x-5, y-2);
            printf("* * * *");
            gotoxy(x-5, y-1);
            printf("* * * *");
            gotoxy(x-3, y);
            printf("* * * * *");
            gotoxy(x-3, y+1);
            printf("* * * * *");
            gotoxy(x-5, y+2);
            printf("* * * *");
            gotoxy(x-5, y+3);
            printf("* * * *");
            break;
        }
        case 3:{
            sil(x+1, y);
            gotoxy(x-1, y-2);
            printf("* * * *");
            gotoxy(x-1, y-1);
            printf("* * * *");
            gotoxy(x-5, y);
            printf("* * * * *");
            gotoxy(x-5, y+1);
            printf("* * * * *");
            gotoxy(x-1, y+2);
            printf("* * * *");
            gotoxy(x-1, y+3);
            printf("* * * *");
            break;
        }
    }
    gotoxy(x, y);
}

void sil(int x, int y)
{
    gotoxy(x-6, y-3);
    printf("             ");
    gotoxy(x-6, y-2);
    printf("             ");
    gotoxy(x-6, y-1);
    printf("             ");
    gotoxy(x-6, y);
    printf("             ");
    gotoxy(x-6, y+1);
    printf("             ");
    gotoxy(x-6, y+2);
    printf("             ");
    gotoxy(x-6, y+3);
    printf("             ");
}

void ates(int yon)
{
    int a, b;
    switch(yon){
        case 0:{
            a = x1-1;
            b = y1 - 4;
            while(b > 1){
                gotoxy(a, b+1);
                printf("   ");
                gotoxy(a, b);
                printf("   ");
                gotoxy(a, b);
                printf("* *");
                gotoxy(a, b-1);
                printf("* *");
                b--;
                Sleep(15);
            }
            gotoxy(a, b+1);
            printf("   ");
            gotoxy(a, b);
            printf("   ");
            break;
        }
        case 1:{
            a = x1-1;
            b = y1 + 4;
            while(b < 40){
                gotoxy(a, b-1);
                printf("   ");
                gotoxy(a, b);
                printf("   ");
                gotoxy(a, b);
                printf("* *");
                gotoxy(a, b+1);
                printf("* *");
                b++;
                Sleep(15);
            }
            gotoxy(a, b-1);
            printf("   ");
            gotoxy(a, b);
            printf("   ");
            break;
        }
        case 2:{
            a = x1 + 8;
            b = y1;
            while(a <150){
                gotoxy(a-2, b);
                printf("   ");
                gotoxy(a-2, b+1);
                printf("   ");
                gotoxy(a, b);
                printf("* *");
                gotoxy(a, b+1);
                printf("* *");
                a+=2;
                Sleep(15);
            }
            gotoxy(a-2, b);
            printf("   ");
            gotoxy(a-2, b+1);
            printf("   ");
            break;
        }
        case 3:{
            a = x1 - 10;
            b = y1;
            while(a > 0){
                gotoxy(a+2, b);
                printf("   ");
                gotoxy(a+2, b+1);
                printf("   ");
                gotoxy(a, b);
                printf("* *");
                gotoxy(a, b+1);
                printf("* *");
                a-=2;
                Sleep(15);
            }
            gotoxy(a+2, b);
            printf("   ");
            gotoxy(a+2, b+1);
            printf("   ");
            break;
        }
    }
}

void duvar()
{

}



























