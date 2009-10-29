/* menu.h */


void top_menu(int value)
{
  main_keyboard((unsigned char)value, 0, 0);
}


void bottom_menu(int value)
{
  main_keyboard((unsigned char)value, 0, 0);
}


void change_plane(int option)
{
  if(option == 0)
  {
    PLANE_TYPE = 0; 
  }
  if(option == 1)
  {
    PLANE_TYPE = 1;
  }
  if(option == 2)
  {
    PLANE_TYPE = 2;
  }
  std::cout << "Plane updated to: " << PLANE_TYPE << std::endl;

  // redisplay? 
}

void change_texture(int option)
{
  if(option == 0)
  {
    TEXTURE_OPTION = 0;
  }
  if(option == 1)
  {
    TEXTURE_OPTION = 1;
  }
  if(option == 2)
  {
    TEXTURE_OPTION = 2;
  }
  std::cout << "Texture Option updated to: " << TEXTURE_OPTION << std::endl;
}

void change_mini(int option)
{
  if(option == 0)
  {
    MINI_OPTION = 0;
  }
  if(option == 1)
  {
    MINI_OPTION = 1;
  }
  std::cout << "Minification updated to: " << MINI_OPTION << std::endl;
}

void change_mag(int option)
{
  if(option == 0)
  {
    MAG_OPTION = 0;
  }
  if(option == 1)
  {
    MAG_OPTION = 1;
  }
  std::cout << "Magnification updated to: " << MAG_OPTION << std::endl;
}

void change_pfn(int option)
{
  if(option == 0)
  {
    VIS_N_FACE = 0;
  }
  if(option == 1)
  {
    VIS_N_FACE = 1;
  }
  std::cout << "Visual Per Face Noramls updated to: " << VIS_N_FACE << std::endl;
}

void change_pvn(int option)
{
  if(option == 0)
  {
    VIS_N_VER = 0;
  }
  if(option == 1)
  {
    VIS_N_VER = 1;
  }
  std::cout << "Visual Per Vertex Noramls updated to: " << VIS_N_VER << std::endl;
}

void change_cangle(int option)
{
  if(option == 0)
  {
    C_ANGLE = 0;
  }
  if(option == 1)
  {
    C_ANGLE = 15;
  }
  if(option == 2)
  {
    C_ANGLE = 25;
  }
  if(option == 3)
  {
    C_ANGLE = 35;
  }
  std::cout << "crease angle updated to: " << C_ANGLE << std::endl;

}

void change_mat(int option)
{
  if(option == 0)
  {
    MATERIAL_OPTION = 0;
  }
  if(option == 1)
  {
    MATERIAL_OPTION = 1;
  }
  if(option == 2)
  {
    MATERIAL_OPTION = 2;
  }
  std::cout << "material updated to: " << MATERIAL_OPTION << std::endl;
}

void change_shade(int option)
{
  if(option == 0)
  {
    SHADING_OPTION = 0;
  }
  if(option == 1)
  {
    SHADING_OPTION = 1;
  }
  std::cout << "shading updated to: " << SHADING_OPTION << std::endl;
}

void change_camera(int option)
{
  // 0 -4
  if(option == 0)
  {
    CAMERA_OPTION = 0;
  }
  if(option == 1)
  {
    CAMERA_OPTION = 1;
  }
  if(option == 2)
  {
    CAMERA_OPTION = 2;
  }
  if(option == 3)
  {
    CAMERA_OPTION = 3;
  }
  if(option == 4)
  {
    CAMERA_OPTION = 4;
  }
  std::cout << "camera updated to: " << CAMERA_OPTION << std::endl;
}
void setup_menus(void)
{
  int sub_plane = glutCreateMenu(change_plane);
  glutAddMenuEntry("Flat Plane", 0);
  glutAddMenuEntry("Multistep", 1);
  glutAddMenuEntry("Marble", 2);
  int sub_text = glutCreateMenu(change_texture);
  glutAddMenuEntry("No Textures", 0);
  glutAddMenuEntry("Texture - Replace" , 1);
  glutAddMenuEntry("Texture - Blend" , 2);
  int sub_mini = glutCreateMenu(change_mini);
  glutAddMenuEntry("Simple", 0);
  glutAddMenuEntry("Smooth", 1);
  int sub_mag = glutCreateMenu(change_mag);
  glutAddMenuEntry("Simple", 0);
  glutAddMenuEntry("Smooth", 1);
  int sub_pfn = glutCreateMenu(change_pfn);
  glutAddMenuEntry("Off", 0);
  glutAddMenuEntry("On", 1);
  int sub_pvn = glutCreateMenu(change_pvn);
  glutAddMenuEntry("Off", 0);
  glutAddMenuEntry("On", 1);
  int sub_cangle = glutCreateMenu(change_cangle);
  glutAddMenuEntry("Off", 0);
  glutAddMenuEntry("15 Degrees", 1);
  glutAddMenuEntry("25 Degrees", 2);
  glutAddMenuEntry("35 Degrees", 3);
  int sub_mat = glutCreateMenu(change_mat);
  glutAddMenuEntry("Diffuse", 0);
  glutAddMenuEntry("Specular", 1);
  glutAddMenuEntry("Design", 2);
  int sub_shade = glutCreateMenu(change_shade);
  glutAddMenuEntry("Flat", 0);
  glutAddMenuEntry("Smooth", 1);
  int sub_camera = glutCreateMenu(change_camera);
  glutAddMenuEntry("Top Down", 0);
  glutAddMenuEntry("45 Degree", 1);
  glutAddMenuEntry("Light Source", 2);
  glutAddMenuEntry("Navigation Camera", 3);
  glutAddMenuEntry("First Person", 4);

  glutCreateMenu(top_menu);
  glutAddSubMenu("Plane", sub_plane);
  glutAddSubMenu("Textures", sub_text);
  glutAddSubMenu("Minification", sub_mini);
  glutAddSubMenu("Magnification", sub_mag);
  glutAddSubMenu("Per Face Normals", sub_pfn);
  glutAddSubMenu("Per Vertex Normals", sub_pvn);
  glutAddSubMenu("Crease Angle", sub_cangle);
  glutAddSubMenu("Materials", sub_mat);
  glutAddSubMenu("Shading", sub_shade);
  glutAddSubMenu("Camera", sub_camera);


  glutAttachMenu(GLUT_RIGHT_BUTTON);
    


}

