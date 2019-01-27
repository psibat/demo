#pragma once

#include "entity_manager.h"

class System {
	public:
		System(EntityManager &entity_manager);

		void update() {
			throw std::runtime_error("Unimplemented update() method");
		}

	protected:
		void update_entities();

		EntityManager &entity_manager;
	private:
		void update_entity(int id) {
			throw std::runtime_error("Unimplemented update_entity() method");
		}
};