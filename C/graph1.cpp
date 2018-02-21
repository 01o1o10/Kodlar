#include <graphics.h>

int main()
{
	initwindow(400,300);
	moveto(0,0);
	lineto(50,50);
	while(!kbhit());
	closegraph();
	return 0;
}
