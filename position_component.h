#pragma once

#include "component.h"

#include "coordinates.h"


struct PositionComponent : public Component {
	Coordinates coords = Coordinates(0,0);

	PositionComponent() {}
	PositionComponent(float x, float y) : coords(x, y) {}
};

