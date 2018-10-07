#pragma once
#include "Observer.h"

class TurnOff : public Observer
{
public:
	TurnOff();
	~TurnOff();
	void SubscribeToObservable(Observable *o);
	void Unsubscribe(Observable *o);
	void DoMyJob(Observable *whoToldMeToDoMyJob);

};

