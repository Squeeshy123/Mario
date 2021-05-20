#include "Levels/LevelOne.h"

void LevelOne::load() {
    //Load Player
    Entity* player = add_entity();
    
    player->add_component<TransformComponent>(100.0f, 100.0f, 2.0f, 2.0f);
    player->add_component<SpriteComponent>();
    player->add_component<PlayerMovementComponent>();

    // Load tilemap
    Entity* e_tilemap = add_entity();

    TilemapComponent* c_tilemap = e_tilemap->add_component<TilemapComponent>("assets/bricks.png");
    for(int x = 0; x<100; x++){
        for(int y = 0; y<100; y++){
            c_tilemap->add_tile(x,y,0);
        }
    }
}