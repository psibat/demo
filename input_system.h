#pragma once
#include "system.h"

#include "SDL.h"

class InputSystem : public System {
	public:
		InputSystem(EntityManager &entity_manager);

		void update(SDL_Event &event);

	private:
		void update_entities(SDL_Event &event);
		void update_entity(int id, SDL_Event &event);
};

