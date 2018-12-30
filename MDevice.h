#include <cstdlib>
#include "MRequest.h"

ref class MDevice
{
public:
	MDevice(int id_, double lower_bound, double upper_bound);

	double getTOsvoboz();

	int getNumber();
	int getServed();
	bool isFree();
	double getKISP(); // коэффициент использрвания

	void serve(MRequest^ req);
	MRequest^ finalize();
	MRequest^ getRequest();
	int Src();
	int NReq();
private:
	int numReq;
	int numSrc;
	double lower_bound, upper_bound;
	int id_dev, nServed;
	double TOsvoboz, TObsl; // момент освобождения, момент обслуживания
	MRequest ^request = gcnew MRequest(0, 0, 0);
	double lamda;
	bool isFree_ = true;
};

