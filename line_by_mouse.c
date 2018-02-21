#include<GL/glut.h>
#include<stdio.h>
#define ht 800
#define wd 800
int clicks=0,x1,x2,y1,y2;

void myInit( void )
{
    glClearColor (1.0,1.0,1.0,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,ht,0.0,wd);
}

void mouseClick(int button,int state,int x,int y){
        if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){

                if(clicks==0){
                        clicks++;
                        x1=x;
                        y1=wd-y;
                }
                else{
                        x2=x;
                        y2=wd-y;
                        printf("Drawing Line between (%d,%d) and (%d,%d)",x1,y1,x2,y2);
                        glBegin(GL_LINES);
                                glVertex2i(x1,y1);
                                glVertex2i(x2,y2);
                        glEnd();
                        x1=x2;
                        y1=y2;
                        clicks=0;
                        glFlush();
                }
        }
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glEnd();
    glFlush();
}
void main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(wd,ht);
    glutInitWindowPosition(150,150);
    glutCreateWindow("Line Drawing By Mouse Click");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMouseFunc(mouseClick);
    glutMainLoop();
}
