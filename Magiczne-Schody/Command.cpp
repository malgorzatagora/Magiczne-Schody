/*******************************************************
* Copyright (C) 2018 Mateusz Urbanek <mateuszurbanek@gmail.com>
*
* This file is part of project Magiczne Schody.
*
* Project Magiczne Schody can not be copied and/or distributed without the express
* permission of Malgorzata Gora <gora.malgorzata.b@gmail.com>
*******************************************************/
#include "stdafx.h"
#include "Command.h"


void Command :: addSuccessor(Command *successor) {
		if (nextSuccessor)
			nextSuccessor->addSuccessor(successor);
		else
			nextSuccessor = successor;
	}
Command :: ~Command() { }

void Command:: setSuccessor(Command *successor) {
		nextSuccessor = successor;
	}

 void Command::processRequest(char exeCommand)
	{
		nextSuccessor->processRequest(exeCommand);
	}


