#pragma once

#include "world.h"

world Ukraine;

namespace test_model01 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::CheckedListBox^  parameters;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->parameters = (gcnew System::Windows::Forms::CheckedListBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(564, 202);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 156);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Draw";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// parameters
			// 
			this->parameters->FormattingEnabled = true;
			this->parameters->Items->AddRange(gcnew cli::array< System::Object^  >(12) {L"price", L"salary", L"plan", L"workers", L"labor_capacity", 
				L"capital_capacity", L"raw_capacity", L"capital_investments", L"raw_investments", L"sales", L"sold", L"profit"});
			this->parameters->Location = System::Drawing::Point(564, 12);
			this->parameters->Name = L"parameters";
			this->parameters->Size = System::Drawing::Size(120, 184);
			this->parameters->TabIndex = 1;
			this->parameters->TabStop = false;
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(12, 12);
			this->chart1->Name = L"chart1";
			this->chart1->Size = System::Drawing::Size(546, 346);
			this->chart1->TabIndex = 2;
			this->chart1->Text = L"chart1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(686, 370);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->parameters);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Main";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 srand(1);
				 if (parameters->
				 for (int i = 0; i < 500; i++)
				 {
					 Ukraine.step();
				 }
//				 Ukraine.change_tax(0.1);
/*				 for (int i = 0; i < 200; i++)
				 {
					 Ukraine.step();
				 }//*/
				 button1->Text = L"finish";
			 }
	};
}

