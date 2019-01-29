#pragma once

#include "component.h"

#include <set>

#include <SDL.h>

#include "actions.h"

struct ActionComponent : public Component {
	ActionComponent() {}
	ActionComponent(float speed) : speed(speed) {}

	std::set<Action> current_actions;

	float speed;
};

