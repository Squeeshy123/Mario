#include <iostream>
#include <SDL/SDL.h>

#include "Player.h"
#include "Renderer.h"
#include "World.h"

void Player::draw_player()
{
	Renderer::set_draw_color(Color{255,0,0,0});
	Renderer::render_rect(position, Vec2(50, 50));
}

void Player::player_input(SDL_Event& evnt)
{
	if (evnt.type == SDL_KEYDOWN) {
		switch (evnt.key.keysym.sym) {
			case SDLK_d:
				velocity.x = speed;
				printf("D");
				break;
			case SDLK_a:
				velocity.x = -speed;
				printf("A");
				break;
		}
	}
}

void Player::player_update()
{
}

void Player::player_physics(float dT, World& world)
{
	for (int i = 0; i < world.collision_rects.size(); i++) {
	
	}
	velocity.y += 9.8f;
	position = position + velocity * dT;
	velocity.x = 0;
}
