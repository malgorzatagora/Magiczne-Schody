#include "stdafx.h"
#include "TurnOff.h"


TurnOff::TurnOff()
{
	for (int i = 0; i < numberOfStairs; i++)
	{
		this->myArray[i] = 0;
	}
}


TurnOff::~TurnOff()
{
	//todo: remowe from observable's list of observers
}


void TurnOff::SubscribeToObservable(Observable *o)
{
	o->RegisterNewObserver(this);
}

void TurnOff::Unsubscribe(Observable *o)
{
	o->DeleteObserver(this);
}

void TurnOff::DoMyJob(Observable *whoToldMeToDoMyJob)
{
	//update shared array 
	for (int i = 0; i < numberOfStairs; i++)
	{
		this->arrayWithBrightnessValues[i] = 0;
	}

	//unsubscrive myself when work done
	this->Unsubscribe(whoToldMeToDoMyJob);
}
	

