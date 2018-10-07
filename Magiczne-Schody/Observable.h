#pragma once
#define NUMBER_OF_LIGHT_EFFECTS 20


class Observable
{
public:
	Observable();
	~Observable();
	void RegisterNewObserver(class Observer *o);
	int UnregisterObserver(class Observer *o);
	void UnregisterAllObservers(void);
	void NotifyObservers();
	int CheckWhatToDo();
	int CheckHowManyObserversRegistered();

private:
	class Observer *observersArray[NUMBER_OF_LIGHT_EFFECTS];
	int howManyRegisteredObservers;
};
