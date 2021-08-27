#pragma once
#include "MMath.h"
union SDL_Event;

struct Player {
	Vec2 position;
	Vec2 velocity;
	float speed = 10.0f;
};

void draw_player(Player& player);
void player_input(Player& player, SDL_Event& evnt);
void player_update(Player& player);
void player_physics(Player& player, float dT);
void player_collision(Player& player, World);
