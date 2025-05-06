#include<GL/glut.h>
#include<iostream>

using namespace std;
float x=0, y=0, dx=0.02, dy=0.023, r=0.1;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(x,y,0);
	glColor3f(0.2,0.8,0.2);

	glutSolidSphere(r,50,30);
	glutSwapBuffers();

}
void update(int)
{
	x=x+dx;
	y=y+dy;

	if(x+r > 1 || x-r <-1) {	
		dx=-dx;
	}
	if( y+r > 1 || y-r <-1) {
		dy=-dy;
	}
	glutPostRedisplay();
	glutTimerFunc(6,update,0);
}
void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-1,1,-1,1);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,480);
	glutCreateWindow("Bouncing Ball");
	glClearColor(2,1.2,0,0);
	
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(10,update,0);
	glutMainLoop();
}
