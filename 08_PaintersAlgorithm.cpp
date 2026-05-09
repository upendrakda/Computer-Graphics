// Program to implement Painter's Algorithm with filled rectangles
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

struct Object
{
    int x1, y1, x2, y2; // rectangle coordinates
    int depth;          // distance from viewer
    int color;
};

void swap(struct Object *a, struct Object *b)
{
    struct Object temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    system("clear");
    int gd = DETECT, gm;
    int n, i, j;

    struct Object obj[10];

    printf("Enter number of rectangles: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nRectangle %d\n", i + 1);

        printf("Enter coordinates (x1 y1 x2 y2): ");
        scanf("%d %d %d %d", &obj[i].x1, &obj[i].y1, &obj[i].x2, &obj[i].y2);

        printf("Enter depth value: ");
        scanf("%d", &obj[i].depth);

        obj[i].color = i + 1; // assign color
    }

    // Sort objects from far to near
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (obj[i].depth < obj[j].depth)
            {
                swap(&obj[i], &obj[j]);
            }
        }
    }

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Draw filled rectangles from back to front
    for (i = 0; i < n; i++)
    {
        setfillstyle(SOLID_FILL, obj[i].color);
        bar(obj[i].x1, obj[i].y1, obj[i].x2, obj[i].y2);
        delay(700);
    }

    getch();
    closegraph();
    return 0;
}