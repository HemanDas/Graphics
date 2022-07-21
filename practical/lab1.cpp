#include<graphics.h>
#include<iostream>
using namespace std;
int main()
{	
	int gd,gm;
	initwindow(1280,728);
	setcolor(RED);
	line(200,200,450,450);
	cout<<getmaxx()<<endl<<getmaxy();
	setcolor(BLUE);
	circle(200,200,100);
	putpixel(20,20,YELLOW);
	rectangle(2,2,500,500);
	setfillstyle(HATCH_FILL,BLUE);
 ellipse(200,200,0,360,150,200);
	floodfill(99,99,BLUE);
	getch();
	
	return 0;
}