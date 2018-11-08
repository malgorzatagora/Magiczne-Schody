#include "stdafx.h"
#include "DimUp.h"


DimUp::DimUp()
{
	this->counter = 0.0;
}


DimUp::~DimUp()
{
	//todo: remove from observable's list of observers
}


void DimUp::SubscribeToObservable(Observable *o)
{
	for (int i = 0; i < numberOfStairs - 1; i++)
	{
		this->myArray[i] = 0;
	}
	this->counter = 50.0;
	o->RegisterNewObserver(this);
}

void DimUp::Unsubscribe(Observable *o)
{
	o->UnregisterObserver(this);
}

void DimUp::DoMyJob(Observable *whoToldMeToDoMyJob)
{
	//unsubscrive myself when work done
	if (this->counter < -100)
	{
		this->Unsubscribe(whoToldMeToDoMyJob);
	}
	else
	{
		//update my own array 
		for (int x = 0; x < numberOfStairs - 1; x++)
		{
			this->myArray[x] = LinearFunction(x, 50.0 / 15.0, this->counter);
		}

		//update shared array 
		for (int i = 0; i < numberOfStairs; i++)
		{
			if (this->myArray[i] < this->arrayWithBrightnessValues[i])
			{
				this->arrayWithBrightnessValues[i] = this->myArray[i];
			}
		}

		this->counter -= 0.4;
	}

}