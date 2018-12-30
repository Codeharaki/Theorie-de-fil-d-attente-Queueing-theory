#pragma once
#include <cstdlib>
#include "MRequest.h"
#include "RequestStats.h"

ref class MSource
{
public:
	MSource(const int id_src, double lamda);

	void makeNextPost(); // Post - ����������� � �����
	void updateStatus(MRequest ^request, bool isObrabotano);
	void reset();

	double getTPost();
	int getNumber();
	int getKol();
	int getOtk();
	int getKobs();
	int getN_Generated();
	double getBOTK(); // ����������� ������
	double getMTOG(); // ���. �������� ������ � ������
	double getTObsluz();
	double getTBuf();
	double getDispTObsluz();
	double getDispTbuf();
	void setTPost(double a);
	void setN_generated(int b);
private:
	double lamda;
	double lower_bound, upper_bound;
	double TPost; // TPost - ����� ����������� � �����
	int id_src, Kol, Otk, Kobs; //  ����� ��� ������, ��� �������, ��� ������.
	int nGenerated;
	double TOg, TObsluz, TBuf; // ����� ����� ����, ����, � ������

	System::Collections::Generic::List<RequestStats^> ^reqStatus;
};
