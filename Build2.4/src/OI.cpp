/*
 * OperatingSystem.cpp
 *
 *  Created on: Feb 1, 2016
 *      Author: Developer
 */
#include <OI.h>
OI::OI()
{
	drive = new Joystick(0);
	arm = new Joystick(1);
}
Joystick* OI::getJoystickDrive()
{
	return drive;
}
Joystick* OI::getJoystickAux()
{
	return arm;
}
