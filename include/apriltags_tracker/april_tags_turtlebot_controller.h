#ifndef APRIL_TAGS_TURTLEBOT_CONTROLLER_H_
#define APRIL_TAGS_TURTLEBOT_CONTROLLER_H_

#include <ros/ros.h>
#include "apriltags_tracker/april_tag_pos.h"
#include "apriltags_tracker/target_pos.h"

class AprilTagsTurtlebotController {
public:
  AprilTagsTurtlebotController();
  virtual ~AprilTagsTurtlebotController();

  void positionCallback(const apriltags_tracker::april_tag_pos::ConstPtr& msg);
  void targetPositionCallback(const apriltags_tracker::target_pos::ConstPtr& msg);

  void control(float x, float y, float orientation);
  
  ros::NodeHandle  m_nh;
  ros::Subscriber  m_pos_sub; 
  ros::Subscriber  m_t_pos_sub;
  ros::Publisher   m_cmd_vel_pub;

  float m_target_x;
  float m_target_y;

  float m_max_linear_speed;
  float m_min_linear_speed;
  float m_min_positive_linear_speed;
  float m_max_negative_linear_speed;
  float m_max_angular_speed;
  float m_min_angular_speed;
  float m_min_positive_angular_speed;
  float m_max_negative_angular_speed;
  float m_ros_rate;
};

#endif // APRIL_TAGS_TURTLEBOT_CONTROLLER_H_
