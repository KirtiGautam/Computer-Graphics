#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

void rotate(float triangle[][2], int n, int x_pivot, int y_pivot, int angle)
{
    int i = 0;
    while (i < n)
    {
        int x_shifted = triangle[i][0] - x_pivot;
        int y_shifted = triangle[i][1] - y_pivot;

        triangle[i][0] = x_pivot + (x_shifted * cos(angle * 3.141592653589 / 180) - y_shifted * sin(angle * 3.141592653589 / 180));
        triangle[i][1] = y_pivot + (x_shifted * sin(angle * 3.141592653589 / 180) + y_shifted * cos(angle * 3.141592653589 / 180));

        i++;
    }
    i = 1;
    while (i < n)
    {
        line(triangle[i - 1][0], triangle[i - 1][1], triangle[i][0], triangle[i][1]);
        if (i + 1 == n)
            line(triangle[i][0], triangle[i][1], triangle[0][0], triangle[0][1]);
        i++;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    float triangle[3][2];
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter (x,y) coordinate " << i + 1 << " ---> ";
        for (int j = 0; j < 2; j++)
            cin >> triangle[i][j];
    }

    //Triangle
    setcolor(2);
    line(triangle[0][0], triangle[0][1], triangle[1][0], triangle[1][1]);
    line(triangle[1][0], triangle[1][1], triangle[2][0], triangle[2][1]);
    line(triangle[2][0], triangle[2][1], triangle[0][0], triangle[0][1]);

    int angle, pivot[2] = {0, 0};
    cout << "Enter angle of rotation ---> ";
    cin >> angle;
    cout << "Enter coordinate of rotation(x,y) ---> ";
    cin >> pivot[0] >> pivot[1];

    //Rotated triangle
    setcolor(6);
    rotate(triangle, 3, pivot[0], pivot[1], angle);

    getch();
    return 0;
}