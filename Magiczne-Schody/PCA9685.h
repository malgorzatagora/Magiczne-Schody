#pragma once
#include "mbed.h"
#define MODE1_ADDRESS	0x00
#define MODE2_ADDRESS	0x01
#define MODE1_SLEEP		0x10
#define MODE1_EXTCLK	0x40
#define MODE1_AI		0x20
#define MODE1_ALLCALL	0x01
//...

/*#define LED0_ON_L		0x06
#define LED0_ON_H		0x07
#define LED0_OFF_L		0x08
#define LED0_OFF_H		0x09
*/

class PCA9685
{
public:
	PCA9685(I2C *i2c, int address);
	~PCA9685();
	void GoToSleep(void);
	void Restart(void);
	void Init(void);
	void Reset(void);
	void SetPWMFreq(int frequency);
	void SetMode1(int newMode);
	void SetMode2(int newMode);
	void SetPin(int pinNumber, int dutyCycle);
	int ReadRegister(int registerNumber);

private:
	I2C * i2c;
	int address;
	void WriteRegister(int registerNumber, int value);
};

