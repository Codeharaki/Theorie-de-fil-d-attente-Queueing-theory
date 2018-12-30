#pragma once
#include "MRequest.h"

ref class MBuffer
{
public:
	MBuffer(int sizeBf_);
	~MBuffer();

	void putRequest(MRequest^ req);
	MRequest^ popRequestServed();
	MRequest^ popRequestDenied();

	bool isFull();
	bool isEmpty();
	int getSize();

	System::Collections::Generic::List<MRequest^>^ getReqBuf();
	
private:
	int sizeBf, nFull;
	System::Collections::Generic::List<MRequest^> ^bufferReq;
	System::Collections::Generic::List<bool> ^statusBf;
};

