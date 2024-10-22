
#include <iostream>

#include <SDL.h>

#include <glmixedbinding/glmixedbinding.h>
#include <glmixedbinding/Version.h>
#include <glmixedbinding/FunctionCall.h>
#include <glmixedbinding/CallbackMask.h>

#include <glmixedbinding/glmixed/glmixed.h>
#include <glmixedbinding/getProcAddress.h>

#include <glmixedbinding-aux/ContextInfo.h>
#include <glmixedbinding-aux/Meta.h>
#include <glmixedbinding-aux/types_to_string.h>
#include <glmixedbinding-aux/ValidVersions.h>
#include <glmixedbinding-aux/debug.h>

#include <CubeScape.h>


using namespace glmixed;
using namespace glmixedbinding;


namespace
{
    CubeScape * cubescape(nullptr);
    SDL_Window* gWindow = nullptr;
    SDL_GLContext gContext;
    bool quit = false;
}


void framebuffer_resize()
{
    int width, height;
    SDL_GL_GetDrawableSize(gWindow, &width, &height);
    cubescape->resize(width, height);
}

void key_callback(SDL_Event e)
{
    const auto key = e.key.keysym.sym;
    const auto mod = e.key.keysym.mod;
    
    bool numCubesChanged = false;

    if (key == SDLK_q && (mod & KMOD_CTRL) && (e.type == SDL_KEYDOWN))
    {
        quit = true;
    }

    if (key == SDLK_i && (e.type == SDL_KEYDOWN))
    {
        cubescape->setNumCubes(cubescape->numCubes() + 1);
        numCubesChanged = true;
    }

    if (key == SDLK_d && (e.type == SDL_KEYDOWN))
    {
        cubescape->setNumCubes(cubescape->numCubes() - 1);
        numCubesChanged = true;
    }

    if (numCubesChanged)
    {
        const int n = cubescape->numCubes();
        std::cout << "#cubes = " << n << " * " << n << " = " << n * n << std::endl;
    }
}

int main(int, char *[])
{
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		std::cout << "#SDL2: SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;

		return 1;
	}
    
    //Use OpenGL 3.1 core
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);

    //Create window
    gWindow = SDL_CreateWindow( "Cubescape", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1440, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
    if( gWindow == nullptr )
    {
        std::cout << "#SDL2: Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        
        return 1;
    }

    SDL_SetWindowResizable(gWindow, SDL_TRUE);
    
    //Create context
    gContext = SDL_GL_CreateContext( gWindow );
    if( gContext == NULL )
    {
        std::cout << "#SDL2: OpenGL context could not be created! SDL Error: " << SDL_GetError() << std::endl;
        
        return 1;
    }
    
    // initialize glmixedbinding
    glmixedbinding::initialize(reinterpret_cast<glmixedbinding::ProcAddress(*)(const char*)>(SDL_GL_GetProcAddress), false); // only resolve functions that are actually used (lazy)
    glmixedbinding::aux::enableGetErrorCallback();

    //Use Vsync
    if( SDL_GL_SetSwapInterval( 1 ) < 0 )
    {
        std::cout << "SDL2: Unable to set VSync! SDL Error: " << SDL_GetError() << std::endl;
    }

    // // print some gl infos (query)

    std::cout << std::endl
        << "OpenGL Version:  " << aux::ContextInfo::version() << std::endl
        << "OpenGL Vendor:   " << aux::ContextInfo::vendor() << std::endl
        << "OpenGL Renderer: " << aux::ContextInfo::renderer() << std::endl;

    std::cout << std::endl
        << "Press i or d to either increase or decrease number of cubes." << std::endl << std::endl;


    cubescape = new CubeScape();

    int width, height;
    SDL_GL_GetDrawableSize(gWindow, &width, &height);
    cubescape->resize(width, height);

    //Event handler
    SDL_Event e;
    
    //Enable text input
    SDL_StartTextInput();

    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while(SDL_PollEvent(&e) != 0)
        {
            //User requests quit
            if(e.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN)
            {
                key_callback(e);
            }
            else if (e.type == SDL_WINDOWEVENT)
            {
                if (e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
                    framebuffer_resize();
                }
            }
        }

        //Render quad
        cubescape->draw();
        
        //Update screen
        SDL_GL_SwapWindow( gWindow );
    }
    
    //Disable text input
    SDL_StopTextInput();

    SDL_DestroyWindow(gWindow);
    SDL_Quit();

    return 0;
}
