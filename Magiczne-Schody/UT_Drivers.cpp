/*******************************************************
* Copyright (C) 2018 Pawel Owsikowski <pawel.owsikowski@gmail.com>
*
* This file is part of  project Magiczne Schody.
*
* Project Magiczne Schody can not be copied and/or distributed without the express
* permission of Malgorzata Gora <gora.malgorzata.b@gmail.com>
*
* Unit tests for  Drivers class
*******************************************************/

#include "stdafx.h"
#include "CppUnitTest.h"
#include "Drivers.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MagiczneSchody
{
	TEST_CLASS(DriversTest)
	{
	public:

		TEST_METHOD(GetInstance)
		{
			Drivers::Instance();
		}

		TEST_METHOD(i2cPinAssignment)
		{
			Assert::AreEqual(static_cast<int>(PB_8), 
				static_cast<int>(Drivers::Instance()->i2c.testGetSclPin()));
			Assert::AreEqual(static_cast<int>(PB_9),
				static_cast<int>(Drivers::Instance()->i2c.testGetSdaPin()));
		}
	};
}