#pragma once

#include "entity_manager.h"

class System {
	public:
		System(EntityManager &entity_manager);
	protected:
		EntityManager &entity_manager;
};