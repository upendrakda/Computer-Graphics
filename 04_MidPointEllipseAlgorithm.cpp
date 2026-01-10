// Implement mid point ellipse algorithm for drawing a circle of given centre and radius
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    int gd = DETECT, gm;
    int xc, yc;
    int rx, ry;
    int x, y;
    float p1, p2;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    /* Input center and radii */
    printf("Enter center coordinates (xc yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter x-radius (rx) and y-radius (ry): ");
    scanf("%d %d", &rx, &ry);

    /* Region 1 */
    x = 0;
    y = ry;
    p1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);

    while ((2 * ry * ry * x) <= (2 * rx * rx * y))
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (p1 < 0)
        {
            x++;
            p1 = p1 + (2 * ry * ry * x) + (ry * ry);
        }
        else
        {
            x++;
            y--;
            p1 = p1 + (2 * ry * ry * x) - (2 * rx * rx * y) + (ry * ry);
        }
        delay(10);
    }

    /* Region 2 */
    p2 = (ry * ry * (x + 0.5) * (x + 0.5))
       + (rx * rx * (y - 1) * (y - 1))
       - (rx * rx * ry * ry);

    while (y >= 0)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (p2 > 0)
        {
            y--;
            p2 = p2 - (2 * rx * rx * y) + (rx * rx);
        }
        else
        {
            x++;
            y--;
            p2 = p2 + (2 * ry * ry * x) - (2 * rx * rx * y) + (rx * rx);
        }
        delay(10);
    }

    getch();
    closegraph();
    return 0;
}
