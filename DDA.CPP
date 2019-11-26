#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#define round(a) ((int)(a + 0.5))

void dda(int xin, int yin, int xfin, int yfin)
{
    int dx = xfin - xin, dy = yfin - yin, steps;
    if (dx > dy)
        steps = dx;
    else
        steps = dy;
    float xincr = dx / steps, yincr = dy / steps;
    for (int i = 0; i < steps; i++)
    {
        xin += xincr;
        yin += yincr;
        putpixel(round(xin), round(yin), GREEN);
    }
}

void bresenham(int xin, int yin, int xfin, int yfin)
{
    int dx = xfin - xin, dy = yfin - yin;
    int d = (2 * dy) - dy;
    for (int i = 0; i < dx; i++)
    {
        if (d >= 0)
        {
            d = d + (2 * (dy - dx));
            yin += 1;
        }
        else
            d = d + (2 * dy);
        xin += 1;
        putpixel(xin, yin, GREEN);
    }
}

int main()
{
    int xin, yin, xfin, yfin;
    cout << "Enter initial x coordinates-->";
    cin >> xin;
    cout << "Enter initial y coordinates-->";
    cin >> yin;
    cout << "Enter final x coordinates-->";
    cin >> xfin;
    cout << "Enter final y coordinates-->";
    cin >> yfin;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    dda(xin, yin, xfin, yfin);
    bresenham(xin + 200, yin, xfin + 200, yfin);
    getch();
    return 0;
}