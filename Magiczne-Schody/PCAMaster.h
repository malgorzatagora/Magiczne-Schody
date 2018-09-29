#pragma once
#include "PCA9685.h"

#define PCA1_ADDRESS	0x80
#define PCA2_ADDRESS	0x82
#define PCA3_ADDRESS	0x84
#define PCA4_ADDRESS	0x88


class PCAMaster
{
public:
	PCAMaster(int howManyStairs, PCA9685 * arrayOfAvaliablePCAs);
	~PCAMaster();
	void InitAllPCAs(PCADriverType myConfiguration);
	void UpdateAllPCAs(float *dutyCycleValuesForAllStairs, char howManyStairs);
	int NumberOfPCAs(void);

private:
	int numberOfPCAs;
	PCA9685 *arrayOfPCAs[4];

};