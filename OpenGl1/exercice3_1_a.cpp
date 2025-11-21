#include <GL/glut.h>

void drawTriangle() {
    glBegin(GL_TRIANGLES);
        glColor3f(1,0,0); glVertex2f(-0.5f, -0.5f);
        glColor3f(0,1,0); glVertex2f( 0.5f, -0.5f);
        glColor3f(0,0,1); glVertex2f( 0.0f,  0.5f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // ⟹ Rotation de 45° autour de l’axe Z
    glRotatef(45.f, 0.f, 0.f, 1.f);

    drawTriangle();
    glFlush();
}

int main(int argc,char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutCreateWindow("Exercice 3.1.a - Rotation 45°");

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
