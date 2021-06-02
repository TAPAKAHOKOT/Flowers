#pragma once

using namespace System::Drawing;


ref class Moon {
public:
	int x;
	int y;
	int screenWidth;
	int screenHeight;
	bool day = false;

	Moon(int w, int h) {
		x = -100;
		y = 200;
		screenWidth = w;
		screenHeight = h;
	}

	void dropPos() {
		x = -100;
		y = 200;
	}

	bool move() {
		if (!day) {
			x+=2;
			y-=2;

			if (y < -100)
				day = true;
			if (y < 20)
				return true;
		}
		return false;
	}

	void draw(Graphics^ g) {
		auto img = gcnew Bitmap("C:/Users/Igrok/Desktop/OP animation/moon.png");
		g->DrawImage(img, x, y, img->Width, img->Height);

		Brush^ b = gcnew SolidBrush(Color::FromArgb(200, Color::GhostWhite));
		g->FillEllipse(b, x, y, img->Width, img->Height);
	}
};

