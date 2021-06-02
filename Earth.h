#pragma once
#include "Grass.h";
using namespace System::Drawing;


ref class Earth{
public:
	int screenWidth;
	int screenHeight;
	int grassNum;
	array<Grass^>^ grass;

	Earth(int w, int h) {
		screenWidth = w;
		screenHeight = h;

		grassNum = 100;
		grass = gcnew array<Grass^>(grassNum);

		for (int i = 0; i < grassNum; i++) {
			grass[i] = gcnew Grass(rand()%screenWidth, screenHeight/2 + rand()%(screenHeight/2) );
		}
	}

	void draw(Graphics^ g) {
		Brush^ b = gcnew SolidBrush(Color::LightGreen);
		g->FillRectangle(b, 0, screenHeight / 2, screenWidth, screenHeight / 2);

		Brush^ nb = gcnew SolidBrush(Color::Green);
		for (int i = 0; i < grassNum; i++) {
			g->FillRectangle(nb, grass[i]->x, grass[i]->y, grass[i]->width, grass[i]->height);
		}
	}
};

