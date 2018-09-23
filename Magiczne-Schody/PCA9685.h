#pragma once
#include "mbed.h"
#define MODE1_ADDRESS	0x00
#define MODE2_ADDRESS	0x01
#define MODE1_SLEEP		0x10
#define MODE1_EXTCLK	0x40
#define MODE1_AI		0x20
#define MODE1_ALLCALL	0x01
#define MODE2_OCH		0x08	//Outputs CHange on ACK requires
								//all 4 PWM channel registers to be loaded
								//before outputs will change on the last ACK.
#define MODE2_INVRT		0x10
#define PRE_SCALE		0xFE	//prescaler for PWM output frequency
#define LED_FREQ		0x1E	//200 Hz
#define SERVO_FREQ		0x79	//50 Hz
//...

#define LED0_ON_L		0x06
/*#define LED0_ON_H		0x07
#define LED0_OFF_L		0x08
#define LED0_OFF_H		0x09
*/

typedef enum PCADriverType
{
	LED,
	SERVO
}PCADriverType;

class PCA9685
{
public:
	PCA9685(I2C *i2c, int address);
	~PCA9685();
	void Init(PCADriverType myConfiguration);
	int SetAllPinsToSpecifiedValues(float *dutyCycleValues, int arrayLength);


private:
	I2C * i2c;
	int address;
	void SetMode1(char newMode);
	void SetMode2(char newMode);
	void SetPWMFreq(int frequency);
};