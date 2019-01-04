#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define ROUND(a) ((int)(a + 0.5))
#define PII 3.14

void draw_triangle(int, int, int, int, int, int);
void rotation(int, int, int, int, int, int, float);

int main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;
    initgraph(&gd, &gm, NULL);

    printf("The coordinates of the equilateral triangle are (330, 61), (250, 200) and (410, 200)\n");

    printf("The coordinate of the centroid of the triangle is (330, 154)\n");

    draw_triangle(330, 61, 250, 200, 410, 200);
    delay(5000);

    printf("The angle of rotation is 45 degrees\n");

    rotation(330, 61, 250, 200, 410, 200, -45); //negative angle because the origin starts from top in the graphics window frame
    delay(5000);
}

/*Function to draw the triangle*/
void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
   line(x1, y1, x2, y2);
   line(x2, y2, x3, y3);
   line(x3, y3, x1, y1);
}

/*Function to rotate the triangle*/
void rotation(int x1, int y1, int x2, int y2, int x3, int y3, float theta)
{
    int l1, m1, l2, m2, l3, m3, xf = 330, yf = 154;

    cleardevice();
    /*Convert angle in degree to radian*/
    theta = (theta * PII) / 180;

    l1 = xf + (x1 - xf)*cos(theta) - (y1 - yf)*sin(theta);
    m1 = yf + (x1 - xf)*sin(theta) + (y1 - yf)*cos(theta);
    l2 = xf + (x2 - xf)*cos(theta) - (y2 - yf)*sin(theta);
    m2 = yf + (x2 - xf)*sin(theta) + (y2 - yf)*cos(theta);
    l3 = xf + (x3 - xf)*cos(theta) - (y3 - yf)*sin(theta);
    m3 = yf + (x3 - xf)*sin(theta) + (y3 - yf)*cos(theta);
    draw_triangle(l1, m1, l2, m2, l3, m3);
}


