#pragma once
#include "Observer.h"

class TurnOff : public Observer
{
public:
	TurnOff();
	~TurnOff();
	void SubscribeToObservable(Observable *o);
	void DoMyJob(int whatToDo, float *workArray, int workArraySize);

private:
	eWhatToDoCode myJobCode;
};

