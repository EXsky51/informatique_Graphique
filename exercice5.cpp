#include <GL/freeglut.h>

int windowWidth = 800;
int windowHeight = 600;

// Dessin simple pour voir effet caméra
void DrawScene() {
    glBegin(GL_TRIANGLES);
    glColor3f(1,0,0); glVertex3f(-0.5f,0,-2);
    glColor3f(0,1,0); glVertex3f(0.5f,0,-2);
    glColor3f(0,0,1); glVertex3f(0,1,-2);
    glEnd();
}

void Display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0,(float)windowWidth/windowHeight,0.1,100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Caméra placée en hauteur et en retrait
    gluLookAt(
        0,2,5,   // position caméra
        0,0,0,   // point regardé
        0,1,0    // vecteur up
    );

    DrawScene();

    glutSwapBuffers();
}

void Reshape(int w,int h){
    windowWidth=w;
    windowHeight=h;
    glViewport(0,0,w,h);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(windowWidth,windowHeight);
    glutCreateWindow("Exercice 5 - Caméra");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutMainLoop();
    return 0;
}
