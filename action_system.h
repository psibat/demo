#pragma once

#include "basic_system.h"

class ActionSystem : public BasicSystem {
	public:
		ActionSystem(EntityManager &entity_manager);

		void update();

	private:
		void update_entity(int id);

};