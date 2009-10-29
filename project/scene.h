
Mesh plane;
int cur_plane = -1;


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
  // glscale
  // glrotate
  renderObject(&plane);
  
}
