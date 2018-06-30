#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "r2016bSingleARDroneCtrl";

// For Block r2016bSingleARDroneCtrl/subscribe pose1
SimulinkSubscriber<geometry_msgs::PoseStamped, SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PoseStamped> Sub_r2016bSingleARDroneCtrl_631;

// For Block r2016bSingleARDroneCtrl/subscribe pose2
SimulinkSubscriber<geometry_msgs::PoseStamped, SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PoseStamped> Sub_r2016bSingleARDroneCtrl_614;

// For Block r2016bSingleARDroneCtrl/subscribe pose3
SimulinkSubscriber<geometry_msgs::PointStamped, SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PointStamped> Sub_r2016bSingleARDroneCtrl_615;

// For Block r2016bSingleARDroneCtrl/subscribe pose4
SimulinkSubscriber<geometry_msgs::PointStamped, SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PointStamped> Sub_r2016bSingleARDroneCtrl_632;

// For Block r2016bSingleARDroneCtrl/Send Command 1/publish cmd
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Twist> Pub_r2016bSingleARDroneCtrl_268;

// For Block r2016bSingleARDroneCtrl/Send Command 2/publish cmd
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Twist> Pub_r2016bSingleARDroneCtrl_591;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

