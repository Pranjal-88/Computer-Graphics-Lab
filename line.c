#include <GL/glew.h>   
#include <GL/freeglut.h> 
#include <stdio.h>

void initOpenGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glClearDepth(1.0f);                  
    glEnable(GL_DEPTH_TEST);             
    glDepthFunc(GL_LEQUAL);              
    glShadeModel(GL_SMOOTH);             
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glLoadIdentity();                                  

    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);   
        glVertex3f(-0.5f, 0.0f, 0.0f); 
        glVertex3f(0.5f, 0.0f, 0.0f);  
    glEnd();

    glutSwapBuffers(); 
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);                         
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
    glutInitWindowSize(800, 600);                  
    glutCreateWindow("OpenGL Line with GLEW"); 

    glewExperimental = GL_TRUE;                    
    GLenum glewStatus = glewInit();                
    if (glewStatus != GLEW_OK) {                   
        fprintf(stderr, "Error: %s\n", glewGetErrorString(glewStatus));
        return -1;
    }

    initOpenGL();                                  
    glutDisplayFunc(display);                      

    glutMainLoop();                                
    return 0;
}
