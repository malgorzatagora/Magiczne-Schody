/*******************************************************
* Copyright (C) 2018 Pawel Owsikowski <pawel.owsikowski@gmail.com>
*
* This file is part of  project Magiczne Schody.
*
* Project Magiczne Schody can not be copied and/or distributed without the express
* permission of Malgorzata Gora <gora.malgorzata.b@gmail.com>
*******************************************************/

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
