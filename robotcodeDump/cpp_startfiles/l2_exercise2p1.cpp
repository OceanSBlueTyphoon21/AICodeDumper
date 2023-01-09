#include "ros/console.h"
#include "rosbot_control/rosbot_class.h"
#include <iostream>
#include <list>
#include <map>
#include <ros/ros.h>
#include <string>

using namespace std;

int main(int argc, char **argv) {
  ros::init(argc, argv, "rosbot_node");

  RosbotClass rosbot;

  // The robot's x position limit
  float x_limit = 5.0;

  // Move the Robot forward for 3 seconds
  rosbot.move_forward(4.0);

  // Get the robot's x position/coordinate
  float x_1 = rosbot.get_position(1);
  ROS_INFO_STREAM(" Robot's x position" << x_1 << "\n");

  // check the Robot's X position if it meets the limit.
  if (x_1 >= x_limit) {
    rosbot.stop_moving();
  } else {
    rosbot.move_backwards(2.0);
    rosbot.stop_moving();
  }
  return 0;
}