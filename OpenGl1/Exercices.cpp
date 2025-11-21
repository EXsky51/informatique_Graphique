/*
g++ -Wall -Wextra -g3 testgl.cpp \
-o output/testgl.exe \
-I /mingw64/include \
-L /mingw64/lib \
-lfreeglut -lopengl32 -lglu32 -lwinmm -lgdi32

*/

#include <GL/freeglut.h>

// Fonction qui dessine le triangle
void Render() {
    glClearColor(1.f, 1.f, 1.f, 1.f); // fond blanc
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);

    glBegin(GL_TRIANGLES);

    // Sommet 1 - rouge
    glColor3f(1.f, 0.f, 0.f);
    glVertex2f(0.0f, 0.5f);

    // Sommet 2 - vert
    glColor3f(0.f, 1.f, 0.f);
    glVertex2f(0.5f, -0.5f);

    // Sommet 3 - bleu
    glColor3f(0.f, 0.f, 1.f);
    glVertex2f(-0.5f, -0.5f);

    glEnd();
}

// Fonction de callback pour l'affichage
void Display() {
    Render();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Exercice 1.1 - Triangle Coloré");

    glutDisplayFunc(Display);
    glutMainLoop();

    return 0;
}

