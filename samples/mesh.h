#include <vector>
#include <mathutil.h>

struct Mesh
{ 
  std::vector<Vec3f> m_v; //vertex
  std::vector<Vec3f> m_c; //color
  std::vector<int> m_vi;
  std::vector<int> m_ci;

  std::vector<Vec3f> m_t; //texture
  std::vector<int> m_ti; //texture index

  std::vector<Vec3f> m_nf; // per face normal
  std::vector<Vec3f> m_nv; // per vertex normal
};

void renderObject(Mesh *t)
{
  std::vector<Vec3f> v = t->m_v;
  std::vector<int> vi = t->m_vi;
  std::vector<Vec3f> tx = t->m_t;
  //colors etc

  glBegin(GL_TRIANGLES);
  for(unsigned int i = 0; i < vi.size(); i++)
  {
    glTexCoord2f(tx[vi[i]].x, tx[vi[i]].y);
    glVertex3f(v[vi[i]].x, v[vi[i]].y, v[vi[i]].z);
  }
  glEnd();
}

void generatePerFaceNormals(Mesh *t)
{
  unsigned int i;
  std::vector<Vec3f> v = t->m_v;
  std::vector<int> vi = t->m_vi;

  for(i = 0; i < vi.size(); i+=3)
  {
    Vec3f ab = v[vi[i+1]] - v[vi[i]]; 
    Vec3f ac = v[vi[i+2]] - v[vi[i]];
    Vec3f temp = ab.cross(ac);
    t->m_nf.push_back(temp);
  }
}

void renderPerFaceNormals(Mesh *t)
{
  std::vector<Vec3f> v = t->m_v;
  std::vector<int> vi = t->m_vi;
  std::vector<Vec3f> n = t->m_nf;

  unsigned int i;
  unsigned int c = 0;

  for(int i = 0; i < vi.size(); i+= 3)
  {
    float x = (((float)1/3))*(v[vi[i]].x + v[vi[i+1]].x + v[vi[i+2]].x);
    float y = (((float)1/3))*(v[vi[i]].y + v[vi[i+1]].y + v[vi[i+2]].y);
    float z = (((float)1/3))*(v[vi[i]].z + v[vi[i+1]].z + v[vi[i+2]].z);
    n[c] *= 1.5; 
    glBegin(GL_LINES);
    glVertex3f(x,y,z);
    glVertex3f(x+n[c].x, y+n[c].y, z+n[c].z);
    glEnd();
    c++;
  }

}
