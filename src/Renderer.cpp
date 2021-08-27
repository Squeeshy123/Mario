#include "Renderer.h"
#include "Game.h"

Game* game = Game::get_singleton();

void Renderer::set_draw_color(const Color& col) {
	SDL_SetRenderDrawColor(game->get_renderer(), col.r, col.g, col.b, col.a);
}

void Renderer::render_rect(const Vec2& location, const Vec2& size)
{
	SDL_Rect rect;
	rect.x = location.x;
	rect.y = location.y;
	rect.w = size.x;
	rect.h = size.y;

	SDL_RenderFillRect(game->get_renderer(), &rect);
}

