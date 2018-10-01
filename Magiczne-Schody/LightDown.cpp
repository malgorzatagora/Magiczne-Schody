#include "stdafx.h"
#include "LightDown.h"


LightDown::LightDown()
{
	this->myJobCode = LIGHT_DOWN;
}


LightDown::~LightDown()
{
	//todo: remowe from observable's list of observers
}


void LightDown::SubscribeToObservable(Observable *o)
{
	o->RegisterNewObserver(this);
}

void LightDown::DoMyJob(int whatToDo, float *workArray, int workArraySize)
{
	if (whatToDo == (this->myJobCode))
	{
		for (int i = 0; i < workArraySize; i++)
		{
			workArray[i] = (workArraySize - i) * 2.0;
		}
	}
}