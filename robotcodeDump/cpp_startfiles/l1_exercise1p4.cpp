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

  // Get the x coordinate and timestamp of the robot
  float x_1 = rosbot.get_position(1);
  double t_1 = rosbot.get_time();

  // Robot Moves
  rosbot.move();

  // Get x coordinate and timestamp of the robot
  float x_2 = rosbot.get_position(1);
  double t_2 = rosbot.get_time();

  // Calculate the mean robot speed
  float speed = (x_2 - x_1) / (t_2 - t_1);

  // Print the robot average speed and whether the robot's speed was <= 1.0
  // ROS_INFO_STREAM("The Average robot speed: " << speed << "\n");
  ROS_INFO_STREAM("\n"
                  << "Is the Speed <1.0 m/s? " << (speed <= 1.0)
                  << " (1 = True, 0 = False)"
                  << "\n"
                  << "The Robot AVG Speed: " << speed);

  return 0;
