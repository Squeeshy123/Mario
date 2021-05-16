#include "Player.h"

float vel_x = 0;
float vel_y = 0;

const float speed = 1000;
const float gravity = 980000;

bool is_moving = false;

void PlayerMovementComponent::begin()
{
	t_comp = get_owner()->get_component<TransformComponent>();
}

void PlayerMovementComponent::tick(float deltaTime)
{
	vel_y = gravity * deltaTime;

	if (!is_moving) {
		vel_x = 0;
	}

	t_comp->pos_y = MMath::clamp(t_comp->pos_y + vel_y * deltaTime, 0.0f, 720.0f - t_comp->size_y * 64.0f);
	t_comp->pos_x = MMath::clamp(t_comp->pos_x + vel_x * deltaTime, 0.0f, 1280.0f - t_comp->size_x * 64.0f);
}

void PlayerMovementComponent::input(SDL_Event event)
{
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_d:
			vel_x = speed;
			is_moving = true;
			break;
		case SDLK_a:
			vel_x = -speed;
			is_moving = true;
			break;
		case SDLK_SPACE:
			vel_y += gravity;
			t_comp->size_y++;
			is_moving = true;
			break;
		}
	}
	if (event.type == SDL_KEYUP) {
		is_moving = false;
	}
}
