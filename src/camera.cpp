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
void cameraUpdate(camera* cam, const Uint8* keys)
{
        float speed=0.1f;
        float aSpeed=0.1f;
        mat4 rot=rotate(cam->x,vec3(0.f,1.f,0.f))*rotate(cam->y,vec3(1.f,0.f,0.f));
        vec3 front=speed*vec3(rot*vec4(0.f,0.f,1.f,0.f));
        vec3 side=cross(front, vec3(0.f,1.f,0.f));
        if (keys[SDL_SCANCODE_UP])
            cam->pos-=front;
        if (keys[SDL_SCANCODE_DOWN])
            cam->pos+=front;
        if (keys[SDL_SCANCODE_LEFT])
            cam->pos+=side;
        if (keys[SDL_SCANCODE_RIGHT])
            cam->pos-=side;
        if (keys[SDL_SCANCODE_W])
            cam->y+=aSpeed;
        if (keys[SDL_SCANCODE_A])
            cam->x+=aSpeed;
        if (keys[SDL_SCANCODE_S])
            cam->y-=aSpeed;
        if (keys[SDL_SCANCODE_D])
            cam->x-=aSpeed;

    
}
mat4 cameraView(camera* cam)
{
   mat4 res;
   res=rotate(cam->x,vec3(0.f,1.f,0.f))*rotate(cam->y,vec3(1.f,0.f,0.f))*res;
   res=translate(cam->pos)*res;
   return inverse(res); 
}
