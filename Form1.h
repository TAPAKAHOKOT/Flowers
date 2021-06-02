#pragma once
#include "Flower.h";
#include "Earth.h";
#include "Sky.h";
#include "Sun.h";
#include "Moon.h";
#include "Rain.h";
#include "FlowerFruit.h";
#include <cstdlib>;
#include <ctime>;

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			this->DoubleBuffered = true;
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}
	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ mainTimer;
	protected:

	protected:
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Label^ lblSpeed;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;


	protected:
		property System::Windows::Forms::CreateParams^ CreateParams {
			virtual System::Windows::Forms::CreateParams^ get() override {
				System::Windows::Forms::CreateParams^ cp = __super::CreateParams;
				cp->Style |= 0x40000;
				return cp;
			}
		}

	private:
		array<System::Windows::Forms::PictureBox^>^ flowersPicturesArr;
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->mainTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->lblSpeed = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// mainTimer
			// 
			this->mainTimer->Tick += gcnew System::EventHandler(this, &Form1::mainTimer_Tick);
			// 
			// trackBar1
			// 
			this->trackBar1->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->trackBar1->Location = System::Drawing::Point(597, 46);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(258, 45);
			this->trackBar1->TabIndex = 0;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &Form1::trackBar1_Scroll);
			// 
			// lblSpeed
			// 
			this->lblSpeed->AutoSize = true;
			this->lblSpeed->BackColor = System::Drawing::Color::Transparent;
			this->lblSpeed->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F));
			this->lblSpeed->Location = System::Drawing::Point(604, 9);
			this->lblSpeed->Name = L"lblSpeed";
			this->lblSpeed->Size = System::Drawing::Size(241, 20);
			this->lblSpeed->TabIndex = 1;
			this->lblSpeed->Text = L"Ñêîðîñòü òå÷åíèÿ âðåìåíè";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(594, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(45, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Áûñòðî";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(797, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Ìåäëåííî";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Location = System::Drawing::Point(680, 97);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(112, 35);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Âûçâàòü äîæäü";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(867, 723);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblSpeed);
			this->Controls->Add(this->trackBar1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Flowers";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::OnPaint);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}


		int size = 100;
		int radius = 10;
		int timeCounter = 0;

		int flowersAdded = 0;
		int flowersFruitAdded = 0;
		int maxFlowersFruitNum = 5;
		int maxFlowersNum = 30 + maxFlowersFruitNum;

		array<Flower^>^ flowersArr;
		array<FlowerFruit^>^ flowerFruitArr;
		Graphics^ g;
		Earth^ earth;
		Sky^ sky;
		Sun^ sun;
		Moon^ moon;
		Rain^ rain;

		private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
			srand(static_cast<unsigned int>(time(0)));

			earth = gcnew Earth(this->Width, this->Height);
			sky = gcnew Sky(this->Width, this->Height);
			sun = gcnew Sun(this->Width, this->Height);
			moon = gcnew Moon(this->Width, this->Height);
			rain = gcnew Rain(this->Width, this->Height);

			g = this->CreateGraphics();
			g->Clear(Color::White);

			mainTimer->Interval = 1;
			mainTimer->Start();

			flowersArr = gcnew array<Flower^>(maxFlowersNum);
			flowerFruitArr = gcnew array<FlowerFruit^>(maxFlowersFruitNum);
			flowersPicturesArr = gcnew array<System::Windows::Forms::PictureBox^>(maxFlowersNum);

			//addFlower(300, 400); // -150 => 700; -300 => 400 <=> 850; 700
		}

		private: bool addFlower(int x, int y) {
			if (maxFlowersNum <= flowersAdded)
				return false;

			flowersArr[flowersAdded] = gcnew Flower(x, y);

			flowersAdded++;
			return true;
		}

		private: bool addFlowerFruit(int x, int y) {
			if (maxFlowersNum <= flowersAdded)
				return false;

			flowersArr[flowersAdded] = gcnew FlowerFruit(x, y);

			flowersAdded++;
			flowersFruitAdded++;
			return true;
		}
		
		bool changed = true;
		private: System::Void mainTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
			Invalidate();
		}


	private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
		int val = (trackBar1->Value + 1);

		mainTimer->Interval = val * val * val;
	}

	private: void sortFlowers() {
		for (int i = 0; i < flowersAdded; i++) {
			for (int k = 0; k < i; k++) {
				auto f1 = flowersArr[i];
				auto f2 = flowersArr[k];

				if (f1->getY() < f2->getY()) {
					flowersArr[i] = f2;
					flowersArr[k] = f1;
				}
			}
		}
	}

	private: void sortFlowersFruit() {
		for (int i = 0; i < flowersAdded; i++) {
			for (int k = 0; k < i; k++) {
				auto f1 = flowerFruitArr [i] ;
				auto f2 = flowerFruitArr[k];

				if (f1->getY() < f2->getY()) {
					flowerFruitArr[i] = f2;
					flowerFruitArr[k] = f1;
				}
			}
		}
	}

	private: int sortDeadFlowers() {
		int c = 0;
		for (int i = 0; i < flowersAdded; i++) {
			if (i >= flowersAdded - 1)
				break;
			auto f = flowersArr[i];
			if (f->Dead) {
				c++;
				for (int k = i+1; k < flowersAdded; k++) {
					auto f1 = flowersArr[k-1];
					auto f2 = flowersArr[k];

					flowersArr[k-1] = f2;
					flowersArr[k] = f1;
				}
			}
		}

		return c;
	}

		   
	int alpha = 0;
	private: System::Void OnPaint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		bool deadFound = false;

		Graphics^ g = e->Graphics;

		sky->draw(g);
		earth->draw(g);

		bool isDay = false;
		bool isEvening = false;

		bool growOn = true;

		if (!sun->night) {
			growOn = true;
			isDay = false;
			isEvening = sun->move();
			sun->draw(g);
			moon->dropPos();

			if (isEvening) {
				growOn = false;
				if (alpha < 150)
					alpha += 2;
			}
			
			if (sun->night)
				moon->day = false;
		}
		else {
			growOn = false;
			isEvening = false;
			isDay = moon->move();
			moon->draw(g);
			sun->dropPos();

			if (isDay) {
				growOn = true;
				if (alpha > 0)
					alpha -= 4;
			}
				
			if (moon->day)
				sun->night = false;
		}

		if (alpha > 150)
			alpha = 150;
		if (alpha < 0)
			alpha = 0;

		if (maxFlowersNum >= flowersAdded) {
			if (rand() % 10 == 1) {
				if (addFlower(rand() % (850) - 150, rand() % (300) + 100))
					sortFlowers();
			}
			if (rand() % 60 == 1 && maxFlowersFruitNum > flowersFruitAdded) {
				if (addFlowerFruit(rand() % (850) - 150, rand() % (300) + 100))
					sortFlowers();
			}
		}

		for (int i = 0; i < flowersAdded; i++) {
			auto f = flowersArr[i];
			if (!f->Dead) {
				f->IsDay = growOn;
				f->isRain(rain->isRainy);
				f->draw(g);
			}
			else
				deadFound = true;
		}

		if (deadFound) {
			deadFound = false;
			int deadNum = sortDeadFlowers();
			flowersAdded -= deadNum;
		}

		if (rand() % 1000 == 123)
			rain->isRainy = true;
		rain->draw(g);
		
		Brush^ b = gcnew SolidBrush(Color::FromArgb(alpha, Color::DarkBlue));
		g->FillRectangle(b, 0, 0, this->Width, this->Height);
	}


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		rain->isRainy = true;
	}
};

}
