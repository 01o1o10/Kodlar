#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main()
{
initwindow(650,500);
outtextxy(300,80,"TURK BAYRAGI");
setbkcolor(9);
fillellipse(147,105,5,5);
fillellipse(147,395,5,5);
bar(145,395,150,105);
setfillstyle(1,4);
setcolor(0);
bar(150,390,550,110),
setfillstyle(1,15);
setcolor(4);
fillellipse(325,250,80,80);

setfillstyle(1,4);
setcolor(4);
fillellipse(345,250,65,65);
setfillstyle(1,15);

setcolor(15);
int poly[22]={395,250,418,257,418,280,431,261,454,
269,440,250,453,231,431,238,417,220,417,243,395,250};
fillpoly(11,poly);
getch();
closegraph();
return 0;
}
