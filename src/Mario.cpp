#include <iostream>
#include <SDL/SDL.h>

#include <SDL/sdl_image.h>
#include "ServerManager.h"

#include "ECS.h"
#include "Components.h"

static Server::ServerManager* server_manager = new Server::ServerManager();

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


    SDL_Event event;
    bool running = true;
    Manager* manager = new Manager(server_manager);
    Entity* e = manager->add_entity();
    
    e->add_component<TransformComponent>(100, 100, 2, 2);
    

    //printf("(%i, %i)", e->get_component<TransformComponent>()->pos_x, e->get_component<TransformComponent>()->pos_y);

    e->add_component<SpriteComponent>();
    
    manager->begin();

    while (running)
    {
        while (SDL_PollEvent(&event) > 0)
        {
            switch (event.type)
            {
            case SDL_QUIT:
                std::cout << "Quitting application\n";
                running = false;
                break;

            case SDL_MOUSEMOTION:
                std::cout << "Mouse Position = { "
                    << event.motion.x << " "
                    << event.motion.y << " }\n";
                break;

            case SDL_MOUSEBUTTONDOWN:
            case SDL_MOUSEBUTTONUP:
                std::cout << convert_button_number_to_string(event.button.button)
                    << " mouse button " << ((event.button.state == SDL_PRESSED) ? "pressed" : "released");
                std::cout << "\n";
                break;

            case SDL_KEYDOWN:
            case SDL_KEYUP:
                std::cout << "Key " << (char)event.key.keysym.sym << " "
                    << ((event.key.state == SDL_PRESSED) ? "pressed" : "released") << "\n";
                break;
            }
        }

        manager->tick(0.1f);

        server_manager->get_render_server()->render();

        SDL_RenderPresent(server_manager->get_render_server()->get_renderer());
    }

    SDL_DestroyWindow(window);
    SDL_Quit();


    printf("Hello world!");
    return 0;
}