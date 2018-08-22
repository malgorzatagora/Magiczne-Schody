/*******************************************************
* Copyright (C) 2018 Pawel Owsikowski <pawel.owsikowski@gmail.com>
*
* This file is part of  project Magiczne Schody.
*
* Project Magiczne Schody can not be copied and/or distributed without the express
* permission of Malgorzata Gora <gora.malgorzata.b@gmail.com>
*******************************************************/
#pragma once

enum LEDControllerErrorCode 
{
	SUCCESS = 0,
	BAD_CHANNEL = 11,
	PWM_VALUE_OUT_OF_RANGE = 12
};


class ILEDController {
public:
	// pure virtual function providing interface framework.
	virtual LEDControllerErrorCode setPWM(unsigned int channel, unsigned int PWMValue) = 0;
};




