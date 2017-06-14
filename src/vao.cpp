/*
 * =====================================================================================
 *
 *       Filename:  vao.cpp
 *
 *    Description:  Implémentation Structures et méthodes autour des VAO
 *
 *        Version:  1.0
 *        Created:  26/05/2017 19:29:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigue Siry, rodsiry@gmail.com
 *   Organization:  Ecole Supérieure d'électricité
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include "../include/vao.h"
#ifndef  BUFFER_OFFSET
#define  BUFFER_OFFSET(offset) ((char*)NULL + (offset))
#endif   /* ----- #ifndef BUFFER_OFFSET----- */

using namespace glm;
vao createVAO(float* vertices, int size)
{
    vao res;
    res.vboID=0;
    res.vaoID=0;
    glGenBuffers(1,&res.vboID);
    glBindBuffer(GL_ARRAY_BUFFER, res.vboID);
    glBufferData(GL_ARRAY_BUFFER, size*sizeof(float), vertices, GL_STATIC_DRAW);
    //glBufferSubData(GL_ARRAY_BUFFER, 0, size*sizeof(float), vertices);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    if(glIsVertexArray(res.vaoID)==GL_TRUE)
        glDeleteVertexArrays(1,&res.vaoID);
    glGenVertexArrays(1, &res.vaoID); 
    glBindVertexArray(res.vaoID);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, res.vboID);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE, 0, NULL);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);
    return res;
}
void printVAO(vao data, GLuint sh, int size, glm::mat4 projection,glm::mat4 model,glm::mat4 view)
{
    glUseProgram(sh);
    glBindVertexArray(data.vaoID);
    glUniformMatrix4fv(glGetUniformLocation(sh, "projection"),1,GL_FALSE, value_ptr(projection));
    glUniformMatrix4fv(glGetUniformLocation(sh, "model"),1,GL_FALSE, value_ptr(model));
    glUniformMatrix4fv(glGetUniformLocation(sh, "view"),1,GL_FALSE, value_ptr(view));
    glDrawArrays(GL_TRIANGLES, 0, size);
    glBindVertexArray(0); 
    glUseProgram(0);
}
void printBillboard(vao data, GLuint sh, int size, glm::mat4 projection,glm::mat4 model,glm::mat4 view)
{
    mat4 modelView=view*model;
    modelView=mat4(1.f)+modelView-mat4(mat3(modelView));
    //modelView[3][3]=1.f;
    printVAO(data, sh, size, projection, mat4(1.f), modelView);
}
vao freeVAO(vao data)
{
    glDeleteBuffers(1, &data.vboID);
    glDeleteVertexArrays(1,&data.vaoID);
}

