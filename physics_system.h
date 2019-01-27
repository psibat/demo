#pragma once

#include "basic_system.h"

class PhysicsSystem : public BasicSystem {
	public:
		PhysicsSystem(EntityManager &entity_manager);

		void update();

	private:
		void update_entity(int id);
};