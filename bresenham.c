#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
static int xi,yi,xf,yf;


void init(void)
{
 glClearColor(1.0,1.0,1.0,0.0);
 glMatrixMode(GL_PROJECTION);
 glPointSize(4.0);
 gluOrtho2D(0.0,400.0,0.0,400.0);
}


void setPixel(GLint x,GLint y)
{
 glBegin(GL_POINTS);
 glVertex2f(x,y);
 glEnd();
}


void Line()
{
 int x,y;
 int dx,dy;
 int pk;
 int k;
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0,0,0);
 setPixel(xi,yi);
 dx=xf-xi;
 dy=yf-yi;
 pk=2*dy-dx;
 x=xi;
 y=yi;
 for(k=0;k<dx-1;++k)
 {
   if(pk<0)
   {
      pk=pk+2*dy;
   }
   else
   {
      pk=pk+2*dy-2*dx;
      ++y;
   }
   ++x;
   setPixel(x,y);
 }
 glFlush();
}


int main (int argc,char **argv)
{
 printf("Enter the endpoints of line\n");
 scanf("%d%d%d%d",&xi,&yi,&xf,&yf);
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(50,25);
 glutInitWindowSize(640,480);
 glutCreateWindow("Bresenham Line");
 init();
 glutDisplayFunc(Line);
 glutMainLoop();
 return 0;
}
