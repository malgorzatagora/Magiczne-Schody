/*******************************************************
* Copyright (C) 2018 Pawel Owsikowski <pawel.owsikowski@gmail.com>
*
* This file is part of  project Magiczne Schody.
*
* Project Magiczne Schody can not be copied and/or distributed without the express
* permission of Malgorzata Gora <gora.malgorzata.b@gmail.com>
*
* I2C stub class 
* Implements constructor and write method from mbed I2C class
*******************************************************/

#include "stdafx.h"
#include "I2C.h"


I2C::I2C(PinName sda, PinName scl)
{
	this->sda = sda;
	this->scl = scl;
	this->writeResult = 0;
	for (int i = 0; i < maxDataLength; i++)
	{
		this->data[i] = 0;
	}
	

}


I2C::~I2C()
{
}

int I2C::write(int address, const char * data, int length, bool repeated)
{
	this->address = address;
	if (length > maxDataLength) length = maxDataLength;
	for (int i = 0; i < length; i++)
	{
		this->data[i] = data[i];
	}
	return this->writeResult;
}
