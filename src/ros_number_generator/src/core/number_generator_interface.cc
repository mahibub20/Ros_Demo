/****************************************************************************
* Copyright (C) 2017 by KPIT Technologies                                  *
*                                                                          *
****************************************************************************/

/**
* @file
* @author
* @date
* @brief
*
*
*/
#include "ros_number_generator/core/number_generator_interface.h"

NumberGenerator::NumberGenerator(uint32_t _nMaxRandomValue, uint32_t _nMinRandomValue)
  : current_random_number_(0) {
  SetRandomValRange(_nMaxRandomValue, _nMinRandomValue);
}

NumberGenerator::~NumberGenerator() {

}

uint32_t NumberGenerator::GetCurrentRandomNumber() {
  return current_random_number_;
}

void NumberGenerator::SetRandomValRange(uint32_t _nMaxRandomValue, uint32_t _nMinRandomValue) {
  if (_nMaxRandomValue > _nMinRandomValue) {
    max_random_value_ = _nMaxRandomValue;
    min_random_value_ = _nMinRandomValue;
  }
  else {
    max_random_value_ = _nMinRandomValue;
    min_random_value_ = _nMaxRandomValue;
  }
}

uint32_t NumberGenerator::GetNumber() {
  current_random_number_ = min_random_value_ + (GenerateNumber()%(max_random_value_ - min_random_value_));
  return current_random_number_;
}
