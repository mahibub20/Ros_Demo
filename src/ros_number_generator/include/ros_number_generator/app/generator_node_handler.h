/****************************************************************************
* Copyright (C) 2017 by KPIT Technologies                                  *
*                                                                          *
****************************************************************************/
/**
* @file		Generator Node Handler
* @author       Rajat Jayanth Shetty <Rajat.Shetty@kpit.com>
* @author       Sujeyendra Tummala <Tummala.Sujeyendra@kpit.com>
* @author       Sasi Kiran Alur	<Sasi.Alur@kpit.com> 
* @date         18 Oct 2017
* @brief        Perform factory creation and processing data functionalities
*
*
**/
#ifndef GENERATOR_NODE_H
#define GENERATOR_NODE_H

/*  include files  */
#include "ros_number_generator/core/communication_factory.h"
#include "ros_number_generator/core/number_generator_factory.h"
#include "ros_number_generator/app/number_generator_srand.h"
#include "ros_number_generator/app/number_generator_lcg.h"

class GeneratorNodeHandler {
 public:
  /**
  * Function name: GeneratorNodeHandler()
  *
  * @brief Constructor for the Node Handler
  **/
  GeneratorNodeHandler();
  
  /**
  * Function name: ~GeneratorNodeHandler()
  * 
  * @brief Destructor for the Node Handler
  **/
  ~GeneratorNodeHandler();

  /**
  * Function name: GetNumber
  *
  * @brief Get random value generated using the generator Factory Node
  * 
  * @return	uint32_t  return value of result
  **/
  uint32_t GetNumber();

  /**
  * Function name: Execute
  *
  * @brief Execute the Generator and communication functionalities
  *
  * @return	void
  **/
  void Execute();

 private:
  /**
  * Function name: CreateNumberFactory
  *
  * @brief Call number generator factory and Create generator object
  * 
  * @return	void
  **/
  void CreateNumberFactory();

  /**
  * Function name: CreateCommunicationFactory
  *
  * @brief Call communication factory and Create communication object
  * 
  * @return	void
  **/
  void CreateCommunicationFactory();
  

  NumberGeneratorFactory* number_generator_; // Pointer to generator factory
  CommFactory*   communication_factory_;   // Pointer to communication factory
};
#endif /* GENERATOR_NODE_H */
