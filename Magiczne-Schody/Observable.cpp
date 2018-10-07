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
	bool alreadySubscribed = 0;
	for (int i = 0; i < (this->howManyRegisteredObservers); i++)
	{
		if (o == this->observersArray[i])
		{
			alreadySubscribed = 1;
		}
	}
	if (alreadySubscribed == 0) {
		this->observersArray[howManyRegisteredObservers] = o;
		this->howManyRegisteredObservers++;
	}
}

int Observable::UnregisterObserver(Observer *o)
{
	int result = -1;
	for (int i = 0; i < (this->howManyRegisteredObservers); i++)
	{
		if (o == this->observersArray[i])
		{
			result = 0;
			while (i < (this->howManyRegisteredObservers-1))
			{
				this->observersArray[i] = this->observersArray[i + 1];
				i++;
			}
			this->howManyRegisteredObservers--;
			break;
		}
		else { result = -1; }
	}
	
	return result;
}

void Observable::UnregisterAllObservers(void)
{
	this->howManyRegisteredObservers = 0;
}



void Observable::NotifyObservers()
{
	for (int i = 0; i < (this->howManyRegisteredObservers); i++)
	{
		this->observersArray[i]->DoMyJob(this);
	}
}

int Observable::CheckWhatToDo()
{
	int result = 1;
	return result;
}

int Observable::CheckHowManyObserversRegistered()
{
	return (this->howManyRegisteredObservers);
}