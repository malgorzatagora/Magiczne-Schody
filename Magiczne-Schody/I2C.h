/*******************************************************
* Copyright (C) 2018 Pawel Owsikowski <pawel.owsikowski@gmail.com>
*
* This file is part of  project Magiczne Schody.
*
* Project Magiczne Schody can not be copied and/or distributed without the express
* permission of Malgorzata Gora <gora.malgorzata.b@gmail.com>
*
* I2C stub class
*******************************************************/
#pragma once

typedef enum PinName
{
	PB_9,
	PB_8
}PinName;


class I2C
{
public:
	I2C(PinName sda, PinName scl);
	~I2C();
	int write(int address, const char *data, int length, bool repeated = false);

	inline PinName testGetSdaPin()
	{
		return sda;
	}

	inline PinName testGetSclPin()
	{
		return scl;
	}

	inline int testGetAddress()
	{
		return address;
	}

	inline int testGetData(unsigned int index)
	{
		int result = -1;
		if (index < maxDataLength)
		{	
			result = static_cast<unsigned int>(data[index]);
		}
		return result;
	}


private:
	static const int maxDataLength = 5;
	char data[maxDataLength];
	int address;
	int writeResult;
	PinName sda, scl;
};

