//
// File: r2016bSingleARDroneCtrl_private.h
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
#ifndef RTW_HEADER_r2016bSingleARDroneCtrl_private_h_
#define RTW_HEADER_r2016bSingleARDroneCtrl_private_h_
#include "rtwtypes.h"
#include "r2016bSingleARDroneCtrl.h"

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void r2016bSing_Waypointmanager_Init(DW_Waypointmanager_r2016bSing_T
  *localDW);
extern void r2016bSingleARD_Waypointmanager(const real_T rtu_waypoint[1771],
  real_T rtu_x_e, real_T rtu_y_e, real_T rtu_z_e, real_T rtu_yaw_e, real_T
  rtu_delta_p, B_Waypointmanager_r2016bSingl_T *localB,
  DW_Waypointmanager_r2016bSing_T *localDW);
extern void Coordinatetrnasformationfromine(real_T rtu_Vec_i, real_T rtu_Vec_i_a,
  real_T rtu_psi, B_Coordinatetrnasformationfro_T *localB);
extern void r2016bSingleAR_Integration_Init(DW_Integration_r2016bSingleAR_T
  *localDW);
extern void r2016bSingleARDrone_Integration(real_T rtu_x_e, real_T rtu_y_e,
  real_T rtu_x_d, real_T rtu_y_d, real_T rtu_waypoint_num,
  B_Integration_r2016bSingleARD_T *localB, DW_Integration_r2016bSingleAR_T
  *localDW);
extern void r2016bSingleARDr_MATLABFunction(const real_T rtu_u[2], real_T rtu_a,
  B_MATLABFunction_r2016bSingle_T *localB);
extern void r2016bSingleARDroneC_pose1_Init(B_pose1_r2016bSingleARDroneCt_T
  *localB, P_pose1_r2016bSingleARDroneCt_T *localP);
extern void r2016bSingleARDroneCtrl_pose1(boolean_T rtu_Enable, const
  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PoseStamped *rtu_In1,
  B_pose1_r2016bSingleARDroneCt_T *localB);
extern void r2016bSingleARDroneCtr_vel_Init(B_vel_r2016bSingleARDroneCtrl_T
  *localB, P_vel_r2016bSingleARDroneCtrl_T *localP);
extern void r2016bSingleARDroneCtrl_vel(boolean_T rtu_Enable, const
  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PointStamped *rtu_In1,
  B_vel_r2016bSingleARDroneCtrl_T *localB);

#endif                                 // RTW_HEADER_r2016bSingleARDroneCtrl_private_h_ 

//
// File trailer for generated code.
//
// [EOF]
//
