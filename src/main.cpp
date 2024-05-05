//
//  main.cpp
//  VerletIntegrationNew
//
//  Created by Nicholas Moy on 3/28/24.
//

#define GL_SILENCE_DEPRECATION

#include <SDL2/SDL.h>
#include <OpenGL/gl3.h>
#include <glm/glm.hpp>
#include <iostream>
#include <format>
#include "physics.hpp"
#include "renderer.hpp"
#include "window.hpp"

#define FPS 60
const float FRAME_MSEC = 1000.0f/60;
const float TIME_STEP = FRAME_MSEC/1000;

int main(int argc, char *argv[])
{
    // Main loop objects
    SDL_Event e;
    bool running = true;
    unsigned int a = SDL_GetTicks();
    unsigned int b = SDL_GetTicks();
    unsigned int lastRender = SDL_GetTicks();
    
    Window window = Window();
    Renderer renderer = Renderer();
    Physics physics = Physics();
    
    window.addRenderer(&renderer);
    renderer.addPhysics(&physics);
    
    glClearColor(210.0/255, 222.0/255, 228.0/255, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(window);
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Main program loop
    while(running)
    {
        // Cap Framerate
        a = SDL_GetTicks();
        if(a < b)
        {
            SDL_Delay(1);
        }
        else
        {
            while(a > b)
            {
                //std::cout << "delta: " << a-b << "\n";
                // Poll events
                window.PollIO(e, &running);
                
                /* Game physics */
                physics.update((float)1.0f/FPS);
                
                b += FRAME_MSEC;
            }
            
            // Render
            //unsigned int current = SDL_GetTicks();
            //std::cout << "FPS: " << 1000/(current - lastRender) << "\n";
            renderer.render();
            //lastRender = SDL_GetTicks();
            
            // Update screen
            SDL_GL_SwapWindow(window);
            glClear(GL_COLOR_BUFFER_BIT);
        }
    }

    SDL_Quit();
    return 0;
}
