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

/*  include files */
#include "ros_number_generator/app/generator_node_handler.h"
#include "ros_number_generator/app/publish_subscribe.h"

/**
* @brief Default values for Random generator Range
**/
namespace constVariables {
  constexpr uint32_t MAX_RANDOM_VALUE = 1000;
  constexpr uint32_t MIN_RANDOM_VALUE = 0;
}

/**
 * Function name: GeneratorNodeHandler()
 *
 * @brief Constructor for the Node Handler
**/
GeneratorNodeHandler::GeneratorNodeHandler() {
  CreateNumberFactory();
  CreateCommunicationFactory();
}

/**
 * Function name: ~GeneratorNodeHandler()
 * 
 * @brief Destructor for the Node Handler
 *
 * Deletes the instance of COmmunication Factory and
 * number generator factory 
**/
GeneratorNodeHandler::~GeneratorNodeHandler() {
  if(NULL != number_generator_){
	  delete  number_generator_;
	  number_generator_ = NULL;
  }

  if(NULL != communication_factory_) {
  	delete communication_factory_;
	communication_factory_ = NULL;
  }
}

/**
* Function name: CreateNumberFactory
*
* @brief Call number generator factory and Create generator object
* 
**/
void GeneratorNodeHandler::CreateNumberFactory() {
  number_generator_ = new NumberGeneratorFactory();
  number_generator_->CreateGenerator(new NumberGeneratorLCG(constVariables::MAX_RANDOM_VALUE,constVariables::MIN_RANDOM_VALUE));
}

/**
* Function name: GetCommunicationFactory
*
* @brief Get the created communication object by factory 
*   
**/
void GeneratorNodeHandler::CreateCommunicationFactory() {
  communication_factory_ = new CommFactory();
  communication_factory_->CreateCommunicator(new PublishSubscribe(this));
}

void GeneratorNodeHandler::Execute()
{
  if( nullptr != communication_factory_ )  
    communication_factory_->ExecuteCommunication();
}

/**
* Function name: GetNumber
*
* @brief Get random value geeratedusing the generator Factory Node
* 
**/
uint32_t GeneratorNodeHandler::GetNumber() {
  if( nullptr != number_generator_ )
    return number_generator_->ExecuteGenerator();
  return 0;
}

