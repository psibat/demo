#include "basic_system.h"

BasicSystem::BasicSystem(EntityManager &entity_manager) : System(entity_manager) { }

void BasicSystem::update_entities() {
	for (int id = 0; id < entity_manager.get_max_entities(); id++) {
		if (entity_manager.exists(id)) {
			update_entity(id);
		}
	}
}
