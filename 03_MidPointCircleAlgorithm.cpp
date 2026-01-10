// Implement mid point circle  for drawing a circle of given centre and radius
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    int gd = DETECT, gm;
    int xc, yc, r;
    int x, y;
    int p;

    /* Input center and radius */
    printf("Enter center coordinates (xc yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter radius of circle: ");
    scanf("%d", &r);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    /* Step 1: Initialize */
    x = 0;
    y = r;
    p = 1 - r;

    /* Draw initial points */
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);

    /* Step 2: Generate points */
    while (x < y)
    {
        x++;

        if (p < 0)
        {
            p = p + 2 * x + 1;
        }
        else
        {
            y--;
            p = p + 2 * (x - y) + 1;
        }

        /* Draw points in all 8 octants */
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        delay(10);
    }

    getch();
    closegraph();
    return 0;
}
