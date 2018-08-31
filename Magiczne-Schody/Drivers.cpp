#include "stdafx.h"
#include "Drivers.h"


Drivers* Drivers::_instance = 0;

Drivers* Drivers::Instance() {
	if (_instance == 0) {
		_instance = new Drivers;
	}
	return _instance;
}

Drivers::Drivers() : i2c(i2c_sda, i2c_scl)
{
}
