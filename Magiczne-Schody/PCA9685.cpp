#include "stdafx.h"
#include "PCA9685.h"


PCA9685::PCA9685(I2C *i2c)
{
	this->i2c = i2c;
}


PCA9685::~PCA9685()
{
}
