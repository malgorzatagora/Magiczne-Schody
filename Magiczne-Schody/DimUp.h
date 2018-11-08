#pragma once
#include "Observer.h"

class DimUp : public Observer
{
public:
	DimUp();
	~DimUp();
	void SubscribeToObservable(Observable *o);
	void Unsubscribe(Observable *o);
	void DoMyJob(Observable *whoToldMeToDoMyJob);

private:
	double counter;
};

