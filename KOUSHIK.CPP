#include <iostream.h>
#include <graphics.h>
#include <bios.h>
#include <process.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>


int knt;
int x1,x2,x3,x4,x5;
int x,y;
int myx,myy;
void mainmenu();
void move();
int score=0;
char string[50];
int a,b;
int k;
int m,n;
void me();
void game();
void enemy1(int,int);
void enemy(int,int);
void enemy3(int,int);
int checkkb();
void enemy2(int,int);
void direction();
void spawn();

void end(int xx,int yy)
{       if(knt!=1)
   {		  if(yy>=myy-20&&yy<=myy+20)
		  {
		  if(xx<=myx+10&&xx>=myx-10)
		  {
		  clrscr();
		  cleardevice();
		  setfillstyle(11,BROWN);
		  bar(0,0,getmaxx(),getmaxy());
		  setbkcolor(BLACK);
		  settextstyle(7,0,4);
		  setcolor(CYAN);

		  outtextxy(100,100,"Game over");
		  itoa(score, string, 10);
		  outtextxy(50,250,"score:");
		  outtextxy(250,250,string);
		  delay(5000);
		  exit(0);
		  } }
   }
 }
void cal()
{
 itoa(score, string, 10);
 settextstyle(0,0,1);
 outtextxy(550,50,"score: ");
 outtextxy(600,50,string);
}
void pointer(int b)
{
 int a=100;
 int pol[9];
 pol[0]=a;
 pol[1]=b;
 pol[2]=a+30;
 pol[3]=b-30;
 pol[4]=a+20;
 pol[5]=b+10;
 pol[6]=a+10;
 pol[7]=b-5;
 pol[8]=a;
 pol[9]=b;
 setfillstyle(SOLID_FILL,getmaxcolor());
 fillpoly(5,pol);
}
void game()
{
   setbkcolor(BLACK);
   int i=0,m=0,n=0;
   myx = getmaxx()/2;
   myy = getmaxy()-40;
   me();
   int k=1;
    while(k)
   {
      me();
      move();
      spawn();
      move();
      score=score+k*50;
      checkkb();
      k++;
      knt=0;
}
}
void mainmenu()
{

 setbkcolor(BLACK);
 int maxx=getmaxx(),maxy=getmaxy(),poly[9];
poly[0] = 100;
poly[1] = 3*(maxy / 4)-100;

poly[2] = maxx - 30;
poly[3] = 20;

poly[4] = maxx - 200;
poly[5] = maxy - 20;

poly[6] = maxx / 2;
poly[7] = maxy / 2;

poly[8] = 350;
poly[9]=maxy/2-50;
 int j=0;
 for(int i=0;i<=360;i++)
 {
 setcolor(WHITE);
 settextstyle(4,0,5);
 outtextxy(10,60,"SPACE INVADER");
 setcolor(RED);
 if(i%20==0)
 j++;
 setfillstyle(j,6);
 ellipse(200,380,0,i,150,80);
 fillpoly(4, poly);
 ellipse(i,120,i,360,5,2);
 delay(10);
 }
 setcolor(WHITE);
 settextstyle(3,1,3);
 outtextxy(80,310,"Done by ");
 settextstyle(7,0,3);
 outtextxy(120,330,"Arjun Raju");
 outtextxy(120,360,"Babu A");
 outtextxy(120,390,"Kawshik K");
 delay(1500);

 clrscr();
 cleardevice();

 top:
 int y1;
 if(y1>285) y1=185;
 if(y1<185) y1=285;
 pointer(y1);
 setbkcolor(WHITE);
 settextstyle(3,0,5);
 setcolor(RED);
 outtextxy(150,150," Game");
 outtextxy(150,200," Instructions");
 outtextxy(150,250," Exit");
 while(!kbhit())
 {
 for(i=0;i<=getmaxcolor();i++)
 {
 setcolor(BLUE);
 pointer(y1);
 setcolor(i);
 outtextxy(100,20,"MAIN MENU");
 settextstyle(8,0,7);
 delay(80);
 }
 }
 while(a!=7181)
 {
	  if(kbhit()) a=bioskey(0);
	  if(a==20480)
	  {
		  cleardevice(); y1+=50;a=0;goto top;
	  }
	  else if(a==18432)
	  {
		  cleardevice(); y1-=50;a=0;goto top;
	  }
	  else if(a==7181)
	  {
	   if(y1==185)
	   {
	    knt=1;
	    setcolor(MAGENTA);
	    clrscr();
	    setbkcolor(LIGHTGRAY);
	    settextstyle(4,0,5);
	    delay(200);
	    outtextxy(50,50,"Loading.");
	    delay(250);
	    clrscr();
	    outtextxy(50,50,"Loading..");
	    delay(500);
	    clrscr();
	    outtextxy(50,50,"Loading...");
	    delay(50);
	    clrscr();
	    setcolor(WHITE);
	    game();
	   }
	   else if(y1==235)
	   {
	    cleardevice();
	    setbkcolor(MAGENTA);
	    setcolor(BLUE);
	    settextstyle(7,0,4);
	    outtextxy(100,250,"Press arrow keys to move");
	    getch();
	    cleardevice();
	    outtextxy(100,250,"Dodge ships to get points");
	    getch();
	    cleardevice();
	    outtextxy(100,250,"Good Luck!!");
	    getch();
	    cleardevice();
	    goto top;
	   }
	   else
	   exit(0);
	  }}}

void me()
{
 checkkb();
 int radius=20;
 cal();
setfillstyle(CLOSE_DOT_FILL,getmaxcolor());
ellipse(myx,myy,0,360,8,30);                      //body
ellipse(myx,myy-10,0,180,5,15);
arc(myx,myy-10,180,360,5);

arc(myx,myy+3,120,245,radius-5);                  //wings
arc(myx,myy+3,295,415,radius-5);
arc(myx+5,myy-30,150,255,radius+30);
arc(myx-5,myy-30,285,390,radius+30);
arc(myx+20,myy-60,190,240,radius+40);
arc(myx-20,myy-60,300,350,radius+40);

arc(myx+12,myy-17,215,325,3);                      //right gun
arc(myx+12,myy-15,215,325,3);
arc(myx+12,myy-19,215,325,3);
arc(myx+12,myy-21,215,325,3);
arc(myx+12,myy-23,215,325,3);
arc(myx+12,myy-25,215,325,3);
ellipse(myx+12,myy-25,0,360,3,2);

arc(myx-12,myy-15,215,325,3);                       //left gun
arc(myx-12,myy-17,215,325,3);
arc(myx-12,myy-19,215,325,3);
arc(myx-12,myy-21,215,325,3);
arc(myx-12,myy-23,215,325,3);
arc(myx-12,myy-25,215,325,3);
ellipse(myx-12,myy-25,0,360,3,2);

   }
void move()
{
if(kbhit())
   {
   int c=bioskey(0);
   if(c==19200)
   {
    if(myx>50)
   myx=myx-50;
   }
   else if(c==19712)
   {
    if(myx<getmaxx()-50)
    myx=myx+50;
   }
   }
     me();
   }
	   void spawn()
	   {
	    int ran;
	    int y=0;
	    int x1=random(50)+50;
	    int x2=random(50)+160;
	    int x3=random(50)+270;
	    int x4=random(50)+380;
	    int x5=random(50)+490;
	    int r=random(3)+1;
	    if(r==1)
	    {
	    ran=random(5);
	    y=0;
	    if(ran==0)
	    {
	    while(y<getmaxy()-10)
	    {
	    enemy(x3,y);
	    enemy3(x5,y);
	    enemy2(x1,y);
	    y++;
	    checkkb();
	    delay(4);
	    cleardevice();
	    move();
	    }
	    }

	    if(ran==1)
	    {
	    while(y<getmaxy()-10)
	    {
	    move();
	    enemy2(x1,y);
	    enemy3(x4,y);
	    enemy1(x3,y);
	    y++;
	    checkkb();
	    delay(3);
	    cleardevice();
	    move();
	    }
	    }
	    else if(ran==2)
	    {
	    while(y<getmaxy()-10)
	    { move();
	    enemy(x2,y);enemy1(x3,y);enemy3(x4,y);
	    y++;
	    checkkb();
	    delay(3);
	    cleardevice();
	    move();
	    }
	    }
	    else if(ran==3)
	    {
	     while(y<getmaxy()-10)
	    {
	    move();
	    enemy(x2,y);
	    enemy2(x1,y);
	    enemy(x5,y);
	    y++;
	    checkkb();
	    delay(3);
	    cleardevice();
	    move();
	    }
	    }
	    else if(ran==4)
	    {
	    while(y<getmaxy()-10)
	     {
	     move();
	    enemy2(x3,y);
	    enemy2(x4,y);
	    enemy3(x5,y);
	    y++;
	       checkkb();
	     delay(3);
	     cleardevice();
	     move();
	      }
	    }
	    }
	    if(r==2)
	    {
	     ran=random(5);
	    int y=0;
	    if(ran==0)
	    { move();
	    while(y<getmaxy()-10)
	    {
	    enemy2(x3,y);
	    enemy1(x5,y);
	    enemy3(x1,y);
	    enemy(x2,y);
	    y++;
	    checkkb();
	    delay(5);
	    cleardevice();
	    move();
	    }
	    }

	    if(ran==1)
	    {
	    while(y<getmaxy()-10)
	    {
	    move();
	    enemy3(x1,y);
	    enemy2(x2,y);
	    enemy1(x4,y);
	    enemy3(x3,y);
	    y++;
	      checkkb();
	    delay(3);
	    cleardevice();
	    move();
	    }
	    }
	    else if(ran==2)
	    {
	    while(y<getmaxy()-10)
	    {
	    move();
	    enemy3(x2,y);
	    enemy1(x3,y);
	    enemy2(x4,y);
	    y++;
	    checkkb();
	    delay(3);
	    cleardevice();
	    move();
	    }
	    }
	    else if(ran==3)
	    {
	     while(y<getmaxy()-10)
	     {
	     move();
	     enemy1(x2,y);enemy2(x1,y);enemy1(x4,y);enemy3(x5,y);
	     y++;
	     checkkb();
	     delay(3);
	     cleardevice();
	     move();
	    }
	    }
	    else if(ran==4)
	    {
	     while(y<getmaxy()-10)
	    {
	     move();
	     enemy1(x2,y);enemy(x3,y);enemy3(x4,y);enemy3(x5,y);
	     y++;
	     checkkb();
	     delay(3);
	     cleardevice();
	     move();
	    }
	    }
	    }

	    if(r==3)
	    {
	    ran=random(5);
	    y=0;
	    if(ran==0)
	    { move();
	    while(y<getmaxy()-10)
	    {
	    enemy1(x3,y);
	    enemy(x5,y);
	    y++;
	      checkkb();
	    delay(10);
	    cleardevice();
	    move();
	    }
	    }

	    if(ran==1)
	    {
	    while(y<getmaxy()-10)
	    { move();
	    enemy1(x2,y);enemy(x3,y);
	    y++;
	    checkkb();
	    delay(3);
	    cleardevice();
	    move();
	    }
	    }
	    else if(ran==2)
	    {
	    while(y<getmaxy()-10)
	    { move();
	    enemy1(x2,y);enemy(x4,y);
	    y++;
	      checkkb();
	    delay(3);
	    cleardevice();
	    move();
	    }
	    }
	    else if(ran==3)
	    {
	     while(y<getmaxy()-10)
	     { move();
	    enemy1(x1,y);enemy(x5,y);
	    y++;
	       checkkb();
	     delay(3);
	     cleardevice();
	     move();
	      }
	    }
	    else if(ran==4)
	    {
	    while(y<getmaxy()-10)
	     { move();
	     move();
	    enemy(x3,y);enemy1(x4,y);
	    y++;
	       checkkb();
	     delay(3);
	     cleardevice();
	     move();
	      }
	    }
	    move();
	    }  }


   void enemy3(int x,int y)
   {
   end(x,y);
    int notex=0;
   if(knt==1)
   {
    if(y>=myy-30)
    {
     if((x>=myx-50)&&(x<=myx+50))
     {
      notex=1;
      knt=0;
     }
    }
   }
   if(notex!=1)
   {
   ellipse(x,y,0,180,10,10);
   line(x-10,y,x+10,y);
   line(x-10,y,x-7,y-20);
   line(x+10,y,x+7,y-20);
   line(x-7,y-20,x-7,y-50);
   line(x+7,y-20,x+7,y-50);
   line(x-7,y-50,x-5,y-55);
   line(x-5,y-55,x-3,y-50);
   line(x+7,y-50,x+5,y-55);
   line(x+5,y-55,x+3,y-50);
   line(x-3,y-50,x-3,y-15);
   line(x+3,y-50,x+3,y-15);
   pieslice(x-3,y-15,0,60,5);
   }
   }

   void enemy2(int x,int y)
   {
    end(x,y);
    int notex=0;
   if(knt==1)
   {
    if(y>=myy-30)
    {
     if((x>=myx-50)&&(x<=myx+50))
     {
      notex=1;
      knt=0;
     }
    }
   }

   if(notex!=1)
   {
   ellipse(x,y,180,360,4,16);
   line(x-3,y,x-3,y-45);
   line(x-1,y,x-1,y-30);
   line(x+3,y,x+3,y-45);
   line(x+1,y,x+1,y-30);
   line(x+3,y-35,x+6,y-45);
   line(x-3,y-35,x-6,y-45);
   ellipse(x+6,y-35,270,90,5,10);
   ellipse(x-6,y-35,90,270,5,10);
   line(x+6,y-20,x+30,y-55);
   line(x,y-45,x+30,y-60);
   ellipse(x+32,y-58,0,360,2,8);
   line(x-6,y-20,x-30,y-55);
   line(x,y-45,x-30,y-60);
   ellipse(x-32,y-58,0,360,2,8);
   }
   }

   void enemy1(int x,int y)
   {
   int notex=0;
   end(x,y);
   if(knt==1)
   {
    if(y>=myy-30)
    {

     if((x>=myx-50)&&(x<=myx+50))
     {
      notex=1;
      knt=0;
     }
    }
   }
   if(notex!=1)
   {
   line(x+40,y+5,x+40,y-15);
   line(x-40,y+5,x-40,y-15);
   line(x+40,y-15,x+25,y-15);
   line(x-40,y-15,x-25,y-15);

   circle(x+20,y-10,4);
   line(x+24,y-10,x+24,y-17);
   line(x+16,y-10,x+16,y-23);
   line(x+24,y-17,x+22,y-17);
   line(x+22,y-17,x+22,y-30);
   line(x+16,y-23,x+18,y-23);
   line(x+18,y-23,x+18,y-30);
   line(x+18,y-30,x+21,y-30);

   circle(x-20,y-10,4);
   line(x-24,y-10,x-24,y-17);
   line(x-16,y-10,x-16,y-23);
   line(x-24,y-17,x-22,y-17);
   line(x-22,y-17,x-22,y-30);
   line(x-16,y-23,x-18,y-23);
   line(x-18,y-23,x-18,y-30);
   line(x-18,y-30,x-21,y-30);

   ellipse(x,y-15,0,180,15,50);
   ellipse(x,y+3,180,360,40,8);

   ellipse(x,y+8,0,180,19,10);
   ellipse(x,y,0,180,10,5);

   ellipse(x,y-10,0,180,15,5);
   ellipse(x,y-10,0,180,15,11);
   ellipse(x,y-10,0,180,15,17);
   ellipse(x,y-10,0,180,15,23);
   ellipse(x,y-10,0,180,15,29);
   ellipse(x,y-10,0,180,15,34);
   ellipse(x,y-10,0,180,15,40);
   ellipse(x,y-10,0,180,15,46);
   ellipse(x,y-10,0,180,15,52);

   line(x+20,y+5,x+20,y-1);
   line(x-20,y+5,x-20,y-1);
   line(x-20,y-1,x-27,y-6);
   line(x-27,y-6,x-27,y-15);
   line(x+20,y-1,x+27,y-6);
   line(x+27,y-6,x+27,y-15);

   line(x+39,y+2,x+39,y-14);
   line(x-39,y+2,x-39,y-14);
   line(x+37,y+3,x+37,y-12);
   line(x-37,y+3,x-37,y-12);
   line(x+35,y+4,x+35,y-10);
   line(x-35,y+4,x-35,y-10);
   line(x+33,y+5,x+33,y-8);
   line(x-33,y+5,x-33,y-8);
   line(x+31,y+6,x+31,y-6);
   line(x-31,y+6,x-31,y-6);
   line(x+29,y+6,x+29,y-4);
   line(x-29,y+6,x-29,y-4);
   line(x+27,y+7,x+27,y-2);
   line(x-27,y+7,x-27,y-2);
   line(x+25,y+8,x+25,y);
   line(x-25,y+8,x-25,y);
   checkkb();
   }
   }
   void enemy(int x,int y)
   {
    end(x,y);
    int notex=0;
   if(knt==1)
   {
    if(y>=myy-30)
    {
     if((x>=myx-50)&&(x<=myx+50))
     {
      notex=1;
      knt=0;
     }
    }
   }
   if(notex!=1)
   {
   line(x,y,x-30,y-30);
   line(x,y,x+30,y-30);
   line(x-30,y-30,x-30,y-40);
   line(x+30,y-30,x+30,y-40);
   line(x-30,y-40,x-25,y-40);
   line(x+30,y-40,x+25,y-40);
   line(x-15,y-40,x-5,y-30);
   line(x+15,y-40,x+5,y-30);
   ellipse(x,y-30,0,360,5,2);
   circle(x+5,y-25,4);
   circle(x-5,y-25,4);
   circle(x-20,y-35,7);
   circle(x-20,y-35,5);
   circle(x+20,y-35,7);
   circle(x+20,y-35,5);
   line(x,y,x-15,y-40);
   line(x,y,x+15,y-40);
   checkkb();
   setcolor(WHITE);
   checkkb();
   }
   }

int checkkb()
{
  if(kbhit())
   {
    int a=bioskey(0);
    if(a==283)
    exit(0);
    if(a==6512)
    {
     top:
     int y1=150;
     setcolor(BLUE);
     circle(120,y1,5);
     setfillstyle(10,RED);
     bar(100,100,getmaxx()-100,getmaxy()-100);

     settextstyle(0,1,3);
     setcolor(GREEN);
     outtextxy(120,110,"Game Paused");
     settextstyle(7,0,5);
     outtextxy(130,150,"PRESS ANY KEY");
     outtextxy(135,210,"TO RESUME");
     delay(20);
     while(a!=7181)
 {
	  if(kbhit()) a=bioskey(0);
	  if(a==20480)
	  {
		  cleardevice(); y1+=50;a=0;goto top;
	  }
	  else if(a==18432)
	  {
		  cleardevice(); y1-=50;a=0;goto top;
	  }
	  else if(a==7181)
	  {
	   if(y1==150)
	   {
	   return 0;
	   }
	   else
	   exit(0);
	  }
 }
 }
 if(a==14624)
 {
  setcolor(YELLOW);
  line(myx+15,myy-5,myx+15,myy-355);
  line(myx-15,myy-5,myx-15,myy-355);
  delay(100);
  knt=1;
 }
 }}
int main(void)
{
   int gdriver = DETECT, gmode, errorcode;

   int poly[10];
   int radius = 100;

   initgraph(&gdriver, &gmode, "");

   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
   mainmenu();

   closegraph();
   return 0;
}

