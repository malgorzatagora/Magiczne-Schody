/*******************************************************
* Copyright (C) 2018 Malgorzata Gora <gora.malgorzata.b@gmail.com>
*
* This file is part of  project Magiczne Schody.
*
* Project Magiczne Schody can not be copied and/or distributed without the express
* permission of Malgorzata Gora <gora.malgorzata.b@gmail.com>
*******************************************************/

#include "stdafx.h"
#include "CircularBuffer.h"


CircularBuffer::CircularBuffer(int bufferSize)
{
	this->bufferSize = bufferSize;
	buffer = new char[bufferSize];
	head = 0;
	tail = 0;
	isEmpty = true;
	isFull = false;
}


CircularBuffer::~CircularBuffer()
{
	delete buffer;
	buffer = nullptr;
}


eCurcularBufferErrorCode CircularBuffer::AddCharacter(char a)
{
	if (true == isFull) {
		if (TERMINATOR == a) {
			tail = lastTerminatorIndex + 1; //do poprawy!!!
			isFull = false;
		}
		return BUFFER_FULL;
	}
	buffer[tail] = a;
	if (TERMINATOR == a) {
		isEmpty = false;
	}
	UpdateBufferIncrease();
	return SUCCESS;
}

bool CircularBuffer::IsCommandAvailable()
{
		return !isEmpty;
}

eCurcularBufferErrorCode CircularBuffer::GetCommand(char *command)
{
	if (command == nullptr) {
		return ERROR;
	}
	if (true == isEmpty) {
		return BUFFER_EMPTY;
	}
	while (TERMINATOR != buffer[head]) {

		*(command++) = buffer[head++];
	}
	*(command++) = '\0';
	UpdateBufferDecrease();
	return SUCCESS;
}


void CircularBuffer::UpdateBufferIncrease()
{
	tail++;
	if (bufferSize == tail) {
		tail = 0;
	}
	if (head == tail) {
		isFull = true;
	}

}


void CircularBuffer::UpdateBufferDecrease()
{
	head++;
	isFull = false;
	if (bufferSize == head) {
		head = 0;
	}
	if (head == tail) {
		isEmpty = true;
	}
}