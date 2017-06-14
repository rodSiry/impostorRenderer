/*
 * =====================================================================================
 *
 *       Filename:  vao.h
 *
 *    Description:  Structure VAO
 *
 *        Version:  1.0
 *        Created:  26/05/2017 19:23:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigue Siry (), rodsiry@gmail.com
 *   Organization:  Ecole Supérieure d'électricité
 *
 * =====================================================================================
 */

#ifndef  VAO_INC
#define  VAO_INC
#include <GL/glew.h>
#include <string>
#include <GL/glx.h>
#include <GL/glu.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

struct vao
{
    GLuint vboID;
    GLuint vaoID;
};
vao createVAO(float* vertices, int size);
void printVAO(vao data, GLuint sh, int size, glm::mat4 projection,glm::mat4 model,glm::mat4 view);
void printBillboard(vao data, GLuint sh, int size, glm::mat4 projection,glm::mat4 model,glm::mat4 view);
vao freeVAO(vao data);
#endif   /* ----- #ifndef VAO_INC  ----- */
