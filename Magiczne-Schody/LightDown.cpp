#include "stdafx.h"
#include "LightDown.h"


LightDown::LightDown()
{
	this->counter = -50;
}


LightDown::~LightDown()
{
	//todo: remowe from observable's list of observers
}


void LightDown::SubscribeToObservable(Observable *o)
{
	for (int i = 0; i < numberOfStairs; i++)
	{
		this->myArray[i] = 0;
	}
	this->counter = -50;
	o->RegisterNewObserver(this);
}

void LightDown::Unsubscribe(Observable *o)
{
	o->UnregisterObserver(this);
}

void LightDown::DoMyJob(Observable *whoToldMeToDoMyJob)
{
	//unsubscrive myself when work done
	if (50 <= this->counter)
	{
		this->Unsubscribe(whoToldMeToDoMyJob);
	}
	else
	{
		//update my own array 
		for (int x = 0; x < numberOfStairs; x++)
		{
			this->myArray[x] = LinearFunction(x, 50.0 / 15.0, this->counter);
		}

		//update shared array 
		for (int i = 0; i < numberOfStairs; i++)
		{
			if (this->myArray[i] > this->arrayWithBrightnessValues[i])
			{
				this->arrayWithBrightnessValues[i] = this->myArray[i];
			}
		}

		this->counter += 0.4;
	}

}