#include "rosbot_control/rosbot_class.h"
#include <iostream>
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "rosbot_node");

  RosbotClass rosbot;
  rosbot.move();

  float xcoordinate1 = rosbot.get_position(1);
  float ycoordinate1 = rosbot.get_position(2);

  ROS_INFO_STREAM(xcoordinate1 << " & " << ycoordinate1);

  rosbot.move();

  float xcoordinate2 = rosbot.get_position(1);
  float ycoordinate2 = rosbot.get_position(2);

  ROS_INFO_STREAM(xcoordinate2 << " & " << ycoordinate2);

  return 0;
}