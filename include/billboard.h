/*
 * =====================================================================================
 *
 *       Filename:  billboard.h
 *
 *    Description:  Fonctions relatives au billboarding
 *
 *        Version:  1.0
 *        Created:  29/05/2017 19:16:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigue Siry, rodsiry@gmail.com
 *   Organization:  Ecole supérieure d'électricité
 *
 * =====================================================================================
 */

#ifndef  BILLBOARD_INC
#define  BILLBOARD_INC
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

struct obillboard 
{
    vao data;
    tex img;
    glm::vec3 pos;
    float size;
    int nw;
    int nh;
};
void printBillboard(obillboard bill, GLuint sh,  glm::mat4 projection, glm::mat4 model,glm::mat4 view);

#endif   /* ----- #ifndef BILLBOARD_INC  ----- */
