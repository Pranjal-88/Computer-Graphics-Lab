#include <stdio.h>
#include <GL/glut.h>
#include <math.h>


void plotEllipsePoints(int xc, int yc, int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(xc+x,yc+y);
    glVertex2i(xc-x,yc+y);
    glVertex2i(xc+x,yc-y);
    glVertex2i(xc-x,yc-y);
    glEnd();
}

// Midpoint Ellipse Algorithm
void drawEllipse(int xc, int yc, int rx, int ry) {
    float dx,dy,d1,d2;
    int x=0,y=ry;

    d1=(ry*ry)-(rx*rx*ry)+(0.25*rx*rx);
    dx=2*ry*ry*x;
    dy=2*rx*rx*y;

    while(dx<dy) {
        plotEllipsePoints(xc,yc,x,y);
        if (d1<0) {
            x++;
            dx+=2*ry*ry;
            d1+=dx+(ry*ry);
        } else {
            x++; y--;
            dx+=2*ry*ry;
            dy-=2*rx*rx;
            d1+=dx-dy+(ry*ry);
        }
    }


    d2=((ry*ry)*((x+0.5)*(x+0.5)))+((rx*rx)*((y-1)*(y-1)))-(rx*rx*ry*ry);

    while (y>=0) {
        plotEllipsePoints(xc,yc,x,y);
        if (d2>0) {
            y--;
            dy-=2*rx*rx;
            d2+=(rx*rx)-dy;
        } else {
            y--;
            x++;
            dx+=2*ry*ry;
            dy-=2* rx*rx;
            d2+=dx-dy+(rx*rx);
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0); 
    glPointSize(2.0); 


    drawEllipse(100, 50, 200, 100);
    glFlush();
}


void initGL() {
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    gluOrtho2D(-400,400,-300,300); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Ellipse Algorithm");
    initGL();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}