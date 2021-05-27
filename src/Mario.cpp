#include <iostream>
#include <SDL/SDL.h>

#include <SDL/sdl_image.h>
#include "ServerManager.h"

#include "ECS.h"
#include "Components.hpp"

#include "Levels/Levels.h"

#include "Scripts/Player.h"

const std::string base_title = "Mario | ";

int checkpoint = 0;
void debugcheck(std::string s) {
    std::cout << s << " Debug: " << checkpoint << "\n";
    checkpoint++;
}

char const* convert_button_number_to_string(int button)
{
    char const* result = "NO_BUTTON";
    switch (button)
    {
    case SDL_BUTTON_LEFT:
        result = "left";
        break;

    case SDL_BUTTON_MIDDLE:
        result = "middle";
        break;

    case SDL_BUTTON_RIGHT:
        result = "right";
        break;

    default:
        break;
    }

    return result;
}


int wmain(int argc, char* argv[])
{
    
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("SDL_Init failed: %s\n", SDL_GetError());
    }
    else {
        printf("yes render\n");
    }

    
    if (IMG_Init(IMG_INIT_PNG)) {
        printf("yes image\n");
    }
    else {
        printf("no image\n");
    }


    SDL_Window* window = SDL_CreateWindow("SDL2 Window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1280,
        720,
        SDL_RENDERER_ACCELERATED);

    Server::ServerManager* server_manager = new Server::ServerManager(window);

    SDL_Event event;
    bool running = true;

    LevelOne* manager = new LevelOne(server_manager);

    manager->load();

    manager->begin();

    double deltaTime = 0;

    Uint32 lastUpdate = SDL_GetTicks();

    while (running)
    {        
        while (SDL_PollEvent(&event) > 0)
        {
            manager->input(event);
            if (event.type == SDL_QUIT) {
                SDL_Quit();
                return 0;
            }
        }
        

        server_manager->get_render_server()->render();
    

        Uint32 current = SDL_GetTicks();

        // Calculate dT (in seconds)

        float deltaTime = (current - lastUpdate) / 1000.0f;


        
        manager->tick(deltaTime);
        
        std::string Title = base_title + std::to_string(deltaTime);
        SDL_SetWindowTitle(window, Title.c_str());

        lastUpdate = current;

        SDL_RenderPresent(server_manager->get_render_server()->get_renderer());
    }

    SDL_DestroyWindow(window);
    SDL_Quit();


    printf("Hello world!");
    return 0;
}