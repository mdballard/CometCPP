// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "StrafingDrive.h"
#include "Commands/MoveStrafeDrive.h"

#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

StrafingDrive::StrafingDrive() : Subsystem("StrafingDrive") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	strafeRightTalon = RobotMap::strafingDriveStrafeRightTalon;
	strafeLeftTalon = RobotMap::strafingDriveStrafeLeftTalon;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Config();
}
    
void StrafingDrive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new MoveStrafeDrive());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void StrafingDrive::SetDrive_Arcade(float x, bool highRate)
{
	if (highRate)
	{
		Master->Set(Limit(x)*HighSpeedRate);
	} else
	{
		Master->Set(Limit(x)*LowSpeedRate);
	}
}

void StrafingDrive::LinearDrive(float inches)
{
	Master->Set(inches*PulsesPerInch);
}

void StrafingDrive::Stop()
{
	strafeRightTalon->Disable();
	strafeLeftTalon->Disable();
}

void StrafingDrive::Set_PositionMode()
{
	Master->SetControlMode(CANSpeedController::kPosition);
}

void StrafingDrive::Set_VoltageMode()
{
	Master->SetControlMode(CANSpeedController::kPercentVbus);
}

void StrafingDrive::Zero_Encoder()
{
	Master->SetPosition(0);
}

int StrafingDrive::Get_Encoder()
{
	return Master->GetEncPosition();
}

void StrafingDrive::Config()
{
	int masterCan;
	PulsesPerInch = Preferences::GetInstance()->GetInt("StrafingDrive::QuadEncoder::PulsesPerInch");
	HighSpeedRate = Preferences::GetInstance()->GetFloat("StrafingDrive::HighSpeed");
	LowSpeedRate  = Preferences::GetInstance()->GetFloat("StrafingDrive::LowSpeed");

	if (Preferences::GetInstance()->GetBoolean("StrafingDrive::RightTalon::Slaved"))
	{
		Master = strafeLeftTalon;
		Slave = strafeRightTalon;
		masterCan = Preferences::GetInstance()->GetInt("StrafingDrive::RightTalon::MasterCANID");

	} else
	{
		Master = strafeRightTalon;
		Slave = strafeLeftTalon;
		masterCan = Preferences::GetInstance()->GetInt("StrafingDrive::LeftTalon::MasterCANID");
	}
	Set_VoltageMode();
	Slave->SetControlMode(CANSpeedController::kFollower);
	Slave->Set(masterCan);

	if (Preferences::GetInstance()->GetBoolean("StrafingDrive::RightTalon::EnablePID"))
	{
		strafeRightTalon->SetFeedbackDevice(CANTalon::QuadEncoder);
		if (Preferences::GetInstance()->GetBoolean("StrafingDrive::RightTalon::SensorReversed"))
		{
			strafeRightTalon->SetSensorDirection(true);
		} else
		{
			strafeRightTalon->SetSensorDirection(false);
		}
		strafeRightTalon->SetP(Preferences::GetInstance()->GetDouble("StrafingDrive::RightTalon::PID::P"));
		strafeRightTalon->SetI(Preferences::GetInstance()->GetDouble("StrafingDrive::RightTalon::PID::I"));
		strafeRightTalon->SetD(Preferences::GetInstance()->GetDouble("StrafingDrive::RightTalon::PID::D"));
		strafeRightTalon->SetF(Preferences::GetInstance()->GetDouble("StrafingDrive::RightTalon::PID::F"));
		if(Preferences::GetInstance()->GetBoolean("StrafingDrive::RightTalon::EnableVoltRampRate"))
		{
			strafeRightTalon->SetVoltageRampRate(Preferences::GetInstance()->GetDouble("StrafingDrive::RightTalon::VoltRampRate"));
		}

		if (Preferences::GetInstance()->GetBoolean("StrafingDrive::RightTalon::EnableCLRampRate"))
		{
			strafeRightTalon->SetCloseLoopRampRate(Preferences::GetInstance()->GetDouble("StrafingDrive::RightTalon::CLRampRate"));
		}

		strafeRightTalon->SetIzone(Preferences::GetInstance()->GetInt("StrafingDrive::RightTalon::IZone"));
	}

	if (Preferences::GetInstance()->GetBoolean("StrafingDrive::LeftTalon::EnablePID"))
	{
		strafeLeftTalon->SetFeedbackDevice(CANTalon::QuadEncoder);
		if (Preferences::GetInstance()->GetBoolean("StrafingDrive::LeftTalon::SensorReversed"))
		{
			strafeLeftTalon->SetSensorDirection(true);
		} else
		{
			strafeLeftTalon->SetSensorDirection(false);
		}
		strafeLeftTalon->SetP(Preferences::GetInstance()->GetDouble("StrafingDrive::LeftTalon::PID::P"));
		strafeLeftTalon->SetI(Preferences::GetInstance()->GetDouble("StrafingDrive::LeftTalon::PID::I"));
		strafeLeftTalon->SetD(Preferences::GetInstance()->GetDouble("StrafingDrive::LeftTalon::PID::D"));
		strafeLeftTalon->SetF(Preferences::GetInstance()->GetDouble("StrafingDrive::LeftTalon::PID::F"));
		if(Preferences::GetInstance()->GetBoolean("StrafingDrive::LeftTalon::EnableVoltRampRate"))
		{
			strafeLeftTalon->SetVoltageRampRate(Preferences::GetInstance()->GetDouble("StrafingDrive::LeftTalon::VoltRampRate"));
		}

		if (Preferences::GetInstance()->GetBoolean("StrafingDrive::LeftTalon::EnableCLRampRate"))
		{
			strafeLeftTalon->SetCloseLoopRampRate(Preferences::GetInstance()->GetDouble("StrafingDrive::LeftTalon::CLRampRate"));
		}

		strafeLeftTalon->SetIzone(Preferences::GetInstance()->GetInt("StrafingDrive::LeftTalon::IZone"));
	}

}

float StrafingDrive::Limit(float num)
{
	if (num > 1.0)
	{
		return 1.0;
	}
	if (num < -1.0)
	{
		return -1.0;
	}
	return num;
}
