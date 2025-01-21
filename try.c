#include <GL/glew.h>   // Include the GLEW header
#include <GL/freeglut.h> // Include the FreeGLUT header
#include <stdio.h>

// Function to initialize OpenGL settings
void initOpenGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set the background color to black
    glClearDepth(1.0f);                  // Set the depth buffer value
    glEnable(GL_DEPTH_TEST);             // Enable depth testing
    glDepthFunc(GL_LEQUAL);              // Set the type of depth test
    glShadeModel(GL_SMOOTH);             // Enable smooth shading
}

// Function to render the triangle
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the color and depth buffers
    glLoadIdentity();                                  // Reset the model-view matrix

    // Draw a triangle
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);   // Red color
        glVertex3f(-0.5f, -0.5f, 0.0f); // Bottom left vertex

        glColor3f(0.0f, 1.0f, 0.0f);   // Green color
        glVertex3f(0.5f, -0.5f, 0.0f); // Bottom right vertex

        glColor3f(0.0f, 0.0f, 1.0f);   // Blue color
        glVertex3f(0.0f, 0.5f, 0.0f);  // Top vertex
    glEnd();

    glutSwapBuffers(); // Swap the front and back buffers
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);                         // Initialize FreeGLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Set display mode
    glutInitWindowSize(800, 600);                  // Set the window size
    glutCreateWindow("OpenGL Triangle with GLEW"); // Create a window with a title

    glewExperimental = GL_TRUE;                    // Enable GLEW experimental features
    GLenum glewStatus = glewInit();                // Initialize GLEW
    if (glewStatus != GLEW_OK) {                   // Check for GLEW initialization errors
        fprintf(stderr, "Error: %s\n", glewGetErrorString(glewStatus));
        return -1;
    }

    initOpenGL();                                  // Initialize OpenGL settings
    glutDisplayFunc(display);                      // Register the display callback function

    glutMainLoop();                                // Enter the FreeGLUT event processing loop
    return 0;
}
