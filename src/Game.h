#pragma once
#include <SDL/SDL.h>
#include "Player.h"
class World;
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
        Player* player;
        World* world;
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

        void set_player(Player* new_player) {
            player = new_player;
        }
        void set_world(World* new_world) {
            world = new_world;
        }

    
};

