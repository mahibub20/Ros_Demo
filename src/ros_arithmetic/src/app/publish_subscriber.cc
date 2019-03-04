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
*              1) Create a receiver callback object and assigs it with the 
*                 node handler reference
*              2) Gets the multiplier result for the received value
*              3) Sends message 
*              4) Receives message through subscribe
**/

/*! Include Files */
#include "ros_arithmetic/app/publish_subscribe.h"

/*! Class Declarations */
/**
* @brief Implements the constructor to the receiver callback class that assigns
*        the multiplier node handle reference to the received reference
**/
ReceiverCallback::ReceiverCallback(MultiplierNodeHandler *node_handler) {
  node_handler_ = node_handler;
}

/**
* @brief Implements the destructor to the receiver callback class
**/
ReceiverCallback::~ReceiverCallback() {
}

/**
* @brief Implements the callback function that get the multiplier of received values         
**/
void ReceiverCallback::MultiplierCallback(const ros_ran_num_msg::rand_num::ConstPtr& value) {
  ROS_INFO("Node Received Value 1: [%u] and Value 2: [%u]", value->number1, value->number2);

  uint32_t vresult = node_handler_->ProcessData(value->number1, value->number2);
  ROS_INFO("The Multiplier value is [%u]", vresult);
}

/*! Class Declarations */
/**
* @brief Implements the constructor to the publishSubsribe class that creates an object
*        of receiver callback class and assigns the received multiplier node handle
*        reference to reference callback class
**/
PublishSubscribe::PublishSubscribe(MultiplierNodeHandler *multiplier_node_handler) {
  multiplier_node_handler_ = multiplier_node_handler;
  
  receiver_callback_ = new ReceiverCallback(multiplier_node_handler);
}

/**
* @brief Implements the destructor to the PublishSubscribe class
**/
PublishSubscribe::~PublishSubscribe() {
}

/**
* @brief Implements the functionality to send the message
**/
void PublishSubscribe::SendMessage() {
}

/**
* @brief Implements the functionality to receive the message through ros subscribe
*        and calls the receiver callback function
**/
void PublishSubscribe::ReceiveMessage() {
  multiplier_subscriber_ = node_handle_.subscribe("random_number_srand", 100, &ReceiverCallback::MultiplierCallback, receiver_callback_);
  
  ros::spinOnce();
}
