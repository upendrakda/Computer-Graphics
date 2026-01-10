// Program to implement the Boundary Fill Algorithm
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

void boundaryFill4(int x, int y, int fillColor, int boundaryColor)
{
    int currentColor = getpixel(x, y);

    if (currentColor != boundaryColor && currentColor != fillColor)
    {
        putpixel(x, y, fillColor);

        boundaryFill4(x + 1, y, fillColor, boundaryColor);
        boundaryFill4(x - 1, y, fillColor, boundaryColor);
        boundaryFill4(x, y + 1, fillColor, boundaryColor);
        boundaryFill4(x, y - 1, fillColor, boundaryColor);
    }
}

int main()
{
    system("clear");
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    int x, y;

    // Take input from user
    printf("Enter top-left corner of rectangle (x1 y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter bottom-right corner of rectangle (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    printf("Enter starting point inside rectangle (x y): ");
    scanf("%d %d", &x, &y);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Draw the rectangle boundary
    rectangle(x1, y1, x2, y2);

    // Call boundary fill
    boundaryFill4(x, y, RED, WHITE);

    getch();
    closegraph();
    return 0;
}