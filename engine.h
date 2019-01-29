#pragma once

#include "entity_manager.h"
#include "collision_system.h"
#include "render_system.h"
#include "input_system.h"
#include "action_system.h"
#include "physics_system.h"

class Engine {
	public:
		Engine();
		~Engine();

		void start();
		void stop();
	private:
		SDL_Window *window;
		SDL_Renderer *renderer;
		SDL_Event event;

		bool is_running = true;

		EntityManager entity_manager;

		// Systems
		CollisionSystem collision_system;
		RenderSystem render_system;
		InputSystem input_system;
		ActionSystem action_system;
		PhysicsSystem physics_system;

		void gameplay();

		void input();
		void process();
		void draw();

};