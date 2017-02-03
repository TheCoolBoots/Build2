/*
 * OperatingSystem.h
 *
 *  Created on: Feb 1, 2016
 *      Author: Developer
 */
#ifndef OI_H
#define OI_H
#include "WPILib.h"

class OI
{
private:
	Joystick* drive;
	Joystick* arm;

public:
	OI();
	Joystick* getJoystickDrive();
	Joystick* getJoystickAux();
};
#endif




