#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <iostream>
#include <GL/glut.h>

// The beginnings of ours...
#include <mathutil.h>
#include <mesh.h>
#include <primitive.h>


float eyex = 0;
float eyey = 0;
float eyez = 0;

int WIDTH = 1024;
int HEIGHT = 768;
// need to go into another .h
int top_width, top_height, bottom_width, bottom_height;
int window, top, bottom;
#define GAP 15

void main_reshape(int width, int height)
{
  WIDTH = width;
  HEIGHT = height;
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, (float)width / (float)height, 0.1f, 20.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glutSetWindow(top);
  glutPositionWindow(GAP, GAP);
  top_width = width - (2 * GAP);
  top_height = (height * 0.8) - (2 * GAP);
  glutReshapeWindow(top_width, top_height);

  glutSetWindow(bottom);
  bottom_width = width - (2 * GAP);
  bottom_height = (height * 0.2) - GAP;
  glutPositionWindow(GAP,(height * 0.8));
  glutReshapeWindow(bottom_width, bottom_height);
}

void main_display()
{
  glClearColor(0.8f, 0.8f, 0.8f, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glutSwapBuffers();
}

void main_keyboard(unsigned char key, int x, int y)
{
  switch(key)
  {
    case 'u' : 
      eyex += 0.1;
      break;
    case 'i' :
      eyex -= 0.1;
      break;
    case 'j' :
      eyey += 0.1;
      break;
    case 'k' : 
      eyey -= 0.1;
      break;
    case 'n' :
      eyez += 0.1;
      break;
    case 'm' : 
      eyez -= 0.1;
      break;
    default:
      break;
  }
  std::cout << "EYEZ: " << eyex << " " << eyey << " " << eyez << std::endl;
  main_reshape(WIDTH, HEIGHT);
}

void top_reshape(int height, int width)
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, (float)width / (float)height, 0.1f, 10.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 0, 1);
}

void top_display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  // shadeing
  //models
  //textures
  //etc
  glutSwapBuffers();
}

void bottom_reshape(int width, int height)
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, width, height, 0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClearColor(0.0, 0.0, 0.0, 0.0);
}

void bottom_display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glColor3f(1.0, 0.0, 0.0);

  //bottom shit
  glutSwapBuffers();
}

void redisplay_all(void)
{
  glutSetWindow(top);
  glutPostRedisplay();
  glutSetWindow(bottom);
  glutPostRedisplay();
}

void idle()
{
  main_display();
}

void init(void)
{
  //generateCylinder(&cylinder);
  //generatePerFaceNormals(&cylinder);
  //generatePerVertexNormals(true, &cylinder, 30);
}

int main(int argc, char** argv)
{
  std::cout << "Boom Boom!" << std::endl;
  init();
  std::cout << "made it past init" << std::endl;
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
  glutInitWindowSize(WIDTH, HEIGHT);
  glutInitWindowPosition(50, 50);
  glutInit(&argc, argv);

  window = glutCreateWindow("Project 2");
  glutReshapeFunc(main_reshape);
  glutDisplayFunc(main_display);
  glutKeyboardFunc(main_keyboard);
  glutIdleFunc(idle);

  top = glutCreateSubWindow(window, 1, 1, 10, 10);
  glutReshapeFunc(top_reshape);
  glutDisplayFunc(top_display);
  glutIdleFunc(idle);
  glutKeyboardFunc(main_keyboard);

  bottom = glutCreateSubWindow(window, 1000, 1000, 50, 50);
  glutReshapeFunc(bottom_reshape);
  glutDisplayFunc(bottom_display);
  glutKeyboardFunc(main_keyboard);
  glutMainLoop();

  return 0;

}
