#pragma once
#include "MBuffer.h"
#include "Run.h"
namespace SMO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ByStepForm
	/// </summary>
	public ref class ByStepForm : public System::Windows::Forms::Form
	{
	private:
		array<MDevice^> ^devices;
		array<MSource^> ^sources;
		int sizeBuffer;
		int minNRequest;
		int Src;
		int count;
		bool passed,passed_2;
		array<double> ^bval;

		MBuffer ^buffer;
		DataTable^ tableBuffer;
		DataTable^ tableCalendar;
	public:
		ByStepForm(void)
		{
			
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		ByStepForm(array<MSource^> ^srcs, array<MDevice^> ^devs, int sizeBF, int NRmin , int nSrc)
		{
			InitializeComponent();
			sources = srcs;
			devices = devs;
			Src = nSrc;
			sizeBuffer = sizeBF;
			buffer = gcnew MBuffer(sizeBF);
			//srand(time(0));
			minNRequest = NRmin;
			count = 0;
			passed = false;
			passed_2 = false;
			bval = gcnew array<double>(30);

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ByStepForm()
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
			if (tableBuffer)
				delete tableBuffer;
			if (tableCalendar)
				delete tableCalendar;
		}
	private: System::Windows::Forms::DataGridView^  dataGridView_Calendar;
	private: System::Windows::Forms::DataGridView^  dataGridView_Buffer;

	private: System::Windows::Forms::Button^  btCancel;
	private: System::Windows::Forms::Button^  btNext;
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
			this->dataGridView_Calendar = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView_Buffer = (gcnew System::Windows::Forms::DataGridView());
			this->btCancel = (gcnew System::Windows::Forms::Button());
			this->btNext = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Calendar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Buffer))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView_Calendar
			// 
			this->dataGridView_Calendar->AllowUserToOrderColumns = true;
			this->dataGridView_Calendar->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_Calendar->Location = System::Drawing::Point(11, 11);
			this->dataGridView_Calendar->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dataGridView_Calendar->Name = L"dataGridView_Calendar";
			this->dataGridView_Calendar->RowTemplate->Height = 24;
			this->dataGridView_Calendar->Size = System::Drawing::Size(445, 408);
			this->dataGridView_Calendar->TabIndex = 0;
			this->dataGridView_Calendar->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ByStepForm::dataGridView_Calendar_CellContentClick);
			// 
			// dataGridView_Buffer
			// 
			this->dataGridView_Buffer->AllowUserToOrderColumns = true;
			this->dataGridView_Buffer->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_Buffer->Location = System::Drawing::Point(476, 10);
			this->dataGridView_Buffer->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dataGridView_Buffer->Name = L"dataGridView_Buffer";
			this->dataGridView_Buffer->RowTemplate->Height = 24;
			this->dataGridView_Buffer->Size = System::Drawing::Size(444, 408);
			this->dataGridView_Buffer->TabIndex = 1;
			// 
			// btCancel
			// 
			this->btCancel->Location = System::Drawing::Point(838, 442);
			this->btCancel->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btCancel->Name = L"btCancel";
			this->btCancel->Size = System::Drawing::Size(82, 29);
			this->btCancel->TabIndex = 2;
			this->btCancel->Text = L"Cancel";
			this->btCancel->UseVisualStyleBackColor = true;
			this->btCancel->Click += gcnew System::EventHandler(this, &ByStepForm::btCancel_Click);
			// 
			// btNext
			// 
			this->btNext->Location = System::Drawing::Point(724, 442);
			this->btNext->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btNext->Name = L"btNext";
			this->btNext->Size = System::Drawing::Size(80, 29);
			this->btNext->TabIndex = 3;
			this->btNext->Text = L"Next Step";
			this->btNext->UseVisualStyleBackColor = true;
			this->btNext->Click += gcnew System::EventHandler(this, &ByStepForm::btNext_Click);
			// 
			// ByStepForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(932, 481);
			this->Controls->Add(this->btNext);
			this->Controls->Add(this->btCancel);
			this->Controls->Add(this->dataGridView_Buffer);
			this->Controls->Add(this->dataGridView_Calendar);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"ByStepForm";
			this->Text = L"ByStepForm";
			this->Load += gcnew System::EventHandler(this, &ByStepForm::ByStepForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Calendar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Buffer))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		
	private: System::Void createCalendar() {
		// create table dynamicaly
		tableCalendar = gcnew DataTable();
		// add columns
		tableCalendar->Columns->Add("Событие");
		tableCalendar->Columns->Add("Время");
		tableCalendar->Columns->Add("Число заявок");
		tableCalendar->Columns->Add("Число отказов");
		// add rows
		if (sources) {
			for (int i = 0; i < sources->Length; i++)
			{
				tableCalendar->Rows->Add("И" + sources[i]->getNumber(), sources[i]->getTPost(),//+ sources[i]->getTObsluz() + sources[i]->getTBuf(), //+ sources[i]->getMTOG(), 
					sources[i]->getN_Generated(), sources[i]->getOtk());
				    
			}

			for (int i = 0; i < devices->Length; i++)
			{
				tableCalendar->Rows->Add("П" + devices[i]->getNumber(), devices[i]->getTOsvoboz(), devices[i]->getServed(), "И"+devices[i]->Src() + " З"+(devices[i]->NReq()));
			}
		}
		// show 
		dataGridView_Calendar->DataSource = tableCalendar;
		dataGridView_Calendar->DataBindings;
	}
	private: System::Void createResBuffer() {
		// create table dynamicaly
		tableBuffer = gcnew DataTable();
		// add column name
		tableBuffer->Columns->Add("Позиция");
		tableBuffer->Columns->Add("Время");
		tableBuffer->Columns->Add("Источник");
		tableBuffer->Columns->Add("Заявка");
		// add rows
		if (buffer) {
			System::Collections::Generic::List<MRequest^> ^reqInbf = buffer->getReqBuf();
			for (int i = 0; i < reqInbf->Count; i++)
			{
				tableBuffer->Rows->Add((i+1), reqInbf[i]->getTPOST(), reqInbf[i]->getID(), reqInbf[i]->getR_ID());
			}
		}
		// show 
		dataGridView_Buffer->DataSource = tableBuffer;
		dataGridView_Buffer->DataBindings;
	}
	
	private: System::Void btCancel_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	private: System::Void btNext_Click(System::Object^  sender, System::EventArgs^  e)
	{
		int minID_ist = 0;
		// this show next step
		// run step
		if (count < Src)
		{
			if (passed == false)
				for (int i = 0; i < Src; i++)
				{
					sources[i]->makeNextPost();
				}
			passed = true;

			if (passed_2 == false) 
				for (int i = 0; i < Src; i++)
				{
					bval[i] = sources[i]->getTPost();
				}
			
			 minID_ist = 0;
			for (int i = 1; i < Src; i++)
			{
				if (bval[i] < bval[minID_ist] )
					minID_ist = i;
			}
			//////Put just one element and others to be shown with next button
			if (passed_2 == false) {
				for (int i = 0; i < Src; i++)
				{
					bval[i] = sources[i]->getTPost();
					if (i != minID_ist) {
						sources[i]->setTPost(0);
						sources[i]->setN_generated(0);
					}
					
				}
				passed_2 = true; goto lab1;
			} 
			sources[minID_ist]->setTPost(bval[minID_ist]);
			sources[minID_ist]->setN_generated(1);
		    
		lab1: 
			int az=0;
			for (int i = 0; i < Src; i++)
			{
				if (sources[i]->getTPost()==0) {
					az -= 1;
				}
			}
			if (az == 0)count = Src;
		}
		else {
			 minID_ist = get_minID_ist(sources);
		}
		  int minID_prib = get_minID_prib(devices);
			int idFree_prib = get_IDFree_prib(devices);

			if (buffer->isEmpty())
			{
				MRequest^ req = gcnew MRequest(minID_ist + 1, sources[minID_ist]->getN_Generated() , sources[minID_ist]->getTPost());
				buffer->putRequest(req); // put request to buffer
				sources[minID_ist]->makeNextPost(); // create next requuest
				bval[minID_ist] = 1000;

																						//step by step
			}
			else if (idFree_prib != -1) {
				// take request from buffer
				MRequest^ req = buffer->popRequestServed();
				devices[idFree_prib]->serve(req);
			}
			else if (sources[minID_ist]->getTPost() < devices[minID_prib]->getTOsvoboz())
			{
				//generate new request and add to buffer
				MRequest^ req = gcnew MRequest(minID_ist + 1, sources[minID_ist]->getN_Generated() + 1, sources[minID_ist]->getTPost());
				sources[minID_ist]->makeNextPost();
				bval[minID_ist] = 1000;

				if (buffer->isFull())
				{
					MRequest^ req_otk = buffer->popRequestDenied();
					bval[req_otk->getID() - 1] = 1000;
					sources[req_otk->getID() - 1]->updateStatus(req_otk, false);
					

					buffer->putRequest(req);

					// step_by_step
				}
				else
				{
					buffer->putRequest(req);
					// step_by_step
				}
			}
			else {
				MRequest^ obr = devices[minID_prib]->finalize();
				sources[obr->getID() - 1]->updateStatus(obr, true);
				devices[minID_prib]->serve(buffer->popRequestServed());
				//step by step
			}

		
		
		////////////
		createCalendar();
		createResBuffer();
	}
	private: System::Void ByStepForm_Load(System::Object^  sender, System::EventArgs^  e) {
	 // the first step
	//	srand(time(0));
		createCalendar();
		createResBuffer();
	}
private: System::Void dataGridView_Calendar_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
};
}
