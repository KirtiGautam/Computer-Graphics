#include<iostream.h>
#include<conio.h>
#include<graphics.h>
int main(){
   int gd=DETECT, gm;
   initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
   putpixel(300, 150, RED);
   getch();
   return 0;
}