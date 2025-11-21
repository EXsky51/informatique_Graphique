#include <GL/glut.h>

void drawTriangle()
{
    glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);   glVertex2f(-0.5f, -0.5f);
        glColor3f(0.f, 1.f, 0.f);   glVertex2f( 0.5f, -0.5f);
        glColor3f(0.f, 0.f, 1.f);   glVertex2f( 0.f,  0.5f);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Exercice 3.1.c :
    glTranslatef(1.0f, 0.f, 0.f);    // déplacer à droite
    glRotatef(-45.f, 0.f, 0.f, 1.f); // tourner vers la gauche
    glScalef(1.5f, 1.5f, 1.f);       // agrandir 1.5x

    drawTriangle();

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Exercice 3.1.c");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
