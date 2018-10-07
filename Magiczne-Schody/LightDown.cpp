#include "stdafx.h"
#include "LightDown.h"


LightDown::LightDown()
{
	for (int i = 0; i < numberOfStairs; i++)
	{
		this->myArray[i] = 100.0;
	}
	this->counter = 0;
}


LightDown::~LightDown()
{
	//todo: remowe from observable's list of observers
}


void LightDown::SubscribeToObservable(Observable *o)
{
	o->RegisterNewObserver(this);
}

void LightDown::Unsubscribe(Observable *o)
{
	o->DeleteObserver(this);
}

void LightDown::DoMyJob(Observable *whoToldMeToDoMyJob)
{
	this->counter++;
	//update my own array
	for (int i = 1; i < numberOfStairs; i++)
	{
		this->myArray[numberOfStairs-i] = this->myArray[numberOfStairs - i - 1];
	}
	this->myArray[0] = static_cast<float>(100 - (this->counter)* 10);

	//update shared array 
	for (int i = 0; i < numberOfStairs; i++)
	{
		if (this->myArray[i] < this->arrayWithBrightnessValues[i])
		{
			this->arrayWithBrightnessValues[i] = this->myArray[i];
		}
	}

	//unsubscrive myself when work done
	if (numberOfStairs == this->counter)
	{
		this->Unsubscribe(whoToldMeToDoMyJob);
	}
}