#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<winuser.h>
using namespace std;
int x=50,y=450,radius=15,a=0,b=600,c=1,page=0,posx=0,yx;
float g=8,dx,dy,tx=10,screenwidth=1566, screenheight=720;
void start(){
    settextstyle(4,HORIZ_DIR,3);
    outtextxy(400,400, "press enter to start or press escape to exit " );
}
void body(int x,int y,int radius){ 
        //stickman//
            //head//
            circle(x, y, radius);
            //eyes//
            circle(x-5, y-4, 3);
            circle(x+5, y-4, 3);
            //      //
            //mouth//
            line(x-5,y+8,x+5,y+8);
            //
            //torso//
            line(x, y + radius, x, y + radius + 20);
            //hand
            if(y+radius+40<590){

            line(x,y+radius+5,x-13,y+radius);
            line(x,y+radius+5,x+13,y+radius);
            }
            else{
            line(x,y+radius+5,x-10,y+radius+20);
            line(x,y+radius+5,x+10,y+radius+20);
            delay(5);
            }
            //legs//
            if(y+radius+20<600 &&y+radius+20>570&& x>x-15+c && x<x+15-c && GetAsyncKeyState(VK_RIGHT)){
            line(x,y+radius+20,x-10+c,y+radius+40);
            line(x,y+radius+20,x+10-c,y+radius+40);
            c+=1;
            if(c==15){ c=1;}
            }
            else if(y+radius+20<600 &&y+radius+20>570 && x>x-15+c && x<x+15-c && GetAsyncKeyState(VK_LEFT)){
            line(x,y+radius+20,x-10+c,y+radius+40);
            line(x,y+radius+20,x+10-c,y+radius+40);
            c+=1;
            if(c==15){ c=1;}
            }
            else if(y+radius+40<590){
            line(x,y+radius+20,x-14,y+radius+30);
            line(x,y+radius+20,x+14,y+radius+30);
            }
            else{
            line(x,y+radius+20,x-10,y+radius+40);
            line(x,y+radius+20,x+10,y+radius+40);
            }
            // Sun
            setlinestyle(0,0,2);
            setfillstyle(SOLID_FILL,YELLOW);
            circle(x+1000,50,100);
            floodfill(x+1000,50,WHITE);
            //
            //ground
            //line(a,b,a+10000,b); 
            //ground color
            setfillstyle(SOLID_FILL,BROWN);

            rectangle(a,b,a+10000,b+100);
            floodfill(5000,b+20,WHITE);
            //
            //ellipse as cloud and lines as a spike   
            //spikes in loop
            for(int j=1; j<40; j++){
            line(30+300*j,b,30+300*j,b-20);
            line(50+300*j,b,50+300*j,b-20);
            line(70+300*j,b,70+300*j,b-20);
            }
            //ellipse(cloud) in loops;
            for(int i=0; i<20;i++){
            setfillstyle(SOLID_FILL,WHITE);
            ellipse(100, 100, 0, 360, 200, 100);
            fillellipse(100+i*2000, 100,200, 100);
            fillellipse(340+i*2000, 50,200, 100);
            fillellipse(300+i*2000, 120,200, 100);
            }
            //

}
void gravity(){
            if(y+radius+46<b ){
                cleardevice();
                body(x,y,radius);
                delay(1);
                dy=dy+g;
            }
}
void background(){
        // background color according to coordinates / using as different environment scene
        if(x>7000){setbkcolor(BLACK);}
        else if(x>5000&&x<6000){setbkcolor(LIGHTGRAY);}
        else if(x>6000&&x<7000){setbkcolor(LIGHTMAGENTA);}
        else if(x>4000&&x<5000){setbkcolor(RED);}
        else if(x>2000&&x<3000){setbkcolor(LIGHTBLUE);}
        else if(x>1000&&x<2000){setbkcolor(CYAN);}
        else{setbkcolor(2);}
}
void collision(){
    end:
    // using spike as an obstacle
    for(int j=1; j<50; j++){
    if( (y+radius+30>=b-20 && x-14>=30+300*j && x-14<=75+300*j)|| (y+radius+30>=b-20 && x+8>=30+300*j && x+8<=70+300*j)){
                
                main:
                setbkcolor(RED);

                cleardevice();
                settextstyle(4,HORIZ_DIR,4);
                outtextxy(screenwidth-1050,400, "You died.Press enter to restart" );
                if(GetAsyncKeyState(VK_RETURN)&1){ // setting it as a restart mechanism
                    dx=67;                         // placing player in starting position
                    posx=0;                        // resetting the coordinate of camera tracker for player in intital position
                    screenwidth=1566;
                    setviewport(posx,0,screenwidth,screenheight, 1);//placing the camera track in intial position
                    goto end;                       // exiting loop to continue the main program
                    cleardevice();}
                if(GetAsyncKeyState(VK_RIGHT)|| GetAsyncKeyState(VK_LEFT)|| GetAsyncKeyState(VK_UP)){// making the player stand still to show the "you are dead "message
                    goto main;
                }
    }}
}
int main(){
    // initializing velocity
    dx=x;
    dy=y;
    //
    initwindow(10000,700);   
    cleardevice();
    while (1)
    {
    
    start();
    if(GetAsyncKeyState(VK_RETURN)){
        while(1)
        {   
            // to remove flickering / buffering of the images seen in window
            setactivepage(page);
            setvisualpage(1-page);
            //
            cleardevice();
            body(x,y,radius);
            background();
            gravity();
            collision();
            if(GetAsyncKeyState(VK_RIGHT)&& x<=9000){      // max position that a player can go right is upto 9000
                dx+=10;                                    // player moves right direction with 10 velocity
            if(x>400 && x<=8000){                          //camera track only starts after player coordinate is greater than 400
            setviewport(posx,0,screenwidth,screenheight, 1);//camera track
            posx=posx-tx;
            screenwidth+=tx;}
            }
            if(GetAsyncKeyState(VK_LEFT)&&x>=17 && x<=9000){// min position that a player can go left is upto 17
                dx-=10;                                     // player moves left direction with 10 velocity
            if(x>300&&x<=8000){
            setviewport(posx,0,screenwidth,screenheight, 1);
            posx=posx+tx;
            screenwidth-=tx;}
            }
            if(GetAsyncKeyState(VK_UP)&1 && y>=500 && y+radius+30<600&& y+radius+30>580){        // max position that a player can go up is upto 9000
                for(int i=0; i<100;i++){
                dy-=1;                                      // loop for jump
                
                }
               //PlaySoundA((LPCSTR) "C:\\jump.mp3", NULL,SND_ASYNC);    
                if(GetAsyncKeyState(VK_RIGHT)){dx+=3;}  
                if(GetAsyncKeyState(VK_LEFT)){dx-=3;}  
            }
            
                
            page=1-page;
            x=dx;
            y=dy;
            if(GetAsyncKeyState(VK_ESCAPE)){break;}
            delay(1);
        }
        
            cleardevice();
    }
    if(GetAsyncKeyState(VK_ESCAPE)){break;}
    }
    getch();
    //closegraph();
}