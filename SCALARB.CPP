#include <iostream.h>
#include <conio.h>
#include <graphics.h>

void scale(int arr[], int x_scale, int y_scale, int n, float sx, float sy)
{
    int i = 0;
    while (i < n)
    {
        //shifting to origin
        int x_shifted = arr[i] - x_scale;
        int y_shifted = arr[i + 1] - y_scale;

        //Shifting back to point
        arr[i] = x_scale + (x_shifted * sx);
        arr[i + 1] = y_scale + (y_shifted * sy);

        i += 2;
    }
}

void scaleArbitrary(int hut[])
{
    //Scaling around arbitrary point
    float sx, sy;
    cout << "Enter x scaling factor (Sx)---> ";
    cin >> sx;
    cout << "Enter y scaling factor (Sy)---> ";
    cin >> sy;
    int x_scale, y_scale;
    cout << "Enter arbitrary point of scaling (x,y) ---> ";
    cin >> x_scale >> y_scale;
    scale(hut, x_scale, y_scale, 16, sx, sy);

    //drawing scaled object
    drawpoly(8, hut);
}

void scaleAndTranslate(int hut[])
{
    //Scaling about origin
    float sx, sy;
    cout << "Enter x scaling factor (Sx)---> ";
    cin >> sx;
    cout << "Enter y scaling factor (Sy)---> ";
    cin >> sy;
    scale(hut, 0, 0, 16, sx, sy);

    //Translation
    int x_scale, y_scale;
    cout << "Enter x translation factor (Tx)---> ";
    cin >> x_scale;
    cout << "Enter y translation factor (Ty)---> ";
    cin >> y_scale;
    for (int i = 0; i < 16; i += 2)
    {
        hut[i] += x_scale;
        hut[i + 1] += y_scale;
    }

    //Final figure
    drawpoly(8, hut);
}

int main()
{
    clrscr();
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    //Hut
    int hut[] = {300, 75, 450, 225, 425, 225, 425, 400, 175, 400, 175, 225, 150, 225, 300, 75},
        huta[] = {300, 75, 450, 225, 425, 225, 425, 400, 175, 400, 175, 225, 150, 225, 300, 75};
    //Drawing house
    drawpoly(8, hut);
    // drawpoly(5, wall);

    //Scaling and translation
    setcolor(4);
    scaleAndTranslate(hut);

    getch();
    closegraph();

    //Making original figure again
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    drawpoly(8, huta);

    //Scaling around arbitrary point
    setcolor(1);
    scaleArbitrary(huta);

    getch();

    return 0;
}