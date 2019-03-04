/****************************************************************************
* Copyright (C) 2017 by KPIT Technologies                                  *
*                                                                          *
****************************************************************************/
/**
* @file		Multiplier Node Handler
* @author       Sasi Kiran <Sasi.Alur@kpit.com>
* @author       Rajat Jayanth Shetty  <rajat.shetty@kpit.com>	
* @author       Sujeyndra Tummala	<Tummala.Sujeyendra@kpit.com>
* @date         18 oct 2017
* @brief        Perform factory creation and processing data functionalities
*
*
**/

/* include files */
#include "ros_arithmetic/app/multiplier_node_handler.h"
#include "ros_arithmetic/app/publish_subscribe.h"
#include "ros_arithmetic/app/multiplier_arithmetic.h"

MultiplierNodeHandler::MultiplierNodeHandler() {
  CreateMultiplierFactory();
  CreateCommunicationFactory();
}

MultiplierNodeHandler::~MultiplierNodeHandler() {
  if(nullptr != arithmetic_factory_){
    delete  arithmetic_factory_;
    arithmetic_factory_ = nullptr;
  }

  if(nullptr != communication_factory_){
    delete communication_factory_;
    communication_factory_ = nullptr ;
  }
}

void MultiplierNodeHandler::CreateMultiplierFactory() {
  arithmetic_factory_ = new NumberArithmeticFactory();
  arithmetic_factory_->CreateArithmeticOperation(new NumberMultiplier());  
}

void MultiplierNodeHandler::CreateCommunicationFactory() {
  communication_factory_ = new CommFactory();
  communication_factory_->CreateCommunicator(new PublishSubscribe(this));
}

void MultiplierNodeHandler::Execute() { 
  if( nullptr != communication_factory_ ) 
    communication_factory_->ExecuteCommunication();
}

uint32_t MultiplierNodeHandler::ProcessData(uint32_t value1, uint32_t value2) {  
  if( nullptr != arithmetic_factory_ )   
    return arithmetic_factory_->ExecuteArithmeticOperation(value1, value2);
  return 0;
}
