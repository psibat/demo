#pragma once

#include <vector>
#include <map>
#include <typeinfo>

#include "collision_component.h"
#include "sprite_component.h"
#include "position_component.h"
#include "physics_component.h"
#include "action_component.h"


class EntityManager {
	public:
		EntityManager(int max_entities);

		// Misc
		int get_max_entities();

		// Entity
		int create();
		void destroy(int id);
		bool exists(int id);

		// Components
		void add(int id, Component *component);
		Component *get(int id, const std::type_info *type);
		void remove(int id, const std::type_info *type);

		template <typename T> T
			*get(int id) {
				return dynamic_cast<T*>(get(id, &typeid(T)));
			}

		template <typename T>
			void remove(int id) {
				remove(id, &typeid(T));
			}

	private:
		int const max_entities;

		// Components / flags
		std::vector<bool> existence;

		typedef std::vector<Component *> ComponentVector;

		std::map<const std::type_info*, ComponentVector> components {
			{&typeid(CollisionComponent), ComponentVector(max_entities)},
			{&typeid(SpriteComponent), ComponentVector(max_entities)},
			{&typeid(PositionComponent), ComponentVector(max_entities)},
			{&typeid(PhysicsComponent), ComponentVector(max_entities)},
			{&typeid(ActionComponent), ComponentVector(max_entities)}

		};

};