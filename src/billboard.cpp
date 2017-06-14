/*
 * =====================================================================================
 * *       Filename:  billboard.cpp
 *
 *    Description:  Implémentation fonctions billboard
 *
 *        Version:  1.0 *        Created:  29/05/2017 19:20:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigue Siry, rodsiry@gmail.com
 *   Organization:  Ecole supérieure d'électricité
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "../include/billboard.h"
using namespace glm;
void printMat(mat3 m)
{
    for(int i(0);i<3;i++)
    {
        for(int j(0);j<3;j++)
            std::cout<<m[i][j]<<" ";
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}
void printBillboard(obillboard bill, GLuint sh, glm::mat4 projection, glm::mat4 model,glm::mat4 view)
{

	int inv=0;
	int nh=bill.nh;
	int nw=bill.nw;
	//model=model*translate(bill.pos);
	//Billboard transform
	float w=0;
	float h=0;
	mat4 interm=mat4(mat3(model));
	interm[3][3]=1.f;
	mat3 r=mat3(view*interm);
	//calcul des angles d'euler
	float z=-degrees(atan2(r[1][1],r[1][0]));
	float x=degrees(atan2(sqrt(r[1][0]*r[1][0]+r[1][1]*r[1][1]),r[1][2]))-90.f;
	//vec3 v1=normalize(r[2][0]*r[2]+r[0][0]*r[0]);
	vec3 v=vec3(r[1][0],r[1][1],0.f);
	vec3 v2=normalize((r[0][0]*r[1][0]+r[0][1]*r[1][1])*r[0]+(r[2][0]*r[1][0]+r[2][1]*r[1][1])*r[2]);
	if(v2.z<0.f)
		v2=-v2;
	vec3 v1=cross(r[1],v2);
	if(v1.x<0.f)
		v1=-v1;
	//vec3 v2=normalize(r[2][2]*r[2]+r[0][2]*r[0]);
	float y;
	if(r[1][1]>0)
		y=degrees(atan2(dot(v2,r[2]),dot(v1,r[2])))+90.f;
	else
		y=-degrees(atan2(dot(v2,r[2]),dot(v1,r[2])))-90.f;
	//inversion de la texure
	int i=inv%2;
	//gestion des quadrants
	h=int(floor(nh*(0.5f-x/180.f)))%nh;
	w=int(round(nw*(180.f+y)/360.f))%nw;
	if(inv==1)
		w=int(round(nw*(180.f-y)/360.f))%nw;
	//gestion de l'axe de sym�trie
	else if(inv==2&&w>nw/2.f)
	{w=-2*w;i=1;}
	else if(inv==2&&w<nw/2.f)
	{w=2*w;i=0;}
	//fix pour les arrondis de calcul
	float seuil=10.0f;
	if(abs(x-90.f)<seuil)
	{
		z=90.f-degrees(atan2(r[2][1],r[2][0]));
		if(inv==1)
			z=-90.f-degrees(atan2(r[2][1],r[2][0]));
		w=0.25f*nw;
		if(inv==2)
		{w=nw/2;i=0;}
	}
	if(abs(x+90.f)<seuil)
	{
		z=90.f-degrees(atan2(r[2][1],r[2][0]));
		if(inv==1)
			z=-90.f-degrees(atan2(r[2][1],r[2][0]));
		w=0.25f*nw;
		if(inv==2)
		{w=nw/2;i=0;}
	}
	//matrice finale
	mat4 modelview=view*model-mat4(mat3(view*model))+rotate(radians(90.f+z),vec3(0.f,0.f,-1.f));
	modelview[3][3]=1.f;
	//
	GLint p[2]={w,h};
	GLint n[2]={nw,nh};
	GLfloat in[1]={i};
	GLfloat rap=float(bill.img.w)/float(bill.img.h);
	//
	//
	//
	glUseProgram(sh);
	glBindTexture(GL_TEXTURE_2D, bill.img.ID);
	glUniform1iv(glGetUniformLocation(sh, "uvN"),2,n);
	glUniform1iv(glGetUniformLocation(sh, "uvP"),2,p);
	glUniform1f(glGetUniformLocation(sh, "r"), rap);
	glUniform1i(glGetUniformLocation(sh, "tex"), 0);
	printVAO(bill.data, sh, 9,projection, modelview, mat4(1.f));
}


