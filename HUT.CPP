#include<iostream.h>
#include<conio.h>
#include<graphics.h>
int main(){
  clrscr();
  int gd=DETECT, gm;
  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");


  //Drawing Sun
  int arr[]={300, 75, 150, 225, 450, 225, 300, 75 };
  setfillstyle(SOLID_FILL, YELLOW);
  circle(500, 60, 50);
  floodfill(500,60, WHITE);


  //Drawing Roof
  setfillstyle(SOLID_FILL, RED);
  drawpoly(4, arr);
  floodfill(300, 76, WHITE);


  //Drawing Wall
  setfillstyle(SOLID_FILL, 7);
  rectangle(175, 226, 425, 400);
  floodfill( 176, 227 ,WHITE );

  //Drawing Base
  setfillstyle(SOLID_FILL, WHITE);
  rectangle(0, 401, 900, 900);
  floodfill(1, 452, WHITE);

  //Drawing left Door
  setfillstyle(4, WHITE);
  rectangle(250, 323, 300, 400);
  floodfill(251, 324, WHITE);

  //Drawing right door
  setfillstyle(5 ,WHITE);
  rectangle(301, 323, 350, 400);
  floodfill(302, 324, WHITE);

  //Drawing window
  setfillstyle(2 ,WHITE);
  rectangle(350, 250, 410, 291);
  floodfill(351, 251, WHITE);


  getch();
  closegraph();
  return 0;
}