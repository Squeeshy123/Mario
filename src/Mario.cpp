#include <iostream>
#include <string>
#include <SDL/SDL.h>


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

    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Event evnt;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&evnt) > 0)
        {
            if (evnt.type == SDL_QUIT) {
                running = false;
            }
        }
    }

    delete window;
    delete renderer;

    return 0;
}