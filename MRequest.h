#pragma once

ref class MRequest
{
public:
	MRequest(int id_, int Rid, double tpost_);

	void setTBuf(double time);
	void setTObsl(double time);
	void setTExit(double time);
	void setIdDev(int devID);

	double getTBuf();
	double getTObsl();
	double getTOG();
	double getTExit();
	int getDevId();
	int getR_ID();

	int getID();
	double getTPOST();
	int id;
private:
	int r_id, Tog;
	double TPost;
	double TBuf, TObsl, TExit;
	int idDev;
};

