#pragma once
#include "Observer.h"

class LightDown : public Observer
{
public:
	LightDown();
	~LightDown();
	void SubscribeToObservable(Observable *o);
	void Unsubscribe(Observable *o);
	void DoMyJob(Observable *whoToldMeToDoMyJob);

private:
	double counter;
};

