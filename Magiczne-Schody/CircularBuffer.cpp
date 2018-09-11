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



CircularBuffer::CircularBuffer(int bufferSize, void (*callback)(void))
{
	this->bufferSize = bufferSize;
	this->buffer = new char[bufferSize];
	this->head = 0;
	this->tail = 0;
	this->isEmpty = true;
	this->isFull = false;
	this->callback = callback;
}


CircularBuffer::~CircularBuffer()
{
	delete buffer;
	buffer = nullptr;
}


eCircularBufferErrorCode CircularBuffer::AddCharacter(char a)
{
	if (true == isFull) {
		if ((TERMINATOR == a) && (lastTerminatorIndex < (bufferSize-1))) {
			tail = ++lastTerminatorIndex; 
			isFull = false;
		}
		return BUFFER_FULL;
	}
	buffer[tail] = a;
	if (TERMINATOR == a) {
		isEmpty = false;
		callback();
	}
	UpdateBufferIncrease();
	return SUCCESS;
}


bool CircularBuffer::IsCommandAvailable()
{
		return !isEmpty;
}


eCircularBufferErrorCode CircularBuffer::GetCommand(char *command)
{
	if (true == isEmpty) {
		return BUFFER_EMPTY;
	}
	while (TERMINATOR != buffer[head]) {

		*(command++) = buffer[head++];
	
		if (head >= bufferSize) {
			head = 0;
		}
	}
	*(command) = TERMINATOR;
	UpdateBufferDecrease();
	return SUCCESS;
}


void CircularBuffer::UpdateBufferIncrease()
{
	tail++;
	if (tail >= bufferSize) {
		tail = 0;
	}
	if (tail == head) {
		isFull = true;
	}
}


void CircularBuffer::UpdateBufferDecrease()
{
	head++;
	isFull = false;
	if (head >= bufferSize) {
		head = 0;
	}
	if ((head == tail) || (lastTerminatorIndex == (head-1)) || ((0 == head) && (lastTerminatorIndex == (bufferSize -1)))){
		isEmpty = true;
	}
}


char CircularBuffer::GetElement(int elementIndex) 
{
	return buffer[elementIndex];
}


int CircularBuffer::HeadPosition(void)
{
	return head;
}


int CircularBuffer::BuffSize(void)
{
	return bufferSize;
}