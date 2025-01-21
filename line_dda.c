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
    float dx=x2-x1;
    float dy=y2-y1;
    float steps;

    if (fabs(dx)>fabs(dy))
        steps=fabs(dx)*1000;
    else
        steps=fabs(dy)*1000;

    float x_incr=dx/steps;
    float y_incr=dy/steps;

    float x=x1;
    float y=y1;

    glPointSize(2.0f);  
    glBegin(GL_POINTS);

    for (int i=0; i<=(int)steps;i++) {
        glVertex2f(x, y);  
        x+=x_incr;       
        y+=y_incr;       
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