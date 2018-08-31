#pragma once

#include "mbed.h"

class Drivers
{
public:
	static Drivers* Instance();
	I2C i2c;
protected:
	Drivers();
	//I2C pin assignment:
	static const PinName i2c_sda = PinName::PB_9;
	static const PinName i2c_scl = PinName::PB_8;
private:
	static Drivers *_instance;
};
 