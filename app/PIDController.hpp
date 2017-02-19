/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file PIDController.hpp
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

 #ifndef CPP_BOILERPLATE_APP_PIDCONTROLLER_HPP_
 #define CPP_BOILERPLATE_APP_PIDCONTROLLER_HPP_

 /** @brief Represents a PID controller
 *
 * A PID controller continuously calculates an error value e(t) as
 * the difference between a desired setpoint and a measured
 * process variable and applies a correction based on proportional,
 * integral, and derivative terms (sometimes denoted P, I, and D
 * respectively) which give their name to the controller type.
 * Note: the system being controlled is often called "the plant"
 * See <https://en.wikipedia.org/wiki/PID_controller>
 *
 */

 class PIDController {
 public:
 PIDController();
 virtual ~PIDController();

  /** @brief Set the private variable for the coeffecient Kp
   * @param [in] pKp a double the specifies the value to set for Kp
   */
 void setKp(const double pKp);

  /** @brief Set the private variable for the coeffecient Ki
   * @param [in] pKi a double the specifies the value to set for Ki
   */
 void setKi(const double pKi);

  /** @brief Set the private variable for the coeffecient Kd
   * @param [in] pKd a double the specifies the value to set for Kd
   */
 void setKd(const double pKd);

  /** @brief Reset private internal state variables to 0
   */
 void reset();

  /** @brief Compute the correction to the plant based on the set point and process variable
   * @param [in] setPoint a double for the current setpoint for the plant's output
   * @param [in] processVariable a double for the current measurement of plant output
   * @param [in] time an integer for the current elapsed time in abstract time ticks
   */
 double computeCorrection(const double setPoint, const double processVariable,
 const int time);

 private:
  // private storage for the PID coefficients
  double coeffKp, coeffKi, coeffKd;

  // private storage for internal state variables
  double previousError, integral;
  int previousTime;
 };


 #endif /* CPP_BOILERPLATE_APP_PIDCONTROLLER_HPP_ */
