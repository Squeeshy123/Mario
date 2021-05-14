#include "ECS.h"
/*
template< class ComponentType >
ComponentType* Entity::get_component() {
	for (auto&& component : components) {
		if (component->get_id() == ComponentType::get_id())
			return static_cast<ComponentType*>(component.get());
	}
	return (nullptr);
}
*/
/*
template< class ComponentType >
bool Entity::has_component() {
	return get_component<ComponentType>() != nullptr;
}
*/

Manager::Manager(Server::ServerManager* p_server_manager)
{
	server_manager = p_server_manager;
}