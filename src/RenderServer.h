#pragma once
#include <vector>


#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include <string>
class RenderAsset;


class RenderServer
{
	private:
		SDL_Renderer* renderer;
		std::vector<RenderAsset*> render_buffer;
	public:

		void begin();


		void update_textures();

		RenderAsset* create_render_asset(std::string path, int p_x, int p_y, int p_width, int p_height);
		
		
		SDL_Texture* load_texture(std::string path);

		void render();

		SDL_Renderer* get_renderer() {
			return renderer;
		}
};

