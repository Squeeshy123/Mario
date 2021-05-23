#include "Levels/LevelOne.h"

#include <iostream>

SpriteComponent* sp = nullptr;

void LevelOne::load() {
    //Load Player
    Entity* player = add_entity();
    
    player->add_component<TransformComponent>(100.0f, 100.0f, 2.0f, 2.0f);
    //sp = player->add_component<SpriteComponent>();
    player->add_component<PlayerMovementComponent>();
    


    printf("Added player!\n");

    // Load tilemap
    Entity* e_tilemap = add_entity();

    std::vector<std::string> tileset = {(std::string)"assets/bricks.png"};

    /*e_tilemap->add_component<TransformComponent>(100.0f, 500.0f, 1.0f, 1.0f);
    e_tilemap->add_component<TilemapComponent>();
    
    printf("Added tilemap");

    TilemapComponent* c_tilemap = e_tilemap->get_component<TilemapComponent>();
    
    c_tilemap->set_tileset(tileset);
    for(int x = 0; x<100; x++){
        for(int y = 0; y<100; y++){
            c_tilemap->add_tile(x,y,0);
        }
    }*/
}

void LevelOne::begin(){
    printf("bbbb\n");
    for (size_t i = 0; i < entities.size(); i++) {entities[i]->begin();};
    
   // sp->render_asset->instances.push_back(Vec2{64.0f,64.0f});
}