#include "Game.h"
Game* Game::singleton = nullptr;

Game* Game::get_singleton() {
    if (Game::singleton == nullptr) 
        Game::singleton = new Game();
    
    return Game::singleton;
}