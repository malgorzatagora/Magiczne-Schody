#include "stdafx.h"
#include "Observer.h"


float Observer::arrayWithBrightnessValues[numberOfStairs] = {};

double Observer::LinearFunction(int x, double a, double b)
{
	double result;
	result = a * (double)x + b;
	if (result < 0.0) result = 0.0;
	else if (result > 50.0) result = 50.0;
	return result;
}

double Observer::SquareFunction(int x, double a, double b, double c)
{
	double result;
	result = a * (double)(x*x) + b * (double)x + c;
	if (result < 0.0) result = 0.0;
	else if (result > 50.0) result = 50.0;
	return result;
}