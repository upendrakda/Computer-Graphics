#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    system("clear");

    int gd = DETECT, gm;
    int choice;

    int x1, y1, x2, y2, x3, y3;
    int tx, ty;
    int cx, cy;          /* rotation point */
    float sx, sy, angle, rad;

    /* Input triangle coordinates */
    printf("Enter coordinates of triangle:\n");
    printf("x1 y1: ");
    scanf("%d %d", &x1, &y1);
    printf("x2 y2: ");
    scanf("%d %d", &x2, &y2);
    printf("x3 y3: ");
    scanf("%d %d", &x3, &y3);

    printf("\nMENU");
    printf("\n1. Translation");
    printf("\n2. Rotation");
    printf("\n3. Scaling");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    /* Draw original triangle */
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    if (choice == 1)
    {
        printf("Enter translation factors (tx ty): ");
        scanf("%d %d", &tx, &ty);

        setcolor(RED);
        line(x1 + tx, y1 + ty, x2 + tx, y2 + ty);
        line(x2 + tx, y2 + ty, x3 + tx, y3 + ty);
        line(x3 + tx, y3 + ty, x1 + tx, y1 + ty);
    }
    else if (choice == 2)
    {
        printf("Enter rotation angle (in degrees): ");
        scanf("%f", &angle);

        printf("Enter rotation point (cx cy): ");
        scanf("%d %d", &cx, &cy);

        rad = angle * (3.14159 / 180);

        setcolor(GREEN);

        line(
            cx + (x1 - cx) * cos(rad) - (y1 - cy) * sin(rad),
            cy + (x1 - cx) * sin(rad) + (y1 - cy) * cos(rad),
            cx + (x2 - cx) * cos(rad) - (y2 - cy) * sin(rad),
            cy + (x2 - cx) * sin(rad) + (y2 - cy) * cos(rad)
        );

        line(
            cx + (x2 - cx) * cos(rad) - (y2 - cy) * sin(rad),
            cy + (x2 - cx) * sin(rad) + (y2 - cy) * cos(rad),
            cx + (x3 - cx) * cos(rad) - (y3 - cy) * sin(rad),
            cy + (x3 - cx) * sin(rad) + (y3 - cy) * cos(rad)
        );

        line(
            cx + (x3 - cx) * cos(rad) - (y3 - cy) * sin(rad),
            cy + (x3 - cx) * sin(rad) + (y3 - cy) * cos(rad),
            cx + (x1 - cx) * cos(rad) - (y1 - cy) * sin(rad),
            cy + (x1 - cx) * sin(rad) + (y1 - cy) * cos(rad)
        );
    }
    else if (choice == 3)
    {
        printf("Enter scaling factors (sx sy): ");
        scanf("%f %f", &sx, &sy);

        setcolor(YELLOW);
        line(x1 * sx, y1 * sy, x2 * sx, y2 * sy);
        line(x2 * sx, y2 * sy, x3 * sx, y3 * sy);
        line(x3 * sx, y3 * sy, x1 * sx, y1 * sy);
    }
    else
    {
        printf("Invalid choice!");
    }

    getch();
    closegraph();
    return 0;
}
