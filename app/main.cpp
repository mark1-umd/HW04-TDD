/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file main.cpp
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

int main()
{
  PIDController myController;
  myController.reset();
  myController.setKp(5);
  std::cout << "myController correction is "
            << myController.computeCorrection(1, 5, 1) << std::endl;
  return 0;
}
