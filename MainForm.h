#pragma once
#include "ByStepForm.h"
#include "AutoForm.h"
#include "SetDevForm.h"
#include "SetSrcForm.h"
#include "MBuffer.h"
#include "windows.h"
namespace SMO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		int nDev, nSrc, sizeBf, minNRequest;
		double lamdaIst, lowerDev, upperDev;
		array<MDevice^> ^devices;
		array<MSource^> ^sources;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  txtMinRequest;

		MBuffer^ buffer;
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
			if (devices)
			{
				delete devices;
			}
			if (sources)
			{
				delete sources;
			}
			if (buffer)
			{
				delete buffer;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btSetSrc;
	private: System::Windows::Forms::Button^  btSetDev;
	private: System::Windows::Forms::Button^  btSave;
	private: System::Windows::Forms::Button^  btByStep;

	private: System::Windows::Forms::Button^  btAuto;
	private: System::Windows::Forms::TextBox^  txNSrc;
	private: System::Windows::Forms::TextBox^  txNDev;
	private: System::Windows::Forms::TextBox^  txSizeBf;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	protected:

	protected:

	protected:

	protected:
	private: System::ComponentModel::IContainer^  components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btSetSrc = (gcnew System::Windows::Forms::Button());
			this->btSetDev = (gcnew System::Windows::Forms::Button());
			this->btSave = (gcnew System::Windows::Forms::Button());
			this->btByStep = (gcnew System::Windows::Forms::Button());
			this->btAuto = (gcnew System::Windows::Forms::Button());
			this->txNSrc = (gcnew System::Windows::Forms::TextBox());
			this->txNDev = (gcnew System::Windows::Forms::TextBox());
			this->txSizeBf = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtMinRequest = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(126, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(186, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Queueing System";
			this->label1->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
			// 
			// btSetSrc
			// 
			this->btSetSrc->Location = System::Drawing::Point(339, 104);
			this->btSetSrc->Name = L"btSetSrc";
			this->btSetSrc->Size = System::Drawing::Size(110, 24);
			this->btSetSrc->TabIndex = 1;
			this->btSetSrc->Text = L"Source Setting";
			this->btSetSrc->UseVisualStyleBackColor = true;
			this->btSetSrc->Click += gcnew System::EventHandler(this, &MainForm::btSetSrc_Click);
			// 
			// btSetDev
			// 
			this->btSetDev->Location = System::Drawing::Point(339, 146);
			this->btSetDev->Name = L"btSetDev";
			this->btSetDev->Size = System::Drawing::Size(110, 24);
			this->btSetDev->TabIndex = 2;
			this->btSetDev->Text = L"Device Setting";
			this->btSetDev->UseVisualStyleBackColor = true;
			this->btSetDev->Click += gcnew System::EventHandler(this, &MainForm::btSetDev_Click);
			// 
			// btSave
			// 
			this->btSave->Location = System::Drawing::Point(167, 323);
			this->btSave->Name = L"btSave";
			this->btSave->Size = System::Drawing::Size(135, 24);
			this->btSave->TabIndex = 3;
			this->btSave->Text = L"Save Changes";
			this->btSave->UseVisualStyleBackColor = true;
			this->btSave->Click += gcnew System::EventHandler(this, &MainForm::btSave_Click);
			// 
			// btByStep
			// 
			this->btByStep->Location = System::Drawing::Point(61, 377);
			this->btByStep->Name = L"btByStep";
			this->btByStep->Size = System::Drawing::Size(110, 24);
			this->btByStep->TabIndex = 4;
			this->btByStep->Text = L"Step Mode";
			this->btByStep->UseVisualStyleBackColor = true;
			this->btByStep->Click += gcnew System::EventHandler(this, &MainForm::btByStep_Click);
			// 
			// btAuto
			// 
			this->btAuto->Location = System::Drawing::Point(313, 377);
			this->btAuto->Name = L"btAuto";
			this->btAuto->Size = System::Drawing::Size(110, 24);
			this->btAuto->TabIndex = 5;
			this->btAuto->Text = L"Auto Mode";
			this->btAuto->UseVisualStyleBackColor = true;
			this->btAuto->Click += gcnew System::EventHandler(this, &MainForm::btAuto_Click);
			// 
			// txNSrc
			// 
			this->txNSrc->Location = System::Drawing::Point(167, 104);
			this->txNSrc->Multiline = true;
			this->txNSrc->Name = L"txNSrc";
			this->txNSrc->Size = System::Drawing::Size(135, 24);
			this->txNSrc->TabIndex = 6;
			this->txNSrc->TextChanged += gcnew System::EventHandler(this, &MainForm::txNSrc_TextChanged);
			// 
			// txNDev
			// 
			this->txNDev->Location = System::Drawing::Point(167, 146);
			this->txNDev->Multiline = true;
			this->txNDev->Name = L"txNDev";
			this->txNDev->Size = System::Drawing::Size(135, 24);
			this->txNDev->TabIndex = 7;
			// 
			// txSizeBf
			// 
			this->txSizeBf->Location = System::Drawing::Point(167, 212);
			this->txSizeBf->Multiline = true;
			this->txSizeBf->Name = L"txSizeBf";
			this->txSizeBf->Size = System::Drawing::Size(135, 24);
			this->txSizeBf->TabIndex = 8;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(26, 108);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 15);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Source Number :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(26, 146);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(98, 15);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Device Number :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(31, 212);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(72, 15);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Buffer Size :";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(26, 244);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(105, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Number of Request: ";
			// 
			// txtMinRequest
			// 
			this->txtMinRequest->Location = System::Drawing::Point(167, 241);
			this->txtMinRequest->Margin = System::Windows::Forms::Padding(2);
			this->txtMinRequest->Name = L"txtMinRequest";
			this->txtMinRequest->Size = System::Drawing::Size(135, 20);
			this->txtMinRequest->TabIndex = 13;
			this->txtMinRequest->TextChanged += gcnew System::EventHandler(this, &MainForm::txtMinRequest_TextChanged);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(501, 412);
			this->Controls->Add(this->txtMinRequest);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txSizeBf);
			this->Controls->Add(this->txNDev);
			this->Controls->Add(this->txNSrc);
			this->Controls->Add(this->btAuto);
			this->Controls->Add(this->btByStep);
			this->Controls->Add(this->btSave);
			this->Controls->Add(this->btSetDev);
			this->Controls->Add(this->btSetSrc);
			this->Controls->Add(this->label1);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btSetSrc_Click(System::Object^  sender, System::EventArgs^  e) {
		/// SET SOURCE LAMDA
		nSrc = Int32::Parse(txNSrc->Text);
		sources = gcnew array<MSource^>(nSrc);
		this->Hide();
		SMO::SetSrcForm^ formSrc = gcnew SetSrcForm();
		formSrc->ShowDialog();
		lamdaIst = formSrc->getLamda();
		this->Show();
	}
	private: System::Void btSetDev_Click(System::Object^  sender, System::EventArgs^  e) {
	// SET DEVICES BOUND
		nDev = Int32::Parse(txNDev->Text);
		devices = gcnew array<MDevice^>(nDev);
		this->Hide();
		SMO::SetDevForm^ formDev = gcnew SetDevForm();
		formDev->ShowDialog();
		lowerDev = formDev->getLower();
		upperDev = formDev->getUpper();
		this->Show();
	}
	private: System::Void btSave_Click(System::Object^  sender, System::EventArgs^  e) {
		// SAVE DATA
		sizeBf = Int32::Parse(txSizeBf->Text);
		minNRequest = Int32::Parse(txtMinRequest->Text);
		nDev = Int32::Parse(txNDev->Text);
		nSrc = Int32::Parse(txNSrc->Text);
	}
	private: System::Void btByStep_Click(System::Object^  sender, System::EventArgs^  e) {
		// RUN BY STEP
		
		for (int i = 0; i < nSrc; i++)
		{
			sources[i] = gcnew MSource( i + 1, lamdaIst);
		}
		for (int i = 0; i < nDev; i++)
		{
			devices[i] = gcnew MDevice( i + 1 ,lowerDev, upperDev);
		}

		ByStepForm^ stepForm = gcnew ByStepForm(sources, devices, sizeBf, minNRequest,nSrc);
		this->Hide();
		stepForm->ShowDialog();
		this->Show();
	}
	private: System::Void btAuto_Click(System::Object^  sender, System::EventArgs^  e) {
		// RUN AUTO
		for (int i = 0; i < nSrc; i++)
		{
			sources[i] = gcnew MSource( i + 1, lamdaIst);
			
		}
		for (int i = 0; i < nDev; i++)
		{
			devices[i] = gcnew MDevice( i + 1, lowerDev, upperDev);
		}
		AutoForm^ autoForm = gcnew AutoForm(sources, devices, sizeBf, minNRequest);
		this->Hide();
		autoForm->ShowDialog();
		this->Show();
		this->Show();
	}
private: System::Void txNSrc_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void txtMinRequest_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
