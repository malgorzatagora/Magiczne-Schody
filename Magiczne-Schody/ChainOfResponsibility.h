/*******************************************************
* Copyright (C) 2018 Mateusz Urbanek <mateuszurbanek@gmail.com>
*
* This file is part of project Magiczne Schody.
*
* Project Magiczne Schody can not be copied and/or distributed without the express
* permission of Malgorzata Gora <gora.malgorzata.b@gmail.com>
*******************************************************/

#pragma once


class Chain
{
	Chain *next;
public:
	Chain()
	{
		next = 0;
	}
	void setNext(Chain *n)
	{
		next = n;
	}
	void add(Chain *n)
	{
		if (next)
			next->add(n);
		else
			next = n;
	}
	virtual void execute(int i)
	{
		next->execute(i);
	}
};

//placeholder 

