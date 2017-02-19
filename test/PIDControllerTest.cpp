/**
 * @copyright (c) 2017 Mark R. Jenkins.  All rights reserved.
 * @file PIDControllerTest.cpp
 *
 * @author MJenkins, ENPM 808X Spring 2017
 * @date Feb 19, 2017 - Creation
 *
 * @brief Unit testing for PIDController class
 *
 *
 */

#include <gtest/gtest.h>
#include <memory>
#include "../app/PIDController.hpp"

TEST(PIDControllerTest, testProportionalCoefficient) {
  std::shared_ptr<PIDController> aController =
      std::make_shared<PIDController>();
 aController->reset();
 aController->setKp(5);
  EXPECT_EQ(0, aController->computeCorrection(0, 0, 1));
//  EXPECT_EQ(25, aController->computeCorrection(5, 0, 2));
}

