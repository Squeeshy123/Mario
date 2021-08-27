#include <iostream>
#include <string>
#include <SDL/SDL.h>

#include "Player.h"
#include "Game.h"

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

// use wmain() because SCons doesn't like regular main()
int wmain(int argc, char* argv[])
{
    
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("SDL_Init failed: %s\n", SDL_GetError());
    }
    else {
        printf("yes render\n");
    }

    SDL_Window* window = SDL_CreateWindow(
        "Mario", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        640, 480,
        SDL_WINDOW_OPENGL
    );
    SDL_Renderer* renderer = SDL_CreateRenderer(
        window,
        0,
        SDL_RENDERER_ACCELERATED
    );

    Game* game = Game::get_singleton();

    game->set_renderer(*renderer);
    game->set_window(*window);


    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    Player* player = new Player();

    SDL_Event evnt;
    bool running = true;
    SDL_Rect r;
    r.x = 100;
    r.y = 100;
    r.w = 100;
    r.h = 100;

    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double delta_time = 0;


    while (running) {

        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();

        delta_time = (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());

        if (SDL_PollEvent(&evnt) > 0)
        {
            if (evnt.type == SDL_QUIT) {
                running = false;
            }
            
            player_input(*player, evnt);
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        
        player_physics(*player, delta_time);
        
        draw_player(*player);

        SDL_RenderDrawRect(renderer, &r);
        SDL_RenderPresent(renderer);
    }

    delete window;
    delete renderer;

    return 0;
}