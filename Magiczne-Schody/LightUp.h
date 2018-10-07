#pragma once
#include "Observer.h"

class LightUp : public Observer
{
public:
	LightUp();
	~LightUp();
	void SubscribeToObservable(Observable *o);
	void Unsubscribe(Observable *o);
	void DoMyJob(Observable *whoToldMeToDoMyJob);

private:
	int counter;
};

