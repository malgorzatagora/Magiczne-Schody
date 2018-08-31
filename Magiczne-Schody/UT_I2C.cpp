/*******************************************************
* Copyright (C) 2018 Pawel Owsikowski <pawel.owsikowski@gmail.com>
*
* This file is part of  project Magiczne Schody.
*
* Project Magiczne Schody can not be copied and/or distributed without the express
* permission of Malgorzata Gora <gora.malgorzata.b@gmail.com>
*
* Unit tests for I2C stub class
*******************************************************/

#include "stdafx.h"
#include "CppUnitTest.h"
#include "mbed.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Stubs
{
	TEST_CLASS(I2C_TEST)
	{
	public:

		TEST_METHOD(PinAssignment)
		{
			I2C pca(PB_9, PB_8);
			Assert::AreEqual(static_cast<int>(PB_8), static_cast<int>(pca.testGetSclPin()));
			Assert::AreEqual(static_cast<int>(PB_9), static_cast<int>(pca.testGetSdaPin()));
		}

		TEST_METHOD(Address)
		{
			I2C pca(PB_9, PB_8);
			char data[2] = {0x00, 0xFF};
			
			pca.write(0x64, data, 2);
			Assert::AreEqual(0x64, pca.testGetAddress());
		}


		TEST_METHOD(Data)
		{
			I2C pca(PB_9, PB_8);
			char data[3] = { 0x11, 0x12, 0x13};

			pca.write(0x64, data, 2);
			Assert::AreEqual(0x11, pca.testGetData(0));
			Assert::AreEqual(0x12, pca.testGetData(1));
			Assert::AreEqual(0, pca.testGetData(3));
			Assert::AreEqual(-1, pca.testGetData(7));
		}
		
	};
}