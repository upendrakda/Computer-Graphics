// Program to implement the Flood Fill Algorithm
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

void floodFill4(int x, int y, int oldColor, int newColor)
{
    int currentColor = getpixel(x, y);

    if (currentColor == oldColor && currentColor != newColor)
    {
        putpixel(x, y, newColor);

        floodFill4(x + 1, y, oldColor, newColor);
        floodFill4(x - 1, y, oldColor, newColor);
        floodFill4(x, y + 1, oldColor, newColor);
        floodFill4(x, y - 1, oldColor, newColor);
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

    // Get the old color at starting pixel
    int oldColor = getpixel(x, y);

    // Call flood fill
    floodFill4(x, y, oldColor, RED);

    getch();
    closegraph();
    return 0;
}