/****************************************************************************
* Copyright (C) 2017 by KPIT Technologies                                  *
*                                                                          *
****************************************************************************/
/**
* @file     number_generator_factory.h
* @author   Rajat Jayanth Shetty <rajat.shetty@kpit.com>
* @date     18 Oct 2017
* @brief    This file declares Number Generator Factory Class
*
*/
#ifndef NUMBER_GENERATOR_FACTORY_H
#define NUMBER_GENERATOR_FACTORY_H

/* include files */
#include "ros_number_generator/core/number_generator_interface.h"

class NumberGeneratorFactory {
 public:
  /**
  * Function name: NumberGeneratorFactory()
  *
  * @brief Constructor for the Number Generator Factory class
  *
  * @param[in]	None
  *
  * @return		void
  **/
  NumberGeneratorFactory();
  
  /**
  * Function name: ~NumberGeneratorFactory()
  *
  * @brief Destructor for the Number Generator Factory class
  *
  * @param[in]	None
  *
  * @return		void
  **/
  ~NumberGeneratorFactory();

  /**
  * Function name: CreateGenerator()
  *
  * @brief Receives an instance for the Number Generator
  *
  * @param[in]	NumberGenerator pGenerator contains the data pointer to the 
  *             instance of the Number generator
  *
  * @return		void
  **/
  void CreateGenerator(NumberGenerator* pGenerator);
  
  /**
  * Function name: ExecuteGenerator
  *
  * @brief Execute generator and return generated value
  *
  * @param[in]	None
  *
  * @return	uint32_t  return generated value
  **/
  uint32_t ExecuteGenerator() const;

 private:
  NumberGenerator *number_generator_;   //  Data pointer to the number generator 
};
#endif
