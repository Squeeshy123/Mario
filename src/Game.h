#pragma once
#include <SDL/SDL.h>

class Game
{
public:
    SDL_Renderer* get_renderer() {
        return renderer;
    }
    SDL_Window* get_window() {
        return window;
    }
    void set_renderer(SDL_Renderer& new_renderer) {
        renderer = &new_renderer;
    }
    void set_window(SDL_Window& new_window) {
        window = &new_window;
    }



public:
    static Game* get_singleton();

    ~Game() {

    }
private:
    static Game* singleton;

    SDL_Renderer* renderer;
    SDL_Window* window;

    Game() {
        Game::singleton = this;
    }
};

