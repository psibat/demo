#pragma once

#include "component.h"

#include "coordinates.h"

struct PhysicsComponent : public Component {
	PhysicsComponent() {}

	Coordinates velocity;	
};

