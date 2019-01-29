#pragma once

#include "system.h"

#include <SDL.h>
#include <SDL_image.h>

class RenderSystem : public System {
	public:
		int scale = 2;

		RenderSystem(EntityManager &entity_manager);

		static void load_sprite(SDL_Renderer *renderer, std::string path, SpriteComponent &sprite_component, int height, int width);

		void update(SDL_Renderer* renderer);
		void update_entities(SDL_Renderer* renderer);

	private:
		void update_entity(SDL_Renderer* renderer, int id);

};