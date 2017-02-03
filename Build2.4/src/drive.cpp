#include "WPILib.h"
#include "drive.h"

void Drive::drive(Joystick*stick)
{
	driver->ArcadeDrive(stick);
}
void Drive::AutoArcade(float x, float y)
{
	driver->ArcadeDrive(x, y);
}
