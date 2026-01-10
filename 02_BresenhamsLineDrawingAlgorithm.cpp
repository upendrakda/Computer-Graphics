// Implement Bresenham’s line drawing algorithm for drawing a line segments between two given end points
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    int dx, dy, p;
    int x, y;

    /* Input end points */
    printf("Enter x1 y1: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter x2 y2: ");
    scanf("%d %d", &x2, &y2);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    /* Calculate dx and dy */
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    /* Initial decision parameter */
    p = 2 * dy - dx;

    /* Set starting point */
    x = x1;
    y = y1;

    putpixel(x, y, WHITE);

    /* Bresenham's algorithm (for slope 0 < m < 1) */
    while (x < x2)
    {
        x = x + 1;

        if (p < 0)
        {
            p = p + 2 * dy;
        }
        else
        {
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        }

        putpixel(x, y, WHITE);
        delay(10);
    }

    getch();
    closegraph();
    return 0;
}
