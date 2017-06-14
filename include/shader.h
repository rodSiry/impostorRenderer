/*
 * =====================================================================================
 *
 *       Filename:  shader.h
 *
 *    Description:  fonction wrapper pour shaders glsl
 *
 *        Version:  1.0
 *        Created:  24/05/2017 17:24:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigue Siry (), rodsiry@gmail.com
 *   Organization:  Ecole Supérieure d'électricité
 *
 * =====================================================================================
 */

#ifndef  SHADER_INC
#define  SHADER_INC
#include <GL/glew.h>
#include <string>
#include <GL/glx.h>
#include <GL/glu.h>
#include <iostream>
#include <string>
#include <fstream>
struct Program
{
    GLuint pID;
    GLuint fID;
    GLuint vID;
};
Program createProgram(std::string pathV, std::string pathF);
void freeProgram(Program p);
bool compileShader(GLuint &sh, GLenum type, std::string const& path);
#endif   /* ----- #ifndef SHADER_INC  ----- */

