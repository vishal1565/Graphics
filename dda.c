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
  float dy,dx,m,xa,ya;
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0,0,0);
  x=xi;y=yi;
  dx=xf-xi;dy=yf-yi;
  xa=xi;ya=yi;
  if(dx!=0){
     m=dy/dx;
     if(m==0){
     while(x!=xf){
        setPixel(x,y);
        x++;
     }}
     else{
        while(x!=xf && y!=yf){
        if(m<=-1 && m>=1){
            setPixel(x,y);
            ya++;
            xa=xa+m;
            x=xa;y=ya;
        }
        else{
            setPixel(x,y);
            xa++;
            ya=ya+(1/m);
            x=xa;y=ya;
        }
     }}
}
else{
   if(dx==0){
       while(y!=yf){
       setPixel(x,y);
       y++;
   }}
}
  glFlush();
}


int main (int argc,char **argv)
{
  printf("Enter the endpoints of the line\n");
  scanf("%d%d%d%d",&xi,&yi,&xf,&yf);
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(50,25);
  glutInitWindowSize(640,480);
  glutCreateWindow("Line Drawing by DDA");
  init();
  glutDisplayFunc(Line);
  glutMainLoop();
  return 0;
}
