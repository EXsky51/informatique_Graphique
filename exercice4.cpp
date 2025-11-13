#include <GL/freeglut.h>

int windowWidth = 800;
int windowHeight = 600;

// Dessin d'une primitive simple pour test 2D
void DrawPrimitive2D() {
    glBegin(GL_TRIANGLES);
    glColor3f(1,0,0); glVertex2f(100,100);
    glColor3f(0,1,0); glVertex2f(300,100);
    glColor3f(0,0,1); glVertex2f(200,300);
    glEnd();
}

void Display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeight); // repère pixels

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    DrawPrimitive2D();

    glutSwapBuffers();
}

void Reshape(int w,int h){
    windowWidth=w;
    windowHeight=h;
    glViewport(0,0,w,h);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth,windowHeight);
    glutCreateWindow("Exercice 4 - Projections 2D");

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutMainLoop();
    return 0;
}
