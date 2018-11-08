#include "stdafx.h"
#include "LightUp.h"


LightUp::LightUp()
{
	this->counter = 0.0;
}


LightUp::~LightUp()
{
	//todo: remove from observable's list of observers
}


void LightUp::SubscribeToObservable(Observable *o)
{
	for (int i = 0; i < numberOfStairs; i++)
	{
		this->myArray[i] = 0;
	}
	this->counter = 0.0;
	o->RegisterNewObserver(this);
}

void LightUp::Unsubscribe(Observable *o)
{
	o->UnregisterObserver(this);
}

void LightUp::DoMyJob(Observable *whoToldMeToDoMyJob)
{
	//unsubscrive myself when work done
	if (this->counter > 100)
	{
		this->Unsubscribe(whoToldMeToDoMyJob);
	}
	else
	{
		//update my own array 
		for (int x = 0; x < numberOfStairs; x++)
		{
			this->myArray[x] = LinearFunction(x, -50.0 / 15.0, this->counter);
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