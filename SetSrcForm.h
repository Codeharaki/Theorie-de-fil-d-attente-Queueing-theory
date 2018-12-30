#pragma once

namespace SMO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SetSrcForm
	/// </summary>
	public ref class SetSrcForm : public System::Windows::Forms::Form
	{
	private:
		double lamda;
	public:
		SetSrcForm(void)
		{
			InitializeComponent();
			lamda = 0;
			//
			//TODO: Add the constructor code here
			//
		}
	public:
		double getLamda() { 
			return lamda; 
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SetSrcForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  btOk;
	private: System::Windows::Forms::TextBox^  txtLamda;

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btOk = (gcnew System::Windows::Forms::Button());
			this->txtLamda = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(1, 68);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(94, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Lambda :";
			this->label2->Click += gcnew System::EventHandler(this, &SetSrcForm::label2_Click);
			// 
			// btOk
			// 
			this->btOk->Location = System::Drawing::Point(102, 133);
			this->btOk->Margin = System::Windows::Forms::Padding(2);
			this->btOk->Name = L"btOk";
			this->btOk->Size = System::Drawing::Size(66, 22);
			this->btOk->TabIndex = 2;
			this->btOk->Text = L"OK";
			this->btOk->UseVisualStyleBackColor = true;
			this->btOk->Click += gcnew System::EventHandler(this, &SetSrcForm::btOk_Click);
			// 
			// txtLamda
			// 
			this->txtLamda->Location = System::Drawing::Point(102, 69);
			this->txtLamda->Margin = System::Windows::Forms::Padding(2);
			this->txtLamda->Multiline = true;
			this->txtLamda->Name = L"txtLamda";
			this->txtLamda->Size = System::Drawing::Size(134, 24);
			this->txtLamda->TabIndex = 3;
			this->txtLamda->TextChanged += gcnew System::EventHandler(this, &SetSrcForm::txtLamda_TextChanged);
			// 
			// SetSrcForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(294, 177);
			this->Controls->Add(this->txtLamda);
			this->Controls->Add(this->btOk);
			this->Controls->Add(this->label2);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"SetSrcForm";
			this->Text = L"SetSrcForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btOk_Click(System::Object^  sender, System::EventArgs^  e) {
		lamda = Double::Parse(txtLamda->Text);
		this->Close();
	}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void txtLamda_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
