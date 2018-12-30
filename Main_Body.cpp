#include "Run.h"

int get_minID_ist(array<MSource^> ^source)
{
	int minID_ist = 0;
	for (int i = 0; i < source->Length; i++)
	{
		if (source[i]->getTPost() < source[minID_ist]->getTPost())
			minID_ist = i;
    }
	return minID_ist;
}

int get_minID_prib(array<MDevice^> ^devices)
{
	int minID_prib = -1;

	for (int i = 0; i < devices->Length; i++)
		if (!devices[i]->isFree())
		{
			minID_prib = i;
			break;
		}

	if (minID_prib == -1)
		return minID_prib;

	for (int i = minID_prib; i < devices->Length; i++)
		if ((!devices[i]->isFree()) && (devices[i]->getTOsvoboz() < devices[minID_prib]->getTOsvoboz()))
			minID_prib = i;

	return minID_prib;

}

int get_IDFree_prib(array<MDevice^> ^devices)
{
	int freeID_prib = -1;

	for (int i = 0; i < devices->Length; i++)
	{
		if (devices[i]->isFree())

		{
			freeID_prib = i;
			break;
		}
	}

	return freeID_prib;
}

void run(array<MSource^> ^sources, array<MDevice^> ^devices, MBuffer ^buffer, int KMIN)
{
	int TKOL = 0;
	
	for (int i = 0; i < sources->Length; i++)
		sources[i]->makeNextPost(); // create the first request for ist

	while (true)
	{
		double sum = 0;
		for (int i = 0; i < sources->Length; i++) {
			sum+=sources[i]->getN_Generated(); // create the first request for ist
		}
		if (sum == KMIN) {
			break;
		}
		int minID_ist = get_minID_ist(sources);
		int minID_prib = get_minID_prib(devices);
		int idFree_prib = get_IDFree_prib(devices);

		if (buffer->isEmpty())
		{
			TKOL++;
			MRequest^ req = gcnew MRequest(minID_ist + 1, sources[minID_ist]->getN_Generated(), sources[minID_ist]->getTPost());
			buffer->putRequest(req); // put request to buffer
			sources[minID_ist]->makeNextPost(); // create next requuest

			//step by step
		}
		else if(idFree_prib != -1) {
			// take request from buffer
			MRequest^ req = buffer->popRequestServed();
			devices[idFree_prib]->serve(req);
		}
		else if (sources[minID_ist]->getTPost() < devices[minID_prib]->getTOsvoboz())
		{
			//generate new request and add to buffer
			TKOL++;
			MRequest^ req = gcnew MRequest(minID_ist + 1, sources[minID_ist]->getN_Generated(), sources[minID_ist]->getTPost());
			sources[minID_ist]->makeNextPost();

			if (buffer->isFull())
			{
				MRequest^ req_otk = buffer->popRequestDenied();
				sources[req_otk->getID() -1]->updateStatus(req_otk, false);

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
			sources[obr->getID() -1]->updateStatus(obr, true);
			devices[minID_prib]->serve(buffer->popRequestServed());
			//step by step
		}
	}
}