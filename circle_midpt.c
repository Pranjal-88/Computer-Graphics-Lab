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

void draw_circle(float x1, float y1, float r) {
   float x=0;
   float y=r;
   float P=1-r;
   float steps=0.001;

    glPointSize(2.0f);
    glBegin(GL_POINTS);
   while (x<=y){
        glVertex2f(x1+x,y1+y);
        glVertex2f(x1-x,y1+y);
        glVertex2f(x1+x,y1-y);
        glVertex2f(x1-x,y1-y);
        glVertex2f(x1+y,y1+x);
        glVertex2f(x1-y,y1+x);
        glVertex2f(x1+y,y1-x);
        glVertex2f(x1-y,y1-x);

        if (P<0)
            P+=2*x+steps;
        else {
            y-=steps;
            P+=2*(x-y)+steps;
        }
        
        x+=steps;
   }
   glEnd();
}

// Render the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(1.0f, 1.0f, 1.0f); 
    draw_circle(0.0,0.0,0.5);    
    
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