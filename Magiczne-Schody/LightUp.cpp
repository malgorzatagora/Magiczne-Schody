#include "stdafx.h"
#include "LightUp.h"


LightUp::LightUp()
{
	this->myJobCode = LIGHT_UP;
}


LightUp::~LightUp()
{
	//todo: remowe from observable's list of observers
}


void LightUp::SubscribeToObservable(Observable *o)
{
	o->RegisterNewObserver(this);
}

void LightUp::DoMyJob(int whatToDo, float *workArray, int workArraySize)
{
	if(whatToDo == (this->myJobCode))
	{ 
		for (int i = 0; i < workArraySize; i++)
		{
			workArray[i] = i * 2.0;
		}
	}
}