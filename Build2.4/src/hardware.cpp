/*
 * hardware.cpp
 *
 *  Created on: Feb 1, 2016
 *      Author: Developer
 */
#include "hardware.h"
#include "WPILib.h"
#include "CANTalon.h"


Hardware::Hardware()
{

	Rleft = new CANTalon(1);
	Fleft = new CANTalon(2);
	Rright = new CANTalon(3);
	Fright = new CANTalon(4);
	intake = new Spark(0);
	bicep = new Spark(1);
	forearm = new Spark(2);
	auxArm = new Spark(3);
	ultra = new Ultrasonic(0,1);
	navx = new AHRS(SPI::kMXP);
	wheelEncoder = new Encoder(2,3,false,Encoder::EncodingType::k4X);
//	flywheel = new CANTalon(5);
	feeder = new CANTalon(6);
	conveyor = new Spark(4);
	gearL = new Spark(5);
	gearR = new Spark(6);
	climber = new Spark(7);

	//bicepEncoder = new Encoder(4,5,false,Encoder::EncodingType::k4X);
	//forearmEncoder = new Encoder (6,7,false,Encoder::EncodingType::k4X);

}


