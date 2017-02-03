#include "WPILib.h"
#include "drive.h"
#include "OI.h"
#include "hardware.h"
#include <Math.h>


class Robot:
public IterativeRobot
{
private:
	Drive* driver;
	OI* oi;                 //defines variables
	Hardware* hardware;
	double circumference;
	double degrees;
	Timer t;


public:
	Robot()
	{
		hardware= new Hardware();
		driver= new Drive();
		oi= new OI();              //initiates robot components
		degrees = 0;
	}

	void AutoDrive(float l,float r)
	{
		hardware->Fleft->Set(-l);
		hardware->Rleft->Set(-l);
		hardware->Fright->Set(r);
		hardware->Rright->Set(r);
	}


	void turnLeft(int turnDegrees,double power) //function for autonomous turn Left
	{
		hardware->navx->Reset();
		double startAngle = hardware->navx->GetAngle();
		while ((startAngle-turnDegrees)<hardware->navx->GetAngle())
		{
			AutoDrive(-power,power);
			SmartDashboard::PutNumber("Navx reading",hardware->navx->GetAngle());
		}
		AutoDrive(0,0);

	}
	void turnRight(int turnDegrees,double power)     //function for autonomous turn Right
	{
		hardware->navx->Reset();
		double startAngle = hardware->navx->GetAngle();
		while (startAngle+turnDegrees>hardware->navx->GetAngle())
		{
			AutoDrive(power,-power);
			SmartDashboard::PutNumber("Navx reading",hardware->navx->GetAngle());
		}
		AutoDrive(0,0);
	}
	void PDStraightDrive(double speed, double distance, int TReset)
	{
		double kP = -SmartDashboard::GetNumber("kP", .45);
		double kD = -SmartDashboard::GetNumber("kD", .25);

		int deltaTime = TReset; //milliseconds
		hardware->navx->Reset();
		hardware->wheelEncoder->Reset();

		double error = 0;
		double errornew;
		double change;
		double derivitive;

		t.Reset();

		while(hardware->wheelEncoder->GetDistance() <= distance)
		{
			SmartDashboard::PutNumber("Encoder Reading",hardware->wheelEncoder->GetDistance());
			errornew = hardware->navx->GetAngle();

			change = errornew-error;

			derivitive = change/(double)deltaTime;

			driver->AutoArcade(-speed, (kP*errornew + kD*derivitive));

			error = errornew;
			SmartDashboard::PutNumber("CURRENT ANGLE", hardware->navx->GetAngle());
		}
		driver->AutoArcade(0,0);
	}
	void RobotInit()
	{
		//autonomous variables

		SmartDashboard::PutNumber("kP", .45);
		SmartDashboard::PutNumber("kD", .25);
		SmartDashboard::PutNumber("Wheel Diameter (in inches)", 8);
		SmartDashboard::PutNumber("Autonomous Turn degrees", degrees);
		SmartDashboard::PutNumber("Autonomous Drive Distance",5);
		hardware->Fleft->SetExpiration(30);
		hardware->Rleft->SetExpiration(30);
		hardware->Fright->SetExpiration(30);
		hardware->Rright->SetExpiration(30);
	}
	//double speed, double distance, int TReset
	void AutonomousInit()
	{
		double Degrees = SmartDashboard::GetNumber("Autonomous Turn degrees", degrees);
		circumference = M_PI*SmartDashboard::GetNumber("Wheel Diameter (in inches)", 8);
		double driveDistance = SmartDashboard::GetNumber("Autonomous Drive Distance", 5);
		hardware->wheelEncoder->SetDistancePerPulse(circumference/(180*4.74));     //prepares encoder for autonomous
		PDStraightDrive(.5,driveDistance,5);
		//hello
	}



	void TeleopPeriodic()

	{
		driver->drive(oi->getJoystickDrive());

		if(oi->getJoystickDrive()->GetRawButton(11)==1)
		{
			hardware->Fleft->Reset();
			hardware->Rleft->Reset();
			hardware->Fright->Reset();
			hardware->Rright->Reset();
			hardware->Fleft->EnableControl();
			hardware->Rleft->EnableControl();
			hardware->Fright->EnableControl();
			hardware->Rright->EnableControl();
			hardware->Fleft->ConfigNeutralMode(CANTalon::kNeutralMode_Jumper);
			hardware->Rleft->ConfigNeutralMode(CANTalon::kNeutralMode_Jumper);
			hardware->Fright->ConfigNeutralMode(CANTalon::kNeutralMode_Jumper);
			hardware->Rright->ConfigNeutralMode(CANTalon::kNeutralMode_Jumper);
		}



		hardware->navx->Reset();


		/*
		//shooter
		if (oi -> getJoystickAux() ->GetRawButton (1)==1)
		{
			hardware->flywheel->Set(1);
			hardware->feeder->Set(1);
		}

		//intake
		else if (oi -> getJoystickAux() ->GetRawButton (2)==1)
		{
			hardware->intake->Set(1);
			hardware->conveyor->Set(1);
		}

		//climber
		else if(oi->getJoystickAux()->GetRawButton(5)==1)
		{
			hardware->climber->Set(1);
		}


		else //turn everything off
		{
			hardware->flywheel->Set(0);
			hardware->feeder->Set(0);
			hardware->intake->Set(0);
			hardware->conveyor->Set(0);
			hardware->climber->Set(0);
			hardware->Fleft->Set(0);
			hardware->Rleft->Set(0);
			hardware->Fright->Set(0);
			hardware->Rright->Set(0);
		}
		*/
	}
};

START_ROBOT_CLASS(Robot);
