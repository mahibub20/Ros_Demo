/****************************************************************************
* Copyright (C) 2017 by KPIT Technologies                                  *
*                                                                          *
****************************************************************************/

/**
* @file		Number Arithmetic Factory
* @author       Sasi Kiran	
* @date         18 oct 2017
* @brief        Implementation class for factory
*
*
**/
#include <cstddef>

#include "ros_arithmetic/core/number_arithmetic_factory.h"

NumberArithmeticFactory::NumberArithmeticFactory() {
  number_arithmetic_ = nullptr;
}
NumberArithmeticFactory::~NumberArithmeticFactory() {
  if ( nullptr != number_arithmetic_ ) {
    delete number_arithmetic_;
    number_arithmetic_ = nullptr;
  }
}

void NumberArithmeticFactory::CreateArithmeticOperation(NumberArithmeticInterface *number_arithmetic) {
  if ( nullptr != number_arithmetic_ ) {
    delete number_arithmetic_;
    number_arithmetic_ = nullptr;
  }
  number_arithmetic_ = number_arithmetic;
}

uint32_t NumberArithmeticFactory::ExecuteArithmeticOperation(uint32_t value1, uint32_t value2)
{
  if( nullptr != number_arithmetic_ )
    return number_arithmetic_->DoArithmeticOperation(value1, value2);
  return 0;
}

