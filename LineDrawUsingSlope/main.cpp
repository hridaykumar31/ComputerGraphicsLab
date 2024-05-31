#include <bits/stdc++.h>
#include <GL/glut.h>
#include <windows.h>
using namespace std;

int startX, startY, endX, endY; // Renamed variables to avoid conflict
const int windowWidth = 800;
const int windowHeight = 600;

void drawLine()
{
    float dx = endX - startX;
    float dy = endY - startY;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float m = dy / dx;

    float m1 = abs(m);
    float xIncrement, yIncrement;

    if(m >= 0 && m <= 1 && dx >= 0 && dy >= 0)
    {
        xIncrement = 1;
        yIncrement = m1;
    }
    else if(m >= 0 && m <= 1 && dx < 0 && dy < 0)
    {
        xIncrement = -1;
        yIncrement = -m1;
    }
    else if(m >= -1 && m < 0 && dx > 0 && dy < 0)
    {

        xIncrement = 1;
        yIncrement = -m1;
    }
    else if(m >= -1 && m < 0 && dx < 0 && dy > 0)
    {

        xIncrement = -1;
        yIncrement = m1;
    }
    else if(m > 1 && dx > 0 && dy > 0)
    {
        xIncrement = 1 / m1;
        yIncrement = 1;
    }
    else if(m > 1 && dx < 0 && dy < 0)
    {
        xIncrement = -(1 / m1);
        yIncrement = -1;
    }
    else if(m < -1 && dx > 0 && dy < 0)
    {

        xIncrement = 1 / m1;
        yIncrement = -1;
    }
    else if(m < -1 && dx < 0 && dy  > 0)
    {

        xIncrement = -(1 / m1);
        yIncrement = 1;
    }
    glBegin(GL_POINTS);
    float x = startX;
    float y = startY;
    for(int i = 0; i <= steps; i++)
    {
        glVertex2i(x, y);
        cout << x << " " << y << endl;
        x += xIncrement;
        y += yIncrement;
    }
    glEnd();


}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);
    glPointSize(3.0);
    drawLine();
    glFlush();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeight);
}

int main(int argc, char** argv)
{
    cout << "Enter the values of startX and startY: ";
    cin >> startX >> startY;
    cout << "Enter the values of endX and endY: ";
    cin >> endX >> endY;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("DDA Line Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
