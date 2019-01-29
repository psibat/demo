#include "engine.h"

#include <iostream>

#include <SDL.h>

const int FPS_LIMIT = 60;
const int FRAME_DELAY = 1000 / FPS_LIMIT;
const int UPDATE_RATE = 60;
const int UPDATE_DELAY = 1000 / UPDATE_RATE;
const int NATIVE_WIDTH = 768;
const int NATIVE_HEIGHT = 432;


Engine::Engine() : entity_manager(200), 
collision_system(entity_manager), render_system(entity_manager), input_system(entity_manager), action_system(entity_manager), physics_system(entity_manager) {}

Engine::~Engine() {
	stop();
}

void Engine::start() {
	int height, width;

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, NATIVE_WIDTH, NATIVE_HEIGHT, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	int player = entity_manager.create();
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
	Uint64 current_counter = 0;
	Uint64 previous_counter = SDL_GetPerformanceCounter();

	double delta_time_ms = 0;
	double accumulated_ms = 0;

	while (is_running) {
		// Usual delta time calc
		current_counter = SDL_GetPerformanceCounter();
		delta_time_ms = (double)((current_counter - previous_counter) * 1000 / SDL_GetPerformanceFrequency());
		previous_counter = current_counter;
		accumulated_ms += delta_time_ms;

		// FPS Counter
		std::cout << "FPS: " << (delta_time_ms > 0 ? 1000 / delta_time_ms : 0) << std::endl;

		// Check input / if game should quit
		input();

		// Make sure game process only occurs at UPDATE_RATE
		while (accumulated_ms >= UPDATE_DELAY) {
			process();
			accumulated_ms -= UPDATE_DELAY;
		}

		// Render
		draw();

		// If FPS limit assigned add a delay
		if (FPS_LIMIT) {
			delta_time_ms = (double)((SDL_GetPerformanceCounter() - current_counter) * 1000 / SDL_GetPerformanceFrequency());
			if (FRAME_DELAY > delta_time_ms) {
				SDL_Delay(FRAME_DELAY - delta_time_ms);
			}
		}
	}
}

void Engine::input() {
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		is_running = false;
		break;
	default:
		break;
	}
	input_system.update(event);
}

void Engine::process() {
	action_system.update();
	physics_system.update();
}

void Engine::draw() {
	render_system.update(renderer);
}
