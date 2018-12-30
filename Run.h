#pragma once
#include "MBuffer.h"
#include "MSource.h"
#include "MDevice.h"
#include <ctime>


int get_minID_ist(array<MSource^> ^source); // ist has min tpost
int get_minID_prib(array<MDevice^> ^devices); // pribor has min tsvobod
int get_IDFree_prib(array<MDevice^> ^devices);
void run(array<MSource^> ^sources, array<MDevice^> ^devices, MBuffer^ bfr, int KMIN);

