#pragma once

#include "world.h"
#include "Result.h"
#include <msclr\marshal_cppstd.h>

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

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::CheckedListBox^  types;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::GroupBox^  groupBox1;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->parameters = (gcnew System::Windows::Forms::CheckedListBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->types = (gcnew System::Windows::Forms::CheckedListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->button1->Location = System::Drawing::Point(0, 360);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(141, 73);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Draw";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// parameters
			// 
			this->parameters->CheckOnClick = true;
			this->parameters->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->parameters->FormattingEnabled = true;
			this->parameters->Items->AddRange(gcnew cli::array< System::Object^  >(15) {L"price", L"salary", L"plan", L"storage", L"workers", 
				L"labor_capacity", L"capital_capacity", L"raw_capacity", L"capital_investments", L"raw_investments", L"sales", L"sold", L"profit", 
				L"money", L"production"});
			this->parameters->Location = System::Drawing::Point(0, 131);
			this->parameters->Name = L"parameters";
			this->parameters->Size = System::Drawing::Size(141, 229);
			this->parameters->TabIndex = 1;
			this->parameters->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->types);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->parameters);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel1->Location = System::Drawing::Point(700, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(141, 433);
			this->panel1->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(45, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 17);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Output";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->label2->Location = System::Drawing::Point(0, 26);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Firm types";
			// 
			// types
			// 
			this->types->CheckOnClick = true;
			this->types->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->types->FormattingEnabled = true;
			this->types->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"raw_firm", L"capital_firm", L"good_firm"});
			this->types->Location = System::Drawing::Point(0, 39);
			this->types->Name = L"types";
			this->types->Size = System::Drawing::Size(141, 79);
			this->types->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->label1->Location = System::Drawing::Point(0, 118);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Parameters";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->groupBox1);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Location = System::Drawing::Point(596, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(106, 433);
			this->panel2->TabIndex = 4;
			// 
			// groupBox1
			// 
			this->groupBox1->Location = System::Drawing::Point(4, 26);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(99, 105);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(21, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 17);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Input";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(841, 433);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->Text = L"Main";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 srand(1);
				 Result^ result = gcnew Result();				 
				 world *country = new world();
				 vector<firm*> values;
				 for (int i = 0; i < types->CheckedItems->Count; i++)
				 {
					 string value = msclr::interop::marshal_as<std::string>(types->CheckedItems[i]->ToString());
					 values = append(values, country->get_firms(value));
				 }
				 for (int i = 0; i < parameters->CheckedItems->Count; i++)
				 {
					for (int j = 0; j < values.size(); j++)
					{						
						
						String^ s = gcnew String((values[j]->get_type()).c_str());
						result->chart->Series->Add(parameters->CheckedItems[i]->ToString() + " " + s + " " + j);
						result->chart->Series[parameters->CheckedItems[i]->ToString() + " " + s + " " + j]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
					}
				 }
				 for (int l = 0; l < 50; l++)
				 {
					 country->step();
					 for (int i = 0; i < parameters->CheckedItems->Count; i++)
					 {
						 for (int j = 0; j < values.size(); j++)
						 {
							 String^ s = gcnew String((values[j]->get_type()).c_str());
							 string value = msclr::interop::marshal_as<std::string>(parameters->CheckedItems[i]->ToString());
							 result->chart->Series[parameters->CheckedItems[i]->ToString() + " " + s + " " + j]->Points->AddY(values[j]->get(value));
						 }
					 }
				 }
//				 Ukraine.change_tax(0.1);
/*				 for (int i = 0; i < 200; i++)
				 {
					 Ukraine.step();
				 }//*/
				 result->Visible = true;
				 button1->Text = L"finish";
			 }
	};
}

