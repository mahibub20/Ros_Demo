/****************************************************************************
* 		Copyright (C) 2017 by KPIT Technologies                     *
*                                                                           *
****************************************************************************/

/**
* @file      publish_subscribe.cc
*
* @author    Sujeyendra Tummala (Tummala.Sujeyendra@kpit.com)
*
* @date      18-Oct- 2017
*
* @brief     This files implements the communication interface class and
*            performs the below features
*              1) Assigns the generator node handler reference
*              2) Advertises the topic that is being published
*              3) Get the random number to be sent form the generator node
*                 handler
*              4) Sends message 
*              5) Receives message through subscribe
**/

/*! Include Files */
#include "ros_number_generator/app/publish_subscribe.h"

/*! Class Declarations */
/**
* @brief Implements the constructor to the publishSubsribe class that 
*        assigns the received generator node handle reference 
*        and advertises the topic to be published
**/
PublishSubscribe::PublishSubscribe(GeneratorNodeHandler *p_generator_node_handler) {
  generator_node_handler = p_generator_node_handler;

  rand_num_publisher = nodeHandle.advertise<ros_ran_num_msg::rand_num>("random_number_srand", 100);
}

/**
* @brief Implements the destructor to the PublishSubscribe class
**/
PublishSubscribe::~PublishSubscribe() {
  if ( generator_node_handler != NULL ) {
       delete generator_node_handler;
       generator_node_handler = NULL;
  }   
}

/**
* @brief Implements the functionality to get the generated 
*        random number and publish it
**/
void PublishSubscribe::SendMessage() {
  ros::Rate rate(1);
  ros_ran_num_msg::rand_num value;
  
  while( nodeHandle.ok() ) {
    value.number1 = generator_node_handler->GetNumber();
    value.number2 = generator_node_handler->GetNumber();

    rand_num_publisher.publish(value);

    ROS_INFO("Number Generator Value 1: [%u] and Value 2: [%u]", value.number1, value.number2);
    
    ros::spinOnce();
    rate.sleep();
  }
}

/**
* @brief Implements the functionality to receive the message
**/
void PublishSubscribe::ReceiveMessage() {
}
