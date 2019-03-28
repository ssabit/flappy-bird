/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"
#include <Windows.h>
#include <MMSystem.h>


	int page=0;
	char str1[30];
	char str2[30];
	int score=0;

//for bird death
	int m=10;

// block hight from bottom
	int p=20;

//screen resolution
	int screen_widith=1024;
	int screen_length=512;

//bird
	int	x=150;
	int y=200;

// Block width
	int wr=40;

//block	(x,y)
	int a=(300-p);
	int b=30;

	int c=(300-p);
	int d=350;

	int e=(630-p);
	int f=30;

	int g=(630-p);
	int h=350;

	int i=(930-p);
	int j=30;

	int k=(930-p);
	int l=350;
//block length
	int b1=225;
	int b2=400;
	int b3=225;
	int b4=400;
	int b5=225;
	int b6=400;

//bird size
	int bw=40;	//width
	int bl=32;  // length
//menu
	int mx=0;
	int my=0;

	//loading
	int q1=380;
	int q2=240;


/*
	function iDraw() is called again and again by the system.
*/





void iDraw()
{

	iClear();

if(page==0){
	
	iShowBMP(q1,q2,"loading.bmp");
	}	


if(page==1){

	iShowBMP(0,0,"firstpage.bmp");
	iShowBMP(100,80,"help.bmp");
	iShowBMP(428,80,"play.bmp");
	iShowBMP(756,80,"exit.bmp");
	}

if(page==2){
	iShowBMP(0, 0,"background.bmp");
//bird
	iShowBMP(x, y, "bird.bmp");
//block 1,2
	iSetColor(0,120,0);
	iFilledRectangle(a,b,wr,b1);
	iSetColor(0,128,0);
	iFilledRectangle(c,d,wr,b2);
//block 3,4
	iSetColor(0,128,0);
	iFilledRectangle(e,f,wr,b3);
	iSetColor(0,128,0);
	iFilledRectangle(g,h,wr,b4);
//block 5,6
	iSetColor(0,128,0);
	iFilledRectangle(i,j,wr,b5);
	iSetColor(0,128,0);
	iFilledRectangle(k,l,wr,b6);


//score
	iSetColor(0,0,0);
	iText(430, 494,"Score: ",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(490, 494, str2, GLUT_BITMAP_TIMES_ROMAN_24);

//game over
	if(x+30>=a && x<=a+30 && y<=b1 || x+30>=e && x<=e+30 && y<=b3 || x+30>=i && x<=i+30 && y<=b5 || x+30>=c && x<=c+30 && y+32>=b2 || x+30>=g && x<=g+30 && y+32>=b4 || x+30>=j && x<=j+30 && y+32>=b6 || y<=30 )
	{

		PlaySound(TEXT("sfx_hit.wav"), NULL, SND_SYNC);
		page=4;
		PlaySound(TEXT("sfx_die.wav"), NULL, SND_ASYNC);
	
	}
}

if(page==3){
		iShowBMP(0,1,"help1.bmp");
		iShowBMP(250,0,"help2.bmp");
		iShowBMP(8,10,"back.bmp");
	}

	if(page==4){
	iShowBMP(0,0,"background.bmp");
	iShowBMP(0, 260, "gameover.bmp");
	iSetColor(0,0,0);
	iText(430, 494,"Score: ",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(490, 494, str1, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(490, 494, str2, GLUT_BITMAP_TIMES_ROMAN_24);


	iShowBMP(240,80,"menu.bmp");
	iShowBMP(652,80,"exit.bmp");
	iShowBMP(150, 28, "bird2.bmp");
	iShowBMP(0, 3, "ground.bmp");
	}
}






void iMouseMove(int mx, int my)
{
	//place your codes here
}




void iMouse(int button, int state, int mx, int my)
{
if(page==2){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		if(y<470 && y>30)
			y+=20;
	PlaySound(TEXT("sfx_wing.wav"), NULL, SND_ASYNC);
	}

}

// menu help
	if(page==1){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){

		if(mx>=100 && mx<=228 && my>=80 && my<=144){
		page=3;
		}
	}

}

//menu play
if(page==1){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		if(mx>=428 && mx<=556 && my>=80 && my<=144){
	     PlaySound(TEXT("sfx_swooshing.wav"), NULL, SND_ASYNC);
			page=2;

		}
	}
}

// menu exit
if(page==1){
   if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
	   if(mx>=756 && mx<=884 && my>=80 && my<=144){
		exit(0);
	   }
	}
}
//help back
if(page==3){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
  	   if(mx>=9 && mx<=70 && my>=10 && my<=72)
		page=1;
	   }
	}

//game over
if(page==4){

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){

		if(mx>=240 && mx<=368 && my>=80 && my<=144){
		page=1;

			x=150;
			y=200;
			score=0;
			a=(300-p);
			b=30;
			c=(300-p);
			d=350;
			e=(630-p);
			f=30;
			g=(630-p);
			h=350;
			i=(930-p);
			j=30;
			k=(930-p);
			l=350;

		}
	}
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){

		if(mx>=652 && mx<=908 && my>=80 && my<=144){
		exit(0);
		}
	}


}


}


/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if(page==2){
	if(key == ' ')
	{
			if(y<470 && y>30)
			y+=20;
	PlaySound(TEXT("sfx_wing.wav"), NULL, SND_ASYNC);
	}
	}
	if(key=='p'){

	iPauseTimer(0);
	}


}
/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/


void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}



void Change(){

if(page==2){

	y-=20;


	if(a>-wr)
		a-=5;
	if(a<=-wr)
		a+=1060;

	if(c>-wr)
		c-=5;
	if(c<=-wr)
		c+=1060;


	if(e>-wr)
		e-=5;
	if(e<=-wr)
		e+=1060;


	if(g>-wr)
		g-=5;
	if(g<=-wr)
		g+=1060;

	if(i>-wr)
		i-=5;
	if(i<=-wr)
		i+=1060;


	if(k>-wr)
		k-=5;
	if(k<=-wr)
		k=1060;
	}

}


void loading(){

	if(page==0){
	
	page=1;
	
	
	}

}



void scores()
{
if(page==2){

	if(x>a+20 && x<a+30 || x>e+20 && x<e+30 || x>i+20 && x<i+30){
		PlaySound(TEXT("sfx_point.wav"), NULL, SND_ASYNC);
		score=score+1;
	}		sprintf(str2,"%d",score);
}

}





int main()
{



	sprintf(str2,"%d",score);
	iSetTimer(5000,loading);
	iSetTimer(500,scores);
	iSetTimer(300,Change);
	iInitialize(screen_widith,screen_length, "Flappy Bird");

	return 0;
}
