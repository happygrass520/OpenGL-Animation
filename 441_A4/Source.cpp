#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

static int shoulder = 0, elbow = 0, wrist = 0, finger1 = 35, finger2 = -30, elbow2 = 0.0;;
static int ant1 = finger1, ant2 = finger2;
static int leg1, leg2 = shoulder;
static int eye_x, eye_y, eye_z = 0;
float horizon = 0.0;
float zoom = 6.0;
float body_move = 0.7;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);

	//Here begins the shading magic
	GLfloat material_specular[] = { 0.7, 0.09, 0.9, 200.0 };
	GLfloat material_ambiant[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat material_diffuse[] = { 0.5, 0.0, 0.0, 1.0 };
	GLfloat material_shininess[] = { 70.0 };
	GLfloat light_pos[] = { 0.0, 40.0, 0.0, 8.0 };

	glShadeModel(GL_FLAT);
	glEnable(GL_NORMALIZE);

	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambiant);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, material_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glEnable(GL_DEPTH_TEST);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, zoom, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glRotatef((GLfloat)eye_y, 1.0, 0.0, 0.0);
	glRotatef((GLfloat)eye_x, 0.0, 1.0, 0.0);
	glRotatef((GLfloat)eye_z, 0.0, 0.0, 1.0);
	glTranslatef(horizon, 0.0, 0.0);


glPushMatrix(); //*create rear segment of the insect
glTranslatef(-1.0, 0.0, 0.0);
glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
glTranslatef(body_move, 0.0, 0.0);
		glPushMatrix(); //**
		glScalef(1.5, 0.4, 0.5);
		glutSolidSphere(1.0, 10, 10);
			glPushMatrix(); //***leg 1 (bottom left)
			glRotatef(-25.0, 1.0, 0.0, 0.0);
			glTranslatef(-0.4, -1.8, 0.0);
			glRotatef((GLfloat)leg1, 0.0, 0.5, 0.5);
			glScalef(0.2, 2.5, 0.2);
			glutSolidCube(1.0);
			glutSolidSphere(0.8, 10, 10);
				glPushMatrix(); //****joint 1
				glTranslatef(0.0, -0.65, 0.0);
				glScalef(0.9, 0.2, 2.0);
				glRotatef(90.0, 1.0, 0.0, 0.0);
				glutSolidSphere(1.0, 10, 10);
					glPushMatrix(); //***foot 1
					glTranslatef(0.0, -0.8, 0.0);
					glScalef(0.85, 7.65, 1.0);
					glRotatef(-270.0, 1.0, 0.0, 0.0);
					glutSolidCone(0.7, 1.0, 10, 10);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //leg 2 (bottom middle)
			glRotatef(-25.0, 1.0, 0.0, 0.0);
			glTranslatef(0.2, -1.8, 0.0);
			glRotatef((GLfloat)leg2, 0.0, -0.5, 0.5);
			glScalef(0.2, 2.5, 0.2);
			glutSolidCube(1.0);
			glutSolidSphere(0.8, 10, 10);
				glPushMatrix(); //joint 2
				glTranslatef(0.0, -0.65, 0.0);
				glScalef(0.9, 0.2, 2.0);
				glRotatef(90.0, 1.0, 0.0, 0.0);
				glutSolidSphere(1.0, 10, 10);
					glPushMatrix(); //foot 2
					glTranslatef(0.0, -0.8, 0.0);
					glScalef(0.85, 7.65, 1.0);
					glRotatef(-270.0, 1.0, 0.0, 0.0);
					glutSolidCone(0.7, 1.0, 10, 10);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //leg 3 (top left)
			glRotatef(25.0, 1.0, 0.0, 0.0);
			glTranslatef(-0.4, 1.8, 0.0);
			glRotatef((GLfloat)leg1, 0.0, -0.5, 0.5);
			glScalef(0.2, 2.5, 0.2);
			glutSolidCube(1.0);
			glutSolidSphere(0.8, 10, 10);
				glPushMatrix(); //joint 3
				glTranslatef(0.0, 0.65, 0.0);
				glScalef(0.9, 0.2, 2.0);
				glRotatef(-90.0, 1.0, 0.0, 0.0);
				glutSolidSphere(1.0, 10, 10);
					glPushMatrix(); //foot 3
					glTranslatef(0.0, 0.8, 0.0);
					glScalef(0.85, 7.65, 1.0);
					glRotatef(270.0, 1.0, 0.0, 0.0);
					glutSolidCone(0.7, 1.0, 10, 10);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();
		
			glPushMatrix(); //leg 4 (top middle)
			glRotatef(25.0, 1.0, 0.0, 0.0);
			glTranslatef(0.2, 1.8, 0.0);
			glRotatef((GLfloat)leg1, 0.0, 0.5, 0.5);
			glScalef(0.2, 2.5, 0.2);
			glutSolidCube(1.0);
			glutSolidSphere(0.8, 10, 10);
				glPushMatrix(); //joint 4
				glTranslatef(0.0, 0.65, 0.0);
				glScalef(0.9, 0.2, 2.0);
				glRotatef(-90.0, 1.0, 0.0, 0.0);
				glutSolidSphere(1.0, 10, 10);
					glPushMatrix(); //foot 4
					glTranslatef(0.0, 0.8, 0.0);
					glScalef(0.85, 7.65, 1.0);
					glRotatef(270.0, 1.0, 0.0, 0.0);
					glutSolidCone(0.7, 1.0, 10, 10);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	/********************************************************************************************************************/
		glTranslatef(0.8, 0.0, 0.0); //create front body segment of the insect
		glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
		glRotatef((GLfloat)elbow2, 0.0, 1.0, 0.0);
		glTranslatef(0.5, 0.0, 0.0);
		glPushMatrix();
		glScalef(1.5, 0.4, 0.5);
		glutSolidCube(1.0);
		glutSolidSphere(0.8, 5, 5);
			glPushMatrix(); //leg 5 (bottom right)
			glRotatef(-25.0, 1.0, 0.0, 0.0);
			glTranslatef(0.2, -1.8, 0.0);
			glRotatef((GLfloat)leg1, 0.0, 0.5, 0.5);
			glScalef(0.2, 2.5, 0.2);
			glutSolidCube(1.0);
			glutSolidSphere(0.8, 10, 10);
				glPushMatrix(); //joint 5
				glTranslatef(0.0, -0.65, 0.0);
				glScalef(0.9, 0.2, 2.0);
				glRotatef(90.0, 1.0, 0.0, 0.0);
				glutSolidSphere(1.0, 10, 10);
					glPushMatrix(); //foot 5
					glTranslatef(0.0, -0.8, 0.0);
					glScalef(0.85, 7.65, 1.0);
					glRotatef(-270.0, 1.0, 0.0, 0.0);
					glutSolidCone(0.7, 1.0, 10, 10);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();

			glPushMatrix(); //leg 6 (top right)
			glRotatef(25.0, 1.0, 0.0, 0.0);
			glTranslatef(0.2, 1.8, 0.0);
			glRotatef((GLfloat)leg1, 0.0, -0.5, 0.5);
			glScalef(0.2, 2.5, 0.2);
			glutSolidCube(1.0);
			glutSolidSphere(0.8, 10, 10);
				glPushMatrix(); //joint 6
				glTranslatef(0.0, 0.65, 0.0);
				glScalef(0.9, 0.2, 2.0);
				glRotatef(-90.0, 1.0, 0.0, 0.0);
				glutSolidSphere(1.0, 10, 10);
					glPushMatrix(); //foot 6
					glTranslatef(0.0, 0.8, 0.0);
					glScalef(0.85, 7.65, 1.0);
					glRotatef(270.0, 1.0, 0.0, 0.0);
					glutSolidCone(0.7, 1.0, 10, 10);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	/******************************************************************************************************************************************/
	glTranslatef(1.0, 0.0, 0.0); //create the head 
	glRotatef(-35.0, 0.0, 1.0, 0.0);
	glRotatef((GLfloat)wrist, 0.0, 1.0, 0.0);
	glPushMatrix();
	glScalef(0.5, 0.7, 1.0);
	glutSolidSphere(0.5, 5, 5);

		glPushMatrix(); //create first half of left antenna
		glTranslatef(0.7, 0.4, 0.0);
		glRotatef((GLfloat)finger1, 0.0, 0.0, 1.0);
		glScalef(0.7, 0.4, 0.1);
		glutSolidCube(1.0);
			glPushMatrix(); //create second half of left antenna
			glTranslatef(0.8, 0.0, 0.0);
			glutSolidCube(1.0);
			glPopMatrix();
			glPopMatrix();

		glPushMatrix(); //create first half of right antenna
		glTranslatef(0.7, -0.4, 0.0);
		glScalef(0.7, 0.4, 0.1);
		glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0);
		glutSolidCube(1.0);
			glPushMatrix(); //create second half of right antenna 
			glTranslatef(0.8, 0.0, 0.0);
			glutSolidCube(1.0);
			glPopMatrix();

	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
	//glRotatef(10.0, 1.0, 0.0, 0.0);
}

bool flag = true;
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
		case 'q':
			if (elbow2 < -25)
				break;
			elbow2 = elbow2 -  3;
			glutPostRedisplay();
			break;
		case 'Q':
			if (elbow2 > 25)
				break;
			elbow2 = elbow2 + 3;
			glutPostRedisplay();
			break;
		case 'e': //move front half left
			if (elbow > 28)
				break;
			elbow = (elbow + 4);
			glutPostRedisplay();
			break;
		case 'E': //move front half right
			if (elbow < -28)
				break;
			elbow = (elbow - 4);
			glutPostRedisplay();
			break;
		case 'w': //move the head left
			if (wrist > 35)
				break;
			wrist = (wrist + 5);
			glutPostRedisplay();
			break;
		case 'W': //move the head right
			if (wrist < -30)
				break;
			wrist = (wrist - 5) % 360;
			glutPostRedisplay();
			break;
		case 'a': //animate and make the insect walk
			shoulder = 0;
			elbow = 0;
			elbow2 = -4;
			if (flag)
			{
				leg1 = leg1 + 1;
				leg2 = leg2 + 1;
				wrist = wrist + 1;
				if (leg1 == 15 || leg2 == 15)
					flag = false;
				if (horizon > 7)
					horizon = -7;
				horizon = horizon + .1;
				glutPostRedisplay();
			}
			else if (flag == false)
			{
				leg1 = leg1 - 1;
				leg2 = leg2 - 1;
				wrist = wrist - 1;
				if (leg1 == -15 || leg2 == -15)
					flag = true;
				if (horizon > 7)
					horizon = -7;
				horizon = horizon + .1;
				glutPostRedisplay();
			}
			//glutPostRedisplay();
			break;
					/***********camera control cases************/
			case 'i': //rotate view up
				eye_y = eye_y + 10;
				glutPostRedisplay();
				break;
			case 'k': //rotate view down
				eye_y = eye_y - 10;
				glutPostRedisplay();
				break;
			case 'j': //totate view left
				eye_x = eye_x - 10;
				glutPostRedisplay();
				break; 
			case 'l': //rotate view right
				eye_x = eye_x + 10;
				glutPostRedisplay();
				break; 
			case 'm':
				eye_z = eye_z + 10;
				glutPostRedisplay();
				break;
			case 'n':
				eye_z = eye_z - 10;
				glutPostRedisplay();
				break;
			default:
					break;
	}
}
int startx = 0;
int starty = 0;
bool right_pressed = false; 
void mouse(int button, int state, int x, int y)
{
	starty = y;
	switch(button)
	{
		case GLUT_RIGHT_BUTTON:
			if (state == GLUT_DOWN)
				right_pressed = true;
			if (state == GLUT_UP)
				right_pressed = false;
			break;
		default:
			break;
	}
}
int tempy = 0;
void move(int x, int y)
{
	if (right_pressed)
	{
		if (zoom > 20)
			zoom = 1;
		if (zoom <= 0)
			zoom = 17;
		if (y <= starty)
			zoom = zoom - ((starty - y)*.001);
		else if (y >= starty)
			zoom = zoom + ((y - starty)*.001);
		/**************************************************/
		glutPostRedisplay();
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Kyle Rowland - Homework 4");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(move);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}