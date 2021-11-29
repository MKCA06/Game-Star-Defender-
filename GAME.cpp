#include<iostream.h>
#include<ctype.h>
#include<process.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>

void border();
void game();
void entrance();
void loading();
void menu();

void loading()
{
	clrscr();
	int gdriver = DETECT, gmode, errorcode;
	int left, top, right, bottom;
	initgraph(&gdriver, &gmode, "");
	delay(2000);
	left = getmaxx() / 2 - 100;
	top = getmaxy() / 2 - 10;
	right = getmaxx() / 2 + 100;
	bottom = getmaxy() / 2 + 10;
	setcolor(RED);
	settextstyle(TRIPLEX_FONT , 0 ,3);
	outtextxy(left+40,bottom+5,"Loading . . .");
	setcolor(WHITE);
	rectangle(left,top,right,bottom);
	randomize();
	setcolor(GREEN);
	for(int i=left+2 ; i<=right-2 ; i++)
	{
		int k=random(35);
		delay(k);
		rectangle(left+2,top+2,i,bottom-2);
	}
	closegraph();
	clrscr();

}

void entrance()
{
	clrscr();
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "");
	int x=getmaxx(),y=getmaxy(),xm=getmaxx() / 2;
	setcolor(RED);
	delay(500);
	for(int p=0 ;  p<y ; p++ )
	{
		line(xm,0,0,p);
		line(xm,0,x,p);
		delay(3);
	}
	setcolor(BLUE);
	for(int r=x,R=0 ; R<=xm && r>=xm ; R++,r-- )
	{
		line(xm,0,R,y);
		line(xm,0,r,y);
		delay(3);
	}
	setcolor(GREEN);
	for(int q=xm,Q=xm ; q<=x && Q>=0 ; q++,Q-- )
	{
		line(xm,y,Q,0);
		line(xm,y,q,0);
		delay(3);
	}
	setcolor(CYAN);
	for(int t=0 ;  t<=y ; t++ )
	{
		line(xm,y,0,t);
		line(xm,y,x,t);
		delay(3);
	}
	delay(50);
	setcolor(WHITE);
}

void border()
{
	delay(200);
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "");
	setbkcolor(BLUE);
	int x=getmaxx()-2,y=getmaxy()-2,xm=getmaxx() / 2;
	setlinestyle(DASHED_LINE,0,2);
	setcolor(RED);
	for(int i=xm,j=xm,w=2000 ; i>0 && j<x ; i--,j++,w++ )
	{
		line(xm,2,i,2);
		line(xm,6,i,6);
		line(xm,2,j,2);
		line(xm,6,j,6);
		delay(3);
		sound(w);
	}
	delay(50);
	for(int k=0,e=3000 ; k<y ; k++,e++)
	{
		line(2,2,2,k);
		line(7,2,7,k);
		line(x-3,2,x-3,k);
		line(x-8,2,x-8,k);
		delay(3);
		sound(e);
	}
	delay(50);
	for(int a=0,b=x,q=w ; a<=xm && b>=xm ; b--,a++,q=q-4)
	{
		line(2,y,a,y);
		line(2,y-6,a,y-6);
		line(x,y,b,y);
		line(x,y-6,b,y-6);
		delay(3);
		sound(q);
	}
	nosound();
}
void game()
{
	replay:
	char name[20];
	int gdriver = DETECT, gmode, errorcode;
	int left, top, right, bottom;
	initgraph(&gdriver, &gmode, "");
	left = getmaxx() / 2 - 100;
	top = getmaxy() / 2 - 6;
	right = getmaxx() / 2 + 100;
	bottom = getmaxy() / 2 + 20;

	border();

	outtextxy(left+35,top-12, "Enter Your Name");
	setlinestyle(SOLID_LINE,0,3);
	rectangle(left,top,right,bottom);
	gotoxy(31,16);
	gets(name);

	_setcursortype(_NOCURSOR);
	setbkcolor(BLUE);
	border();
	char move,choice;
	int score=0,l=3;
	int xx=20;
	int x=40 ,y=25;
	int p=0,q=0,r=0;
	gotoxy(xx,4);
	cout<<"0";
	randomize();

	do
	{
		setbkcolor(BLUE);
		move = getch();


		if(move==75 && x>=8 && x<=72)
		{
			sound(500);
			delay(10);
			nosound();
			--x;
		}
		else if(move==77 && x>=7 && x<=71)
		{
			sound(500);
			delay(10);
			nosound();
			++x;
		}
		else if(move==32)
		{
			setcolor(4);
			sound(400);
			delay(50);
			nosound();
			for(int j=y-4 ; j>=4 ; j--)
			{
				gotoxy(x+1,j-1);
				cout<<"!";
				gotoxy(x+1,j);
				cout<<" ";
				delay(25);
			}
			gotoxy(x+1,j);
			cout<<" ";

			if(xx==x+1)
			{
				score++;
				sound(5000);
				delay(70);
				nosound();
				xx=random (63)+10;
				gotoxy(xx,4);
				cout<<"0";
			}
			else
			{
				l--;
			}

		}
		else if(move==27)
		{
			for(int i=2000 ; i>=0 ; i--)
			{
				sound(i);
				delay(1);
				nosound();
			}
			break;
		}
		if(score==10 && p==0)
		{
			for(int k=0 ; k<=2000  ; k++)
			{
				sound(k);
				gotoxy(35,11);
				cout<<"GREAT GOING";
				delay(1);
				nosound();
			}
			p++;
			gotoxy(35,11);
			cout<<"            ";
		}
		if(score==25 && q==0)
		{
			for(int k=0 ; k<=2000 ; k++)
			{
				sound(k);
				gotoxy(35,11);
				cout<<"MARVELLOUS";
				delay(1);
				nosound();
			}
			q++;
			gotoxy(35,11);
			cout<<"                ";
		}
		if(score==50 && r==0)
		{
			for(int k=0 ; k<=2000 ; k++)
			{
				sound(k);
				gotoxy(35,11);
				cout<<"PLAYI'N LIKE A PRO";
				delay(1);
				nosound();
			}
			r++;
			gotoxy(35,11);
			cout<<"                      ";
		}
		gotoxy(x-5,y-1);
		cout<<" * ";
		gotoxy(x-4,y);
		cout<<" * ";
		gotoxy(x-2,y-2);
		cout<<" * ";
		gotoxy(x-2,y-1);
		cout<<" * ";
		gotoxy(x-2,y);
		cout<<" * ";
		gotoxy(x,y);
		cout<<" * ";
		gotoxy(x,y-1);
		cout<<" * ";
		gotoxy(x,y-2);
		cout<<" * ";
		gotoxy(x,y-3);
		cout<<" * ";
		gotoxy(x+2,y);
		cout<<" * ";
		gotoxy(x+2,y-1);
		cout<<" * ";
		gotoxy(x+2,y-2);
		cout<<" * ";
		gotoxy(x+4,y);
		cout<<" * ";
		gotoxy(x+5,y-1);
		cout<<" * ";
		gotoxy(6,2);
		cout<<"YOUR SCORE";
		gotoxy(10,3);
		cout<<score;
		gotoxy(64,2);
		cout<<"LIVES LEFT";
		gotoxy(70,3);
		cout<<l;
		gotoxy(36,2);
		cout<<name;
	}while(l>=0);
	cleardevice();
	border();
	gotoxy(35,7);
	cout<<"GAME OVER";
	gotoxy(34,10);
	cout<<"YOUR SCORE";
	gotoxy(39,11);
	cout<<score;
	gotoxy(33,13);
	cout<<"PLAY AGAIN (Y/N) ";
	lb:
	gotoxy(39,14);
	cin>>choice;
	if(choice=='Y' || choice=='y')
	{
		loading();
		goto replay;
	}
	else if(choice=='N' || choice=='n')
	{
		for(int i=2000 ; i>=0 ; i--)
		{
			sound(i);
			delay(1);
			nosound();
		}
		exit(0);
	}
	else
	{
		cout<<"INVALID ENTRY ";
		goto lb;
	}
}


void main()
{
	clrscr();
	entrance();
	loading();
	game();
}














