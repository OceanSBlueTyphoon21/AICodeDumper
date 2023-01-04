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

  // create a dictionary, robotx
  map<double, float> robotx_dictionary;

  // Get the x coordinate and timestamp of the robot
  float xcoordinate1 = rosbot.get_position(1);
  double timestamp1 = rosbot.get_time();
  robotx_dictionary[timestamp1] = xcoordinate1;

  // Robot Moves
  rosbot.move();

  // Get x coordinate and timestamp of the robot
  float xcoordinate2 = rosbot.get_position(1);
  double timestamp2 = rosbot.get_time();
  robotx_dictionary[timestamp2] = xcoordinate2;

  // Print out the timestamps keys and their x coordinate values
  for (auto item : robotx_dictionary)
    cout << "Timestamp: " << item.first << ", X Coordinate:  " << item.second
         << "\n";

  // float ycoordinate1 = rosbot.get_position(2);

  // ROS_INFO_STREAM(xcoordinate1 << " & " << ycoordinate1);

  // rosbot.move();

  // float xcoordinate2 = rosbot.get_position(1);
  // float ycoordinate2 = rosbot.get_position(2);

  // ROS_INFO_STREAM(xcoordinate2 << " & " << ycoordinate2);

  return 0;
}