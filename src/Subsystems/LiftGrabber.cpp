// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "LiftGrabber.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

static bool ActiveIsClosed = true;

LiftGrabber::LiftGrabber() : Subsystem("LiftGrabber") {
	opened = true;
	ActiveIsClosed = Preferences::GetInstance()->GetBoolean("LiftGrabber::ActiveIsClosed");

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	liftGrabberSolenoid = RobotMap::liftGrabberLiftGrabberSolenoid;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Open();
}
    
void LiftGrabber::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void LiftGrabber::Open()
{
	liftGrabberSolenoid->Set(!ActiveIsClosed);
	opened = true;
}

void LiftGrabber::Close()
{
	liftGrabberSolenoid->Set(ActiveIsClosed);
	opened = false;
}

void LiftGrabber::Toggle()
{
	if (Is_Open())
	{
		Close();
	} else
	{
		Open();
	}
}


bool LiftGrabber::Is_Open()
{
	return opened;
}

