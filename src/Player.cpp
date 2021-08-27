#include <iostream>
#include <SDL/SDL.h>

#include "Player.h"
#include "Renderer.h"


void draw_player(Player& player)
{
	Renderer::set_draw_color(Color{255,0,0,0});
	Renderer::render_rect(player.position, Vec2(50, 50));
}

void player_input(Player& player, SDL_Event& evnt)
{
	if (evnt.type == SDL_KEYDOWN) {
		switch (evnt.key.keysym.sym) {
			case SDLK_d:
				player.velocity.x = player.speed;
				printf("D");
				break;
			case SDLK_a:
				player.velocity.x = -player.speed;
				printf("A");
				break;
		}
	}
}

void player_update(Player& player)
{
}

void player_physics(Player& player, float dT)
{
	player.velocity.y += 9.8f;
	player.position = player.position + player.velocity * dT;
	player.velocity.x = 0;
}

void player_collision(Player& player)
{
}
