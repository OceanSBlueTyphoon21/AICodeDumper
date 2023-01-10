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
  rosbot.move_forward(5.0);

  // Get the robot's x position/coordinate
  float x_1 = rosbot.get_position(1);
  ROS_INFO_STREAM("X position: " << x_1 << "\n");

  // While statement implementation
  while (rosbot.get_position(1) < x_limit) {
    rosbot.move_backwards(2);
  }

  // stop robot if robot's x position > than the limit
  rosbot.stop_moving();
