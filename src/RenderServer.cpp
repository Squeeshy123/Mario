#include "RenderServer.h"

#include <SDL/SDL.h>
#include "RenderAsset.h"

std::vector<SDL_Texture*> texs;

void RenderServer::begin() {
	update_textures();
}

void RenderServer::update_textures() {
	texs.clear();
	for (size_t i = 0; i < render_buffer.size(); i++) {
		load_texture(render_buffer[i]->get_path());
	}
}

RenderAsset* RenderServer::create_render_asset(RenderType p_render_type, std::string path, int p_x, int p_y, int p_width, int p_height)
{
	printf("updating textures\n");
	RenderAsset* ra = new RenderAsset(this, p_render_type, path, p_x, p_y, p_width, p_height);	
	
	render_buffer.push_back(ra);
	
	update_textures();

	return ra;
}

SDL_Texture* RenderServer::load_texture(std::string path)
{
	SDL_Surface* sdl_s = IMG_Load(path.c_str());

	printf("Creating Texture\n");
	if (sdl_s == NULL) {
		printf("Unable to create texture surface, SDL_Image Error: %s\n", IMG_GetError());
	}
	else {
		SDL_Texture* sdl_t = SDL_CreateTextureFromSurface(renderer, sdl_s);
		if (sdl_t == NULL) {
			printf("Unable to create texture surface, SDL_Image Error: %s\n", IMG_GetError());
		}

		SDL_FreeSurface(sdl_s);

		texs.push_back(sdl_t);

		return sdl_t;
	}
	return nullptr;
}


void RenderServer::render() {

	SDL_SetRenderDrawColor(renderer, 0, 100, 255, 255);
	SDL_RenderClear(renderer);

	//printf("Start render");
	for (size_t x = 0; x < render_buffer.size(); x++) {
		
		if (render_buffer[x]->render_type == RenderType::Texture) {

			for (int y = 0; y < render_buffer[x]->instances.size(); y++) {
				SDL_Rect r;
				
				r.x = (int)render_buffer[x]->get_rect().x + render_buffer[x]->instances[y].x;
				r.y = (int)render_buffer[x]->get_rect().y + render_buffer[x]->instances[y].y;
				r.w = (int)render_buffer[x]->get_rect().w;
				r.h = (int)render_buffer[x]->get_rect().h;
				
				SDL_RenderCopy(renderer, texs[x], NULL, &r);
			}
		}
	}
	//printf("Finished render");
}

RenderServer::RenderServer(SDL_Window* window) {
	renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
}

RenderServer::~RenderServer() {
	SDL_DestroyRenderer(renderer);
	texs.clear();
}