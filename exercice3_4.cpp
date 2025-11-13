#include <GL/freeglut.h>
#include <cmath> // pour sin() et cos()

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

    float t = glutGet(GLUT_ELAPSED_TIME) / 1000.0f; // temps en secondes

    // ----- VIEWPORT 1 : Haut gauche (2 triangles avec matrices custom) -----
    glViewport(0, height / 2, width / 2, height / 2);
    glScissor(0, height / 2, width / 2, height / 2);
    glClearColor(1.f, 0.8f, 0.8f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Triangle fixe
    DrawPrimitive(GL_TRIANGLES);

    // Sauvegarde matrice
    glPushMatrix();

    // Triangle animé avec matrices custom
    // ----- Matrice de scale -----
    float scaleFactor = 0.5f + 0.5f * sin(t * 2.f);
    float S[16] = {
        scaleFactor, 0, 0, 0,
        0, scaleFactor, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };

    // ----- Matrice de rotation Z -----
    float angle = t * 60.f * 3.14159265f / 180.0f; // radians
    float cosA = cos(angle);
    float sinA = sin(angle);
    float R[16] = {
        cosA, sinA, 0, 0,
       -sinA, cosA, 0, 0,
        0,    0,    1, 0,
        0,    0,    0, 1
    };

    // ----- Matrice de translation -----
    float T[16] = {
        1, 0, 0, 0.5f,
        0, 1, 0, 0.0f,
        0, 0, 1, 0.0f,
        0, 0, 0, 1
    };

    // Applique les matrices dans l’ordre scale -> rotation -> translation
    glMultMatrixf(T);
    glMultMatrixf(R);
    glMultMatrixf(S);

    DrawPrimitive(GL_TRIANGLES);

    // Restaure matrice originale
    glPopMatrix();

    // ----- VIEWPORT 2 : Haut droite -----
    glViewport(width / 2, height / 2, width / 2, height / 2);
    glScissor(width / 2, height / 2, width / 2, height / 2);
    glClearColor(0.8f, 1.f, 0.8f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    DrawPrimitive(GL_TRIANGLE_STRIP);

    // ----- VIEWPORT 3 : Bas gauche -----
    glViewport(0, 0, width / 2, height / 2);
    glScissor(0, 0, width / 2, height / 2);
    glClearColor(0.8f, 0.8f, 1.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    DrawPrimitive(GL_LINES);

    // ----- VIEWPORT 4 : Bas droite -----
    glViewport(width / 2, 0, width / 2, height / 2);
    glScissor(width / 2, 0, width / 2, height / 2);
    glClearColor(1.f, 1.f, 0.8f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    DrawPrimitive(GL_POINTS);

    glDisable(GL_SCISSOR_TEST);
    glFlush();
}

// -----------------------------------------------------------
// Animation continue
// -----------------------------------------------------------
void Idle() {
    glutPostRedisplay();
}

// -----------------------------------------------------------
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Exercice 3.4 - Matrices custom");

    glutDisplayFunc(Display);
    glutIdleFunc(Idle);

    glutMainLoop();
    return 0;
}
