/*******************************************************
* Copyright (C) 2018 Malgorzata Gora <gora.malgorzata.b@gmail.com>
*
* This file is part of  project Magiczne Schody.
*
* Project Magiczne Schody can not be copied and/or distributed without the express
* permission of Malgorzata Gora <gora.malgorzata.b@gmail.com>
*******************************************************/

#pragma once
#include "ICircularBuffer.h"
constexpr auto BUFFER_SIZE = 10;
constexpr auto TERMINATOR = '\n';

class CircularBuffer: public ICircularBuffer
{
public:
	CircularBuffer();
	~CircularBuffer();
	eCurcularBufferErrorCode AddCharacter(char a);
	bool IsCommandAvailable();
	eCurcularBufferErrorCode GetCommand(char *command);

private:
	char buffer[BUFFER_SIZE];
	int bufferBeginningIndex;
	int nextCommandBeginningIndex;
	bool isEmpty;
	bool isFull;
	void UpdateBufferIncrease();
	void UpdateBufferDecrease();
};



