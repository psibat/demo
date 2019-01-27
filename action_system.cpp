#include "action_system.h"

#include <iostream>

#include "action_component.h"
#include "physics_component.h"

ActionSystem::ActionSystem(EntityManager &entity_manager) : System(entity_manager) {}

void ActionSystem::update() {
	for (int id = 0; id < entity_manager.get_max_entities(); id++) {
		if (entity_manager.exists(id)) {
			update_entity(id);
		}
	}
}

void ActionSystem::update_entity(int id) {
	ActionComponent *action = entity_manager.get<ActionComponent>(id);
	if (action != NULL) {

	}

	
}
