#pragma once

#include "system.h"

class ActionSystem : public System {
	public:
		ActionSystem(EntityManager &entity_manager);

		void update();

	private:

		void update_entity(int id);

};