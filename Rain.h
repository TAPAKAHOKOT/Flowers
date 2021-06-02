#pragma once
#include "Blob.h";
using namespace System::Drawing;

ref class Rain
{
	public:
		int screenWidth;
		int screenHeight;
		int blobNum;
		int alpha;
		bool isRainy = false;
		bool blobsCreated = false;
		int blobsAllCounter = 0;
		array<Blob^>^ blob = gcnew array<Blob^>(200);

	Rain(int w, int h) {
		blobNum = 0;
		alpha = 0;
		screenWidth = w;
		screenHeight = h;

		createBlob(rand() % 49 + 50);
	}

	int sortOutBlob() {
		int c = 0;
		for (int i = 0; i < blobNum; i++) {
			if (i >= blobNum - 1)
				break;
			auto f = blob[i];
			if (f->out) {
				c++;
				for (int k = i + 1; k < blobNum; k++) {
					auto f1 = blob[k - 1];
					auto f2 = blob[k];

					blob[k - 1] = f2;
					blob[k] = f1;
				}
			}
		}

		return c;
	}

	void createBlob(int num) {
		for (int i = 0; i < num; i++) {
			blobsAllCounter++;
			blob[blobNum + i] = gcnew Blob(rand() % screenWidth, -rand() % 300, screenHeight - rand() % 1000);
		}

		blobNum += num;
	}


	void draw(Graphics^ g) {

		if (isRainy && alpha < 80)
			alpha+=2;
		if (!isRainy && alpha > 0)
			alpha-=2;

		Brush^ b = gcnew SolidBrush(Color::FromArgb(alpha, Color::Black));
		g->FillRectangle(b, 0, 0, screenWidth, screenHeight);

		if (isRainy) {
			bool hasOut = false;
			Brush^ nb = gcnew SolidBrush(Color::DarkSlateBlue);
			for (int i = 0; i < blobNum; i++) {
				if (blob[i]->out)
					hasOut = true;
				g->FillRectangle(nb, blob[i]->x, blob[i]->y, blob[i]->width, blob[i]->height);
				blob[i]->move();
			}

			blobNum -= sortOutBlob();

			if (blobsAllCounter < 400) {
				if (blobNum <= 200)
					createBlob(1);
			}
			else {
				isRainy = false;
				blobsAllCounter = 0;
				blobNum = 0;
			}

			
		}
	}
};

