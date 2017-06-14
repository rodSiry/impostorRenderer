/*
 * =====================================================================================
 *
 *       Filename:  texture.cpp
 *
 *    Description:  Implémentation fonctions relatives à la gestion des textures
 *
 *        Version:  1.0
 *        Created:  28/05/2017 15:51:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigue Siry, rodsiry@gmail.com
 *   Organization:  Ecole Supérieure d'électricité
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "../include/texture.h"

tex loadTexture(std::string path)
{
    tex res;
    SDL_Surface* image=IMG_Load(path.c_str());
    return res;
}
