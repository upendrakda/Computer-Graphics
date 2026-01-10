// Implement DDA algorithm for drawing a line segments between two given end points
#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    system("clear");
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    float dx, dy, steps, x_inc, y_inc;
    float x, y;
    int i;

    printf("Enter the coordinates of first point (x1 y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the coordinates of second point (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    x_inc = dx / steps;
    y_inc = dy / steps;

    x = x1;
    y = y1;

    for (i = 0; i <= steps; i++)
    {
        putpixel((int)(x + 0.5), (int)(y + 0.5), WHITE);
        x = x + x_inc;
        y = y + y_inc;
        delay(10);
    }

    getch();
    closegraph();
    return 0;
}
