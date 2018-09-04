/*******************************************************
* Copyright (C) 2018 Mateusz Urbanek <mateuszurbanek@gmail.com>
*
* This file is part of project Magiczne Schody.
*
* Project Magiczne Schody can not be copied and/or distributed without the express
* permission of Malgorzata Gora <gora.malgorzata.b@gmail.com>
*******************************************************/

#pragma once
#include "IChainOfResponsibility.h"

class ChainOfResponsibility
{
public:
	ChainOfResponsibility() : mNextLink(0) { }

public:
	void addNextLink(ChainOfResponsibility *l);

		virtual ~ChainOfResponsibility();

		void setNextLink(ChainOfResponsibility *l);

protected:
	virtual void executeCommand(char eCommand);

private:
	ChainOfResponsibility *mNextLink;
};
