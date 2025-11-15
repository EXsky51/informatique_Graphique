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

    // ---- Temps écoulé en secondes ----
    float t = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;

    /*
     * CHOISIS UNE DES ANIMATIONS :
     */

    // 1️⃣ Rotation animée
    glRotatef(t * 50.f, 0.f, 0.f, 1.f);  
    // (50° par seconde)

    // 2️⃣ Homothétie animée (commenter la ligne au-dessus)
    // float s = 0.5f + 0.5f * sin(t);  // oscillation entre 0.0 et 1.0
    // glScalef(s, s, 1.f);

    // 3️⃣ Translation animée (commenter le reste)
    // float x = sin(t) * 0.7f;        // mouvement gauche/droite
    // glTranslatef(x, 0.f, 0.f);

    drawTriangle();

    glutSwapBuffers();
}

void timer(int value)
{
    glutPostRedisplay();      // redessine régulièrement
    glutTimerFunc(16, timer, 0); // ~60 FPS
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Exercice 3.2");

    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}
