#include<iostream.h>
#include<conio.h>
#include<graphics.h>

class wheel{
   public:
	  void circle(int, int, int );
	  void line(int, int, int, int);
	  int round(float a){return (a+0.5);}
};
void wheel::line(int xin, int yin, int xfin, int yfin ){
   int dx=xfin-xin, dy=yfin-yin, steps;
   if(dx>dy)
       steps=dx;
   else
       steps=dy;
   float xincr=dx/steps, yincr=dy/steps;
   for(int i=0;i<steps;i++){
       xin+=xincr;
       yin+=yincr;
       putpixel(round(xin), round(yin), BLACK);
   }
}
void wheel:: circle(int x_centre, int y_centre, int r){

    int x = r, y = 0;

    putpixel( x + x_centre, y + y_centre, BLUE);

    if (r > 0)
    {
	putpixel( x + x_centre, -y + y_centre, BLUE);
	putpixel( y + x_centre, x + y_centre, BLUE);
	putpixel( -y + x_centre, x + y_centre, BLUE);
    }

    int P = 1 - r;
    while (x > y)
    {
	y++;

	if (P <= 0)
	    P = P + 2*y + 1;

	else
	{
	    x--;
	    P = P + 2*y - 2*x + 1;
	}

	if (x < y)
	    break;

	putpixel( x + x_centre, y + y_centre, BLUE);
	putpixel( -x + x_centre, y + y_centre, BLUE);
	putpixel( x + x_centre, -y + y_centre, BLUE);
	putpixel( -x + x_centre, -y + y_centre, BLUE);

	if (x != y)
	{
	    putpixel( y + x_centre, x + y_centre, BLUE);
	    putpixel( -y + x_centre, x + y_centre, BLUE);
	    putpixel( y + x_centre, -x + y_centre, BLUE);
	    putpixel( -y + x_centre, -x + y_centre, BLUE);
	}
    }

}


int main()
{
    clrscr();
    wheel w;
    int gd=DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    setfillstyle(SOLID_FILL, WHITE);
    w.circle(150, 150, 100);
    floodfill(150, 150, BLUE);
    w.line(50, 150, 250, 150);
    w.line(150, 50, 150, 250);
    w.line(0, 250, 650, 250);
    getch();
    return 0;
}