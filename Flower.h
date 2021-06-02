#pragma once

using namespace System::Drawing;

ref class Flower{
	public:
		int timeCounter,
			fullAge,
			age,
			ageAdding,
			x,
			y,
			growLim;
		bool
			isDay = false,
			growth = true,
			bloom = false,
			aging = false,
			dead = false;
	public:
		property int TimeCounter {
			void set(int val) { timeCounter = val; }
			int get() { return timeCounter; }
		}

		property int Age {
			void set(int val) { age = val; }
			int get() { return age; }
		}

		property int AgeAdding {
			void set(int val) { ageAdding = val; }
			int get() { return ageAdding; }
		}

		property int FullAge {
			void set(int val) { fullAge = val; }
			int get() { return fullAge; }
		}
		
		property int X {
			void set(int val) { x = val; }
		}

		property int Y {
			void set(int val) { y = val; }
		}

		property bool Dead {
			bool get() { return dead; }
		}

		property bool IsDay {
			bool get() { return isDay; }
			void set(bool val) { isDay = val; }
		}
		Flower() {
			growLim = 10;
			timeCounter = 0;
			fullAge = 0;
			age = 0;
			ageAdding = 1;
			this->x = 0;
			this->y = 0;
		}

		Flower(int x, int y) : Flower() {
			this->x = x;
			this->y = y;
		}

		void isRain(bool status) {	
			AgeAdding = status ? 2 : 1;
		}

		virtual bool growUp() {
			fullAge += AgeAdding;
			age += AgeAdding;

			if (growLim * 17 <= fullAge) {
				growth = false;
				bloom = true;
			}

			if (growLim * (17 + 6 * 5) <= fullAge) {
				bloom = false;
				aging = true;
			}

			if (growLim * (17 + 6 * 5 + 9) <= fullAge) {
				aging = false;
				dead = true;
			}

			if (age >= growLim) {
				age = 0;
				return true;
			}
			return false;
		}
		virtual System::String^ getNextFlower() {
			bool gr = growUp();

			if (bloom) {
				if (timeCounter >= 22)
					timeCounter = 17;
			}

			if (timeCounter >= 31)
				dead = true;
			
			if (!dead)
				if (gr)
					return "C:/users/Igrok/Desktop/OP animation/leaf/leafs320/leaf" + (timeCounter++).ToString() + ".png";
				else
					return "C:/users/Igrok/Desktop/OP animation/leaf/leafs320/leaf" + (timeCounter).ToString() + ".png";
			else
				return "";
		}

		virtual System::String^ getCurFlower() {
			return "C:/users/Igrok/Desktop/OP animation/leaf/leafs320/leaf" + (timeCounter).ToString() + ".png";
		}

		void draw(Graphics^ g) {
			auto way = this->getCurFlower();
			if (IsDay)
				auto way = this->getNextFlower();

			if (way != "") {
				auto img = gcnew Bitmap(way);
				g->DrawImage(img, x, y, img->Width, img->Height);
			}
		}

		int getCounter() { return timeCounter; }
		int getX() { return this->x; }
		int getY() { return this->y; }
};

