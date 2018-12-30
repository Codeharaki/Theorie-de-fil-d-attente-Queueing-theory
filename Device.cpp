#include "MDevice.h"
#include <algorithm>

MDevice::MDevice( int id_, double lower_bound, double upper_bound)
{
	MDevice::lower_bound = lower_bound;
	MDevice::upper_bound = upper_bound;
	//MDevice::lamda = lamda;
	MDevice::id_dev = id_;
	TOsvoboz = 0;
	TObsl = 0;
	nServed = 0;
}

void MDevice::serve(MRequest^ req)
{
	numReq = req->getR_ID();
	numSrc = req->getID();
	request = req;
	double CTIME = (TOsvoboz > request->getTPOST()) ? TOsvoboz : request->getTPOST();
	//double TAYOB = (log((rand() % 50) + 1) - log(RAND_MAX)) / (-lamda);
	double TAYOB= ((double)(rand() % 100) / (double)RAND_MAX) * (upper_bound - lower_bound) + lower_bound;
	TOsvoboz = TAYOB + CTIME;
	isFree_ = false;
	TObsl += TAYOB;
	nServed++;

	request->setTBuf(CTIME - req->getTPOST());
	request->setTObsl(TAYOB);
	request->setTExit(TOsvoboz);
	request->setIdDev(id_dev);
}
int MDevice::NReq() {

	return numReq;
}

int MDevice::Src()
{
	return numSrc;
}
double MDevice::getTOsvoboz()
{
	return TOsvoboz;
}

int MDevice::getNumber()
{
	return id_dev;
}

int MDevice::getServed()
{
	return nServed;
}

bool MDevice::isFree()
{
	return isFree_;
}

double MDevice::getKISP()
{
	double ctime = (TOsvoboz > request->getTPOST()) ? TOsvoboz : request->getTPOST();
	return TObsl / (ctime + request->getTOG());
}

MRequest ^MDevice::finalize()
{
	isFree_ = true;
	return request;
}

MRequest ^MDevice::getRequest()
{
	return request;
}