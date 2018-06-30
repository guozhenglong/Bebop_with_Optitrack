#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block r2016bSingleARDroneCtrl/subscribe pose1
extern SimulinkSubscriber<geometry_msgs::PoseStamped, SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PoseStamped> Sub_r2016bSingleARDroneCtrl_631;

// For Block r2016bSingleARDroneCtrl/subscribe pose2
extern SimulinkSubscriber<geometry_msgs::PoseStamped, SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PoseStamped> Sub_r2016bSingleARDroneCtrl_614;

// For Block r2016bSingleARDroneCtrl/subscribe pose3
extern SimulinkSubscriber<geometry_msgs::PointStamped, SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PointStamped> Sub_r2016bSingleARDroneCtrl_615;

// For Block r2016bSingleARDroneCtrl/subscribe pose4
extern SimulinkSubscriber<geometry_msgs::PointStamped, SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PointStamped> Sub_r2016bSingleARDroneCtrl_632;

// For Block r2016bSingleARDroneCtrl/Send Command 1/publish cmd
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Twist> Pub_r2016bSingleARDroneCtrl_268;

// For Block r2016bSingleARDroneCtrl/Send Command 2/publish cmd
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Twist> Pub_r2016bSingleARDroneCtrl_591;

void slros_node_init(int argc, char** argv);

#endif
