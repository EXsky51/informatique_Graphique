#include <GL/freeglut.h>
#include <cmath> // pour sin()

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

    // --- Temps écoulé pour l'animation ---
    float t = glutGet(GLUT_ELAPSED_TIME) / 1000.0f; // en secondes

    // ----- VIEWPORT 1 : Triangle animé (haut gauche) -----
    glViewport(0, height / 2, width / 2, height / 2);
    glScissor(0, height / 2, width / 2, height / 2);
    glClearColor(1.f, 0.8f, 0.8f, 1.f); // fond rose clair
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(t * 60.f, 0.f, 0.f, 1.f);       // rotation continue
    float scale = 0.5f + 0.5f * sin(t * 2.f); // pulsation
    glScalef(scale, scale, 1.f);
    DrawPrimitive(GL_TRIANGLES);

    // ----- VIEWPORT 2 : Rectangle (haut droite) -----
    glViewport(width / 2, height / 2, width / 2, height / 2);
    glScissor(width / 2, height / 2, width / 2, height / 2);
    glClearColor(0.8f, 1.f, 0.8f, 1.f); // vert clair
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    DrawPrimitive(GL_TRIANGLE_STRIP);

    // ----- VIEWPORT 3 : Ligne (bas gauche) -----
    glViewport(0, 0, width / 2, height / 2);
    glScissor(0, 0, width / 2, height / 2);
    glClearColor(0.8f, 0.8f, 1.f, 1.f); // bleu clair
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    DrawPrimitive(GL_LINES);

    // ----- VIEWPORT 4 : Point (bas droite) -----
    glViewport(width / 2, 0, width / 2, height / 2);
    glScissor(width / 2, 0, width / 2, height / 2);
    glClearColor(1.f, 1.f, 0.8f, 1.f); // jaune clair
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    DrawPrimitive(GL_POINTS);

    glDisable(GL_SCISSOR_TEST);

    glFlush();
}

// -----------------------------------------------------------
// Fonction pour l'animation continue
// -----------------------------------------------------------
void Idle() {
    glutPostRedisplay(); // redessine la scène
}

// -----------------------------------------------------------
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Exercice 3.2 - Animation");

    glutDisplayFunc(Display);
    glutIdleFunc(Idle); // animation continue

    glutMainLoop();
    return 0;
}
