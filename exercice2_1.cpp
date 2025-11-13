/*
Compilation (Windows + MinGW) :
g++ -Wall -Wextra -g3 exercice2_1.cpp \
-o output/exercice2_1.exe \
-I /mingw64/include \
-L /mingw64/lib \
-lfreeglut -lopengl32 -lglu32 -lwinmm -lgdi32
*/

#include <GL/freeglut.h>

// -----------------------------------------------------------
// Fonction pour dessiner une primitive simple
// -----------------------------------------------------------
void DrawPrimitive(int type) {
    glBegin(type);
    switch (type) {
        case GL_TRIANGLES:
            glColor3f(1.f, 0.f, 0.f);
            glVertex2f(-0.5f, -0.5f);
            glColor3f(0.f, 1.f, 0.f);
            glVertex2f(0.5f, -0.5f);
            glColor3f(0.f, 0.f, 1.f);
            glVertex2f(0.0f, 0.5f);
            break;

        case GL_TRIANGLE_STRIP:
            glColor3f(1.f, 0.f, 0.f);
            glVertex2f(-0.5f, -0.5f);
            glColor3f(0.f, 1.f, 0.f);
            glVertex2f(-0.5f, 0.5f);
            glColor3f(0.f, 0.f, 1.f);
            glVertex2f(0.5f, -0.5f);
            glColor3f(1.f, 1.f, 0.f);
            glVertex2f(0.5f, 0.5f);
            break;

        case GL_LINES:
            glColor3f(0.f, 0.f, 0.f);
            glVertex2f(-0.8f, 0.f);
            glVertex2f(0.8f, 0.f);
            break;

        case GL_POINTS:
            glColor3f(0.f, 0.f, 0.f);
            glVertex2f(0.f, 0.f);
            break;
    }
    glEnd();
}

// -----------------------------------------------------------
// Fonction principale de rendu
// -----------------------------------------------------------
void Display() {
    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);

    glEnable(GL_SCISSOR_TEST);

    // Viewport 1 : en haut à gauche
    glViewport(0, height / 2, width / 2, height / 2);
    glScissor(0, height / 2, width / 2, height / 2);
    glClearColor(1.f, 0.8f, 0.8f, 1.f); // fond rose clair
    glClear(GL_COLOR_BUFFER_BIT);
    DrawPrimitive(GL_TRIANGLES);

    // Viewport 2 : en haut à droite
    glViewport(width / 2, height / 2, width / 2, height / 2);
    glScissor(width / 2, height / 2, width / 2, height / 2);
    glClearColor(0.8f, 1.f, 0.8f, 1.f); // vert clair
    glClear(GL_COLOR_BUFFER_BIT);
    DrawPrimitive(GL_TRIANGLE_STRIP);

    // Viewport 3 : en bas à gauche
    glViewport(0, 0, width / 2, height / 2);
    glScissor(0, 0, width / 2, height / 2);
    glClearColor(0.8f, 0.8f, 1.f, 1.f); // bleu clair
    glClear(GL_COLOR_BUFFER_BIT);
    DrawPrimitive(GL_LINES);

    // Viewport 4 : en bas à droite
    glViewport(width / 2, 0, width / 2, height / 2);
    glScissor(width / 2, 0, width / 2, height / 2);
    glClearColor(1.f, 1.f, 0.8f, 1.f); // jaune clair
    glClear(GL_COLOR_BUFFER_BIT);
    DrawPrimitive(GL_POINTS);

    glDisable(GL_SCISSOR_TEST);

    glFlush();
}

// -----------------------------------------------------------
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Exercice 2.1 - Viewports multiples");
    void (*func)() = Display;
    glutDisplayFunc(func);
    glutMainLoop();

    return 0;
}