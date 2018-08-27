/*******************************************************
* Copyright (C) 2018 Malgorzata Gora <gora.malgorzata.b@gmail.com>
*
* This file is part of  project Magiczne Schody.
*
* Project Magiczne Schody can not be copied and/or distributed without the express
* permission of Malgorzata Gora <gora.malgorzata.b@gmail.com>
*******************************************************/
#pragma once

enum eCurcularBufferErrorCode
{
	SUCCESS = 0,
	BUFFER_EMPTY = 5,
	BUFFER_FULL = 6,
	ERROR = 7
};

class ICircularBuffer
{
public:
	// pure virtual functions providing interface framework.
	virtual eCurcularBufferErrorCode AddCharacter(char a) = 0;
	virtual bool IsCommandAvailable() = 0;
	virtual eCurcularBufferErrorCode GetCommand(char *command) = 0;
};
