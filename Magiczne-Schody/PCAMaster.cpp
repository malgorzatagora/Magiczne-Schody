#include "stdafx.h"
#include "PCAMaster.h"


PCAMaster::PCAMaster(int howManyStairs, PCA9685 * arrayOfAvaliablePCAs)
{
	
	int numberOfPinsInPCA = 16;
	this->numberOfPCAs = (howManyStairs / numberOfPinsInPCA);
	if ((howManyStairs % 16) != 0){
		this->numberOfPCAs++;
	}

	for (int i = 0; i < this->numberOfPCAs; i++){
		this->arrayOfPCAs[i] = &(arrayOfAvaliablePCAs[i]);
	}
}


PCAMaster::~PCAMaster()
{}


void PCAMaster::InitAllPCAs(PCADriverType myConfiguration)
{
	for (int i = 0; i < this->numberOfPCAs; i++) {
		this->arrayOfPCAs[i]->Init(LED);
	}
}

void PCAMaster::UpdateAllPCAs(float *dutyCycleValuesForAllStairs, char howManyStairs)
{
	float dutyCycleValuesArray[16] = {};
	int index = 0;
	int whichPCA = 0;
	for (int i = 0; i < howManyStairs; i++) {
		index = i % 16;
		dutyCycleValuesArray[index] = dutyCycleValuesForAllStairs[i];
		if (15 == index) {
			this->arrayOfPCAs[whichPCA]->SetAllPinsToSpecifiedValues(dutyCycleValuesArray, 16);
			whichPCA++;
		}
	}
	while (index <15)
	{
		dutyCycleValuesArray[++index] = 0;
	}
	this->arrayOfPCAs[whichPCA]->SetAllPinsToSpecifiedValues(dutyCycleValuesArray, 16);	
}

int PCAMaster::NumberOfPCAs(void)
{
	return (this->numberOfPCAs);
}