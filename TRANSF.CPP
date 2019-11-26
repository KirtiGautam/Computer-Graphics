#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    int xin, xfin, yin, yfin;
    cout << "Enter initial x coordinate  --> ";
    cin >> xin;
    cout << "Enter initial y coordinate --> ";
    cin >> yin;
    cout << "Enter final x coordinate  --> ";
    cin >> xfin;
    cout << "Enter final y coordinate --> ";
    cin >> yfin;
    setcolor(2);
    line(xin, yin, xfin, yfin);

    int xt, yt;
    cout << "Enter x transformation --> ";
    cin >> xt;
    cout << "Enter y transformation --> ";
    cin >> yt;
    setcolor(4);
    line(xin + xt, yin + yt, xfin + xt, yfin + yt);

    double theta;
    cout << "Enter angle of rotation --> ";
    cin >> theta;
    theta *= (3.141592653589 / 180);
    setcolor(6);
    line(xin, yin, (int)(xin + ((xfin - xin) * cos(theta) - (yfin - yin) * sin(theta))), (int)(yin + ((xfin - xin) * sin(theta) + (yfin - yin) * cos(theta))));

    float scaleX, scaleY;
    cout << "Enter scaling factor of x -->";
    cin >> scaleX;
    cout << "Enter scaling factor of y -->";
    cin >> scaleY;
    setcolor(14);
    line(xin * scaleX, yin * scaleY, xfin * scaleX, yfin * scaleY);

    getch();
    return 0;
}