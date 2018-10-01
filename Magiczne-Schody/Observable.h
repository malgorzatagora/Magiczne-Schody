#pragma once
#define NUMBER_OF_LIGHT_EFFECTS 20

enum eWhatToDoCode
{
	LIGHT_UP = 10,
	LIGHT_DOWN = 11,
	TURN_OFF = 12
};

class Observable
{
public:
	Observable();
	~Observable();
	void RegisterNewObserver(class Observer *o);
	int DeleteObserver(class Observer *o);
	void NotifyObservers(float *workArray, int workArraySize);
	int CheckWhatToDo(int *infoArray, int index);
	int CheckHowManyObserversRegistered();

private:
	class Observer *observersArray[NUMBER_OF_LIGHT_EFFECTS];
	eWhatToDoCode whatToDo;
	int howManyRegisteredObservers;
};
