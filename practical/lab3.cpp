#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
void BLA(float x1 ,float y1,float x2 ,float y2 )
{
	float xinc , yinc , po, dx ,dy;
	dx=fabs(x2-x1);
	dy=fabs(y2-y1);

	if (x2>x1)
	 xinc=1;
	else
	 xinc=-1;

	if (y2>y1)
	 yinc=1;
	else
	 yinc=-1;

	putpixel(x1,y1,RED);

	if (dx>dy)
	{
	 po= 2*dy - dx;
	 for(int i=0; i<dx ; i++)
	 	{
		 	if(po<0)
		 	{
				x1=x1+xinc;
				y1=y1+yinc;
				po=po+2*dy;
			}
			else
			{
				x1=x1+xinc;
				y1=y1+yinc;
				po=po+2*dy-2*dx;
			}
			putpixel(x1,x2,YELLOW);
			delay(100);
	 	}

	}
	else
	{
	 po= 2*dx - dy;
	 for(int i=0; i<dy ; i++)
	 	{
		 	if(po<0)
		 	{
				x1=x1;
				y1=y1+yinc;
				po=po+2*dx;
			 }
			else
			{
				x1=x1+xinc;
				y1=y1+yinc;
				po=po+2*dx-2*dy;
			}
			putpixel(x1,y1,YELLOW);
			delay(100);
	 	}

	}

}

int main()
{
	initwindow(1000,900);
	float x1 ,y1 ,y2, x2;
	cout<<"Enter the initial and final coordinates of line:"<<endl;
	cin>> x1 >> y1 >>x2>>y2;
	BLA(x1,y1,x2,y2);
	return 0;
}