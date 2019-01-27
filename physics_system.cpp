#include "physics_system.h"

#include <iostream>
#include <cmath>

#include "physics_component.h"
#include "position_component.h"

PhysicsSystem::PhysicsSystem(EntityManager &entity_manager) : BasicSystem(entity_manager) {}

void PhysicsSystem::update() {
	for (int id = 0; id < entity_manager.get_max_entities(); id++) {
		if (entity_manager.exists(id)) {
			update_entity(id);
		}
	}
}


void PhysicsSystem::update_entity(int id) {
	PhysicsComponent *physics = entity_manager.get<PhysicsComponent>(id);
	ActionComponent *action = entity_manager.get<ActionComponent>(id);
	PositionComponent *position = entity_manager.get<PositionComponent>(id);
	if (physics != NULL && position != NULL && action != NULL) {
		physics->velocity = physics->velocity * action->speed;
		position->coords += physics->velocity;
	}
}
