#include "action_system.h"

#include <iostream>

#include "action_component.h"
#include "physics_component.h"

ActionSystem::ActionSystem(EntityManager &entity_manager) : BasicSystem(entity_manager) {}

void ActionSystem::update() {
	for (int id = 0; id < entity_manager.get_max_entities(); id++) {
		if (entity_manager.exists(id)) {
			update_entity(id);
		}
	}
}

void ActionSystem::update_entity(int id) {
	ActionComponent *action = entity_manager.get<ActionComponent>(id);
	PhysicsComponent *physics = entity_manager.get<PhysicsComponent>(id);
	if (action != NULL && physics != NULL) {
		physics->velocity.clear();
		if (!action->current_actions.empty()) {
			switch (*(action->current_actions.begin())) {
			case MOVE_UP:
				physics->velocity.y = -1;
				break;
			case MOVE_DOWN:
				physics->velocity.y = 1;
				break;
			case MOVE_LEFT:
				physics->velocity.x = -1;
				break;
			case MOVE_RIGHT:
				physics->velocity.x = 1;
				break;
			}
		}
	}

	
}
