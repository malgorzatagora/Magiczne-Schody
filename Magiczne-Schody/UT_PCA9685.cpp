/*******************************************************
* Copyright (C) 2018 Pawel Owsikowski <pawel.owsikowski@gmail.com>
*
* This file is part of  project Magiczne Schody.
*
* Project Magiczne Schody can not be copied and/or distributed without the express
* permission of Malgorzata Gora <gora.malgorzata.b@gmail.com>
*
* Unit tests for PCA9685 class
*******************************************************/

#include "stdafx.h"
#include "CppUnitTest.h"
#include "mbed.h"
#include "PCA9685.h"
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Stubs
{
	TEST_CLASS(PCA9685_TEST)
	{
	public:

		TEST_METHOD(AddDevices)
		{
			I2C pca_i2c(PB_9, PB_8);
			I2C *wsk_i2c = &pca_i2c;
			// TODO:
			// PCA9685 pca(wsk_i2c);
			// pca.addDevice(0x00);
			// pca.addDevice(0x01);
			// pca.addDevice(0x07);

			//pca.configureAllDevices()
			// assert ("0x64 0x01 0x18", i2cGetSnapshotData())  // zrobiæ to na jednym stringu
			// assert ("0x64 0x00 0x21", i2cGetSnapshotData()) 
			// assert ("0x66 0x01 0x18", i2cGetSnapshotData())
			// assert ("0x66 0x00 0x21", i2cGetSnapshotData())
			// assert ("0x72 0x01 0x18", i2cGetSnapshotData())
			// assert ("0x72 0x00 0x21", i2cGetSnapshotData())
			

			//pca.setPWM(0, 50);
			
		}

		TEST_METHOD(InitModes)
		{
			I2C i2c_pca(PB_9, PB_8);
			PCA9685 myPCA(&i2c_pca, 0x64);
			int addressFromFile;
			int registerAddressFromFile;
			char delimiter;
			int registerDataFromFile;
			myPCA.Init();

			std::ifstream readDataFromFile("I2CResultsFile.txt");
			if (!readDataFromFile) Assert::AreEqual("success", "failed");

			readDataFromFile >> addressFromFile;
			readDataFromFile >> registerAddressFromFile;
			readDataFromFile >> delimiter;
			readDataFromFile >> registerDataFromFile;
			Assert::AreEqual(0x64, addressFromFile);
			Assert::AreEqual(MODE2_ADDRESS, registerAddressFromFile);
			Assert::AreEqual(0x18, registerDataFromFile);

			readDataFromFile.close();
		}




	};
}