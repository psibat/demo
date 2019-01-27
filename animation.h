#pragma once

struct Animation {
	int row;
	int total_frames;
	int speed;

	double accumulated = 0;

	Animation() {};
	Animation(int row, int total_frames, int speed) {
		this->row = row;
		this->total_frames = total_frames;
		this->speed = speed;
	}
};