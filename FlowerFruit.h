#pragma once
#include "Flower.h";
#include <cstdlib>;

ref class FlowerFruit : public Flower{
	public:
		FlowerFruit(int x, int y) : Flower(x, y) {}

		virtual bool growUp() override {
			fullAge += AgeAdding;
			age += AgeAdding;

			if (growLim * 17 <= fullAge) {
				growth = false;
				bloom = true;
			}

			if (growLim * (17 + 6 * 7) <= fullAge) {
				bloom = false;
				aging = true;
			}

			if (growLim * (17 + 6 * 7 + 11) <= fullAge) {
				aging = false;
			}

			if (growLim * (17 + 6 * 7 + 11 + 20) <= fullAge) {
				growth = true;
				fullAge = 0;
				age = 0;

				if (rand() % 10 == 1)
					this->dead = true;
			}

			if (age >= growLim) {
				age = 0;
				return true;
			}
			return false;
		}

		virtual System::String^ getNextFlower() override {
			bool gr = growUp();

			if (bloom) {
				if (timeCounter >= 22)
					timeCounter = 17;
			}
			if (timeCounter > 32)
				timeCounter = 33;
			if (timeCounter >= 33 && growth)
				timeCounter = 0;

			if (gr)
				return "C:/users/Igrok/Desktop/OP animation/leaf/leafsFruit320/leafFruits" + (timeCounter++).ToString() + ".png";
			else
				return "C:/users/Igrok/Desktop/OP animation/leaf/leafsFruit320/leafFruits" + (timeCounter).ToString() + ".png";
		}

		virtual System::String^ getCurFlower() override {
			if (timeCounter > 32)
				timeCounter = 33;
			return "C:/users/Igrok/Desktop/OP animation/leaf/leafsFruit320/leafFruits" + (timeCounter).ToString() + ".png";
		}
};

