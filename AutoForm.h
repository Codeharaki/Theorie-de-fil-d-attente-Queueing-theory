#pragma once
#include "Run.h"

namespace SMO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for AutoForm
	/// </summary>
	public ref class AutoForm : public System::Windows::Forms::Form
	{
	private:
		array<MSource^> ^sources;
		array<MDevice^> ^devices;
		int minNRequest;
	private: System::Windows::Forms::DataGridView^  dataGridView_Dev;


		MBuffer^ buffer;
	public:
		AutoForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		AutoForm(array<MSource^> ^srcs, array<MDevice^> ^devs, int sizeBf, int NRmin)
		{
			InitializeComponent();
			sources = srcs;
			devices = devs;
			buffer = gcnew MBuffer(sizeBf);
			minNRequest = NRmin;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AutoForm()
		{
			if (components)
			{
				delete components;
			}
			if (sources)
				delete sources;
			if (devices)
				delete devices;
			if (buffer)
				delete buffer;
		}
	private: System::Windows::Forms::DataGridView^  dataGridView_Src;
	protected:

	protected:

	protected:
	private: System::Windows::Forms::Button^  btCancel;

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
			this->dataGridView_Src = (gcnew System::Windows::Forms::DataGridView());
			this->btCancel = (gcnew System::Windows::Forms::Button());
			this->dataGridView_Dev = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Src))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Dev))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView_Src
			// 
			this->dataGridView_Src->AllowUserToOrderColumns = true;
			this->dataGridView_Src->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_Src->Location = System::Drawing::Point(9, 10);
			this->dataGridView_Src->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView_Src->Name = L"dataGridView_Src";
			this->dataGridView_Src->RowTemplate->Height = 24;
			this->dataGridView_Src->Size = System::Drawing::Size(840, 266);
			this->dataGridView_Src->TabIndex = 0;
			this->dataGridView_Src->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AutoForm::dataGridView_Src_CellContentClick);
			// 
			// btCancel
			// 
			this->btCancel->Location = System::Drawing::Point(761, 514);
			this->btCancel->Margin = System::Windows::Forms::Padding(2);
			this->btCancel->Name = L"btCancel";
			this->btCancel->Size = System::Drawing::Size(91, 39);
			this->btCancel->TabIndex = 1;
			this->btCancel->Text = L"Cancel";
			this->btCancel->UseVisualStyleBackColor = true;
			this->btCancel->Click += gcnew System::EventHandler(this, &AutoForm::btCancel_Click);
			// 
			// dataGridView_Dev
			// 
			this->dataGridView_Dev->AllowUserToOrderColumns = true;
			this->dataGridView_Dev->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_Dev->Location = System::Drawing::Point(12, 294);
			this->dataGridView_Dev->Name = L"dataGridView_Dev";
			this->dataGridView_Dev->Size = System::Drawing::Size(440, 241);
			this->dataGridView_Dev->TabIndex = 2;
			// 
			// AutoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(863, 564);
			this->Controls->Add(this->dataGridView_Dev);
			this->Controls->Add(this->btCancel);
			this->Controls->Add(this->dataGridView_Src);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"AutoForm";
			this->Text = L"AutoForm";
			this->Load += gcnew System::EventHandler(this, &AutoForm::AutoForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Src))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Dev))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void AutoForm_Load(System::Object^  sender, System::EventArgs^  e) {
		// show result
		//srand(time(0));
		run(sources, devices, buffer, minNRequest);
		// create table dynamicaly
		DataTable^ tableSrc = gcnew DataTable();
		// add column name
		tableSrc->Columns->Add("Sources");
		tableSrc->Columns->Add("Requests");
		tableSrc->Columns->Add("P failure");
		tableSrc->Columns->Add("T in system");
		tableSrc->Columns->Add("T in Buffer");
		tableSrc->Columns->Add("    Mx    ");
		tableSrc->Columns->Add("Buffer Disp");
		tableSrc->Columns->Add("Service Disp");
		// add rows
		if (sources) {
			for (int i = 0; i < sources->Length; i++)
			{
				tableSrc->Rows->Add("Source" + sources[i]->getNumber(), sources[i]->getN_Generated(), sources[i]->getBOTK(), sources[i]->getTObsluz(),
					sources[i]->getTBuf(), sources[i]->getMTOG(), sources[i]->getDispTbuf(), sources[i]->getDispTObsluz());
			}
		}
		// show 
		dataGridView_Src->DataSource = tableSrc;
		dataGridView_Src->DataBindings;
		/////////////////////////////////////////
		// create table dynamicaly
		DataTable^ tableDev = gcnew DataTable();
		// add column name
		tableDev->Columns->Add("Devices");
		//tableDev->Columns->Add("Время");
		//tableDev->Columns->Add("Число заявок");
		tableDev->Columns->Add("K(util)");
		// add rows
		if (devices) {
			for (int i = 0; i < devices->Length; i++)
			{
				tableDev->Rows->Add("Device" + devices[i]->getNumber(), devices[i]->getKISP());
			}
		}
		// show 
		dataGridView_Dev->DataSource = tableDev;
		dataGridView_Dev->DataBindings;
	}
	private: System::Void btCancel_Click(System::Object^  sender, System::EventArgs^  e) {
		// cancel
		this->Close();
	}
	private: System::Void dataGridView_Src_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	}
};
}
