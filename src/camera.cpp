/*
 * =====================================================================================
 *
 *       Filename:  camera.cpp
 *
 *    Description:  Implémentation fonctions de positionnement spatial
 *
 *        Version:  1.0
 *        Created:  15/06/2017 19:12:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigue Siry, rodsiry@gmail.com
 *   Organization:  Ecole Supérieure d'électricité
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "../include/camera.h"
using namespace glm;
void cameraUpdate(camera* cam)
{

    
}
mat4 cameraView(camera* cam)
{
   mat4 res;
   res=rotate(cam->x,vec3(0.f,1.f,0.f))*rotate(cam->y,vec3(1.f,0.f,0.f))*res;
   res=translate(cam->pos)*res;
   return inverse(res); 
}
