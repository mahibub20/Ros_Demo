/****************************************************************************
* Copyright (C) 2017 by KPIT Technologies                                  *
*                                                                          *
****************************************************************************/

/**
* @file		Number Arithmetic Interface
* @author       Sasi Kiran	
* @date         18 oct 2017
* @brief        Interface class for Number Arithmetic Operations
*
*
**/

#ifndef __NUMBER_MULTIPLIER_H_
#define __NUMBER_MULTIPLIER_H_

/* include files */
#include <ros/types.h>

class NumberArithmeticInterface {
 public:  
  /**
  * Function name: DoArithmeticOperation
  *
  * @brief Perform number arithmetic operation
  *
  * @param[in]	uint32_t value1 this is first number for arithmetic operation
  *
  * @param[in]	uint32_t value2 this is second number for arithmetic operation
  *
  * @return	uint32_t retrun value after arithmetic opeation is done 
  **/
  virtual uint32_t DoArithmeticOperation(uint32_t, uint32_t) = 0;

 protected:
  /**
  * Function name: DisplayResult
  *
  * @brief Display result
  *
  * @param[in]	uint32_t value this is first number for arithmetic operation
  *
  * @return	void 
  **/
  virtual void DisplayResult(uint32_t value) = 0;

};

#endif
