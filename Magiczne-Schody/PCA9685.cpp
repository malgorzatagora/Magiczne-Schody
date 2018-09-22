#include "stdafx.h"
#include "PCA9685.h"


PCA9685::PCA9685(I2C *i2c, int address)
{
	this->i2c = i2c;
	this->address = address;
}


PCA9685::~PCA9685()
{}


void PCA9685::SetMode1(char newMode)
{
	char data[] = { MODE1_ADDRESS, newMode };
	if (newMode & MODE1_AI) {
		this->i2c->testSetAddressAutoIncrement(true);
	}
	else {
		this->i2c->testSetAddressAutoIncrement(false);
	}
	this->i2c->write(this->address, data, 2);
}


void PCA9685::SetMode2(char newMode)
{
	char data[] = { MODE2_ADDRESS, newMode };
	this->i2c->write(this->address, data, 2);
}


void PCA9685::SetPWMFreq(int frequency)
{
	// do nothing - LED_FREQ = 1E is default;
	//TODO:  change freq for servo
}


void PCA9685::Init(void)
{
	SetPWMFreq(LED_FREQ);
	SetMode1(MODE1_AI | MODE1_ALLCALL);
	SetMode2(MODE2_INVRT | MODE2_OCH);
}


int PCA9685::SetAllPinsToSpecifiedValues(float *dutyCycleValuesArray, int arrayLength)
{
	int result;
	char dataToWrite[65];
	int counter;
	if (16 != arrayLength) result = -5;
	else {
		dataToWrite[0] = LED0_ON_L;
		for (int i = 0; i < 16; i++) {
			counter = (dutyCycleValuesArray[i] * 4095) / 100;
			dataToWrite[4 * i + 1] = 0;
			dataToWrite[4 * i + 2] = 0;
			dataToWrite[4 * i + 3] = (char)(counter);
			dataToWrite[4 * i + 4] = (char)(counter >> 8);
		}
		this->i2c->write(this->address, dataToWrite, 65);
		result = 0;
	}
	return result;
}
