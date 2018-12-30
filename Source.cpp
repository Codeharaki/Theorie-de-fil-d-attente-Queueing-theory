#include "MSource.h"


MSource::MSource( const int id_src ,double lamda )
{
	MSource::nGenerated = 0;
	//MSource::lower_bound = lower_bound;
	//MSource::upper_bound = upper_bound;
	MSource::lamda = lamda;
	MSource::id_src = id_src;
	MSource::TPost = 0.0;

	reset();
}

void MSource::makeNextPost()
{
	//double time = (-1) / lamda * log((double) (rand()) / RAND_MAX); // Poisson
	double time= (log((rand() % 50) + 1) - log(RAND_MAX)) / (-lamda);
	//double time = ((double)(rand() % 100) / (double)RAND_MAX) * (upper_bound - lower_bound) + lower_bound;

	TPost = TPost + time;
	nGenerated++;
}

void MSource::updateStatus(MRequest ^request, bool isObrabotano)
{
	Kol++;
	if (isObrabotano){
		Kobs++;
		TOg += request->getTBuf() + request->getTObsl();
		TObsluz += request->getTObsl();
		TBuf += request->getTBuf();
		reqStatus->Add(gcnew RequestStats(request->getTObsl(), request->getTBuf()));
	}
	else {
		Otk++;
	}
}

void MSource::reset()
{
	TPost = 0;
	Kol = 0;
	Otk = 0;
	Kobs = 0;
	TOg = 0;
	TObsluz = 0;
	TBuf = 0;
	if (reqStatus)
		reqStatus->Clear();

	reqStatus = gcnew System::Collections::Generic::List<RequestStats^>();
}

double MSource::getTPost()
{
	return TPost;
}

void MSource::setTPost(double a)
{
	 TPost=a;
}

int MSource::getNumber()
{
	return id_src;
}

int MSource::getKol()
{
	return Kol;
}

int MSource::getOtk()
{
	return Otk;
}

int MSource::getKobs()
{
	return Kobs;
}

int MSource::getN_Generated()
{
	return nGenerated;
}
void MSource ::setN_generated(int b)
{
	nGenerated = b;
}
double MSource::getBOTK()
{
	return (double) Otk/ (double) Kol;
}

double MSource::getMTOG()
{
	return TOg / (double)Kobs;
}

double MSource::getTObsluz()
{
	return TObsluz / (double)Kobs;
}

double MSource::getTBuf()
{
	return TBuf / (double)Kobs;
}

double MSource::getDispTObsluz()
{
	double mean = getTObsluz();
	double sum2 = 0;
	for (int i = 0; i < reqStatus->Count; i++)
		sum2 += (reqStatus[i]->TObsluz - mean)*(reqStatus[i]->TObsluz - mean);
	double disp = sum2 / (reqStatus->Count - 1);
	return disp;
}

double MSource::getDispTbuf()
{
	double mean = getTBuf();
	double sum2 = 0;
	for (int i = 0; i <  reqStatus->Count; i++)
		sum2 += (reqStatus[i]->Tbuf - mean)*(reqStatus[i]->Tbuf - mean);
	double disp = sum2 / (reqStatus->Count - 1);
	return disp;
}
