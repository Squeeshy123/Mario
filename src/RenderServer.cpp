#include "RenderServer.h"

#include <SDL/SDL.h>
#include "RenderAsset.h"

std::vector<SDL_Texture*> texs;

void RenderServer::begin() {
	update_textures();
}

void RenderServer::update_textures() {
	for (size_t i = 0; i < render_buffer.size(); i++) {
		load_texture(render_buffer[i]->get_path());
	}
}

RenderAsset* RenderServer::create_render_asset(std::string path, int p_x, int p_y, int p_width, int p_height)
{
	printf("Added render asset");
	RenderAsset* ra = new RenderAsset(path, p_x, p_y, p_width, p_height);
	render_buffer.push_back(ra);
	

	return ra;
}

SDL_Texture* RenderServer::load_texture(std::string path)
{
	SDL_Texture* sdlt = IMG_LoadTexture(renderer, path.c_str());
	texs.push_back(sdlt);
	return sdlt;
}


void RenderServer::render()
{
	for (size_t i = 0; i < render_buffer.size(); i++) {
		SDL_Rect r;
		r.x = render_buffer[i]->get_rect().x;
		r.y = render_buffer[i]->get_rect().y;
		r.w = render_buffer[i]->get_rect().w;
		r.h = render_buffer[i]->get_rect().h;

		SDL_RenderCopy(renderer, texs[i], NULL, &r);
	}
}
