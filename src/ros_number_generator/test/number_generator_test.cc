#include <gtest/gtest.h>

#include "ros/ros.h"

#include "ros_number_generator/app/generator_node_handler.h"

TEST(MYTEST , TESTVAL)
{
 int val1 = 10;
 int val2 = 20;
 
 EXPECT_EQ(val1,val2);
}

int main(int argc, char **argv) {
  
  testing::InitGoogleTest(&argc, argv);
  int result = RUN_ALL_TESTS();
 
  return result;
}
