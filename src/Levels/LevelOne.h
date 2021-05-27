#include "ECS.h"
#include "Components.hpp"
#include "Scripts/Player.h"

using namespace Server;
class LevelOne : public Manager {
	public:
		LevelOne(ServerManager* p_server_manager)
            : Manager(p_server_manager) {
        }
        

        void load();
        void begin();
        void tick(float deltaTime);
};