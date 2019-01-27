#include "engine.h"

#include <iostream>

#include "SDL.h"

Engine::Engine() : entity_manager(200), 
collision_system(entity_manager), render_system(entity_manager), input_system(entity_manager), action_system(entity_manager), physics_system(entity_manager) {}

Engine::~Engine() {
	stop();
}

void Engine::start() {
	int height, width;

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 768, 432, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	int player = entity_manager.create();
	entity_manager.player = player;
	entity_manager.center = player;
	entity_manager.add(player, new CollisionComponent());
	entity_manager.add(player, new SpriteComponent());
	entity_manager.add(player, new PositionComponent(0, 0));
	entity_manager.add(player, new PhysicsComponent());
	entity_manager.add(player, new ActionComponent(2));
	SpriteComponent *player_sprite = entity_manager.get<SpriteComponent>(player);
	player_sprite->priority = SpriteComponent::PLAYER;
	RenderSystem::load_sprite(renderer, "resources/player.png", *player_sprite, 16, 16);

	int other = entity_manager.create();
	entity_manager.add(other, new CollisionComponent());

	gameplay();

	stop();

}

void Engine::stop() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Engine::gameplay() {
	bool is_running = true;

	const int FPS = 60;
	const int FRAME_DELAY = 1000 / FPS;

	Uint32 frame_start;
	int frame_time;

	while (is_running) {
		frame_start = SDL_GetTicks();

		SDL_PollEvent(&event);
		switch (event.type) {
		case SDL_QUIT:
			is_running = false;
			break;
		default:
			break;
		}

		draw();
		process();
		
		frame_time = SDL_GetTicks() - frame_start;

		if (FRAME_DELAY > frame_time) {
			SDL_Delay(FRAME_DELAY - frame_time);
		}
	}
}

void Engine::process() {
	input_system.update(event);
	//action_system.update();
	physics_system.update();
}

void Engine::draw() {
	render_system.update(renderer);
}
