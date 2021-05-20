#pragma once
#include <vector>

#include <SDL/SDL.h>

#include "RenderServer.h"

#include <memory>
#include "ServerManager.h"

#define COMPONENT_INIT(ID, classname) public: classname() = default;	static const int id = ID;	static int get_id() { return Component::id;} 


class Entity;
class Component;
class Manager;



class Component {	

	public:
		Entity* owner = nullptr;

		COMPONENT_INIT(0, Component);

		virtual void tick(float deltaTime) {};
		virtual void begin() {};

		virtual void input(SDL_Event event) {};

		Entity* get_owner() { return owner; }
		void set_owner(Entity* p_owner) { owner = p_owner;  }

};

class Entity {
	private:
		Manager* manager = nullptr;

		std::vector<std::unique_ptr<Component>> components;

	public:
		void tick(float deltaTime) { 
			for (size_t i = 0; i < components.size(); i++) components[i]->tick(deltaTime);
		}

		void begin() {
			for (size_t i = 0; i < components.size(); i++) components[i]->begin();
		}

		void input(SDL_Event event) {
			for (size_t i = 0; i < components.size(); i++) components[i]->input(event);
		}

		template< class ComponentType, typename... Args >
		ComponentType* add_component(Args&&... params) {
			if (ComponentType::get_id() > -1) {
				if (sizeof...(Args) > 0) {
					components.emplace_back(std::make_unique< ComponentType >(std::forward< Args >(params)...));
					components[components.size() - 1]->set_owner(this);
					return (ComponentType*)(components[components.size() - 1].get());
				}
				else {
					components.emplace_back(std::make_unique< ComponentType >());
					components[components.size() - 1]->set_owner(this);
					return (ComponentType*)(components[components.size() - 1].get());
				}
			}
			return nullptr;
		}

		template<class ComponentType>
		ComponentType* get_component() {
			for (auto&& component : components) {
				if (component->get_id() == ComponentType::get_id())
					return static_cast<ComponentType*>(component.get());
			}
			return (nullptr);
		};

		template<class ComponentType>
		bool has_component() {
			return get_component<ComponentType>() != nullptr;
		};

		Manager* get_manager() { return manager; }
		void set_manager(Manager* p_manager) { manager = p_manager;  }
};

class Manager {
	private:
		std::vector<Entity*> entities;

		Server::ServerManager* server_manager;

	public:

		Manager(Server::ServerManager* p_server_manager);

		void tick(float deltaTime) {
			for (size_t i = 0; i < entities.size(); i++) entities[i]->tick(deltaTime);
		}
		void begin() {
			for (size_t i = 0; i < entities.size(); i++) entities[i]->begin();
		}

		void input(SDL_Event event) {
			for (size_t i = 0; i < entities.size(); i++) entities[i]->input(event);
		}

		Entity* add_entity() { Entity* e = new Entity(); e->set_manager(this); entities.push_back(e); return e; }

		RenderServer* get_render_server() { return server_manager->get_render_server(); };
		
		Server::ServerManager* get_server_manager() { return server_manager; };
};

