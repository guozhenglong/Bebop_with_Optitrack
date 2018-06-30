//
// File: r2016bSingleARDroneCtrl_types.h
//
// Code generated for Simulink model 'r2016bSingleARDroneCtrl'.
//
// Model version                  : 1.386
// Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
// C/C++ source code generated on : Sat Jun 30 16:13:13 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_r2016bSingleARDroneCtrl_types_h_
#define RTW_HEADER_r2016bSingleARDroneCtrl_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Vector3;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
typedef struct {
  // MsgType=geometry_msgs/Vector3
  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Vector3 Angular;
} SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Twist;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_r2016bSingleARDroneCtrl_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_r2016bSingleARDroneCtrl_ros_time_Time_

// MsgType=ros_time/Time
typedef struct {
  real_T Sec;
  real_T Nsec;
} SL_Bus_r2016bSingleARDroneCtrl_ros_time_Time;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_r2016bSingleARDroneCtrl_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_r2016bSingleARDroneCtrl_std_msgs_Header_

// MsgType=std_msgs/Header
typedef struct {
  uint32_T Seq;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;

  // MsgType=ros_time/Time
  SL_Bus_r2016bSingleARDroneCtrl_ros_time_Time Stamp;
} SL_Bus_r2016bSingleARDroneCtrl_std_msgs_Header;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Point_
#define DEFINED_TYPEDEF_FOR_SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Point_

// MsgType=geometry_msgs/Point
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Point;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Quaternion_
#define DEFINED_TYPEDEF_FOR_SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Quaternion_

// MsgType=geometry_msgs/Quaternion
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
  real_T W;
} SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Quaternion;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Pose_
#define DEFINED_TYPEDEF_FOR_SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Pose_

// MsgType=geometry_msgs/Pose
typedef struct {
  // MsgType=geometry_msgs/Point
  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Point Position;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Quaternion Orientation;
} SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Pose;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PoseStamped_
#define DEFINED_TYPEDEF_FOR_SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PoseStamped_

// MsgType=geometry_msgs/PoseStamped
typedef struct {
  // MsgType=std_msgs/Header
  SL_Bus_r2016bSingleARDroneCtrl_std_msgs_Header Header;

  // MsgType=geometry_msgs/Pose
  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Pose Pose;
} SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PoseStamped;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PointStamped_
#define DEFINED_TYPEDEF_FOR_SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PointStamped_

// MsgType=geometry_msgs/PointStamped
typedef struct {
  // MsgType=std_msgs/Header
  SL_Bus_r2016bSingleARDroneCtrl_std_msgs_Header Header;

  // MsgType=geometry_msgs/Point
  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Point Point;
} SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PointStamped;

#endif

#ifndef typedef_robotics_slros_internal_block_T
#define typedef_robotics_slros_internal_block_T

typedef struct {
  int32_T isInitialized;
} robotics_slros_internal_block_T;

#endif                                 //typedef_robotics_slros_internal_block_T

#ifndef typedef_robotics_slros_internal_blo_i_T
#define typedef_robotics_slros_internal_blo_i_T

typedef struct {
  int32_T isInitialized;
} robotics_slros_internal_blo_i_T;

#endif                                 //typedef_robotics_slros_internal_blo_i_T

// Parameters for system: '<Root>/pose1'
typedef struct P_pose1_r2016bSingleARDroneCt_T_ P_pose1_r2016bSingleARDroneCt_T;

// Parameters for system: '<Root>/vel'
typedef struct P_vel_r2016bSingleARDroneCtrl_T_ P_vel_r2016bSingleARDroneCtrl_T;

// Parameters (auto storage)
typedef struct P_r2016bSingleARDroneCtrl_T_ P_r2016bSingleARDroneCtrl_T;

// Forward declaration for rtModel
typedef struct tag_RTM_r2016bSingleARDroneCt_T RT_MODEL_r2016bSingleARDroneC_T;

#endif                                 // RTW_HEADER_r2016bSingleARDroneCtrl_types_h_ 

//
// File trailer for generated code.
//
// [EOF]
//
