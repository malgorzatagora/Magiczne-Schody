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
			Assert::AreEqual(CircularBuffer::TERMINATOR, testBuffer.GetElement(4));
			Assert::AreEqual('i', testBuffer.GetElement(9));
			Assert::AreEqual(static_cast<int>(BUFFER_FULL), static_cast<int>(testBuffer.AddCharacter('X')));
		}
		
		TEST_METHOD(CallbackFunction)
		{
			testVar = 0;
			CircularBuffer testBuffer(10, &TestCallback);
			testBuffer.AddCharacter('A');
			Assert::AreEqual(static_cast <int>(0), static_cast<int>(testVar));
			testBuffer.AddCharacter(CircularBuffer::TERMINATOR);
			Assert::AreEqual(static_cast <int>(1), static_cast<int>(testVar));
			testBuffer.AddCharacter('B');
			Assert::AreEqual(static_cast <int>(1), static_cast<int>(testVar));
			testBuffer.AddCharacter(CircularBuffer::TERMINATOR);
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
			char testArray_1[5] = { 'a', 'b', 'c', 'd', '\n' };
			char testArray_2[9] = { 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', '\n' };
			CircularBuffer testBuffer(10, &TestCallback);
			for (i = 0; i < 5; i++) {
				testBuffer.AddCharacter(testArray_1[i]);
			}
			Assert::AreEqual(static_cast <int>(SUCCESS), static_cast <int>(testBuffer.GetCommand(command)));
			Assert::AreEqual(10, testBuffer.BuffSize());
			Assert::AreEqual(5, testBuffer.HeadPosition());
			for (i = 0; i < 9; i++) {
				Assert::AreEqual(static_cast <int>(SUCCESS), static_cast <int>(testBuffer.AddCharacter(testArray_2[i])));
			}

			Assert::AreEqual('i', testBuffer.GetElement(9));
			Assert::AreEqual('j', testBuffer.GetElement(0));
			Assert::AreEqual('\n', testBuffer.GetElement(3));
		}

		TEST_METHOD(Add3CommandsAndThenGetOneByOne_test1)
		{
			int i = 0;
			char receivedCommand[10] = "";
			CircularBuffer testBuffer(10, &TestCallback);

			//command #1
			testBuffer.AddCharacter('a');
			testBuffer.AddCharacter('b');
			testBuffer.AddCharacter(CircularBuffer::TERMINATOR);
			//command #2
			testBuffer.AddCharacter('c');
			testBuffer.AddCharacter('d');
			testBuffer.AddCharacter(CircularBuffer::TERMINATOR);
			//command #3
			testBuffer.AddCharacter('e');
			testBuffer.AddCharacter('f');
			testBuffer.AddCharacter(CircularBuffer::TERMINATOR);

			testBuffer.GetCommand(receivedCommand); // expected command #1	
			Assert::AreEqual('a', receivedCommand[0]);
		}

		TEST_METHOD(Add3CommandsAndThenGetOneByOne_test2)
		{
			int i = 0;
			char receivedCommand[10] = "";
			CircularBuffer testBuffer(10, &TestCallback);

			//command #1
			testBuffer.AddCharacter('a');
			testBuffer.AddCharacter('b');
			testBuffer.AddCharacter(CircularBuffer::TERMINATOR);
			//command #2
			testBuffer.AddCharacter('c');
			testBuffer.AddCharacter('d');
			testBuffer.AddCharacter(CircularBuffer::TERMINATOR);
			//command #3
			testBuffer.AddCharacter('e');
			testBuffer.AddCharacter('f');
			testBuffer.AddCharacter(CircularBuffer::TERMINATOR);

			testBuffer.GetCommand(receivedCommand); // expected command #1
			Assert::AreEqual('b', receivedCommand[1]);
		}


		TEST_METHOD(Add3CommandsAndThenGetOneByOne_test3)
		{
			int i = 0;
			char receivedCommand[10] = "";
			CircularBuffer testBuffer(10, &TestCallback);

			//command #1
			testBuffer.AddCharacter('a');
			testBuffer.AddCharacter('b');
			testBuffer.AddCharacter(CircularBuffer::TERMINATOR);
			//command #2
			testBuffer.AddCharacter('c');
			testBuffer.AddCharacter('d');
			testBuffer.AddCharacter(CircularBuffer::TERMINATOR);
			//command #3
			testBuffer.AddCharacter('e');
			testBuffer.AddCharacter('f');
			testBuffer.AddCharacter(CircularBuffer::TERMINATOR);

			testBuffer.GetCommand(receivedCommand); // expected command #1
			//A valid C string requires the presence of a terminating "null character"
			Assert::AreEqual('\0', receivedCommand[2]); 		}
	};
}