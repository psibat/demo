#pragma once

#include "system.h"

class BasicSystem : public System {
	public:
		BasicSystem(EntityManager &entity_manager);

		virtual void update() = 0;

	protected:
		void update_entities();

	private:
		virtual void update_entity(int id) = 0;
};