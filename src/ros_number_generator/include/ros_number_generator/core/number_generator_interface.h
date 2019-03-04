/****************************************************************************
* Copyright (C) 2017 by KPIT Technologies                                  *
*                                                                          *
****************************************************************************/
/**
* @file number_generator_interface.h
* @author Rajat Jayanth Shetty  <rajat.shetty@kpit.com>
* @date 18 Oct 2017
* @brief    Interface file for Number generator implementation
*
* This file contains the interface details based on which the Random Generator 
* implemenation is done 
*/

#ifndef NUMBER_GENERATOR_INTERFACE_H
#define NUMBER_GENERATOR_INTERFACE_H

/* include files */
#include <string>

class NumberGenerator {
 public:
  /**
  * Function name: SetRandomValRange()
  *
  * @brief Interface to set the the random genrator range
  *
  * The implementation is defined in the derived class of the interface file
  *
  * @param[in]	uint32_t  max_random_value Maximum range the Random Generator should generate values within
  * @param[in   uint32_t  min_random_value Minimum range the Random Generator should generate values within
  *
  * @return		 void
  **/
  virtual void SetRandomValRange(uint32_t max_random_value, uint32_t min_random_value) = 0;

  /**
  * Function name: GetGeneratedNumber()
  *
  * @brief Interface to query for Number generator to provide a Random number
  *
  * The implementation is defined in the derived class of the interface file
  *
  * @param[in]	None
  *
  * @return		 uint32_t Returns a Random number generated
  **/
  virtual uint32_t GetGeneratedNumber() = 0;

  /**
  * Function name: GetGeneratorName()
  *
  * @brief Interface to query Generator name or Implementation name
  *
  * The implementation is defined in the derived class of the interface file
  *
  * @param[in]	None
  *
  * @return		 std::string  String containing the name of the Random Generator implementation
  **/
  virtual std::string GetGeneratorName() = 0;

 protected:
  /**
  * Function name: GenerateNumber()
  *
  * @brief       Interface containing the actual implementation of the Number Generator
  *
  * The implementation is defined in the derived class of the interface file
  *
  * @param[in]	  None
  *
  * @return		  uint32_t Generates and returns the number generated by the impelementation
  **/
  virtual uint32_t GenerateNumber() = 0;

};
#endif /* NUMBER_GENERATOR_INTERFACE_H*/