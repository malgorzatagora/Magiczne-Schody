#include "stdafx.h"
#include "LightUp.h"


LightUp::LightUp()
{
	for (int i = 0; i < numberOfStairs; i++)
	{
		this->myArray[i] = 0;
	}
	this->counter = 0;
}


LightUp::~LightUp()
{
	//todo: remove from observable's list of observers
}


void LightUp::SubscribeToObservable(Observable *o)
{
	o->RegisterNewObserver(this);
}

void LightUp::Unsubscribe(Observable *o)
{
	o->DeleteObserver(this);
}


void LightUp::DoMyJob(Observable *whoToldMeToDoMyJob)
{
	 //update my own array
		this->myArray[this->counter] = 100.0;

	
	//update shared array 
	for (int i = 0; i<numberOfStairs; i++)
	{
		if (this->myArray[i] > this->arrayWithBrightnessValues[i])
		{
			this->arrayWithBrightnessValues[i] = this->myArray[i];
		}
	} 

	this->counter++;

	//unsubscrive myself when work done
	if (numberOfStairs == this->counter)
	{
		this->Unsubscribe(whoToldMeToDoMyJob);
	}

}