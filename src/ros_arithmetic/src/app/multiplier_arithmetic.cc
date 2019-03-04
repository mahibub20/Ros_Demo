/****************************************************************************
* Copyright (C) 2017 by KPIT Technologies                                  *
*                                                                          *
****************************************************************************/

/**
* @file		Multiplier Arithmetic
* @author       Sasi Kiran	
* @date         18 oct 2017
* @brief        Implementation class for multiplication functionality
*
*
**/

/* include files */
#include "ros_arithmetic/app/multiplier_arithmetic.h"
#include "ros/ros.h"

NumberMultiplier::NumberMultiplier(): multiplier_value_(0) {
}

NumberMultiplier::~NumberMultiplier() {
}

uint32_t NumberMultiplier::DoArithmeticOperation(uint32_t value1, uint32_t value2) { 
  return DoMultiplication(value1, value2);
}

uint32_t NumberMultiplier::DoMultiplication(uint32_t value1, uint32_t value2) {
  multiplier_value_ = (value1)*(value2);
  return multiplier_value_;
}

void NumberMultiplier::DisplayResult(uint32_t value) {
}

