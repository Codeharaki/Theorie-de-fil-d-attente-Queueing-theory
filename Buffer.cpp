#include "MBuffer.h"



MBuffer::MBuffer(int sizeBf_)
{
	MBuffer::sizeBf = sizeBf_;
	bufferReq = gcnew System::Collections::Generic::List<MRequest^>(sizeBf);
	statusBf = gcnew System::Collections::Generic::List<bool>(sizeBf);
	for (int i = 0; i < sizeBf; i++)
	{
		bufferReq->Add(gcnew MRequest(0, 0, 0));
		statusBf->Add(false);
	}
	nFull = 0;
}

MBuffer::~MBuffer()
{
	if (bufferReq)
		delete bufferReq;
	if (statusBf)
		delete statusBf;
}

void MBuffer::putRequest(MRequest^ req)
{
	if (!isFull()) {
		int idFree = 0;
		while (statusBf[idFree] != false)
			idFree++;

		statusBf[idFree] = true;
		bufferReq[idFree] = req;
		nFull++;
	}
	else {
		// Buffer is full
	}
}

MRequest^ MBuffer::popRequestServed()
{
	int idLast = 0;
	for (int i = 0; i < sizeBf; i++)
	{
		if (bufferReq[i]->getTPOST() > bufferReq[idLast]->getTPOST())
			idLast = i;
	}

	MRequest^ temp = bufferReq[idLast];
	bufferReq[idLast] = gcnew MRequest(0, 0, 0);
	statusBf[idLast] = false;
	nFull--;
	return temp;
}

MRequest^ MBuffer::popRequestDenied()
{
	int idOld = 0;
	for (int i = 0; i < sizeBf; i++)
	{
		if (bufferReq[i]->getTPOST() < bufferReq[idOld]->getTPOST())
			idOld = i;
	}

	MRequest^ temp = bufferReq[idOld];
	bufferReq[idOld] = gcnew MRequest(0, 0, 0);
	statusBf[idOld] = false;
	nFull--;
	return temp;
}

bool MBuffer::isFull()
{
	return (nFull == sizeBf);
}

bool MBuffer::isEmpty()
{
	return  (nFull == 0);
}

int MBuffer::getSize()
{
	return sizeBf;
}

System::Collections::Generic::List<MRequest^>^ MBuffer::getReqBuf()
{
	return bufferReq;
}