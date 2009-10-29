/* 
main.h - contains slew of globals
*/


//camera
float eyex = 1;
float eyey = 2;
float eyez = 0;
int light_angle = 0;
//overall size
int WIDTH = 1024;
int HEIGHT = 768;
//windowing variables
int top_width, top_height, bottom_width, bottom_height;
int window, top, bottom;
#define GAP 15
//lighting
GLfloat AmbientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
GLfloat DiffuseLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat SpecularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat SpecRef[] = {0.7f, 0.7f, 0.7f, 1.0f};
GLfloat LightPos[] = {0.0f, 50.0f, 50.0f, 1.0f};
GLubyte Shine = 128;
//controls
int mouse_button;
int mouse_x     = 0;
int mouse_y     = 0;
// overall viewing variables
float scale  = 0.01;
float x_angle   = 0.0;
float y_angle   = 0.0;


// car xyz
float carx = 0;
float cary = 0;
float carz = 0;


// Specific control variables
//0 -> flat plane
//1 -> multistep plane
//2 -> marble plane
int PLANE_TYPE = 0;

// 0 - no textures
// 1 - texture - replace
// 2 - texture - blend
int TEXTURE_OPTION = 0;

// 0 -> simple
// 1 -> smooth
int MINI_OPTION = 0;
// 0 -> simple
// 1 -> smooth
int MAG_OPTION = 0;

// display face normals? 0 -> no, 1 -> yes
int VIS_N_FACE = 0;

// display vertex nomals? 0 -> no, 1 -> standard, 2 -> weight 
int VIS_N_VER = 0;

// crease angle, can be 0 (off), 15, 25, 35
int C_ANGLE = 0;

// 0 -> diffuse
// 1 -> specular
// 2 -> design
int MATERIAL_OPTION = 2;

// 0 -> flat 
// 1 -> smooth
int SHADING_OPTION = 0;

// 0 -> 45 degree
// 1 -> light source
// 2 -> navigation camera
// 3 -> first person
int CAMERA_OPTION = 0;

void redisplay_all(void);
void top_display(void);
