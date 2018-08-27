#include "stdafx.h"
#include "CircularBuffer.h"


CircularBuffer::CircularBuffer()
{
	char buffer[BUFFER_SIZE]{}; //C++ 11
	bufferBeginningIndex = 0;
	nextCommandBeginningIndex = 0;
	isEmpty = true;
	isFull = false;
}


CircularBuffer::~CircularBuffer()
{
}


eCurcularBufferErrorCode CircularBuffer::AddCharacter(char a)
{
	if (true == isFull) {
		return BUFFER_FULL;
	}
	buffer[nextCommandBeginningIndex] = a;
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
	*(command++) == '\0';
	UpdateBufferDecrease();
	return SUCCESS;
}


void CircularBuffer::UpdateBufferIncrease()
{
	nextCommandBeginningIndex++;
	if (BUFFER_SIZE == nextCommandBeginningIndex) {
		nextCommandBeginningIndex = 0;
	}
	if (bufferBeginningIndex == nextCommandBeginningIndex) {
		isFull = true;
	}

}


void CircularBuffer::UpdateBufferDecrease()
{
	bufferBeginningIndex++;
	isFull = false;
	if (BUFFER_SIZE == bufferBeginningIndex) {
		bufferBeginningIndex = 0;
	}
	if (bufferBeginningIndex == nextCommandBeginningIndex) {
		isEmpty = true;
	}
}