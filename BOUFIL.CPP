#include <iostream.h>
#include <conio.h>
#include <graphics.h>

void boundaryfill(int x, int y, int fill, int bound)
{
    if (getpixel(x, y) != fill && getpixel(x, y) != bound)
    {
        putpixel(x, y, fill);
        boundaryfill(x + 1, y, fill, bound);
        boundaryfill(x, y + 1, fill, bound);
        boundaryfill(x - 1, y, fill, bound);
        boundaryfill(x, y - 1, fill, bound);
    }
    return;
}

int main()
{
    clrscr();
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    rectangle(100, 100, 160, 160);
    boundaryfill(120, 110, 4, 15);
    getch();
    return 0;
}
