#include "collision_system.h"

CollisionSystem::CollisionSystem(EntityManager &entity_manager) : System(entity_manager) {}

void CollisionSystem::update() {
	for (int id = 0; id < entity_manager.get_max_entities(); id++) {
		if (entity_manager.exists(id)) {
			update_entity(id);
		}
	}
}

void CollisionSystem::update_entity(int id) {
	CollisionComponent *collision = entity_manager.get<CollisionComponent>(id);
	if (collision != NULL) {

	}
}
