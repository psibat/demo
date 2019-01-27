#include "system.h"

System::System(EntityManager &entity_manager) : entity_manager(entity_manager) { }

void System::update_entities() {
	for (int id = 0; id < entity_manager.get_max_entities(); id++) {
		if (entity_manager.exists(id)) {
			update_entity(id);
		}
	}
}
