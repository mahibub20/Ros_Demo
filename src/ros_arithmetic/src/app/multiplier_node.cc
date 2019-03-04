/****************************************************************************
* Copyright (C) 2017 by KPIT Technologies                                  *
*                                                                          *
****************************************************************************/
/**
* @file		Multiplier Node
* @author       Sasi Kiran	
* @date         18 oct 2017
* @brief        Class to create Multiplier Node Handler
*
**/

/* include files */
#include <sstream>
#include <memory>

#include "ros_arithmetic/app/multiplier_node_handler.h"
#include "ros/ros.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "MultiplierNode");

  std::unique_ptr<MultiplierNodeHandler> multiplierObj(new MultiplierNodeHandler());
  multiplierObj->Execute();
  ros::spin();

  return 0;
}
