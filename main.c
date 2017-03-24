#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

GLfloat xRotated, yRotated, zRotated;
GLdouble radius=1;


void display(void);
void reshape(int x, int y);

void myinit()
{
    /*attributes*/
    glClearColor(1.0,1.0,1.0,1.0);
    /*White Background*/
    glColor3f(1.0,0.0,0.0);
    /*Draw in red*/
    /*setup viewing*/
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,500.0,0.0,500.0);
    glMatrixMode(GL_MODELVIEW);

}

const float DegreesToRadians = M_PI / 180.0; // M_PI = 3.14159...
point3 quad_data[342];
// 8 rows of 18 quads
int k = 0;
for(float phi = -80.0; phi <= 80.0; phi += 20.0)
{
float phir
= phi*DegreesToRadians;
float phir20 = (phi + 20.0)*DegreesToRadians;
for(float theta = -180.0; theta <= 180.0; theta += 20.0)
{
float thetar = theta*DegreesToRadians;
quad_data[k] = point3(sin(thetar)*cos(phir),
cos(thetar)*cos(phir), sin(phir));
k++;
quad_data[k] = point3(sin(thetar)*cos(phir20),
cos(thetar)*cos(phir20), sin(phir20));
k++;
}
}

const float DegreesToRadians = M_PI / 180.0; // M_PI = 3.14159...
int k = 0;
point3 strip_data[40];
strip_data[k] = point3(0.0, 0.0, 1.0);
k++;
float sin80 = sin(80.0*DegreesToRadians);
float cos80 = cos(80.0*DegreesToRadians);
6162
Chapter 2
Graphics Programming
for(float theta = -180.0; theta <= 180.0; theta += 20.0)
{
float thetar = theta*DegreesToRadians;
strip_data[k] = point3(sin(thetar)*cos80,
cos(thetar)*cos80, sin80);
k++;
}
strip_data[k] = point3(0.0, 0.0, -1.0);
k++;
for(float theta = -180.0; theta <= 180.0; theta += 20.0)
{
float thetar = theta;
strip_data[k] = point3(sin(thetar)*cos80,
cos(thetar)*cos80, sin80);
k++;
}

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(350,350);
    glutCreateWindow("Solid Sphere");
    xRotated = yRotated = zRotated = 30.0;
    xRotated=43;
    yRotated=50;

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

