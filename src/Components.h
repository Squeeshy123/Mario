#pragma once

#include <string>

#include "ECS.h"

#include "RenderAsset.h"
#include "ServerManager.h"




#define TRANSFROM_COMPONENT_ID 1
#define SPRITE_COMPONENT_ID 2
#define SCRIPT_COMPONENT_ID 3

#define PLAYER_MOVEMENT_COMPONENT_ID 4

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
				path = "C:\\Users\\finnm\\Desktop\\CSCWork\\Projects\\Mario\\src\\mario.png";

				// Safety check for TransformComponent
				if (t_comp == nullptr) t_comp = get_owner()->get_component<TransformComponent>();

				render_asset = owner->get_manager()->get_render_server()->create_render_asset(RenderType::Texture, path, t_comp->pos_x, t_comp->pos_y, t_comp->size_x * 64, t_comp->size_y * 64);
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