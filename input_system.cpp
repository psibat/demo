#include "input_system.h"

#include "action_component.h"
#include "physics_component.h"

#include "actions.h"

#include <map>

std::map<SDL_Keycode, Action> action_map = { 
	{SDLK_w, MOVE_UP},
	{SDLK_a, MOVE_LEFT},
	{SDLK_s, MOVE_DOWN},
	{SDLK_d, MOVE_RIGHT}
};

InputSystem::InputSystem(EntityManager &entity_manager) : System(entity_manager) {}

void InputSystem::update(SDL_Event &event) {
	update_entities(event);
}

void InputSystem::update_entities(SDL_Event &event) {
	for (int id = 0; id < entity_manager.get_max_entities(); id++) {
		if (entity_manager.exists(id)) {
			update_entity(id, event);
		}
	}
}

void InputSystem::update_entity(int id, SDL_Event &event) {
	ActionComponent *action = entity_manager.get<ActionComponent>(id);
	PhysicsComponent *physics = entity_manager.get<PhysicsComponent>(id);
	if (action != NULL && physics != NULL) {
		if (event.type == SDL_KEYDOWN) {
			action->current_actions.insert(action_map[event.key.keysym.sym]);
		} else if (event.type == SDL_KEYUP) {
			action->current_actions.erase(action_map[event.key.keysym.sym]);
		}
	}
}
