/****************************************************************************
* Copyright (C) 2017 by KPIT Technologies                                  *
*                                                                          *
****************************************************************************/
/**
* @file     number_generator_factory.cc
* @author   Rajat Jayanth Shetty <rajat.shetty@kpit.com>
* @date     18 Oct 2017
* @brief    This file declares Number Generator Factory Class
*
*/

/* include files */
#include "ros_number_generator/core/number_generator_interface.h"
#include "ros_number_generator/core/number_generator_factory.h"

/**
* Function name: NumberGeneratorFactory()
*
* @brief Constructor for the Number Generator Factory class
*
* Initializes the Number Generator factory class
**/
NumberGeneratorFactory::NumberGeneratorFactory() {
  number_generator_ = nullptr;
}

/**
* Function name: ~NumberGeneratorFactory()
*
* @brief Destructor for the Number Generator Factory class
*
**/
NumberGeneratorFactory::~NumberGeneratorFactory() {
  if ( nullptr != number_generator_ ) {
    delete number_generator_;
    number_generator_ = nullptr;
  }
}

/**
* Function name: CreateGenerator()
*  
* @brief Receives an instance for the Number Generator
*
* If an instance of Number generator already exist, the current method will 
* delete the previous instance before assigning a new Number Generator
*
**/
void NumberGeneratorFactory::CreateGenerator(NumberGenerator *p_number_generator) {
  if ( nullptr != number_generator_ ) {
    delete number_generator_;
    number_generator_ = nullptr;
  }
  number_generator_ = p_number_generator;
}

uint32_t NumberGeneratorFactory::ExecuteGenerator() const {  
  if ( nullptr != number_generator_ )  
    return  number_generator_->GetGeneratedNumber();
  return 0;
}
