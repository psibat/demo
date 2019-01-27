#pragma once

#include "system.h"

class CollisionSystem : public System {
	public:
		CollisionSystem(EntityManager &entity_manager);

		void update();

	private:

		void update_entity(int id);

};