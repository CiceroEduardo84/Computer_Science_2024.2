#include <glut.h> 

void display(void) {
glClear(GL_COLOR_BUFFER_BIT); 
glBegin(GL_POLYGON);
glVertex2f(-0.3, -0.3); 
glVertex2f(-0.3, 0.3); 
glVertex2f(0.3, 0.3); 
glVertex2f(0.3, -0.3);
glEnd();
glFlush();
}

int main(void) {
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutCreateWindow("Ola Mundo"); 
glutDisplayFunc(display);
glutMainLoop();
}

