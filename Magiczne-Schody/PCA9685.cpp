#include "stdafx.h"
#include "PCA9685.h"


PCA9685::PCA9685(I2C *i2c, int address)
{
	this->i2c = i2c;
	this->address = address;
}


PCA9685::~PCA9685()
{}
void PCA9685::Init(void)
{}

void PCA9685::SetAllPinsToSpecifiedValues(float *dutyCycleValues)
{}


void PCA9685::Reset(void)
{}
void PCA9685::SetPWMFreq(int frequency)
{}
void PCA9685::SetMode1(int newMode)
{}
void PCA9685::SetMode2(int newMode)
{}


int PCA9685::ReadRegister(int registerNumber)
{
	return 0;
}
void PCA9685::WriteRegister(int registerNumber, int value)
{}

