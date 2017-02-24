/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file PIDController.cpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Feb 18, 2017 - Creation
 *
 * @brief Homework Week 04 - Test Driven Development assignment
 *
 * Requirements: Create a new class declaration for a PID
 * controller that computes a new velocity given a target setpoint
 * and an actual velocity.  Your class must include private Kp,
 * Ki, and Kd members.  Note: Although the requirements state that
 * the process variable is "velocity," the PID controller model is
 * generic enough that the implementation of the class does not need
 * to be limited to "velocity", so the concepts used are "set point",
 * "process variable", and "the correction to apply to the plant".
 *
 */

 #include "PIDController.hpp"
 #include <iostream>

 PIDController::PIDController()
 {
 // TODO Auto-generated constructor stub

 }

 PIDController::~PIDController()
 {
 // TODO Auto-generated destructor stub
 }

 /** @brief Set the private variable for the coeffecient Kp
 * @param [in] pKp a double the specifies the value to set for Kp
 */
void PIDController::setKp(const double pKp) {
	coeffKp = pKp;
}

/** @brief Set the private variable for the coeffecient Ki
 * @param [in] pKi a double the specifies the value to set for Ki
 */
void PIDController::setKi(const double pKi) {
	coeffKi = pKi;
}

/** @brief Set the private variable for the coeffecient Kd
 * @param [in] pKd a double the specifies the value to set for Kd
 */
void PIDController::setKd(const double pKd) {
	coeffKd = pKd;
}

/** @brief Reset private internal state variables to 0
 */
void PIDController::reset() {
	previousTime = 0;
	integral = 0.0;
	previousError = 0.0;
}

/** @brief Compute the correction to the plant based on the set point and process variable
 * @param [in] setPoint a double for the current setpoint for the plant's output
 * @param [in] processVariable a double for the current measurement of plant output
 * @param [in] time an integer for the current elapsed time in abstract time ticks
 */
double PIDController::computeCorrection(const double setPoint,
                                        const double processVariable,
                                        const int time) {

	//Calculate time.
	int dt = time-previousTime;
	//Calculate error
	double error = setPoint - processVariable;
	//Add error to integral
	integral += error*dt;
	//Calculate deviation
	double derivative = (error - previousError)/dt;

	//Store both previous Error and previous Time values.
	previousError = error;
	previousTime = time;

	return (coeffKp*error + coeffKi*integral + coeffKd*derivative);
}

