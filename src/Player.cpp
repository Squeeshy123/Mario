#include <iostream>
#include <SDL/SDL.h>

#include "MMath.h"
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
	Rect upwards_rect = Rect(position.x, position.y + 25, 25, 50);
	Rect downwards_rect = Rect(position.x, position.y - 25, 25, 50);
	Rect left_rect = Rect(position.x - 25, position.y, 50, 25);
	Rect right_rect = Rect(position.x + 25, position.y, 50, 25);
	for (int i = 0; i < world.collision_rects.size(); i++) {
		if (rect_intersects_rect(downwards_rect, *world.collision_rects[i]) && velocity.y < 0)
			velocity.y += 9.8f;
		if (rect_intersects_rect(upwards_rect, *world.collision_rects[i]) && velocity.y > 0)
			velocity.y -= velocity.y;
		if (rect_intersects_rect(left_rect, *world.collision_rects[i]) && velocity.x < 0)
			velocity.x -= velocity.x;
		if (rect_intersects_rect(right_rect, *world.collision_rects[i]) && velocity.x > 0)
			velocity.x -= velocity.x;
			
	}
	//
	position = position + velocity * dT;
	velocity.x = 0;
}
