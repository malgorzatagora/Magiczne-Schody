/*******************************************************
* Copyright (C) 2018 Mateusz Urbanek <mateuszurbanek@gmail.com>
*
* This file is part of project Magiczne Schody.
*
* Project Magiczne Schody can not be copied and/or distributed without the express
* permission of Malgorzata Gora <gora.malgorzata.b@gmail.com>
*******************************************************/

#include "ChainOfResponsibility.h"

class ChainOfResponsibility
{
public:
	void addNextLink(ChainOfResponsibility *l) {
		if (mNextLink)
			mNextLink->addNextLink(l);
		else
			mNextLink = l;
	}

	virtual ~ChainOfResponsibility() { }

	void setNextLink(ChainOfResponsibility *l) {
		mNextLink = l;
	}

protected:
	virtual void executeCommand(char eCommand)
	{
		mNextLink->executeCommand(eCommand);
	}
	
private:
	ChainOfResponsibility *mNextLink;
};




