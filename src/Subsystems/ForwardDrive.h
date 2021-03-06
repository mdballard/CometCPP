// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef FORWARDDRIVE_H
#define FORWARDDRIVE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class ForwardDrive: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	int LeftPulsesPerInch;
	int RightPulsesPerInch;
	int PulsesPerDeg;
	float HighSpeedRate;
	float LowSpeedRate;
	float leftMotorOutput;
	float rightMotorOutput;

public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	CANTalon* forwardLeftTalon;
	CANTalon* forwardRightTalon;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	ForwardDrive();
	void InitDefaultCommand();
	void SetDrive_Arcade(float x, float y, bool highRate = false);
	void SetDrive_Tank(float left, float right, bool highRate = false);
	void LinearDrive(float inches);
	void Pivot(float degrees);

	void Stop();
	void Set_PositionMode();
	void Set_VoltageMode();
	void Zero_Encoders();
	int Get_LeftEncoder();
	int Get_RightEncoder();
	void Config();
	float Limit(float num);
};

#endif
