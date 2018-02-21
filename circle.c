#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
static int xc,yc,r;


void init(void)
{
 glClearColor(1.0,1.0,1.0,0.0);
 glMatrixMode(GL_PROJECTION);
 glPointSize(1.0);
 gluOrtho2D(0.0,400.0,0.0,400.0);
}


void setPixel(GLint x,GLint y)
{
 glBegin(GL_POINTS);
 x=x+xc;y=y+yc;
 glVertex2f(x,y);
 glEnd();
}

void Circle()
{
 int x,y;
 float p;
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0,0,0);
 x=0;y=r;
 p=(5/4)-r;
 while(x<=y){
   if(p>=0){
      p=p+2*x-2*y+4;
      setPixel(x,y);setPixel(y,x);
      x=-1*x;setPixel(x,y);setPixel(y,x);
      y=-1*y;setPixel(x,y);setPixel(y,x);
      x=-1*x;setPixel(x,y);setPixel(y,x);y=-1*y;
      y--;x++;
   }
   else{
      p=p+2*x+3;
      setPixel(x,y);setPixel(y,x);
      x=-1*x;setPixel(x,y);setPixel(y,x);
      y=-1*y;setPixel(x,y);setPixel(y,x);
      x=-1*x;setPixel(x,y);setPixel(y,x);y=-1*y;
      x++;
   }
}
 glFlush();
}

int main (int argc,char **argv)
{
 printf("Enter centre and radius of circle\n");
 scanf("%d%d%d",&xc,&yc,&r);
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(50,25);
 glutInitWindowSize(640,480);
 glutCreateWindow("Circle Drawing");
 init();
 glutDisplayFunc(Circle);
 glutMainLoop();
 return 0;
}
