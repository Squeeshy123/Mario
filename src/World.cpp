#include "World.h"
#include "Player.h"

void World::begin()
{
}

void World::tick(float dT)
{
}

void World::add_collision_rect(Rect r)
{
	collision_rects.push_back(&r);
}
