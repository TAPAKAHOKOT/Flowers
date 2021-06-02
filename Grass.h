#pragma once
#include <cstdlib>;

ref class Grass{
	public:
		int width = rand() % 4;
		int height = rand() % 12;
		int x;
		int y;

		Grass(int x, int y) {
			this->x = x;
			this->y = y;
		}


};

