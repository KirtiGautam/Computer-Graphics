#include <iostream.h>
#include <conio.h>
#include <graphics.h>

void midptellipse(float a, float b, float xc, float yc)
{
    float p, x, y;
    x = 0;
    y = b;
    p = (b * b) - (a * a * b) + (0.25 * a * a);
    do
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        if (p < 0)
        {
            x = x + 1;
            p = p + 2 * b * b * x + b * b;
        }
        else
        {
            x = x + 1;
            y = y - 1;
            p = p + 2 * b * b * x - 2 * a * a * y + b * b;
        }
    } while (2 * b * b * x < 2 * a * a * y);
    p = (b * b * (x + 0.5) * (x + 0.5)) + ((y - 1) * (y - 1) * a * a - a * a * b * b);
    do
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        if (p > 0)
        {
            y = y - 1;
            p = p - 2 * a * a * y + a * a;
        }
        else
        {
            x = x + 1;
            y = y - 1;
            p = p - 2 * a * a * y + 2 * b * b * x + a * a;
        }
    } while (y != 0);
}

int main()
{
    clrscr();
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    midptellipse(50, 100, 200, 200);
    getch();
    return 0;
}