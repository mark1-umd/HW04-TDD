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

// Test acceleration and deceleration with only Kp non-zero
TEST(PIDControllerTest, testKpBasicAcelDecel) {
  std::shared_ptr<PIDController> theController =
      std::make_shared<PIDController>();

  // Establish basic testing parameters
  theController->reset();
  theController->setKp(5);
  theController->setKi(0);
  theController->setKd(0);

  // Progress through modeled behavior
  EXPECT_DOUBLE_EQ(0, theController->computeCorrection(0, 0, 1));
  EXPECT_DOUBLE_EQ(25, theController->computeCorrection(5, 0, 2));
  EXPECT_DOUBLE_EQ(0, theController->computeCorrection(5, 5, 3));
  EXPECT_DOUBLE_EQ(-25, theController->computeCorrection(0, 5, 4));
  EXPECT_DOUBLE_EQ(0, theController->computeCorrection(0, 0, 5));
}

// Test acceleration and deceleration with only Ki non-zero
TEST(PIDControllerTest, testKiBasicAcelDecel) {
  std::shared_ptr<PIDController> theController =
      std::make_shared<PIDController>();

  // Establish basic testing parameters
  theController->reset();
  theController->setKp(0);
  theController->setKi(5);
  theController->setKd(0);

  // Progress through modeled behavior
  EXPECT_DOUBLE_EQ(0, theController->computeCorrection(0, 0, 1));
  EXPECT_DOUBLE_EQ(25, theController->computeCorrection(5, 0, 2));
  EXPECT_DOUBLE_EQ(25, theController->computeCorrection(5, 5, 3));
  EXPECT_DOUBLE_EQ(0, theController->computeCorrection(0, 5, 4));
  EXPECT_DOUBLE_EQ(-25, theController->computeCorrection(0, 5, 5));
  EXPECT_DOUBLE_EQ(0, theController->computeCorrection(0, -5, 6));
  EXPECT_DOUBLE_EQ(0, theController->computeCorrection(0, 0, 7));
}

// Test acceleration and deceleration with only Kd non-zero
TEST(PIDControllerTest, testKdBasicAcelDecel) {
  std::shared_ptr<PIDController> theController =
      std::make_shared<PIDController>();

  // Establish basic testing parameters
  theController->reset();
  theController->setKp(0);
  theController->setKi(0);
  theController->setKd(5);

  // Progress through modeled behavior
  EXPECT_DOUBLE_EQ(0, theController->computeCorrection(0, 0, 1));
  EXPECT_DOUBLE_EQ(25, theController->computeCorrection(5, 0, 2));
  EXPECT_DOUBLE_EQ(-25, theController->computeCorrection(5, 5, 3));
  EXPECT_DOUBLE_EQ(0, theController->computeCorrection(5, 5, 4));
  EXPECT_DOUBLE_EQ(-25, theController->computeCorrection(0, 5, 5));
  EXPECT_DOUBLE_EQ(25, theController->computeCorrection(0, 0, 6));
  EXPECT_DOUBLE_EQ(0, theController->computeCorrection(0, 0, 7));
}
