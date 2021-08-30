#pragma once
#include <SDL/SDL.h>

class Game
{
    private:
        static Game* singleton;

        Game() {
            Game::singleton = this;
        }

    public:
        static Game* get_singleton();

        ~Game() {

        }


    private:
        SDL_Renderer* renderer;
        SDL_Window* window;
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



    
};

