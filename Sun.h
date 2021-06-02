#pragma once

using namespace System::Drawing;


ref class Sun{
	public:
		int x;
		int y;
		int s;
		int screenWidth;
		int screenHeight;
		bool night = false;

	Sun(int w, int h) {
		s = 0;
		x = -200;
		y = 300;
		screenWidth = w;
		screenHeight = h;
	}

	void dropPos() {
		x = -200;
		y = 300;
	}

	bool move() {
		if (!night) {
			if (s++ % 1 == 0) {
				x++;
				y--;
			}

			if (y < -60)
				night = true;
			if (y < 20)
				return true;
		}
		return false;
	}

	void draw(Graphics^ g) {
		auto img = gcnew Bitmap("C:/Users/Igrok/Desktop/OP animation/sun.png");
		g->DrawImage(img, x, y, img->Width, img->Height);
	}
};

