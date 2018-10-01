
#include "stdafx.h"
#include "CppUnitTest.h"
#include "Observer.h"
#include "LightUp.h"
#include "LightDown.h"
#include "TurnOff.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ObserverPatternTest
{
	bool testVar = 0;
	void TestCallback(void) {
		testVar = !testVar;
	}

	TEST_CLASS(ObserverPattern_TEST)
	{
	public:
		TEST_METHOD(OneBigTestToSplitLater)
		{
			int infoArray[3] = { 1,2,3 }; // 1-LightUp, 2-LightDown, 3-TurnOff
			const int workArraysize = 10;
			float workArray[workArraysize] = {};
			int numberOfObservers = 0;
			LightUp Observer1;
			LightDown Observer2;
			TurnOff Observer3;
			Observable Informer;

			Observer1.SubscribeToObservable(&Informer);
			Observer2.SubscribeToObservable(&Informer);
			Observer3.SubscribeToObservable(&Informer);

			numberOfObservers = Informer.CheckHowManyObserversRegistered();
			Assert::AreEqual(3, numberOfObservers);

			Informer.CheckWhatToDo(&infoArray[0], 0);
			Informer.NotifyObservers(&workArray[0], workArraysize);

			Assert::AreEqual(float(18), workArray[9]);

			Informer.CheckWhatToDo(&infoArray[0], 1);
			Informer.NotifyObservers(&workArray[0], workArraysize);

			Assert::AreEqual(float(20), workArray[0]);
			Assert::AreEqual(float(2), workArray[9]);

			Informer.CheckWhatToDo(&infoArray[0], 2);
			Informer.NotifyObservers(&workArray[0], workArraysize);

			Assert::AreEqual(float(0), workArray[9]);

			;

		}
	};
}