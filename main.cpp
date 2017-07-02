#include <iostream>
#include <IL/ilu.h>
#include "include/shader.h"
#include "include/billboard.h"
#include "include/vao.h"
#include "include/camera.h"
#include <glm/glm.hpp>
#include <GL/glx.h>
#include <GL/glu.h>
#include <GL/glew.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <glm/gtx/transform.hpp>

const Uint8 * keys;

int main(int argc, char *argv[]) { 
    int w;
    int h;
    SDL_Window* win(0);
    SDL_GLContext context(0);
    SDL_Event e;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    win=SDL_CreateWindow("TEST", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	ilInit();
    context=SDL_GL_CreateContext(win);
	std::cout<<glGetString(GL_VERSION)<<std::endl;
	glewExperimental=GL_TRUE;
	if(glewInit()!=GLEW_OK)
		std::cout<<"glew failed."<<std::endl;
	Program prog=createProgram("shader/grisVert","shader/grisFrag");
	float vertices[18]={ -1.,-1.,0.,
		1.,-1.,0.,
		1., 1.,0.,
		-1.,-1.,0.,
		1., 1.,0.,
		-1., 1.,0.};
	vao data=createVAO(&vertices[0], 18);
	float c;
    SDL_GetWindowSize(win, &w, &h);
	glViewport(0, 0, w, h);
	glm::mat4 projection=glm::perspective(40.f, float(w)/float(h),0.1f, 100.f);
	glm::mat4 view=glm::lookAt(glm::vec3(0.f,0.f,2.f),glm::vec3(0.f,0.f,0.f),glm::vec3(0.f,1.f,0.f));

	glm::mat4 model(glm::mat4(1.f));
	tex myTex=loadTexture("textures/missile.png");
	obillboard bill;
	bill.img=myTex;
	bill.data=data;
	bill.nh=16;
	bill.nw=32;
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    camera cam; 
    cam.x=0;
    cam.y=0;
    cam.pos=glm::vec3(0,0,0);
	while(1) {
		glViewport(0, 0, w, h);
		projection=glm::perspective(40.f, float(w)/float(h),0.1f, 100.f);
		glClearColor(.0, 1.0, 1.0, 1.0);
		c+=0.01;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//model=glm::rotate(0.f, glm::vec3(0.,1.,0.1))*glm::translate(glm::vec3(0.f,0.f,-10.f))*glm::rotate(c, glm::vec3(1.,1.,0.));
        keys = SDL_GetKeyboardState(NULL);
        while(SDL_PollEvent(&e))
            if(e.type==SDL_WINDOWEVENT)
            {
                SDL_GetWindowSize(win, &w, &h);
                glViewport(0, 0, w, h);
		        projection=glm::perspective(40.f, float(w)/float(h),0.1f, 100.f);
            }
        if (keys[SDL_SCANCODE_ESCAPE])
        {
            break;
        }
        cameraUpdate(&cam, keys);
        view=cameraView(&cam);
		printBillboard(bill, prog.pID, projection, model,view);
        SDL_GL_SwapWindow(win);
    }
	freeVAO(data); 
	freeProgram(prog);
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
