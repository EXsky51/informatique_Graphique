#include <GL/freeglut.h>
#include <cmath>

int windowWidth = 800;
int windowHeight = 600;

float vertices[8][3] = {
    {-0.5f,-0.5f,-0.5f}, {0.5f,-0.5f,-0.5f},
    {0.5f,0.5f,-0.5f}, {-0.5f,0.5f,-0.5f},
    {-0.5f,-0.5f,0.5f}, {0.5f,-0.5f,0.5f},
    {0.5f,0.5f,0.5f}, {-0.5f,0.5f,0.5f}
};

int faces[6][6] = {
    {0,1,2,0,2,3},{4,5,6,4,6,7},{0,1,5,0,5,4},
    {3,2,6,3,6,7},{1,2,6,1,6,5},{0,3,7,0,7,4}
};

float colors[8][3] = {
    {1,0,0},{0,1,0},{0,0,1},{1,1,0},
    {1,0,1},{0,1,1},{0.5f,0.5f,0.5f},{1,1,1}
};

void DrawCube() {
    glBegin(GL_TRIANGLES);
    for(int f=0;f<6;f++){
        for(int i=0;i<6;i++){
            int vi = faces[f][i];
            glColor3fv(colors[vi]);
            glVertex3fv(vertices[vi]);
        }
    }
    glEnd();
}

void Display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0,(float)windowWidth/windowHeight,0.1,100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(3,3,3,0,0,0,0,1,0);

    float t = glutGet(GLUT_ELAPSED_TIME)/1000.0f;
    glRotatef(t*30,1,1,0);

    DrawCube();

    glutSwapBuffers();
}

void Reshape(int w,int h){
    windowWidth=w;
    windowHeight=h;
    glViewport(0,0,w,h);
}

void Idle(){
    glutPostRedisplay();
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(windowWidth,windowHeight);
    glutCreateWindow("Exercice 6 - Cube 3D");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutIdleFunc(Idle);

    glutMainLoop();
    return 0;
}
