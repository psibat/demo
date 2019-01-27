#pragma once

struct Coordinates {
	float x;
	float y;

	Coordinates();
	Coordinates(float x, float y);
	Coordinates& add(const Coordinates& other);
	Coordinates& subtract(const Coordinates& other);
	Coordinates& multiply(const Coordinates& other);
	Coordinates& divide(const Coordinates& other);

	friend Coordinates& operator+(Coordinates& v1, const Coordinates& v2);
	friend Coordinates& operator-(Coordinates& v1, const Coordinates& v2);
	friend Coordinates& operator*(Coordinates& v1, const Coordinates& v2);
	friend Coordinates& operator/(Coordinates& v1, const Coordinates& v2);

	Coordinates& operator+=(const Coordinates& other);
	Coordinates& operator-=(const Coordinates& other);
	Coordinates& operator*=(const Coordinates& other);
	Coordinates& operator/=(const Coordinates& other);

	Coordinates& operator*(const int& value);
	Coordinates& clear();
};