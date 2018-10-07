#pragma once
#include "Observable.h"

static const int numberOfStairs = 10;

class Observer
{
public:
	virtual void SubscribeToObservable(Observable *o) = 0;
	virtual void Unsubscribe(Observable *o) = 0;
	virtual void DoMyJob(Observable *o) = 0;
	static float arrayWithBrightnessValues[numberOfStairs];

protected:
	float myArray[numberOfStairs];

};

