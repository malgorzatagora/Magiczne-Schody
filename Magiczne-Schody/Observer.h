#pragma once
#include "Observable.h"

class Observer
{
public:
	virtual void SubscribeToObservable(Observable *o) = 0;
	virtual void DoMyJob(int whatToDo, float *workArray, int workArraySize) = 0;

};

