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
#include <fstream>
#include <string>

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
			pca.testSetAddressAutoIncrement(false);
			pca.write(0x64, data, 2);
			Assert::AreEqual(0x64, pca.testGetAddress());
		}


		TEST_METHOD(AddressFromFile)
		{
			I2C pca(PB_9, PB_8);
			char data[2] = { 0x00, 0xFF };
			int addressFromFile;

			std::ifstream readDataFromFile("I2CResultsFile.txt");
			if (!readDataFromFile) Assert::AreEqual("success", "failed");

			pca.testSetAddressAutoIncrement(false);
			pca.write(0x64, data, 2);
			readDataFromFile >> addressFromFile;
			Assert::AreEqual(0x64, addressFromFile);
			readDataFromFile.close();
		}

		TEST_METHOD(RegisterAddressFromFile_AutoIncrementOn)
		{
			I2C pca(PB_9, PB_8);
			char data[3] = { 0x00, 0x05, 0xFF };
			int RegisterAddressFromFile;
			std::string lineFromFile;
			std::ifstream readDataFromFile("I2CResultsFile.txt");
			if (!readDataFromFile) Assert::AreEqual("success", "failed");
			
			pca.testSetAddressAutoIncrement(true);
			pca.write(0x64, data, 3);
			std::getline(readDataFromFile, lineFromFile, '\n'); //0x64
			std::getline(readDataFromFile, lineFromFile, '\n'); //0x00 |0x05
																//0x01 |0xFF
			readDataFromFile >> RegisterAddressFromFile;
			Assert::AreEqual(0x01, RegisterAddressFromFile);
			readDataFromFile.close();
		}

		TEST_METHOD(RegisterAddressFromFile_AutoIncrementOff)
		{
			I2C pca(PB_9, PB_8);
			char data[4] = { 0x00, 0x05, 0x10, 0xFF };
			int RegisterAddressFromFile;
			std::string lineFromFile;
			std::ifstream readDataFromFile("I2CResultsFile.txt");
			if (!readDataFromFile) Assert::AreEqual("success", "failed");

			pca.testSetAddressAutoIncrement(false);
			pca.write(0x64, data, 4);
			std::getline(readDataFromFile, lineFromFile, '\n'); //0x64
			std::getline(readDataFromFile, lineFromFile, '\n'); //0x00 |0x05
																//0x10 |0xFF
			readDataFromFile >> RegisterAddressFromFile;
			Assert::AreEqual(0x10, RegisterAddressFromFile);
			readDataFromFile.close();
		}

		TEST_METHOD(Data)
		{
			I2C pca(PB_9, PB_8);
			char data[3] = { 0x11, 0x12, 0x13};

			pca.write(0x64, data, 2);
			Assert::AreEqual(0x11, pca.testGetData(0));
			Assert::AreEqual(0x12, pca.testGetData(1));
			Assert::AreEqual(0, pca.testGetData(3));
			Assert::AreEqual(-1, pca.testGetData(17));
		}


		TEST_METHOD(DataFromFile)
		{
			I2C pca(PB_9, PB_8);
			char data[3] = { 0x11, 0x12, 0x13 };
			int addressFromFile;
			int registerAddressFromFile;
			char delimiter;
			int registerDataFromFile;
			std::string lineFromFile;

			std::ifstream readDataFromFile("I2CResultsFile.txt");
			if (!readDataFromFile) Assert::AreEqual("success", "failed");

			pca.testSetAddressAutoIncrement(false);
			pca.write(0x64, data, 3);

			readDataFromFile >> addressFromFile;
			readDataFromFile >> registerAddressFromFile;
			readDataFromFile >> delimiter;
			readDataFromFile >> registerDataFromFile;
			Assert::AreEqual(0x12, registerDataFromFile);

			readDataFromFile.close();
		}

		
	};
}