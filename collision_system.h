#pragma once

#include "basic_system.h"

class CollisionSystem : public BasicSystem {
	public:
		CollisionSystem(EntityManager &entity_manager);

		void update();

	private:
		void update_entity(int id);

};