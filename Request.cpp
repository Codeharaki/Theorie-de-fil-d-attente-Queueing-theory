#include "MRequest.h"



MRequest::MRequest(int id_, int Rid, double tpost_)
{
	id = id_;
	r_id = Rid;
	TPost = tpost_;
	Tog = 0.0;
}

int MRequest::getID()
{
	return id;
}

double MRequest::getTPOST()
{
	return TPost;
}

void MRequest::setTBuf(double time)
{
	TBuf = time;
	Tog += TBuf;
}
void MRequest::setTObsl(double time)
{
	TObsl = time;
	Tog += TObsl;
}
void MRequest::setTExit(double time)
{
	TExit = time;
}
void MRequest::setIdDev(int devID)
{
	idDev = devID;
}
double MRequest::getTBuf()
{
	return TBuf;
}
double MRequest::getTObsl()
{
	return TObsl;
}

double MRequest::getTOG()
{
	return Tog;
}

double MRequest::getTExit() 
{
	return TExit;
}

int MRequest::getDevId()
{
	return idDev;
}

int MRequest::getR_ID()
{
	return r_id;
}

