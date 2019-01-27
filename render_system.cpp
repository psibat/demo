#include "render_system.h"

#include <iostream>

#include "position_component.h"


RenderSystem::RenderSystem(EntityManager &entity_manager) : System(entity_manager) {}

void RenderSystem::update(SDL_Renderer* renderer) {
	update_entities(renderer);
}

void RenderSystem::update_entities(SDL_Renderer* renderer) {
	SDL_RenderClear(renderer);
	for (int id = 0; id < entity_manager.get_max_entities(); id++) {
		if (entity_manager.exists(id)) {
			update_entity(renderer, id);
		}
	}
	SDL_RenderPresent(renderer);
}
void RenderSystem::update_entity(SDL_Renderer* renderer, int id) {
	SpriteComponent *sprite = entity_manager.get<SpriteComponent>(id);
	PositionComponent *position = entity_manager.get<PositionComponent>(id);
	if (sprite != NULL && position != NULL) {
		sprite->src_rect.x = sprite->src_rect.w * (int) ((SDL_GetTicks() / 100) % 4);
		SDL_Rect dest_rect;
		dest_rect.x = this->scale * position->coords.x;
		dest_rect.y = this->scale * position->coords.y;
		dest_rect.h = this->scale * sprite->scale * sprite->src_rect.h;
		dest_rect.w = this->scale * sprite->scale * sprite->src_rect.w;
		SDL_RenderCopy(renderer, sprite->texture, &sprite->src_rect, &dest_rect);
		//SDL_RenderCopyEx(renderer, sprite->texture, &sprite->src_rect, &dest_rect, 0, 0, SDL_FLIP_NONE);
	}

}

void RenderSystem::load_sprite(SDL_Renderer *renderer, std::string path, SpriteComponent &sprite_component, int height, int width) {
	SDL_Surface *temp_surface = IMG_Load(path.c_str());
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, temp_surface);

	if (temp_surface == NULL) {
		std::cout << "Failed to load: " << path << std::endl;
	}

	SDL_FreeSurface(temp_surface);

	sprite_component.texture = texture;
	sprite_component.src_rect.h = height;
	sprite_component.src_rect.w = width;
	sprite_component.src_rect.x = 0;
	sprite_component.src_rect.y = 0;

	sprite_component.animations.emplace(Action::NONE, Animation(0, 4, 100));
}
