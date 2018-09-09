/*******************************************************
* Copyright (C) 2018 Mateusz Urbanek <mateuszurbanek@gmail.com>
*
* This file is part of project Magiczne Schody.
*
* Project Magiczne Schody can not be copied and/or distributed without the express
* permission of Malgorzata Gora <gora.malgorzata.b@gmail.com>
*******************************************************/

#pragma once
#include "ICommand.h"

class Command : public ICommand
{
public:
	Command() : nextSuccessor(0) { }

public:
	void addSuccessor(Command *successor);

	virtual ~Command();

	void setSuccessor(Command *successor);

protected:
	virtual void processRequest(char exeCommand);

private:
	Command *nextSuccessor;
};
#pragma once
