/*
 * hardware.h
 *
 *  Created on: Feb 1, 2016
 *      Author: Developer
 */
#ifndef HARDWARE_H
#define HARDWARE_H
#include "WPILib.h"
#include "AHRS.h"
#include "CANTalon.h"


class Hardware
{
public:
	Hardware();
	CANTalon*Fleft;
	CANTalon*Fright;
	CANTalon*Rleft;
	CANTalon*Rright;
	CANTalon*Flywheel;
//	CANTalon*Intake;
	Spark*intake;
	Spark*bicep;
	Spark*forearm;
	Spark*auxArm;
	Ultrasonic* ultra;
	AHRS* navx;
	Encoder *wheelEncoder;

	Spark*conveyor;
	Spark*gearL;
	Spark*gearR;
	Spark*climber;
	CANTalon*flywheel;
	CANTalon*feeder;
	//Encoder *bicepEncoder;
	//Encoder *forearmEncoder;

 };
#endif


