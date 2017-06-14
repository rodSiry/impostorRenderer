/*
 * =====================================================================================
 *
 *       Filename:  shader.cpp
 *
 *    Description:  wrapper pour shaders glsl
 *
 *        Version:  1.0
 *        Created:  24/05/2017 17:27:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigue Siry, rodsiry@gmail.com
 *   Organization:  Ecole Supérieure d'électricité
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <../include/shader.h>


Program createProgram(std::string pathV, std::string pathF)
{
    Program res;
    compileShader(res.vID, GL_VERTEX_SHADER, pathV);
    compileShader(res.fID, GL_FRAGMENT_SHADER, pathF);
    res.pID=glCreateProgram();
    glAttachShader(res.pID, res.fID);
    glAttachShader(res.pID, res.vID);
    glBindAttribLocation(res.pID,0,"in_Vertex");
    glLinkProgram(res.pID);
    return res;
}

bool compileShader(GLuint &sh, GLenum type, std::string const& path)
{
    sh=glCreateShader(type);
    std::ifstream file(path.c_str());
    std::string line;
    std::string source;
    while(getline(file, line))
        source+=line+'\n';
    file.close();
    const GLchar* strSource=source.c_str();
    glShaderSource(sh, 1, &strSource, 0);
    glCompileShader(sh);
    GLint erreur(0);
    glGetShaderiv(sh, GL_COMPILE_STATUS, &erreur);
    if(erreur != GL_TRUE)
    {
        std::cout<<"erreur de compilation"<<std::endl;
        GLint tailleErreur(0);
        glGetShaderiv(sh, GL_INFO_LOG_LENGTH, &tailleErreur);
        char* erreur = new char[tailleErreur+ 1];
        glGetShaderInfoLog(sh, tailleErreur, &tailleErreur, erreur);
        erreur[tailleErreur]='\0';
        std::cout<<erreur<<std::endl;
        delete[] erreur;
        glDeleteShader(sh);
        return false;
    }
    else
        return true;
}

void freeProgram(Program p)
{
    glDeleteShader(p.vID);
    glDeleteShader(p.fID);
    glDeleteProgram(p.pID);
}
