#include<GL/glut.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
float x1,y1,x2,y2;

void simpleline();
void dashedline();
void dottedline();

float dx,dy,x,y,length,Xin,Yin,k;
void display()
{
	cout<<"\nSimple line\n";
	simpleline();
	cout<<"\nDashed line\n";
	dashedline();
	cout<<"\nDotted line\n";
	dottedline();
}

void simpleline()
{
	
	cout<<"Enter the value of x1";
	cin>>x1;
	cout<<"Enter the value of y1";
	cin>>y1;
	cout<<"Enter the value of x2";
	cin>>x2;
	cout<<"Enter the value of y2";
	cin>>y2;
	
	dx=x2-x1;
	dy=y2-y1;
	
	if(abs(dx)>abs(dy))
	{
		length=abs(dx);
	}
	else
	length=abs(dy);
	
	Xin=dx/length;
	Yin=dy/length;
	
	x=x1;
	y=y1;
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	
	for(k=1;k<=length;k++)
	{
		x=x+Xin;
		y=y+Yin;
		
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
	}
	glFlush();
}

void dashedline()
{
	cout<<"Enter the value of x1";
	cin>>x1;
	cout<<"Enter the value of y1";
	cin>>y1;
	cout<<"Enter the value of x2";
	cin>>x2;
	cout<<"Enter the value of y2";
	cin>>y2;
	
	dx=x2-x1;
	dy=y2-y1;
	
	if(abs(dx)>abs(dy))
	{
		length=abs(dx);
	}
	else
	length=abs(dy);
	
	Xin=dx/length;
	Yin=dy/length;
	
	x=x1;
	y=y1;
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	int i;
	for(i=0;i<=length;i++)
	{
		x=x+Xin;
		y=y+Yin;
		if(i%2==0)
		{
			glVertex2i(x,y);
		}		
	}
	glEnd();
	glFlush();
}	

void dottedline()
{
	cout<<"Enter the value of x1";
	cin>>x1;
	cout<<"Enter the value of y1";
	cin>>y1;
	cout<<"Enter the value of x2";
	cin>>x2;
	cout<<"Enter the value of y2";
	cin>>y2;
	
	dx=x2-x1;
	dy=y2-y1;
	
	if(abs(dx)>abs(dy))
	{
		length=abs(dx);
	}
	else
	length=abs(dy);
	
	Xin=dx/length;
	Yin=dy/length;
	
	x=x1;
	y=y1;
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	int i;
	for(int i=0;i<=length;i++)
	{
		x=x+Xin;
		y=y+Yin;
		if(i%5==0)
		{
			glVertex2i(x,y);
		}		
	}
	glEnd();
	glFlush();
}	

void init(void)
{
	glClearColor(1.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
}

int main(int argc,char** argv)
{
     cout<<"Enter the value of x1:";
     cin>>x1;
     cout<<"Enter the value of y1:";
     cin>>y1;
     cout<<"Enter the value of x2:";
     cin>>x2;
     cout<<"Enter the value of y2:";
     cin>>y2;
     
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
     glutInitWindowSize(500,500);
     glutInitWindowPosition(100,100);
     glutCreateWindow("Bresenhams line Drawing Algorithm");
     init();
     glutDisplayFunc(display);
     glutMainLoop();
     
     return 0;
}
