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
		
		TEST_METHOD(CallbackFunction)
		{
			testVar = 0;
			CircularBuffer testBuffer(10, &TestCallback);
			testBuffer.AddCharacter('A');
			Assert::AreEqual(static_cast <int>(0), static_cast<int>(testVar));
			testBuffer.AddCharacter(TERMINATOR);
			Assert::AreEqual(static_cast <int>(1), static_cast<int>(testVar));
			testBuffer.AddCharacter('B');
			Assert::AreEqual(static_cast <int>(1), static_cast<int>(testVar));
			testBuffer.AddCharacter(TERMINATOR);
			Assert::AreEqual(static_cast <int>(0), static_cast<int>(testVar));
		}

		TEST_METHOD(GettingCommand)
		{
			int i = 0;
			char command[10] = "";
			CircularBuffer testBuffer(10, &TestCallback);			
			char testArray[10] = { 'a', 'b', 'c', 'd', '\n', 'e', 'f', 'g', 'h', 'i' };

			for (int i = 0; i < 10; i++) {
				testBuffer.AddCharacter(testArray[i]);
			}
			testBuffer.GetCommand(command);

			while (command[i]) {
				Assert::AreEqual(testArray[i], command[i]);
				i++;
			}
			Assert::AreEqual(5, i);
		}

		TEST_METHOD(GettingCommandWhenBufferEmpty)
		{
			int i = 0;
			char command[10] = "";
			char testArray[4] = { 'a', 'b', 'c', '\n' };
			CircularBuffer testBuffer(10, &TestCallback);

			Assert::AreEqual(static_cast <int>(BUFFER_EMPTY), static_cast <int>(testBuffer.GetCommand(command)));

			for (int i = 0; i < 3; i++) {
				testBuffer.AddCharacter(testArray[i]); // '\n' not sent yet
			}
			Assert::AreEqual(static_cast <int>(BUFFER_EMPTY), static_cast <int>(testBuffer.GetCommand(command)));
			testBuffer.AddCharacter('\n');
			Assert::AreEqual(static_cast <int>(SUCCESS), static_cast <int>(testBuffer.GetCommand(command)));
			i = 0;
			while (command[i]) {
				Assert::AreEqual(testArray[i], command[i]);
				i++;
			}
		}

		TEST_METHOD(IsBufferCircularWhenAddingElement)
		{
			int i = 0;
			char command[10] = "";
			char testArray_1[7] = { 'a', 'b', 'c', 'd', 'e', 'f', '\n' };
			char testArray_2[7] = { 'g', 'h', 'i', 'j', 'k', 'l', '\n' };
			CircularBuffer testBuffer(10, &TestCallback);
			for (i = 0; i < 7; i++) {
				testBuffer.AddCharacter(testArray_1[i]);
			}
			for (i = 0; i < 2; i++) {
				Assert::AreEqual(static_cast <int>(SUCCESS), static_cast <int>(testBuffer.AddCharacter(testArray_2[0])));
			}
			Assert::AreEqual(static_cast <int>(SUCCESS), static_cast <int>(testBuffer.GetCommand(command)));

			Assert::AreEqual(static_cast <int>(SUCCESS), static_cast <int>(testBuffer.AddCharacter(testArray_2[2])));

			Assert::AreEqual(static_cast <int>(SUCCESS), static_cast <int>(testBuffer.AddCharacter(testArray_2[3])));

			for (i = 4; i < 7; i++) {
				Assert::AreEqual(static_cast <int>(SUCCESS), static_cast <int>(testBuffer.AddCharacter(testArray_2[i])));
				if (1 == i) {
					testBuffer.GetCommand(command);
				}
			}
			Assert::AreEqual('i', testBuffer.GetElement(9));
			Assert::AreEqual('j', testBuffer.GetElement(0));
			Assert::AreEqual('\n', testBuffer.GetElement(3));
		}
	};
}