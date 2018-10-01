#pragma once
#include "Observer.h"

class LightDown : public Observer
{
public:
	LightDown();
	~LightDown();
	void SubscribeToObservable(Observable *o);
	void DoMyJob(int whatToDo, float *workArray, int workArraySize);

private:
	eWhatToDoCode myJobCode;
};

