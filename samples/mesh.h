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
    Vec3f ab = v[vi[i]] - v[vi[i+1]]; 
    Vec3f ac = v[vi[i]] - v[vi[i+2]];
    Vec3f temp = ab.cross(ac);
    temp = temp.normalize();
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


void generatePerVertexNormals(bool weighted, Mesh *t)
{
  std::vector<Vec3f> v = t->m_v;
  std::vector<int> vi = t->m_vi;
  std::vector<Vec3f> nf = t->m_nf;
  std::vector<Vec3f> nv;
  std::vector< std::vector<int> > v_t_membr; // contains vertex -> triangle membership
  unsigned int i = 0;
  int j = 0;

  // traverse every triangle, building membership
  for(i = 0; i < vi.size(); i += 3)
  {
    v_t_membr[vi[i]].push_back(j);
    v_t_membr[vi[i+1]].push_back(j);
    v_t_membr[vi[i+2]].push_back(j);
    j++;
  }
  
  for(i = 0; i < v_t_membr.size(); i++)
  {
     for(j = 0; j < v_t_membr[i].size(); j++)
     {
       //TODO

     }
  }
  
}

bool isLessCrease(Vec3f a, Vec3f b, int creaseAngle)
{
  bool isLess = false;
  float dotp = a.dot(b);
  dotp = dotp / (a.length() * b.length());
  float angle = acos(dotp);
  angle = ((float)180/PI)*angle;

  if(angle < creaseAngle)
  {
    isLess = true;
  }

  return isLess;
}

