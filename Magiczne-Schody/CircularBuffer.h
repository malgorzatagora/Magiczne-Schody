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


class CircularBuffer: public ICircularBuffer
{
public:
	CircularBuffer(int bufferSize, void (*callback)(void));
	virtual ~CircularBuffer();
	virtual eCircularBufferErrorCode AddCharacter(char a);
	virtual bool IsCommandAvailable();
	virtual eCircularBufferErrorCode GetCommand(char *command);
	char GetElement(int elementIndex);
	int HeadPosition();
	int BuffSize(void);
	static const char TERMINATOR = '\n';

private:
	char *buffer;
	int bufferSize;
	int head;
	int tail;
	int lastTerminatorIndex;
	bool isEmpty;
	bool isFull;
	void (*callback)(void);
	void UpdateBufferIncrease();
	void UpdateBufferDecrease();
};



