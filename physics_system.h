#pragma once

#include "system.h"

class PhysicsSystem : public System {
	public:
		PhysicsSystem(EntityManager &entity_manager);

		void update();


	private:

		void update_entity(int id);
};