#include "stdafx.h"
#include "Observer.h"


Observable::Observable()
{
	this->howManyRegisteredObservers = 0;
}


Observable::~Observable()
{
}


void Observable::RegisterNewObserver(Observer *o)
{
	this->observersArray[howManyRegisteredObservers] = o;
	this->howManyRegisteredObservers++;
}

int Observable::DeleteObserver(Observer *o)
{
	int result;
	for (int i = 0; i < (this->howManyRegisteredObservers); i++)
	{
		if (o == observersArray[i])
		{
			result = 0;
			while (i < (this->howManyRegisteredObservers-1))
			{
				this->observersArray[i] = this->observersArray[i + 1];
				i++;
			}
			this->howManyRegisteredObservers--;
		}
		else { result = -1; }
	}
	return result;
}



void Observable::NotifyObservers(float *workArray, int workArraySize)
{
	for (int i = 0; i < (this->howManyRegisteredObservers); i++)
	{
		this->observersArray[i]->DoMyJob(this->whatToDo, workArray, workArraySize);
	}
}

int Observable::CheckWhatToDo(int *infoArray, int index)
{
	int result = 0;
	switch (infoArray[index])
	{
	default:
		result = -1;
		break;
	case 1:
		this->whatToDo = LIGHT_UP;
		break;
	case 2:
		this->whatToDo = LIGHT_DOWN;
		break;
	case 3:
		this->whatToDo = TURN_OFF;
		break;
	}
	return result;
}

int Observable::CheckHowManyObserversRegistered()
{
	return (this->howManyRegisteredObservers);
}