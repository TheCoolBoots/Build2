#ifndef DRIVE_H
#define DRIVE_H
#include "CANTalon.h"
#include "WPILib.h"

class Drive
{
private:
	RobotDrive* driver;
public:
	Drive()
	{
		CANTalon *Rleft=new CANTalon(1);
		CANTalon *Fleft=new CANTalon(2);
		CANTalon *Fright=new CANTalon(3);
		CANTalon *Rright=new CANTalon(4);

		driver = new RobotDrive(Rleft,Fleft,Fright,Rright);
		driver->SetExpiration(50);
		Rleft->SetSafetyEnabled(false);
		Fleft->SetSafetyEnabled(false);
		Rright->SetSafetyEnabled(false);
		Fright->SetSafetyEnabled(false);
		Rleft->SetExpiration(30);
		Fleft->SetExpiration(30);
		Rright->SetExpiration(30);
		Fright->SetExpiration(30);
	}
	void drive(Joystick*);
	void AutoDrive(float x, float y);
	void AutoArcade(float x, float y);
};
#endif
