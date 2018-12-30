#pragma once

namespace SMO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SetDevForm
	/// </summary>
	public ref class SetDevForm : public System::Windows::Forms::Form
	{
	private:
		double lower;
		double upper;
	public:
		SetDevForm(void)
		{
			InitializeComponent();
			lower = 0;
			upper = 0;
			//
			//TODO: Add the constructor code here
			//
		}
	public:
		double getLower() { return lower; }
		double getUpper() { return upper; }
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SetDevForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::TextBox^  txtLower;
	private: System::Windows::Forms::TextBox^  txtUpper;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  btOk;


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
			this->txtLower = (gcnew System::Windows::Forms::TextBox());
			this->txtUpper = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btOk = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtLower
			// 
			this->txtLower->Location = System::Drawing::Point(118, 71);
			this->txtLower->Margin = System::Windows::Forms::Padding(2);
			this->txtLower->Multiline = true;
			this->txtLower->Name = L"txtLower";
			this->txtLower->Size = System::Drawing::Size(92, 25);
			this->txtLower->TabIndex = 1;
			this->txtLower->TextChanged += gcnew System::EventHandler(this, &SetDevForm::txtLower_TextChanged);
			// 
			// txtUpper
			// 
			this->txtUpper->Location = System::Drawing::Point(118, 109);
			this->txtUpper->Margin = System::Windows::Forms::Padding(2);
			this->txtUpper->Multiline = true;
			this->txtUpper->Name = L"txtUpper";
			this->txtUpper->Size = System::Drawing::Size(92, 25);
			this->txtUpper->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(23, 71);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Alpha :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(23, 109);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(68, 25);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Betta :";
			// 
			// btOk
			// 
			this->btOk->Location = System::Drawing::Point(103, 164);
			this->btOk->Margin = System::Windows::Forms::Padding(2);
			this->btOk->Name = L"btOk";
			this->btOk->Size = System::Drawing::Size(68, 27);
			this->btOk->TabIndex = 5;
			this->btOk->Text = L"OK";
			this->btOk->UseVisualStyleBackColor = true;
			this->btOk->Click += gcnew System::EventHandler(this, &SetDevForm::btOk_Click);
			// 
			// SetDevForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(289, 234);
			this->Controls->Add(this->btOk);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtUpper);
			this->Controls->Add(this->txtLower);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"SetDevForm";
			this->Text = L"SetDevForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btOk_Click(System::Object^  sender, System::EventArgs^  e) {
		lower = Double::Parse(txtLower->Text);
		upper = Double::Parse(txtUpper->Text);
		this->Close();
	}
private: System::Void txtLower_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
