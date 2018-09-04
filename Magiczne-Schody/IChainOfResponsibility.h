/*******************************************************
* Copyright (C) 2018 Mateusz Urbanek <mateuszurbanek@gmail.com>
*
* This file is part of project Magiczne Schody.
*
* Project Magiczne Schody can not be copied and/or distributed without the express
* permission of Malgorzata Gora <gora.malgorzata.b@gmail.com>
*******************************************************/
#pragma once

class IChainOfResponsibility
{
public:
	// pure virtual functions providing interface framework.
	virtual void executeCommand(char eCommand) = 0;
	virtual void addNextLink(ChainOfResponsibility *l) = 0;
	virtual void setNextLink(ChainOfResponsibility *l) = 0;
};