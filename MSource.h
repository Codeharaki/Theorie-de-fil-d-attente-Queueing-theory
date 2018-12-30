#pragma once
#include <cstdlib>
#include "MRequest.h"
#include "RequestStats.h"

ref class MSource
{
public:
	MSource(const int id_src, double lamda);

	void makeNextPost(); // Post - поступление в буфер
	void updateStatus(MRequest ^request, bool isObrabotano);
	void reset();

	double getTPost();
	int getNumber();
	int getKol();
	int getOtk();
	int getKobs();
	int getN_Generated();
	double getBOTK(); // вероятность отказа
	double getMTOG(); // мат. ожидание заявки в буфере
	double getTObsluz();
	double getTBuf();
	double getDispTObsluz();
	double getDispTbuf();
	void setTPost(double a);
	void setN_generated(int b);
private:
	double lamda;
	double lower_bound, upper_bound;
	double TPost; // TPost - время поступление в буфер
	int id_src, Kol, Otk, Kobs; //  общее кол заявок, кол отказов, кол обслуж.
	int nGenerated;
	double TOg, TObsluz, TBuf; // общее время ожид, обсл, в буфере

	System::Collections::Generic::List<RequestStats^> ^reqStatus;
};
