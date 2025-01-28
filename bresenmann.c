#include <GL/glew.h>   
#include <GL/freeglut.h> 
#include <stdio.h>
#include <math.h>

void initOpenGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glViewport(0, 0, 800, 600);
}

void draw_line(float x1, float y1, float x2, float y2) {
    float dx=fabs(x2-x1);
    float dy=fabs(y2-y1);
    float pk=0;
    float incr;
    if (dy<dx)
        incr=dx/1000;
    else 
        incr=dy/1000;
    if (dy<dx)
        pk=2*dy-dx;
    else 
        pk=2*dx-dy;
    float x=x1;
    float y=y1;

    glPointSize(2.0f);
    glBegin(GL_POINTS);
    glVertex2f(x, y);

    if (dy<dx) {
        for (int i=0;i<1000;i++) {
            x+=incr;
            if (pk<0) {
                pk+=2*dy;
            } else {
                pk+=2*dy-2*dx;
                y+=incr;
            }
            glVertex2f(x,y);
        }
    } else {
        for (int i=0;i<1000;i++) {
            y+=incr;
            if (pk<0) {
                pk+=2*dx;
            } else {
                x+=incr;
                pk+=2*(dx-dy);
            }
            glVertex2f(x,y);
        }
    }

    glEnd();
}

// Render the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(1.0f, 1.0f, 1.0f); 
    draw_line(-0.5, -0.5, 0.5, 0.5);    
    
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Window");
    glewExperimental = GL_TRUE;
    glewInit();

    initOpenGL();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}