#pragma once
using namespace System::Drawing;
#include <cstdlib>;
#include "Cloud.h";

ref class Sky{
public:
	array<Cloud^>^ clouds;
	int cloudsNum;
	int screenWidth;
	int screenHeight;
	int maxCloudsNum = 20;

	Sky(int w, int h) {
		cloudsNum = 0;
		clouds = gcnew array<Cloud^>(maxCloudsNum);
		screenWidth = w;
		screenHeight = h;

		for (int i = 0; i < 10; i++)
			clouds[cloudsNum++] = gcnew Cloud(screenWidth, screenHeight, rand()%w);
	}

	int sortOutClouds() {
		int c = 0;
		for (int i = 0; i < cloudsNum; i++) {
			if (i >= cloudsNum - 1)
				break;
			auto f = clouds[i];
			if (f->out) {
				c++;
				for (int k = i + 1; k < cloudsNum; k++) {
					auto f1 = clouds[k - 1];
					auto f2 = clouds[k];

					clouds[k - 1] = f2;
					clouds[k] = f1;
				}
			}
		}

		return c;
	}

	void draw(Graphics^ g) {
		Brush^ b = gcnew SolidBrush(Color::DeepSkyBlue);
		g->FillRectangle(b, 0, 0, screenWidth, screenHeight / 2);

		if (rand() % 50 == 1 && cloudsNum < maxCloudsNum) {
			clouds[cloudsNum++] = gcnew Cloud(screenWidth, screenHeight, screenWidth + 100);
		}

		bool hasOut = false;
		for (int i = 0; i < cloudsNum; i++) {
			auto c = clouds[i];
			c->move();
			c->draw(g);
			if (c->out)
				hasOut = true;
		}

		if (hasOut) {
			cloudsNum -= sortOutClouds();
		}

		
	}
};

