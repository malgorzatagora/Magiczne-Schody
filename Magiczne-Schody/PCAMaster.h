#pragma once
#include "PCA9685.h"

#define PCA1_ADDRESS	0x80
#define PCA2_ADDRESS	0x82
#define PCA3_ADDRESS	0x84
#define PCA4_ADDRESS	0x88
#define COUNT_OF(array) (sizeof(array) / sizeof(array[0]))
static const int numberOfPinsInPCA = 16;

class PCAMaster
{
public:
	PCAMaster(int howManyStairs, PCA9685 * arrayOfAvaliablePCAs, int arraySize);
	~PCAMaster();
	void InitAllPCAs(PCADriverType myConfiguration);
	void UpdateAllPCAs(float *dutyCycleValuesForAllStairs, char howManyStairs);
	int NumberOfPCAs(void);

private:
	int numberOfPCAs;
	PCA9685 *arrayOfPCAs[4];

};