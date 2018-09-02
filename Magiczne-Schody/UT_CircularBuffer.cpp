/*******************************************************
* Copyright (C) 2018 Malgorzata Gora <gora.malgorzata.b@gmail.com>
*
* This file is part of  project Magiczne Schody.
*
* Project Magiczne Schody can not be copied and/or distributed without the express
* permission of Malgorzata Gora <gora.malgorzata.b@gmail.com>
*
* Unit tests for CircularBuffer class
*******************************************************/

#include "stdafx.h"
#include "CppUnitTest.h"
#include "CircularBuffer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CircBuffer_TEST
{
	bool testVar = 0;
	void TestCallback(void) {
		testVar = !testVar;
	}

	TEST_CLASS(CircularBuffer_TEST)
	{
	public:
		TEST_METHOD(AddingElements)
		{
			char testArray[10] = {'a', 'b', 'c', 'd', '\n', 'e', 'f', 'g', 'h', 'i'};
			CircularBuffer testBuffer(10, &TestCallback);
			for (int i = 0; i < 10; i++) {
				Assert::AreEqual(static_cast<int>(SUCCESS), static_cast<int>(testBuffer.AddCharacter(testArray[i])));
			}
			Assert::AreEqual('a', testBuffer.GetElement(0));
			Assert::AreEqual(TERMINATOR, testBuffer.GetElement(4));
			Assert::AreEqual('i', testBuffer.GetElement(9));
			Assert::AreEqual(static_cast<int>(BUFFER_FULL), static_cast<int>(testBuffer.AddCharacter('X')));
		}

		TEST_METHOD(AddingElementsBuffNotFull)
		{
			Assert::AreEqual(1,1);
		}
		
		TEST_METHOD(CallbackFunction)
		{
			testVar = 0;
			CircularBuffer testBuffer(10, &TestCallback);
			testBuffer.AddCharacter('A');
			Assert::AreEqual(static_cast < int>(0), static_cast<int>(testVar));
			testBuffer.AddCharacter('\n');
			Assert::AreEqual(static_cast <int>(1), static_cast<int>(testVar));
			testBuffer.AddCharacter('B');
			Assert::AreEqual(static_cast <int>(1), static_cast<int>(testVar));
			testBuffer.AddCharacter('\n');
			Assert::AreEqual(static_cast <int>(0), static_cast<int>(testVar));
		}

		/*TEST_METHOD(AddingElementsBuffFull)
		{
			
		}

		TEST_METHOD(GettingCommandWhenAvailable)
		{

		}

		TEST_METHOD(GettingCommandWhenBufferEmpty)
		{

		}*/
	};
}