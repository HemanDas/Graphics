#include<graphics.h>
#include<iostream>
#include<conio.h>
#include<dos.h>
void ellipse(float xc,float yc,float a,float b)
{
    float p=b*b-a*a*b+a*a/4;
    float x=0, y=b;
    while(2*b*b*x <= 2*a*a*y)
    {
if(p < 0)
{
   x++;
   p = p+2*b*b*x+b*b;
}
else
{
   x++;
   y--;
   p = p+2*b*b*x-2*a*a*y-b*b;
}


    putpixel(xc+x,yc+y,RED);
    putpixel(xc+x,yc-y,BLUE);
    putpixel(xc-x,yc+y,YELLOW);
    putpixel(xc-x,yc-y,GREEN);
    delay(50);
     }


    p=b*b*(x+0.25)*(x+0.25)+a*a*(y-1)*(y-1)-a*a*b*b;
    while(y > 0)
    {
if(p <= 0)
{
   x++;
   y--;
   p = p+2*b*b*x-2*a*a*y+a*a;
}
else
{
   y--;
   p = p-2*a*a*y+a*a;
}
 putpixel(xc+x,yc+y,RED);
 putpixel(xc+x,yc-y,BLUE);
 putpixel(xc-x,yc+y,YELLOW);
 putpixel(xc-x,yc-y,GREEN);
 delay(50);

    }
}
int main()
{
   initwindow(900,900);
    ellipse(350,250,100,200);

    getch();
}