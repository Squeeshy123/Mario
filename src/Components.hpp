#pragma once

#include <string>
#include <tuple>
#include <vector>

#include "ECS.h"

#include "RenderAsset.h"
#include "ServerManager.h"

#include "MMath.h"


#define TRANSFROM_COMPONENT_ID 1
#define SPRITE_COMPONENT_ID 2
#define SCRIPT_COMPONENT_ID 3

#define PLAYER_MOVEMENT_COMPONENT_ID 4

#define TILEMAP_COMPONENT_ID 5

using namespace MMath;

class TransformComponent : public Component {
	public:
		COMPONENT_INIT(TRANSFROM_COMPONENT_ID, TransformComponent)

		float pos_x;
		float pos_y;
		
		float size_x;
		float size_y;

		TransformComponent(float p_pos_x, float p_pos_y, float p_size_x, float p_size_y) 
			: Component() {
			//Component::id = TRANSFROM_COMPONENENT_ID;

			pos_x = p_pos_x;
			pos_y = p_pos_y;

			size_x = p_size_x;
			size_y = p_size_y;
		}

		void add_position(float p_x, float p_y) {
			pos_x += p_x;
			pos_y += p_y;
		}

		void set_position(float p_x, float p_y) {
			pos_x = p_x;
			pos_y = p_y;
		}

		void add_size(float p_x, float p_y) {
			size_x += p_x;
			size_y += p_y;
		}

		void set_size(float p_x, float p_y) {
			size_x = p_x;
			size_y = p_y;
		}
};


class SpriteComponent 
	: public Component {

	public:
		COMPONENT_INIT(SPRITE_COMPONENT_ID, SpriteComponent)

		std::string path;

		TransformComponent* t_comp = nullptr;

		RenderAsset* render_asset = nullptr;
		/*
		SpriteComponent()
		{
			path = "A:\\Desktop\\Programming\\CPP\\Mario\\Mario\\assets\\mario.png";

			if (get_owner()->has_component<TransformComponent>()) {
				t_comp = get_owner()->get_component<TransformComponent>();
			}
			else {
				printf("Error: No Transform Component.");
			}
		}*/

		SpriteComponent(std::string p_path) 
			: Component() 
		{
			//Component::id = SPRITE_COMPONENENT_ID;
			path = p_path;

			if (get_owner()->has_component<TransformComponent>()) {
				t_comp = get_owner()->get_component<TransformComponent>();
			}
			else {
				printf("Error: No Transform Component.");
			}
		}

		void begin() {
			if (get_owner() != nullptr) {
				path = "assets\\mario.png";
				printf("1111111\n");
				// Safety check for TransformComponent
				if (t_comp == nullptr) t_comp = get_owner()->get_component<TransformComponent>();
				printf("22222\n");
				render_asset = owner->get_manager()->get_render_server()->create_render_asset(RenderType::Texture, path, t_comp->pos_x, t_comp->pos_y, t_comp->size_x * 64, t_comp->size_y * 64);
				printf("33333333\n");
			}
		}

		void tick(float deltaTime) {
			// Update render asset position
			render_asset->set_rect(t_comp->pos_x, t_comp->pos_y, t_comp->size_x * 64, t_comp->size_y * 64);
		}
};

class ScriptComponent : public Component {
	COMPONENT_INIT(SCRIPT_COMPONENT_ID, ScriptComponent)

	public:
		//virtual void begin();
		//virtual void tick(float deltaTime)  {};
		//virtual void input(SDL_Event event) {};


};


class TilemapComponent : public Component {
	public: 
		static const int id = 5; 
		static int get_id() { return Component::id;}
	private:
		std::vector<std::string> sprites;

		TransformComponent* t_comp = owner->get_component<TransformComponent>();;

		std::vector<RenderAsset*> render_assets;

		Vec2 cell_size = Vec2{64,64};

	public:
		std::vector<std::tuple<int, int, int>> tiles;

		TilemapComponent();

		void create_render_assets(){
			render_assets.clear();
			for (int i = 0; i < sprites.size(); i++) {
				render_assets.push_back(owner->get_manager()->get_render_server()->create_render_asset(RenderType::Texture, sprites[i], t_comp->pos_x, t_comp->pos_y, t_comp->size_x * cell_size.x, t_comp->size_y * cell_size.y));
			}
		}

		void set_tileset(std::vector<std::string> p_spr_paths){
			sprites = p_spr_paths;
			update_render_tiles();
		}

		void update_render_tiles() {
			for(int i = 0; i<tiles.size(); i++){
				render_assets[std::get<2>(tiles[i])]->clear_instances();
				render_assets[std::get<2>(tiles[i])]->instances.push_back(Vec2{(float)std::get<0>(tiles[i]) * cell_size.x, (float)std::get<1>(tiles[i]) * cell_size.y});
			}
		}
		// Update the sprite of a tile
		void set_tile_sprite(int tile_index, int new_sprite_index) {
			tiles[tile_index] = std::make_tuple(std::get<0>(tiles[tile_index]), std::get<1>(tiles[tile_index]), new_sprite_index);
		}

		// Add a tile
		void add_tile(int p_pos_x, int p_pos_y, int sprite_index) {
			if (sprite_index > sprites.size()-1){
				printf("Error: Sprite index out of range");
			}
			else {
				tiles.push_back(std::tuple<int, int, int>{p_pos_x, p_pos_y, sprite_index});
				update_render_tiles();
			}
		}
};