/****************************************************************************
* Copyright (C) 2017 by KPIT Technologies                                  *
*                                                                          *
****************************************************************************/
/**
* @file		Number Generator Node
* @author       Rajat Jayanth Shetty <Rajat.Shetty@kpit.com>
* @date         18 Oct 2017
* @brief        Entry point for the Random Generator Node
*
**/

/*  include files  */
#include <memory>

#include "ros/ros.h"
#include "ros_number_generator/app/generator_node_handler.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "NumberGeneratorNode");

  std::unique_ptr<GeneratorNodeHandler> randNumberObj(new GeneratorNodeHandler());
  randNumberObj->Execute();
  return 0;
}

