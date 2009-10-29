void motion(int x, int y)
{
  if(mouse_button == GLUT_LEFT_BUTTON)
  {
    // compute the angle (0..360) around x axis, and y-axis
    y_angle += (float(x - mouse_x)/WIDTH)*360.0;
    x_angle += (float(y - mouse_y)/HEIGHT)*360.0;

  }

  if(mouse_button == GLUT_MIDDLE_BUTTON)
  {
    scale += (y - mouse_y) / 1000.0;
    
    if(scale < 0.001)   scale = 0.001;
    if(scale > 6.0)   scale = 6.0;
    std::cout << "new scale: " << scale << std::endl;
  }

  mouse_x = x;    // update current mouse position
  mouse_y = y;
  redisplay_all();
  std::cout << "x: " << x << " y: " << y << std::endl;
}

void mouse(int button, int state, int x, int y)
{
  // button -- GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON, or GLUT_RIGHT_BUTTON.
  // state  -- GLUT_UP, GLUT_DOWN
  mouse_x = x;
  mouse_y = y;

  mouse_button = button;
  motion(x,y);
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
    case 'e' : 
      carx += 1;
      break;
    case 'E' :
      carx -= 1;
      break;
    case 'r' : 
      cary += 1;
      break;
    case 'R' : 
      cary -= 1;
      break;
    case 't':
      carz += 1;
      break;
    case 'T':
      carz -= 1;
      break;
    default:
      break;
  }
  std::cout << "EYEZ: " << eyex << " " << eyey << " " << eyez << std::endl;
  std::cout << "CAR: " << carx << " " << cary << " " << carz << std::endl;
  redisplay_all();
}

void special_keyboard(int key, int x, int y)
{
  switch(key)
  {
  case GLUT_KEY_LEFT:
    if(CAMERA_OPTION == 1)
    {
      light_angle -= 3;  
    }
    break;
  case GLUT_KEY_RIGHT:
    if(CAMERA_OPTION == 1)
    {
      light_angle += 3;
    }
    break;
  case GLUT_KEY_UP:
    break;
  case GLUT_KEY_DOWN:
    break;
  default:
    break;
  }

  if(CAMERA_OPTION == 1)
  {
    if(light_angle == 360 || light_angle == -360)
    {
      light_angle = 0;
    }
    LightPos[0] = 50*sin((float)light_angle*PI/180);
    LightPos[2] = 50*cos((float)light_angle*PI/180);
    std::cout << "New Light Pos: " << LightPos[0] << " " << LightPos[1] << " " << LightPos[2] << std::endl;
    top_display();
  }
  redisplay_all();
}
