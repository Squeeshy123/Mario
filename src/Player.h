#pragma once
#include "MMath.h"
union SDL_Event;

class World;

class Player {
	private:
		Vec2 position;
		Vec2 velocity;
		float speed = 10.0f;
		

	public:
		void draw_player();
		void player_input(SDL_Event& evnt);
		void player_update();
		void player_physics(float dT, World& world);
};


