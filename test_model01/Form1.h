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

	private: System::Windows::Forms::CheckedListBox^  parameters;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::CheckedListBox^  types;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TabControl^  input;
	private: System::Windows::Forms::TabPage^  raw_firm_tab;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::TextBox^  period_raw;

	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  aproximation_raw;

	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  capital_coefficient_raw;

	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  salary_coefficient_raw;




	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  amortization_raw;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  capital_productivity_raw;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  raw_labor_productivity_raw;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  labor_productivity_raw;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  money_raw;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  number_raw;


	private: System::Windows::Forms::TabPage^  capital_firm_tab;
	private: System::Windows::Forms::TabPage^  good_firm_tab;
	private: System::Windows::Forms::TabPage^  household_tab;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::TextBox^  raw_coefficient_capital;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  period_capital;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::TextBox^  aproximation_capital;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::TextBox^  capital_coefficient_capital;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::TextBox^  salary_coefficient_capital;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::TextBox^  raw_productivity_capital;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::TextBox^  amortization_capital;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::TextBox^  capital_productivity_capital;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::TextBox^  raw_labor_productivity_capital;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::TextBox^  labor_productivity_capital;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::TextBox^  money_capital;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::TextBox^  number_capital;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::TextBox^  raw_coefficient_good;

	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::TextBox^  period_good;

	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::TextBox^  aproximation_good;

	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::TextBox^  capital_coefficient_good;

	private: System::Windows::Forms::Label^  label30;
private: System::Windows::Forms::TextBox^  salary_coefficient_good;

	private: System::Windows::Forms::Label^  label32;
private: System::Windows::Forms::TextBox^  amortization_good;

	private: System::Windows::Forms::Label^  label33;
private: System::Windows::Forms::TextBox^  capital_productivity_good;

	private: System::Windows::Forms::Label^  label34;
private: System::Windows::Forms::TextBox^  raw_productivity_good;

	private: System::Windows::Forms::Label^  label35;
private: System::Windows::Forms::TextBox^  labor_productivity_good;

	private: System::Windows::Forms::Label^  label36;
private: System::Windows::Forms::TextBox^  money_good;

	private: System::Windows::Forms::Label^  label37;
	private: System::Windows::Forms::TextBox^  number_good;
private: System::Windows::Forms::Label^  label31;
private: System::Windows::Forms::TextBox^  money_household;
private: System::Windows::Forms::Label^  label38;
private: System::Windows::Forms::TextBox^  number_household;
private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::Label^  label39;
private: System::Windows::Forms::Label^  label40;
private: System::Windows::Forms::TextBox^  firm_id;
private: System::Windows::Forms::Label^  label41;
private: System::Windows::Forms::TextBox^  iterations;





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
			this->parameters = (gcnew System::Windows::Forms::CheckedListBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->types = (gcnew System::Windows::Forms::CheckedListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->input = (gcnew System::Windows::Forms::TabControl());
			this->raw_firm_tab = (gcnew System::Windows::Forms::TabPage());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->period_raw = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->aproximation_raw = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->capital_coefficient_raw = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->salary_coefficient_raw = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->amortization_raw = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->capital_productivity_raw = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->raw_labor_productivity_raw = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->labor_productivity_raw = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->money_raw = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->number_raw = (gcnew System::Windows::Forms::TextBox());
			this->capital_firm_tab = (gcnew System::Windows::Forms::TabPage());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->raw_coefficient_capital = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->period_capital = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->aproximation_capital = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->capital_coefficient_capital = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->salary_coefficient_capital = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->raw_productivity_capital = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->amortization_capital = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->capital_productivity_capital = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->raw_labor_productivity_capital = (gcnew System::Windows::Forms::TextBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->labor_productivity_capital = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->money_capital = (gcnew System::Windows::Forms::TextBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->number_capital = (gcnew System::Windows::Forms::TextBox());
			this->good_firm_tab = (gcnew System::Windows::Forms::TabPage());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->raw_coefficient_good = (gcnew System::Windows::Forms::TextBox());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->period_good = (gcnew System::Windows::Forms::TextBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->aproximation_good = (gcnew System::Windows::Forms::TextBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->capital_coefficient_good = (gcnew System::Windows::Forms::TextBox());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->salary_coefficient_good = (gcnew System::Windows::Forms::TextBox());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->amortization_good = (gcnew System::Windows::Forms::TextBox());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->capital_productivity_good = (gcnew System::Windows::Forms::TextBox());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->raw_productivity_good = (gcnew System::Windows::Forms::TextBox());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->labor_productivity_good = (gcnew System::Windows::Forms::TextBox());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->money_good = (gcnew System::Windows::Forms::TextBox());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->number_good = (gcnew System::Windows::Forms::TextBox());
			this->household_tab = (gcnew System::Windows::Forms::TabPage());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->money_household = (gcnew System::Windows::Forms::TextBox());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->number_household = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->firm_id = (gcnew System::Windows::Forms::TextBox());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->iterations = (gcnew System::Windows::Forms::TextBox());
			this->input->SuspendLayout();
			this->raw_firm_tab->SuspendLayout();
			this->capital_firm_tab->SuspendLayout();
			this->good_firm_tab->SuspendLayout();
			this->household_tab->SuspendLayout();
			this->SuspendLayout();
			// 
			// parameters
			// 
			this->parameters->CheckOnClick = true;
			this->parameters->FormattingEnabled = true;
			this->parameters->Items->AddRange(gcnew cli::array< System::Object^  >(15) {L"price", L"salary", L"plan", L"storage", L"workers", 
				L"labor_capacity", L"capital_capacity", L"raw_capacity", L"capital_investments", L"raw_investments", L"sales", L"sold", L"profit", 
				L"money", L"production"});
			this->parameters->Location = System::Drawing::Point(658, 50);
			this->parameters->Name = L"parameters";
			this->parameters->Size = System::Drawing::Size(141, 229);
			this->parameters->TabIndex = 1;
			this->parameters->TabStop = false;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(619, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 17);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Output";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(505, 26);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Firm types";
			// 
			// types
			// 
			this->types->CheckOnClick = true;
			this->types->FormattingEnabled = true;
			this->types->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"raw_firm", L"capital_firm", L"good_firm"});
			this->types->Location = System::Drawing::Point(508, 50);
			this->types->Name = L"types";
			this->types->Size = System::Drawing::Size(116, 49);
			this->types->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(655, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Parameters";
			// 
			// input
			// 
			this->input->Controls->Add(this->raw_firm_tab);
			this->input->Controls->Add(this->capital_firm_tab);
			this->input->Controls->Add(this->good_firm_tab);
			this->input->Controls->Add(this->household_tab);
			this->input->Location = System::Drawing::Point(2, 0);
			this->input->Name = L"input";
			this->input->SelectedIndex = 0;
			this->input->Size = System::Drawing::Size(469, 353);
			this->input->TabIndex = 4;
			// 
			// raw_firm_tab
			// 
			this->raw_firm_tab->BackColor = System::Drawing::Color::Transparent;
			this->raw_firm_tab->Controls->Add(this->label14);
			this->raw_firm_tab->Controls->Add(this->period_raw);
			this->raw_firm_tab->Controls->Add(this->label13);
			this->raw_firm_tab->Controls->Add(this->aproximation_raw);
			this->raw_firm_tab->Controls->Add(this->label12);
			this->raw_firm_tab->Controls->Add(this->capital_coefficient_raw);
			this->raw_firm_tab->Controls->Add(this->label11);
			this->raw_firm_tab->Controls->Add(this->salary_coefficient_raw);
			this->raw_firm_tab->Controls->Add(this->label9);
			this->raw_firm_tab->Controls->Add(this->amortization_raw);
			this->raw_firm_tab->Controls->Add(this->label8);
			this->raw_firm_tab->Controls->Add(this->capital_productivity_raw);
			this->raw_firm_tab->Controls->Add(this->label7);
			this->raw_firm_tab->Controls->Add(this->raw_labor_productivity_raw);
			this->raw_firm_tab->Controls->Add(this->label6);
			this->raw_firm_tab->Controls->Add(this->labor_productivity_raw);
			this->raw_firm_tab->Controls->Add(this->label5);
			this->raw_firm_tab->Controls->Add(this->money_raw);
			this->raw_firm_tab->Controls->Add(this->label4);
			this->raw_firm_tab->Controls->Add(this->number_raw);
			this->raw_firm_tab->Location = System::Drawing::Point(4, 22);
			this->raw_firm_tab->Name = L"raw_firm_tab";
			this->raw_firm_tab->Padding = System::Windows::Forms::Padding(3);
			this->raw_firm_tab->Size = System::Drawing::Size(461, 327);
			this->raw_firm_tab->TabIndex = 0;
			this->raw_firm_tab->Text = L"raw_firm";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(236, 145);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(37, 13);
			this->label14->TabIndex = 21;
			this->label14->Text = L"Period";
			// 
			// period_raw
			// 
			this->period_raw->Location = System::Drawing::Point(282, 161);
			this->period_raw->Name = L"period_raw";
			this->period_raw->Size = System::Drawing::Size(143, 20);
			this->period_raw->TabIndex = 20;
			this->period_raw->Text = L"3";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(236, 96);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(67, 13);
			this->label13->TabIndex = 19;
			this->label13->Text = L"Aproximation";
			// 
			// aproximation_raw
			// 
			this->aproximation_raw->Location = System::Drawing::Point(282, 112);
			this->aproximation_raw->Name = L"aproximation_raw";
			this->aproximation_raw->Size = System::Drawing::Size(143, 20);
			this->aproximation_raw->TabIndex = 18;
			this->aproximation_raw->Text = L"0,3";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(236, 48);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(91, 13);
			this->label12->TabIndex = 17;
			this->label12->Text = L"Capital coefficient";
			// 
			// capital_coefficient_raw
			// 
			this->capital_coefficient_raw->Location = System::Drawing::Point(282, 64);
			this->capital_coefficient_raw->Name = L"capital_coefficient_raw";
			this->capital_coefficient_raw->Size = System::Drawing::Size(143, 20);
			this->capital_coefficient_raw->TabIndex = 16;
			this->capital_coefficient_raw->Text = L"0,4";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(236, 6);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(88, 13);
			this->label11->TabIndex = 15;
			this->label11->Text = L"Salary coefficient";
			// 
			// salary_coefficient_raw
			// 
			this->salary_coefficient_raw->Location = System::Drawing::Point(282, 22);
			this->salary_coefficient_raw->Name = L"salary_coefficient_raw";
			this->salary_coefficient_raw->Size = System::Drawing::Size(143, 20);
			this->salary_coefficient_raw->TabIndex = 14;
			this->salary_coefficient_raw->Text = L"0,4";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(7, 241);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(64, 13);
			this->label9->TabIndex = 11;
			this->label9->Text = L"Amortization";
			// 
			// amortization_raw
			// 
			this->amortization_raw->Location = System::Drawing::Point(53, 257);
			this->amortization_raw->Name = L"amortization_raw";
			this->amortization_raw->Size = System::Drawing::Size(143, 20);
			this->amortization_raw->TabIndex = 10;
			this->amortization_raw->Text = L"0,1";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(7, 193);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(96, 13);
			this->label8->TabIndex = 9;
			this->label8->Text = L"Capital productivity";
			// 
			// capital_productivity_raw
			// 
			this->capital_productivity_raw->Location = System::Drawing::Point(53, 209);
			this->capital_productivity_raw->Name = L"capital_productivity_raw";
			this->capital_productivity_raw->Size = System::Drawing::Size(143, 20);
			this->capital_productivity_raw->TabIndex = 8;
			this->capital_productivity_raw->Text = L"10";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(7, 145);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(112, 13);
			this->label7->TabIndex = 7;
			this->label7->Text = L"Raw labor productivity";
			// 
			// raw_labor_productivity_raw
			// 
			this->raw_labor_productivity_raw->Location = System::Drawing::Point(53, 161);
			this->raw_labor_productivity_raw->Name = L"raw_labor_productivity_raw";
			this->raw_labor_productivity_raw->Size = System::Drawing::Size(143, 20);
			this->raw_labor_productivity_raw->TabIndex = 6;
			this->raw_labor_productivity_raw->Text = L"1";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 96);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(91, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Labor productivity";
			// 
			// labor_productivity_raw
			// 
			this->labor_productivity_raw->Location = System::Drawing::Point(52, 112);
			this->labor_productivity_raw->Name = L"labor_productivity_raw";
			this->labor_productivity_raw->Size = System::Drawing::Size(143, 20);
			this->labor_productivity_raw->TabIndex = 4;
			this->labor_productivity_raw->Text = L"5";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(7, 48);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(39, 13);
			this->label5->TabIndex = 3;
			this->label5->Text = L"Money";
			// 
			// money_raw
			// 
			this->money_raw->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->money_raw->Location = System::Drawing::Point(53, 64);
			this->money_raw->Name = L"money_raw";
			this->money_raw->Size = System::Drawing::Size(143, 20);
			this->money_raw->TabIndex = 2;
			this->money_raw->Text = L"1000";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(7, 6);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 13);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Number";
			// 
			// number_raw
			// 
			this->number_raw->Location = System::Drawing::Point(57, 22);
			this->number_raw->Name = L"number_raw";
			this->number_raw->Size = System::Drawing::Size(143, 20);
			this->number_raw->TabIndex = 0;
			this->number_raw->Text = L"1";
			// 
			// capital_firm_tab
			// 
			this->capital_firm_tab->BackColor = System::Drawing::Color::Transparent;
			this->capital_firm_tab->Controls->Add(this->label25);
			this->capital_firm_tab->Controls->Add(this->raw_coefficient_capital);
			this->capital_firm_tab->Controls->Add(this->label10);
			this->capital_firm_tab->Controls->Add(this->period_capital);
			this->capital_firm_tab->Controls->Add(this->label15);
			this->capital_firm_tab->Controls->Add(this->aproximation_capital);
			this->capital_firm_tab->Controls->Add(this->label16);
			this->capital_firm_tab->Controls->Add(this->capital_coefficient_capital);
			this->capital_firm_tab->Controls->Add(this->label17);
			this->capital_firm_tab->Controls->Add(this->salary_coefficient_capital);
			this->capital_firm_tab->Controls->Add(this->label18);
			this->capital_firm_tab->Controls->Add(this->raw_productivity_capital);
			this->capital_firm_tab->Controls->Add(this->label19);
			this->capital_firm_tab->Controls->Add(this->amortization_capital);
			this->capital_firm_tab->Controls->Add(this->label20);
			this->capital_firm_tab->Controls->Add(this->capital_productivity_capital);
			this->capital_firm_tab->Controls->Add(this->label21);
			this->capital_firm_tab->Controls->Add(this->raw_labor_productivity_capital);
			this->capital_firm_tab->Controls->Add(this->label22);
			this->capital_firm_tab->Controls->Add(this->labor_productivity_capital);
			this->capital_firm_tab->Controls->Add(this->label23);
			this->capital_firm_tab->Controls->Add(this->money_capital);
			this->capital_firm_tab->Controls->Add(this->label24);
			this->capital_firm_tab->Controls->Add(this->number_capital);
			this->capital_firm_tab->Location = System::Drawing::Point(4, 22);
			this->capital_firm_tab->Name = L"capital_firm_tab";
			this->capital_firm_tab->Padding = System::Windows::Forms::Padding(3);
			this->capital_firm_tab->Size = System::Drawing::Size(461, 327);
			this->capital_firm_tab->TabIndex = 1;
			this->capital_firm_tab->Text = L"capital_firm";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(235, 94);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(81, 13);
			this->label25->TabIndex = 45;
			this->label25->Text = L"Raw coefficient";
			// 
			// raw_coefficient_capital
			// 
			this->raw_coefficient_capital->Location = System::Drawing::Point(281, 110);
			this->raw_coefficient_capital->Name = L"raw_coefficient_capital";
			this->raw_coefficient_capital->Size = System::Drawing::Size(143, 20);
			this->raw_coefficient_capital->TabIndex = 44;
			this->raw_coefficient_capital->Text = L"0,3";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(235, 192);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(37, 13);
			this->label10->TabIndex = 43;
			this->label10->Text = L"Period";
			// 
			// period_capital
			// 
			this->period_capital->Location = System::Drawing::Point(281, 208);
			this->period_capital->Name = L"period_capital";
			this->period_capital->Size = System::Drawing::Size(143, 20);
			this->period_capital->TabIndex = 42;
			this->period_capital->Text = L"12";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(235, 143);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(67, 13);
			this->label15->TabIndex = 41;
			this->label15->Text = L"Aproximation";
			// 
			// aproximation_capital
			// 
			this->aproximation_capital->Location = System::Drawing::Point(281, 159);
			this->aproximation_capital->Name = L"aproximation_capital";
			this->aproximation_capital->Size = System::Drawing::Size(143, 20);
			this->aproximation_capital->TabIndex = 40;
			this->aproximation_capital->Text = L"0,1";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(235, 46);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(91, 13);
			this->label16->TabIndex = 39;
			this->label16->Text = L"Capital coefficient";
			// 
			// capital_coefficient_capital
			// 
			this->capital_coefficient_capital->Location = System::Drawing::Point(281, 62);
			this->capital_coefficient_capital->Name = L"capital_coefficient_capital";
			this->capital_coefficient_capital->Size = System::Drawing::Size(143, 20);
			this->capital_coefficient_capital->TabIndex = 38;
			this->capital_coefficient_capital->Text = L"0,2";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(235, 4);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(88, 13);
			this->label17->TabIndex = 37;
			this->label17->Text = L"Salary coefficient";
			// 
			// salary_coefficient_capital
			// 
			this->salary_coefficient_capital->Location = System::Drawing::Point(281, 20);
			this->salary_coefficient_capital->Name = L"salary_coefficient_capital";
			this->salary_coefficient_capital->Size = System::Drawing::Size(143, 20);
			this->salary_coefficient_capital->TabIndex = 36;
			this->salary_coefficient_capital->Text = L"0,4";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(235, 239);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(86, 13);
			this->label18->TabIndex = 35;
			this->label18->Text = L"Raw productivity";
			// 
			// raw_productivity_capital
			// 
			this->raw_productivity_capital->Location = System::Drawing::Point(281, 255);
			this->raw_productivity_capital->Name = L"raw_productivity_capital";
			this->raw_productivity_capital->Size = System::Drawing::Size(143, 20);
			this->raw_productivity_capital->TabIndex = 34;
			this->raw_productivity_capital->Text = L"3";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(6, 239);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(64, 13);
			this->label19->TabIndex = 33;
			this->label19->Text = L"Amortization";
			// 
			// amortization_capital
			// 
			this->amortization_capital->Location = System::Drawing::Point(52, 255);
			this->amortization_capital->Name = L"amortization_capital";
			this->amortization_capital->Size = System::Drawing::Size(143, 20);
			this->amortization_capital->TabIndex = 32;
			this->amortization_capital->Text = L"0,2";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(6, 191);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(96, 13);
			this->label20->TabIndex = 31;
			this->label20->Text = L"Capital productivity";
			// 
			// capital_productivity_capital
			// 
			this->capital_productivity_capital->Location = System::Drawing::Point(52, 207);
			this->capital_productivity_capital->Name = L"capital_productivity_capital";
			this->capital_productivity_capital->Size = System::Drawing::Size(143, 20);
			this->capital_productivity_capital->TabIndex = 30;
			this->capital_productivity_capital->Text = L"5";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(6, 143);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(112, 13);
			this->label21->TabIndex = 29;
			this->label21->Text = L"Raw labor productivity";
			// 
			// raw_labor_productivity_capital
			// 
			this->raw_labor_productivity_capital->Location = System::Drawing::Point(52, 159);
			this->raw_labor_productivity_capital->Name = L"raw_labor_productivity_capital";
			this->raw_labor_productivity_capital->Size = System::Drawing::Size(143, 20);
			this->raw_labor_productivity_capital->TabIndex = 28;
			this->raw_labor_productivity_capital->Text = L"0,5";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(5, 94);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(91, 13);
			this->label22->TabIndex = 27;
			this->label22->Text = L"Labor productivity";
			// 
			// labor_productivity_capital
			// 
			this->labor_productivity_capital->Location = System::Drawing::Point(51, 110);
			this->labor_productivity_capital->Name = L"labor_productivity_capital";
			this->labor_productivity_capital->Size = System::Drawing::Size(143, 20);
			this->labor_productivity_capital->TabIndex = 26;
			this->labor_productivity_capital->Text = L"3";
			// 
			// label23
			// 
			this->label23->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(7, 46);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(39, 13);
			this->label23->TabIndex = 25;
			this->label23->Text = L"Money";
			// 
			// money_capital
			// 
			this->money_capital->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->money_capital->Location = System::Drawing::Point(52, 62);
			this->money_capital->Name = L"money_capital";
			this->money_capital->Size = System::Drawing::Size(143, 20);
			this->money_capital->TabIndex = 24;
			this->money_capital->Text = L"1000";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(6, 4);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(44, 13);
			this->label24->TabIndex = 23;
			this->label24->Text = L"Number";
			// 
			// number_capital
			// 
			this->number_capital->Location = System::Drawing::Point(52, 20);
			this->number_capital->Name = L"number_capital";
			this->number_capital->Size = System::Drawing::Size(143, 20);
			this->number_capital->TabIndex = 22;
			this->number_capital->Text = L"1";
			// 
			// good_firm_tab
			// 
			this->good_firm_tab->BackColor = System::Drawing::Color::Transparent;
			this->good_firm_tab->Controls->Add(this->label26);
			this->good_firm_tab->Controls->Add(this->raw_coefficient_good);
			this->good_firm_tab->Controls->Add(this->label27);
			this->good_firm_tab->Controls->Add(this->period_good);
			this->good_firm_tab->Controls->Add(this->label28);
			this->good_firm_tab->Controls->Add(this->aproximation_good);
			this->good_firm_tab->Controls->Add(this->label29);
			this->good_firm_tab->Controls->Add(this->capital_coefficient_good);
			this->good_firm_tab->Controls->Add(this->label30);
			this->good_firm_tab->Controls->Add(this->salary_coefficient_good);
			this->good_firm_tab->Controls->Add(this->label32);
			this->good_firm_tab->Controls->Add(this->amortization_good);
			this->good_firm_tab->Controls->Add(this->label33);
			this->good_firm_tab->Controls->Add(this->capital_productivity_good);
			this->good_firm_tab->Controls->Add(this->label34);
			this->good_firm_tab->Controls->Add(this->raw_productivity_good);
			this->good_firm_tab->Controls->Add(this->label35);
			this->good_firm_tab->Controls->Add(this->labor_productivity_good);
			this->good_firm_tab->Controls->Add(this->label36);
			this->good_firm_tab->Controls->Add(this->money_good);
			this->good_firm_tab->Controls->Add(this->label37);
			this->good_firm_tab->Controls->Add(this->number_good);
			this->good_firm_tab->Location = System::Drawing::Point(4, 22);
			this->good_firm_tab->Name = L"good_firm_tab";
			this->good_firm_tab->Size = System::Drawing::Size(461, 327);
			this->good_firm_tab->TabIndex = 2;
			this->good_firm_tab->Text = L"good_firm";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(235, 94);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(81, 13);
			this->label26->TabIndex = 69;
			this->label26->Text = L"Raw coefficient";
			// 
			// raw_coefficient_good
			// 
			this->raw_coefficient_good->Location = System::Drawing::Point(281, 110);
			this->raw_coefficient_good->Name = L"raw_coefficient_good";
			this->raw_coefficient_good->Size = System::Drawing::Size(143, 20);
			this->raw_coefficient_good->TabIndex = 68;
			this->raw_coefficient_good->Text = L"0,3";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(235, 192);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(37, 13);
			this->label27->TabIndex = 67;
			this->label27->Text = L"Period";
			// 
			// period_good
			// 
			this->period_good->Location = System::Drawing::Point(281, 207);
			this->period_good->Name = L"period_good";
			this->period_good->Size = System::Drawing::Size(143, 20);
			this->period_good->TabIndex = 66;
			this->period_good->Text = L"3";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(235, 143);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(67, 13);
			this->label28->TabIndex = 65;
			this->label28->Text = L"Aproximation";
			// 
			// aproximation_good
			// 
			this->aproximation_good->Location = System::Drawing::Point(281, 159);
			this->aproximation_good->Name = L"aproximation_good";
			this->aproximation_good->Size = System::Drawing::Size(143, 20);
			this->aproximation_good->TabIndex = 64;
			this->aproximation_good->Text = L"0,5";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(235, 46);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(91, 13);
			this->label29->TabIndex = 63;
			this->label29->Text = L"Capital coefficient";
			// 
			// capital_coefficient_good
			// 
			this->capital_coefficient_good->Location = System::Drawing::Point(281, 62);
			this->capital_coefficient_good->Name = L"capital_coefficient_good";
			this->capital_coefficient_good->Size = System::Drawing::Size(143, 20);
			this->capital_coefficient_good->TabIndex = 62;
			this->capital_coefficient_good->Text = L"0,2";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(235, 4);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(88, 13);
			this->label30->TabIndex = 61;
			this->label30->Text = L"Salary coefficient";
			// 
			// salary_coefficient_good
			// 
			this->salary_coefficient_good->Location = System::Drawing::Point(281, 20);
			this->salary_coefficient_good->Name = L"salary_coefficient_good";
			this->salary_coefficient_good->Size = System::Drawing::Size(143, 20);
			this->salary_coefficient_good->TabIndex = 60;
			this->salary_coefficient_good->Text = L"0,4";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(6, 239);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(64, 13);
			this->label32->TabIndex = 57;
			this->label32->Text = L"Amortization";
			// 
			// amortization_good
			// 
			this->amortization_good->Location = System::Drawing::Point(52, 255);
			this->amortization_good->Name = L"amortization_good";
			this->amortization_good->Size = System::Drawing::Size(143, 20);
			this->amortization_good->TabIndex = 56;
			this->amortization_good->Text = L"0,1";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(6, 191);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(96, 13);
			this->label33->TabIndex = 55;
			this->label33->Text = L"Capital productivity";
			// 
			// capital_productivity_good
			// 
			this->capital_productivity_good->Location = System::Drawing::Point(52, 207);
			this->capital_productivity_good->Name = L"capital_productivity_good";
			this->capital_productivity_good->Size = System::Drawing::Size(143, 20);
			this->capital_productivity_good->TabIndex = 54;
			this->capital_productivity_good->Text = L"20";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(6, 143);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(86, 13);
			this->label34->TabIndex = 53;
			this->label34->Text = L"Raw productivity";
			// 
			// raw_productivity_good
			// 
			this->raw_productivity_good->Location = System::Drawing::Point(52, 159);
			this->raw_productivity_good->Name = L"raw_productivity_good";
			this->raw_productivity_good->Size = System::Drawing::Size(143, 20);
			this->raw_productivity_good->TabIndex = 52;
			this->raw_productivity_good->Text = L"5";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(5, 94);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(91, 13);
			this->label35->TabIndex = 51;
			this->label35->Text = L"Labor productivity";
			// 
			// labor_productivity_good
			// 
			this->labor_productivity_good->Location = System::Drawing::Point(51, 110);
			this->labor_productivity_good->Name = L"labor_productivity_good";
			this->labor_productivity_good->Size = System::Drawing::Size(143, 20);
			this->labor_productivity_good->TabIndex = 50;
			this->labor_productivity_good->Text = L"5";
			// 
			// label36
			// 
			this->label36->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(6, 46);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(39, 13);
			this->label36->TabIndex = 49;
			this->label36->Text = L"Money";
			// 
			// money_good
			// 
			this->money_good->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->money_good->Location = System::Drawing::Point(52, 62);
			this->money_good->Name = L"money_good";
			this->money_good->Size = System::Drawing::Size(143, 20);
			this->money_good->TabIndex = 48;
			this->money_good->Text = L"1000";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(6, 4);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(44, 13);
			this->label37->TabIndex = 47;
			this->label37->Text = L"Number";
			// 
			// number_good
			// 
			this->number_good->Location = System::Drawing::Point(52, 20);
			this->number_good->Name = L"number_good";
			this->number_good->Size = System::Drawing::Size(143, 20);
			this->number_good->TabIndex = 46;
			this->number_good->Text = L"1";
			// 
			// household_tab
			// 
			this->household_tab->BackColor = System::Drawing::Color::Transparent;
			this->household_tab->Controls->Add(this->label31);
			this->household_tab->Controls->Add(this->money_household);
			this->household_tab->Controls->Add(this->label38);
			this->household_tab->Controls->Add(this->number_household);
			this->household_tab->Location = System::Drawing::Point(4, 22);
			this->household_tab->Name = L"household_tab";
			this->household_tab->Size = System::Drawing::Size(461, 327);
			this->household_tab->TabIndex = 3;
			this->household_tab->Text = L"household";
			// 
			// label31
			// 
			this->label31->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(3, 39);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(39, 13);
			this->label31->TabIndex = 53;
			this->label31->Text = L"Money";
			// 
			// money_household
			// 
			this->money_household->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->money_household->Location = System::Drawing::Point(51, 57);
			this->money_household->Name = L"money_household";
			this->money_household->Size = System::Drawing::Size(143, 20);
			this->money_household->TabIndex = 52;
			this->money_household->Text = L"1000";
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(6, 4);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(44, 13);
			this->label38->TabIndex = 51;
			this->label38->Text = L"Number";
			// 
			// number_household
			// 
			this->number_household->Location = System::Drawing::Point(51, 15);
			this->number_household->Name = L"number_household";
			this->number_household->Size = System::Drawing::Size(143, 20);
			this->number_household->TabIndex = 50;
			this->number_household->Text = L"200";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(499, 285);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(300, 68);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Draw";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label39
			// 
			this->label39->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label39->AutoSize = true;
			this->label39->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label39->Location = System::Drawing::Point(552, 118);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(31, 17);
			this->label39->TabIndex = 6;
			this->label39->Text = L"OR";
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(505, 141);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(37, 13);
			this->label40->TabIndex = 25;
			this->label40->Text = L"Firm id";
			// 
			// firm_id
			// 
			this->firm_id->Location = System::Drawing::Point(508, 164);
			this->firm_id->Name = L"firm_id";
			this->firm_id->Size = System::Drawing::Size(116, 20);
			this->firm_id->TabIndex = 24;
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label41->Location = System::Drawing::Point(531, 208);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(76, 17);
			this->label41->TabIndex = 27;
			this->label41->Text = L"Iterations";
			// 
			// iterations
			// 
			this->iterations->Location = System::Drawing::Point(534, 231);
			this->iterations->Name = L"iterations";
			this->iterations->Size = System::Drawing::Size(75, 20);
			this->iterations->TabIndex = 26;
			this->iterations->Text = L"100";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(805, 358);
			this->Controls->Add(this->label41);
			this->Controls->Add(this->iterations);
			this->Controls->Add(this->label40);
			this->Controls->Add(this->firm_id);
			this->Controls->Add(this->label39);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->parameters);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->types);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->input);
			this->Name = L"Form1";
			this->Text = L"Main";
			this->input->ResumeLayout(false);
			this->raw_firm_tab->ResumeLayout(false);
			this->raw_firm_tab->PerformLayout();
			this->capital_firm_tab->ResumeLayout(false);
			this->capital_firm_tab->PerformLayout();
			this->good_firm_tab->ResumeLayout(false);
			this->good_firm_tab->PerformLayout();
			this->household_tab->ResumeLayout(false);
			this->household_tab->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 srand(1);
				 Result^ result = gcnew Result();				 
				 world *country = new world(int::Parse(number_raw->Text), int::Parse(number_capital->Text), int::Parse(number_good->Text), int::Parse(number_household->Text), double::Parse(money_household->Text));
				 country->init("raw_firm", double::Parse(money_raw->Text), double::Parse(labor_productivity_raw->Text), double::Parse(raw_labor_productivity_raw->Text), double::Parse(capital_productivity_raw->Text), double::Parse(amortization_raw->Text), 0, double::Parse(salary_coefficient_raw->Text), 0, double::Parse(capital_coefficient_raw->Text), double::Parse(aproximation_raw->Text), double::Parse(period_raw->Text));
				 country->init("capital_firm", double::Parse(money_capital->Text), double::Parse(labor_productivity_capital->Text), double::Parse(raw_labor_productivity_capital->Text), double::Parse(capital_productivity_capital->Text), double::Parse(amortization_capital->Text), double::Parse(raw_productivity_capital->Text), double::Parse(salary_coefficient_capital->Text), double::Parse(raw_coefficient_capital->Text), double::Parse(capital_coefficient_capital->Text), double::Parse(aproximation_capital->Text), double::Parse(period_capital->Text));
				 country->init("good_firm", double::Parse(money_good->Text), double::Parse(labor_productivity_good->Text), 0, double::Parse(capital_productivity_good->Text), double::Parse(amortization_good->Text), double::Parse(raw_productivity_good->Text), double::Parse(salary_coefficient_good->Text), double::Parse(raw_coefficient_good->Text), double::Parse(capital_coefficient_good->Text), double::Parse(aproximation_good->Text), double::Parse(period_good->Text));
				 vector<firm*> values;
				 if (!(String::IsNullOrWhiteSpace(firm_id->Text)))
				 {
					 values.push_back(country->get_firms()[int::Parse(firm_id->Text) % country->get_firms().size()]);
				 }
				 else
				 {
				 
				 for (int i = 0; i < types->CheckedItems->Count; i++)
				 {
					 string value = msclr::interop::marshal_as<std::string>(types->CheckedItems[i]->ToString());
					 values = append(values, country->get_firms(value));
				 }
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
				 for (int l = 0; l < int::Parse(iterations->Text); l++)
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
				 result->Show();
			 }

};
}

