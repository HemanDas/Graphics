#include<iostream>
#include<graphics.h>
using namespace std;

void MCD(int, int ,int);
int r , x ,y;
int main()
{
	initwindow(900,900);
	cout<<"Enter the value of radius : ";
	cin>> r;
	cout<<"Enter the coordinate of center : ";
	cin>> x >> y;
	MCD(r,x,y);
	getch();
}

void MCD(int r, int x , int y)
{
	int po, x1 ,y1,k=0;
	
	po = 1-r;
	x1=0;
	y1=r;
	
	while(x1<=y1)
	{
		
		
		if (po<0)
		{
			x1=x1+1;
			y1=y1;
			po=po+2*x1+3;
		}
		else
		{
			x1=x1+1;
			y1=y1-1;
			po=po+2*x1-2*y1+5;
		}
		putpixel(x+x1,y+y1,RED);
		putpixel(x+y1,y+x1,WHITE);
		putpixel(x+y1,y-x1,YELLOW);
		putpixel(x+x1,y-y1,BLUE);
		putpixel(x-x1,y+y1,CYAN);
		putpixel(x-x1,y-y1,YELLOW);
		putpixel(x-y1,y-x1,RED);
		putpixel(x-y1,y+x1,BLUE);

    	delay(5);

	}
}