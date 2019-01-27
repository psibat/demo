#include "coordinates.h"

Coordinates::Coordinates() : x(0), y(0) {}

Coordinates::Coordinates(float x, float y) : x(x), y(y) { }

Coordinates &Coordinates::add(const Coordinates &other) {
	this->x += other.x;
	this->y += other.y;

	return *this;
}

Coordinates &Coordinates::subtract(const Coordinates &other) {
	this->x -= other.x;
	this->y -= other.y;

	return *this;
}

Coordinates &Coordinates::multiply(const Coordinates &other) {
	this->x *= other.x;
	this->y *= other.y;

	return *this;
}

Coordinates &Coordinates::divide(const Coordinates &other) {
	this->x /= other.x;
	this->y /= other.y;

	return *this;
}

Coordinates &operator+(Coordinates &first, const Coordinates &second) {
	return first.add(second);
}

Coordinates &operator-(Coordinates &first, const Coordinates &second) {
	return first.subtract(second);
}

Coordinates &operator*(Coordinates &first, const Coordinates &second) {
	return first.multiply(second);
}

Coordinates &operator/(Coordinates &first, const Coordinates &second) {
	return first.divide(second);
}

Coordinates &Coordinates::operator+=(const Coordinates &other) {
	return this->add(other);
}

Coordinates &Coordinates::operator-=(const Coordinates &other) {
	return this->subtract(other);
}

Coordinates &Coordinates::operator*=(const Coordinates &other) {
	return this->multiply(other);
}

Coordinates &Coordinates::operator/=(const Coordinates &other) {
	return this->divide(other);
}

Coordinates &Coordinates::operator*(const int &value) {
	this->x *= value;
	this->y *= value;

	return *this;
}

Coordinates &Coordinates::clear() {
	this->x *= 0;
	this->y *= 0;

	return *this;
}