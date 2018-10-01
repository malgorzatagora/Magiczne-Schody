#include "stdafx.h"
#include "TurnOff.h"


TurnOff::TurnOff()
{
	this->myJobCode = TURN_OFF;
}


TurnOff::~TurnOff()
{
	//todo: remowe from observable's list of observers
}


void TurnOff::SubscribeToObservable(Observable *o)
{
	o->RegisterNewObserver(this);
}

void TurnOff::DoMyJob(int whatToDo, float *workArray, int workArraySize)
{
	if (whatToDo == (this->myJobCode))
	{
		for (int i = 0; i < workArraySize; i++)
		{
			workArray[i] = 0;
		}
	}
}