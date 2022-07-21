#include<graphics.h>
#include<iostream>
#include<math.h>
#include<conio.h>
#include<direct.h>
using namespace std;

int main(){
    int c,xt,yt,nx1,nx2,nx3,ny1,ny2,ny3,sx,sy,x1,y1,x2,y2,x3,y3;
    float r,t;
    char a;
    initwindow(1360,720);
    // line(200,200,500,500);
    // line(200,200,200,500);
    // line(200,500,500,500);
    // // int points[]={320, 150, 400, 250, 250, 350, 320, 150};
    // // drawpoly(4, points);
    cout<<"enter the coordinates of triangle"<<endl;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);
 
    cout<<"enter your choice \n 1.translation \n2.Rotation \n3.scaling \n4.exit"<<endl;
    cin>> c;
    switch(c)
    {
        case 1:
                cout<<"enter the translation factor"<<endl;
                cin>>xt>>yt;
                nx1=x1+xt;
                ny1=y1+yt;
                nx2=x2+xt;
                ny2=y2+yt;
                nx3=x3+xt;
                ny3=y3+yt;
                line(nx1,ny1,nx2,ny2);
                line(nx2,ny2,nx3,ny3);
                line(nx3,ny3,nx1,ny1);
                getch();
                break;
        case 2:
                cout<<"enter the angle of rotation"<<endl;
                cin>>r;
                t=(3.14*r)/180;
                nx1=abs(x1*cos(t)-y1*sin(t));
                ny1=abs(x1*sin(t)+y1*cos(t));
                nx2=abs(x2*cos(t)-y2*sin(t));
                ny2=abs(x2*sin(t)+y2*cos(t));
                nx3=abs(x3*cos(t)-y3*sin(t));
                ny3=abs(x3*sin(t)+y3*cos(t));
                line(nx1,ny1,nx2,ny2);
                line(nx2,ny2,nx3,ny3);
                line(nx3,ny3,nx1,ny1);
                getch();
                break;
        case 3: 
                cout<<"Enter the scalling factor"<<endl;
                cin>>sx>>sy;
                nx1=x1*sx;
                ny1=y1*sy;
                nx2=x2*sx;
                ny2=y2*sy;
                nx3=x3*sx;
                ny3=y3*sy;
                line(nx1,ny1,nx2,ny2);
                line(nx2,ny2,nx3,ny3);
                line(nx3,ny3,nx1,ny1);
                getch();
                break;
        case 4:
                break;
        default:
                cout<<"enter the correct choice"<<endl;
                closegraph();
                break;
    }
 
    getch();
}

