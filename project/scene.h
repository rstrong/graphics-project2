
Mesh plane;
int cur_plane = -1;

void move_car(void);

void init_ground(int type)
{
  if(cur_plane != type)
  {
    clearMesh(&plane);
    generatePlane(&plane, type);
    generatePerFaceNormals(&plane);
  
    if(VIS_N_VER == 2)
    {
      generatePerVertexNormals(true, &plane, C_ANGLE);
    }
    else
    {
      generatePerVertexNormals(false, &plane, C_ANGLE);
    }
    cur_plane = type;
  }

}

void ground(void)
{
  glPushMatrix();
  //glScalef(0.01, 0.01, 0.01);
  renderObject(&plane);

  glPopMatrix();
}

void car(void)
{
  if(CAMERA_OPTION != 3)
  {
    glPushMatrix();
    glColor3f(0.3, 0.4, 0.5);
    glTranslatef(carx, cary, carz);
    glRotated(car_angle,0.0, 1.0, 0.0);
    glutSolidTeapot(4.0);
    glPopMatrix();
  }
  move_car();
}

void move_car(void)
{
  carx += steer.x;
  carz += steer.z;
}
