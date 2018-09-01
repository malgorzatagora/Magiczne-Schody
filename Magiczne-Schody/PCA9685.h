#pragma once
#include "mbed.h"

class PCA9685
{
public:
	PCA9685(I2C *i2c);
	~PCA9685();

private:
	I2C * i2c;
};

