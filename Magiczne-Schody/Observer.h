#pragma once
#include "Observable.h"

static const int numberOfStairs = 16;

class Observer
{
public:
	virtual void SubscribeToObservable(Observable *o) = 0;
	virtual void Unsubscribe(Observable *o) = 0;
	virtual void DoMyJob(Observable *o) = 0;
	static float arrayWithBrightnessValues[numberOfStairs];

protected:
	float myArray[numberOfStairs];
	double LinearFunction(int x, double a, double b);
	double SquareFunction(int x, double a, double b, double c);

};

