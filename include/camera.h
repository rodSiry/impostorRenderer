/*
 * =====================================================================================
 *
 *       Filename:  camera.h
 *
 *    Description:  Fonctions de positionnement spatial 
 *
 *        Version:  1.0
 *        Created:  15/06/2017 19:08:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigue Siry (), rodsiry@gmail.com
 *   Organization:  Ecole Supérieure d'électricité
 *
 * =====================================================================================
 */

#ifndef  CAMERA_INC
#define  CAMERA_INC
#include <GL/glew.h>
#include <string>
#include <GL/glx.h>
#include <GL/glu.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include "texture.h"
#include "vao.h"
#include <math.h>
#include <SDL2/SDL.h>

struct camera
{
    glm::vec3 pos;
    float x;
    float y; 
};
void cameraUpdate(camera* cam, const Uint8* keys);
glm::mat4 cameraView(camera* cam);
#endif   /* ----- #ifndef CAMERA_INC  ----- */
