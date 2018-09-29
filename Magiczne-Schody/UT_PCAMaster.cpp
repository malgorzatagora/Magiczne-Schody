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
#include "PCAMaster.h"
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MagiczneSchody
{
	TEST_CLASS(PCAMasterTest)
	{
	public:

		TEST_METHOD(HowManyPCAs)
		{
			I2C i2c_pca(PB_9, PB_8);
			PCA9685 myPCA1(&i2c_pca, PCA1_ADDRESS);
			PCA9685 myPCA2(&i2c_pca, PCA2_ADDRESS);
			PCA9685 myPCA3(&i2c_pca, PCA3_ADDRESS);
			PCA9685 myPCA4(&i2c_pca, PCA4_ADDRESS);
			PCA9685 arrayOfAvailablePCAs[4] = { myPCA1, myPCA2, myPCA3, myPCA4 };
			int numberOfStairs = 35;
			PCAMaster myPCAs(numberOfStairs, arrayOfAvailablePCAs);

			Assert::AreEqual(3, myPCAs.NumberOfPCAs());
		}
		
		TEST_METHOD(InitAllPCAs)
		{
			I2C i2c_pca(PB_9, PB_8);
			PCA9685 myPCA1(&i2c_pca, PCA1_ADDRESS);
			PCA9685 myPCA2(&i2c_pca, PCA2_ADDRESS);
			PCA9685 myPCA3(&i2c_pca, PCA3_ADDRESS);
			PCA9685 myPCA4(&i2c_pca, PCA4_ADDRESS);
			PCA9685 arrayOfAvailablePCAs[4] = { myPCA1, myPCA2, myPCA3, myPCA4 };
			int numberOfStairs = 35;
			PCAMaster myPCAs(numberOfStairs, arrayOfAvailablePCAs);
			int addressFromFile;
			int registerAddressFromFile;
			char delimiter;
			int registerDataFromFile;
			myPCAs.InitAllPCAs(LED);

			std::ifstream readDataFromFile("I2CResultsFile.txt");
			if (!readDataFromFile) Assert::AreEqual("success", "failed");

			readDataFromFile >> addressFromFile;
			readDataFromFile >> registerAddressFromFile;
			readDataFromFile >> delimiter;
			readDataFromFile >> registerDataFromFile;
			Assert::AreEqual(0x84, addressFromFile);
			Assert::AreEqual(MODE2_ADDRESS, registerAddressFromFile);
			Assert::AreEqual(0x18, registerDataFromFile);

			readDataFromFile.close();
		}

		TEST_METHOD(UpdateAllPCAs)
		{
			I2C i2c_pca(PB_9, PB_8);
			PCA9685 myPCA1(&i2c_pca, PCA1_ADDRESS);
			PCA9685 myPCA2(&i2c_pca, PCA2_ADDRESS);
			PCA9685 myPCA3(&i2c_pca, PCA3_ADDRESS);
			PCA9685 myPCA4(&i2c_pca, PCA4_ADDRESS);
			PCA9685 arrayOfAvailablePCAs[4] = { myPCA1, myPCA2, myPCA3, myPCA4 };
			const int numberOfStairs = 35;
			PCAMaster myPCAs(numberOfStairs, arrayOfAvailablePCAs);

			float dutyCycleValuesArray[numberOfStairs] = { 100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0, 10, 20, 30, 50, 60, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0, 10, 20, 30, 50, 60, 10, 20, 30 };


			int addressFromFile;
			int registerAddressFromFile;
			char delimiter;
			int registerDataFromFile;
			std::string lineFromFile;

			myPCAs.InitAllPCAs(LED);
			myPCAs.UpdateAllPCAs(dutyCycleValuesArray, numberOfStairs);


			std::ifstream readDataFromFile("I2CResultsFile.txt");
			if (!readDataFromFile) Assert::AreEqual("success", "failed");

			readDataFromFile >> addressFromFile;
			for (int i = 0; i < 64; i++) {
				std::getline(readDataFromFile, lineFromFile, '\n'); //should be 16x4 lines in file
			}
			//last line:
			readDataFromFile >> registerAddressFromFile;
			readDataFromFile >> delimiter;
			readDataFromFile >> registerDataFromFile;
			Assert::AreEqual(0x45, registerAddressFromFile);
			Assert::AreEqual(0x00, registerDataFromFile);
		}


	};
}