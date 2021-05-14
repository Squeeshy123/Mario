#pragma once

#include <string>

#include "ECS.h"

#include "RenderAsset.h"
#include "ServerManager.h"




#define TRANSFROM_COMPONENT_ID 1
#define SPRITE_COMPONENT_ID 2


class TransformComponent : public Component {
	public:
		COMPONENT_INIT(TRANSFROM_COMPONENT_ID, TransformComponent)

		int pos_x;
		int pos_y;
		
		int size_x;
		int size_y;

		TransformComponent(int p_pos_x, int p_pos_y, int p_size_x, int p_size_y) 
			: Component() {
			//Component::id = TRANSFROM_COMPONENENT_ID;

			pos_x = p_pos_x;
			pos_y = p_pos_y;

			size_x = p_size_x;
			size_y = p_size_y;
		}

		void add_position(int p_x, int p_y) {
			pos_x += p_x;
			pos_y += p_y;
		}

		void set_position(int p_x, int p_y) {
			pos_x = p_x;
			pos_y = p_y;
		}

		void add_size(int p_x, int p_y) {
			size_x += p_x;
			size_y += p_y;
		}

		void set_size(int p_x, int p_y) {
			size_x = p_x;
			size_y = p_y;
		}
};


class SpriteComponent 
	: public Component {

	public:
		COMPONENT_INIT(SPRITE_COMPONENT_ID, SpriteComponent)

		std::string path;

		TransformComponent* t_comp;
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
				path = "mario.png";
				if (t_comp == nullptr) t_comp = get_owner()->get_component<TransformComponent>();
				printf("Trying to add asset");
				owner->get_manager()->get_render_server()->create_render_asset(path, t_comp->pos_x, t_comp->pos_y, t_comp->size_x * 64, t_comp->size_y * 64);
			}
		}
};
