/****************************************************************************
* Copyright (C) 2017 by KPIT Technologies                                  *
*                                                                          *
****************************************************************************/

/**
* @file		Multiplier Node Handler
* @author       Sasi Kiran	
* @date         18 oct 2017
* @brief        Perform multiplication functionality
*
*
**/
#ifndef MULTIPLIER_ARITHMETIC_H_
#define MULTIPLIER_ARITHMETIC_H_

#include "ros_arithmetic/core/number_arithmetic_interface.h"

class NumberMultiplier : public NumberArithmeticInterface {
 public:
  /**
  * Constructor
  * @brief Construct number arithmetic object
  **/
  NumberMultiplier();
  /**
  * Destructor
  * @brief Destruct number arithmetic object
  **/
  ~NumberMultiplier();
  /**
  * Function name: DoArithmeticOperation
  *
  * @brief Perfom arithmetic operation
  * 
  *
  * @param[in]	uint32_t  value1 This is first parameter for arithmetic operation
  *
  * @param[in]	uint32_t  value2 This is second parameter for arithmetic operation
  *
  * @return	uint32_t  return value after operation is done
  **/
  uint32_t DoArithmeticOperation(uint32_t value1,
                                  uint32_t value2);
  /**
  * Function name: DisplayResult
  *
  * @brief Display result
  *
  * @param[in]	uint32_t value this is first number for arithmetic operation
  *
  * @return	void 
  **/
  void DisplayResult(uint32_t value);

 private:
  /**
  * Function name: DoMultiplication
  *
  * @brief Perfom multiplication operation
  * 
  *
  * @param[in]	uint32_t  value1 This is first parameter for multiplication operation
  *
  * @param[in]	uint32_t  value2 This is second parameter for multiplication operation
  *
  * @return	uint32_t  return value after operation is done
  **/
  uint32_t DoMultiplication(uint32_t value1, uint32_t value2);
  //  Multiplier value member variable
  uint32_t multiplier_value_; 
};

#endif /* __MULTIPLIER_ARITHMETIC_H_ */
