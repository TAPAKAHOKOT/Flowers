#pragma once
#include <cstdlib>;

ref class Blob {
public:
	int width = rand() % 6;
	int height = rand() % 10;
	int speedX = 0;
	int speedY = 10 + rand()%3;
	int x;
	int y;
	int mY;
	bool out = false;

	Blob(int x, int y, int mY) {
		this->x = x;
		this->y = y;
		this->mY = mY;
	}

	void move() {
		x += speedX;
		y += speedY;

		if (y > mY + 5)
			out = true;
	}


};