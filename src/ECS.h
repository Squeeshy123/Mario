#pragma once

#include <vector>

#include <SDL/SDL.h>

#include "RenderServer.h"

#include <memory>
#include "ServerManager.h"

#define COMPONENT_INIT(ID, classname) public: static const int id = ID;	static int get_id() { return classname::id;} int iid = ID; int get_iid(){return iid;} classname() = default;

#define COMPONENT_INIT_NC(ID, classname) public: static const int id = ID;	static int get_id() { return classname::id;} int iid = ID; int get_iid(){return iid;}

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

		inline bool operator==(Component& r){
			if(this->get_iid() == r.get_iid())
				return true;
			return false;
		}
		
};



class Entity {
	private:
		Manager* manager = nullptr;

		std::vector<Component*> components;

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
				printf("id: %i,  Size of args: %i\n", ComponentType::get_id(), sizeof...(Args));
				if (sizeof...(Args) > 0) {
					ComponentType* c = new ComponentType(std::forward< Args >(params)...);
					components.emplace_back(c);
					c->set_owner(this);
					return c;
				}
				else {
					ComponentType* c = new ComponentType();
					components.emplace_back(c);
					c->set_owner(this);
					return c;
				}
			}
			
			return nullptr;
		}

		template <typename CompType>
		inline CompType* get_component()
		{
			for(Component* comp : components)
			{
				if (dynamic_cast<CompType*>(comp)!= nullptr)
				{
					return dynamic_cast<CompType*>(comp);
				}
			}
			return nullptr;
		}

		template<class ComponentType>
		bool has_component() {
			return get_component<ComponentType>() != nullptr;
		};

		Manager* get_manager() { return manager; }
		void set_manager(Manager* p_manager) { manager = p_manager;  }

		Entity();
		~Entity(){
			components.clear();
		}
};

class Manager {
	protected:
		std::vector<Entity*> entities;

		Server::ServerManager* server_manager;

	public:

		Manager(Server::ServerManager* p_server_manager);
		~Manager(){
			entities.clear();
		}

		virtual void tick(float deltaTime) {
			for (size_t i = 0; i < entities.size(); i++) entities[i]->tick(deltaTime);
		}
		virtual void begin() {
			for (size_t i = 0; i < entities.size(); i++) entities[i]->begin();
		}

		virtual void input(SDL_Event event) {
			for (size_t i = 0; i < entities.size(); i++) entities[i]->input(event);
		}

		Entity* add_entity() { Entity* e = new Entity(); e->set_manager(this); entities.push_back(e); return e; }

		RenderServer* get_render_server() { return server_manager->get_render_server(); };
		
		Server::ServerManager* get_server_manager() { return server_manager; };
};

