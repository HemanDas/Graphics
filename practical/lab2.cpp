#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;

void DDA_Implement(float x1, float y1, float x2 , float y2)
{
	float k=0 ,dx ,dy ,steps ,xinc ,yinc ,x ,y ;
	dx=abs(x2-x1);
	dy=abs(y2-y1);

	if (fabs(dx)>fabs(dy))
	{
		steps=fabs(dx);
	}
	else
		{
			steps=fabs(dy);
		}
	 xinc = dx/steps;
	 yinc = dy/steps;

	 x=x1;
	 y=y1;

	 do
	 {
	 	putpixel(x,y,YELLOW);
	 	delay(1);
	 	x=x+xinc;
	 	y=y+yinc;
	 	k++;
	 }while(k<=steps);
}
int main()
{
	initwindow(1000,900);
	DDA_Implement(100, 200, 150, 400);
	getch();
	return 0;
}