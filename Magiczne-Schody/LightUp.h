#pragma once
#include "Observer.h"

class LightUp : public Observer
{
public:
	LightUp();
	~LightUp();
	void SubscribeToObservable(Observable *o);
	void DoMyJob(int whatToDo, float *workArray, int workArraySize);

private:
	eWhatToDoCode myJobCode;
};

