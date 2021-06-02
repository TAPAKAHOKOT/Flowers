#pragma once
using namespace System::Drawing;
#include <cstdlib>;


ref class Cloud {
	public:
		int cloudId;
		int x;
		int y;
		int screenWidth;
		int screenHeight;
		bool out = false;

		Cloud(int w, int h, int x) {
			cloudId = rand() % 4;
			this->x = x;
			y = rand()%(h * 2 / 5);
			screenWidth = w;
			screenHeight = h;
		}

		void move() {
			x--;

			if (rand() % 4 == 1)
				y += rand() % 5 - 3;

			if (x < -100)
				out = true;
			if (y < -50)
				out = true;
		}

		void draw(Graphics^ g) {
			auto img = gcnew Bitmap("D:/Projects/Flowers/OP animation/Clouds/cloud" + cloudId.ToString() + ".png");
			g->DrawImage(img, x, y, img->Width, img->Height);
		}
};

