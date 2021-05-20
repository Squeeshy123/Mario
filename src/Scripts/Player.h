#pragma once

#include "../Components.hpp"

#include "../MMath.h"

class PlayerMovementComponent :
    public ScriptComponent
{
    COMPONENT_INIT(PLAYER_MOVEMENT_COMPONENT_ID, PlayerMovementComponent)

    private:
        TransformComponent* t_comp = nullptr;

    public:

        void begin();
        void tick(float deltaTime);
        void input(SDL_Event event);


};

