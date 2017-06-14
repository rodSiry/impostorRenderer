/*
 * =====================================================================================
 *
 *       Filename:  texture.h
 *
 *    Description:  Fonctions de chargement et d'opérations sur les textures
 *
 *        Version:  1.0
 *        Created:  28/05/2017 15:44:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigue Siry (), rodsiry@gmail.com
 *   Organization:  Ecole Supérieure d'électricité
 *
 * =====================================================================================
 */

#ifndef  TEXTURE_INC
#define  TEXTURE_INC
#include <GL/glew.h>
#include <iostream>
#include <GL/glx.h>
#include <GL/glu.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <IL/ilu.h>
struct tex
{
    GLuint ID;
    int w;
    int h;
};

tex loadTexture(std::string path);
#endif   /* ----- #ifndef TEXTURE_INC  ----- */
