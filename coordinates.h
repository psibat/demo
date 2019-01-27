#pragma once

#include <iostream>

struct Coordinates {
	float x;
	float y;

	Coordinates();
	Coordinates(float x, float y);
	Coordinates &add(const Coordinates &other);
	Coordinates &subtract(const Coordinates &other);
	Coordinates &multiply(const Coordinates &other);
	Coordinates &divide(const Coordinates &other);

	friend Coordinates &operator+(Coordinates &first, const Coordinates &second);
	friend Coordinates &operator-(Coordinates &first, const Coordinates &second);
	friend Coordinates &operator*(Coordinates &first, const Coordinates &second);
	friend Coordinates &operator/(Coordinates &first, const Coordinates &second);

	Coordinates &operator+=(const Coordinates &other);
	Coordinates &operator-=(const Coordinates &other);
	Coordinates &operator*=(const Coordinates &other);
	Coordinates &operator/=(const Coordinates &other);

	Coordinates &operator*(const float& value);

	friend std::ostream& operator<<(std::ostream &out, const Coordinates &coords);


	Coordinates &clear();
};