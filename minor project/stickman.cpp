#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<winuser.h>
using namespace std;
int x=50,y=450,radius=15,a=0,b=600,c=1,page=0,posx=0,yx=1,d=0;
float g=8,dx,dy,tx=10,screenwidth=1566, screenheight=720;
void start(){
    cleardevice();
    setcolor(RED);
	settextstyle(1,HORIZ_DIR,7);
    outtextxy(200,300, "Let's begin your adventure");
    setbkcolor(BLACK);
    setcolor(RED);
    settextstyle(1,HORIZ_DIR,yx);
    outtextxy(500,450, "Press enter to start or press escape to exit " );
    yx++;
    if(yx==3){yx=1;}

}
void intro()
{
    delay(2000);
	cleardevice();
	setcolor(CYAN);
	settextstyle(4,HORIZ_DIR,3);
    readimagefile("2.bmp",0,0,1600,700);
    outtextxy(350,350, "You are uncertain of the place you are right now" );
    delay(6000);
    cleardevice();
    readimagefile("1.bmp",0,0,1600,700);
    outtextxy(200,350, "To reach home you have to avoid spike in your path in different environment." );
    delay(6000);
    cleardevice();
    readimagefile("3.bmp",0,0,1600,700);
    outtextxy(350,350, "It's nearing night soon, so you need to be at home to be safe.");
    delay(6000);
    cleardevice();
    delay(2000);

}
void loading_screen()
{	
    cleardevice();
    for(int i=0;i<100;i=i+10)
    {
    	int e=i*2;
    	setcolor(RED);
    	line (200+e,200,400,200);
    	line (300,100+e,300,300);
    	delay(10);
    	int j=i*2.1;
    	setcolor(CYAN);
		line (200,200,400+j,200);
    	line (300,100,300,300+j);
    	delay(10);
    	int k=i*2.3;
		setcolor(BLUE);
		line (200,200,400,200+k);
    	line (300,100,300+k,300);
    	delay(10);
    	int l=i*2.6;
		setcolor(LIGHTGREEN);
		line (200,200,400,200+l);
    	line (300,100,300+l,300);
    	delay(10);
    	int m=i*2.5;
		setcolor(GREEN);
		line (200,200+m,400,200);
    	line (300+m,100,300,300);
        
	}
	setcolor(CYAN);
	settextstyle(4,HORIZ_DIR,6);
    outtextxy(500,350, "L O A D I N G" );
		for(int a=0;a<30;a=a+10) 		//main loop for loading dots
		{                  
				setcolor(CYAN);
				setfillstyle(SOLID_FILL,CYAN);
				rectangle(1000+a,385,1005+a,390);
				floodfill(1001+a,389,CYAN);
				delay(1000);
		}
		cleardevice();
        
}
void body(int x,int y,int radius){ 
        setcolor(WHITE);
        //castle building
            setcolor(WHITE);
            setfillstyle(SOLID_FILL,BROWN);
            rectangle(700,350,950,600);					//rectangle of main house structure
            floodfill(701,351,WHITE);
            
            setfillstyle(SOLID_FILL,LIGHTGRAY);
            rectangle(800,500,850,600);					//door
            floodfill(810,510,WHITE);
            
            setfillstyle(SOLID_FILL,LIGHTGRAY);
			rectangle(730,400,780,450);					//window
			floodfill(740,430,WHITE);
			
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			rectangle(870,400,920,450);					//window
			floodfill(900,430,WHITE);
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
            if(x>7100)
            {
                setfillstyle(SOLID_FILL,WHITE);
                fillellipse(x, 70,100, 100);
                setcolor(BLACK);
                setfillstyle(SOLID_FILL,BLACK);
                fillellipse(x+50, 70,100, 100);
            }
            else{
                setlinestyle(0,0,2);
                setfillstyle(SOLID_FILL,YELLOW);
                circle(x+800,50,100);
                floodfill(x+800,50,WHITE);
            }
            //
            //ground
            //line(a,b,a+10000,b); 
            //ground color
            setcolor(WHITE);
            setfillstyle(SOLID_FILL,BROWN);
            rectangle(a,b,a+10000,b+100);
            floodfill(x,b+20,WHITE);
            //
            //ellipse as cloud and lines as a spike   
            //spikes in loop
            for(int j=3; j<40; j++){
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
                //cleardevice();
                clearviewport();
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
    for(int j=3; j<40; j++){
    if( (y+radius+30>=b-20 && x-8>=30+300*j && x-9<=70+300*j)|| (y+radius+30>=b-20 && x+8>=30+300*j && x+8<=70+300*j)){
                
                main:
                setbkcolor(RED);

                //cleardevice();
                clearviewport();
                settextstyle(4,HORIZ_DIR,4);
                outtextxy(x+50,400, "You died.Press enter to restart" );
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
void postcredit()
{   
    if(x>820&&x<=850){
    //cleardevice();
    clearviewport();
    setbkcolor(BLACK);		
    clearviewport();
    //cleardevice();
    delay(10);
    setcolor(CYAN);
    settextstyle(4,HORIZ_DIR,7);
    outtextxy(screenwidth-1200,750-d, "Created/Coded by:");
    outtextxy(screenwidth-1200,200-d, "Congratulations");
    outtextxy(screenwidth-1500,1200-d, "Thank you for playing this game.");
    settextstyle(4,HORIZ_DIR,3);
    outtextxy(screenwidth-1100,400-d, "You have reached your home" );
    outtextxy(screenwidth-1200,450-d, "Well done on your journey, now you can be safe.");
    outtextxy(screenwidth-1100,500-d, "You can now have a good rest");
    settextstyle(4,HORIZ_DIR,4);
    outtextxy(screenwidth-1100,900-d, "Heman Das      (LEC076BCT012)" );
    outtextxy(screenwidth-1100,1000-d,"Sumeet Deshar(LEC076BCT034)" );
    if(d>=550)
    {
        setcolor(WHITE);
        settextstyle(4,HORIZ_DIR,2);
        outtextxy(screenwidth-400,650,"Press ESC to Exit" );
    }
    d++;
    
    screen:
    if(GetAsyncKeyState(VK_RIGHT)|| GetAsyncKeyState(VK_LEFT)|| GetAsyncKeyState(VK_UP))// making the player stand still to show the "you are dead "message
                {
                    goto screen;
                }
    }
}
int main(){
    // initializing velocity
    dx=x;
    dy=y;
    //
    initwindow(1500,700,"Way To Home?",0,0); 
   
    loading_screen();  
    cleardevice();
    intro();
    cleardevice();
    while (1)
    {
    
    start();
    delay(500);
    if(GetAsyncKeyState(VK_RETURN)){
        loading_screen();  
        while(1)
        {   
            // to remove flickering / buffering of the images seen in window
            setactivepage(page);
            setvisualpage(1-page);
            //
            //cleardevice();
            clearviewport();
            body(x,y,radius);
            background();
            postcredit();
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
                if(GetAsyncKeyState(VK_RIGHT)){dx+=3;}  
                if(GetAsyncKeyState(VK_LEFT)){dx-=3;}  
            }
            //to end at castle door
	        	
            page=1-page;
            x=dx;
            y=dy;
            if(GetAsyncKeyState(VK_ESCAPE)){break;}
            delay(1);
        }
        
            //cleardevice();
            clearviewport();
    }
    if(GetAsyncKeyState(VK_ESCAPE)){break;}
    }
    getch();
    //closegraph();
}