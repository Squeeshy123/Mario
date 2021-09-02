#pragma once
#include <vector>
#include "MMath.h"
#include "Player.h"

class World
{
	public:
		std::vector<Rect*> collision_rects;
		Player* player;

		World() = default;
		~World() = default;

		void begin();
		void tick(float dT);
		void add_collision_rect(Rect r);
};
