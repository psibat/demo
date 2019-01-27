#pragma once

#include "component.h"

#include <string>
#include <map>
#include "SDL.h"

#include "animation.h"
#include "actions.h"

struct SpriteComponent : public Component {
	enum RenderPriority {
		NONE,
		BACKGROUND,
		UNDER_PLAYER,
		PLAYER,
		ABOVE_PLAYER
	};
	SDL_Texture *texture;
	SDL_Rect src_rect;

	int scale = 1;
	RenderPriority priority;
	std::map<Action, Animation> animations;
	int current_frame = 0;
	std::string path_to_file;


	SpriteComponent() {}

};

