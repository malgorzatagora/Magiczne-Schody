
#include "stdafx.h"
#include "CppUnitTest.h"
#include "Observer.h"
#include "LightUp.h"
#include "LightDown.h"
#include "TurnOff.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ObserverPatternTest
{
	TEST_CLASS(ObserverPattern_TEST)
	{
	public:
		TEST_METHOD(Subscribing)
		{
			int numberOfObservers = 0;
			LightUp Observer1;
			LightDown Observer2;
			TurnOff Observer3;
			Observable Notifier;

			Observer1.SubscribeToObservable(&Notifier);
			Observer2.SubscribeToObservable(&Notifier);
			Observer3.SubscribeToObservable(&Notifier);

			numberOfObservers = Notifier.CheckHowManyObserversRegistered();
			Assert::AreEqual(3, numberOfObservers);
		}

		TEST_METHOD(NotSubscribingIfAlreadySubsribed)
		{
			int numberOfObservers = 0;
			LightUp Observer1;
			LightDown Observer2;
			TurnOff Observer3;
			Observable Notifier;

			Observer1.SubscribeToObservable(&Notifier);
			Observer2.SubscribeToObservable(&Notifier);
			Observer3.SubscribeToObservable(&Notifier);
			Observer3.SubscribeToObservable(&Notifier);
			Observer1.SubscribeToObservable(&Notifier);

			numberOfObservers = Notifier.CheckHowManyObserversRegistered();
			Assert::AreEqual(3, numberOfObservers);
		}


		TEST_METHOD(Unsubscribing)
		{
			int numberOfObservers = 0;
			LightDown Observer1;
			LightUp Observer2;
			TurnOff Observer3;
			Observable Notifier;

			Observer1.SubscribeToObservable(&Notifier);
			Observer2.SubscribeToObservable(&Notifier);
			Observer3.SubscribeToObservable(&Notifier);

			Observer1.Unsubscribe(&Notifier);
			Observer3.Unsubscribe(&Notifier);

			numberOfObservers = Notifier.CheckHowManyObserversRegistered();
			Assert::AreEqual(1, numberOfObservers);

			Notifier.NotifyObservers();
			Notifier.NotifyObservers();

			Assert::AreEqual(static_cast<float>(0.4), Observer::arrayWithBrightnessValues[0]);
		}


		TEST_METHOD(UnregisterAll)
		{
			int numberOfObservers = 0;
			TurnOff Observer1;
			LightDown Observer2;
			LightUp Observer3;
			Observable Notifier;
			Observer::arrayWithBrightnessValues[0] = 0;

			Observer1.SubscribeToObservable(&Notifier);
			Observer2.SubscribeToObservable(&Notifier);
			Observer3.SubscribeToObservable(&Notifier);

			Notifier.UnregisterAllObservers();

			numberOfObservers = Notifier.CheckHowManyObserversRegistered();
			Assert::AreEqual(0, numberOfObservers);
			Assert::AreEqual(-1, Notifier.UnregisterObserver(&Observer2));

			Notifier.NotifyObservers();

			Assert::AreEqual(static_cast<float>(0), Observer::arrayWithBrightnessValues[0]);
		}


		TEST_METHOD(NotifyingOneObserver)
		{
			LightUp Observer1;
			Observable Notifier;

			Observer1.SubscribeToObservable(&Notifier);

			Notifier.NotifyObservers();

			Assert::AreEqual(static_cast<float>(0), Observer::arrayWithBrightnessValues[0]);
			Assert::AreEqual(static_cast<float>(0), Observer::arrayWithBrightnessValues[3]);

			Notifier.NotifyObservers();

			Assert::AreEqual(static_cast<float>(0.4), Observer::arrayWithBrightnessValues[0]);
			Assert::AreEqual(static_cast<float>(0), Observer::arrayWithBrightnessValues[3]);
			Assert::AreEqual(static_cast<float>(0), Observer::arrayWithBrightnessValues[15]);

		}

		TEST_METHOD(NotifyingManyObservers)
		{
			LightUp Observer1;
			LightDown Observer2;
			TurnOff Observer3;
			Observable Notifier;

			Observer1.SubscribeToObservable(&Notifier);

			Notifier.NotifyObservers(); //0 step = 0%
			Notifier.NotifyObservers(); //0 step = 0.4%
			Notifier.NotifyObservers(); //0 step = 0.8%
			Notifier.NotifyObservers(); //0 step = 1.2%
			Notifier.NotifyObservers(); //0 step = 1.6%

			Assert::AreEqual(static_cast<float>(1.6), Observer::arrayWithBrightnessValues[0]);
			
			Observer2.SubscribeToObservable(&Notifier); //enable lighting down

			Notifier.NotifyObservers(); //0 step = 2.0%, 15th step =  0%
			Notifier.NotifyObservers(); //0 step = 2.4%, 15th step =  0.4%

			Assert::AreEqual(static_cast<float>(0.4), Observer::arrayWithBrightnessValues[15]);
			Assert::AreEqual(static_cast<float>(2.4), Observer::arrayWithBrightnessValues[0]);


			Observer3.SubscribeToObservable(&Notifier); //enable turnong off all steps

			Observer1.Unsubscribe(&Notifier);// turning off ligthing up
			Notifier.NotifyObservers(); //all steps 0%

			Assert::AreEqual(static_cast<float>(0), Observer::arrayWithBrightnessValues[0]);
			Assert::AreEqual(static_cast<float>(0), Observer::arrayWithBrightnessValues[9]);
		}

	};
}