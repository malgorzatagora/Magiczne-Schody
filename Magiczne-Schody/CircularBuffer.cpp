#include "stdafx.h"
#include "CircularBuffer.h"


CircularBuffer::CircularBuffer(int bufferSize)
{
	this->bufferSize = bufferSize;
	buffer = new char[bufferSize]{}; //C++ 11
	bufferBeginningIndex = 0;
	nextCharIndex = 0;
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
			nextCharIndex = lastTerminatorIndex + 1; //do poprawy!!!
			isFull = false;
		}
		return BUFFER_FULL;
	}
	buffer[nextCharIndex] = a;
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
	while (TERMINATOR != buffer[bufferBeginningIndex]) {

		*(command++) = buffer[bufferBeginningIndex++];
	}
	*(command++) = '\0';
	UpdateBufferDecrease();
	return SUCCESS;
}


void CircularBuffer::UpdateBufferIncrease()
{
	nextCharIndex++;
	if (bufferSize == nextCharIndex) {
		nextCharIndex = 0;
	}
	if (bufferBeginningIndex == nextCharIndex) {
		isFull = true;
	}

}


void CircularBuffer::UpdateBufferDecrease()
{
	bufferBeginningIndex++;
	isFull = false;
	if (bufferSize == bufferBeginningIndex) {
		bufferBeginningIndex = 0;
	}
	if (bufferBeginningIndex == nextCharIndex) {
		isEmpty = true;
	}
}