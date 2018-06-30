//
// File: r2016bSingleARDroneCtrl.cpp
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
#include "r2016bSingleARDroneCtrl.h"
#include "r2016bSingleARDroneCtrl_private.h"
#define r2016bSingleARD_MessageQueueLen (1)

// Block signals (auto storage)
B_r2016bSingleARDroneCtrl_T r2016bSingleARDroneCtrl_B;

// Block states (auto storage)
DW_r2016bSingleARDroneCtrl_T r2016bSingleARDroneCtrl_DW;

// Real-time model
RT_MODEL_r2016bSingleARDroneC_T r2016bSingleARDroneCtrl_M_;
RT_MODEL_r2016bSingleARDroneC_T *const r2016bSingleARDroneCtrl_M =
  &r2016bSingleARDroneCtrl_M_;

//
// System initialize for atomic system:
//    '<S1>/Waypoint manager '
//    '<S2>/Waypoint manager '
//
void r2016bSing_Waypointmanager_Init(DW_Waypointmanager_r2016bSing_T *localDW)
{
  // '<S15>:1:10' wpointer = 1;
  localDW->wpointer = 1.0;
}

//
// Output and update for atomic system:
//    '<S1>/Waypoint manager '
//    '<S2>/Waypoint manager '
//
void r2016bSingleARD_Waypointmanager(const real_T rtu_waypoint[1771], real_T
  rtu_x_e, real_T rtu_y_e, real_T rtu_z_e, real_T rtu_yaw_e, real_T rtu_delta_p,
  B_Waypointmanager_r2016bSingl_T *localB, DW_Waypointmanager_r2016bSing_T
  *localDW)
{
  real_T a;
  real_T b_a;
  int32_T a_tmp;

  //  Waypoint matrix contains final position, orientatoin, and waiting time.
  //  Number of waypoints
  // MATLAB Function 'Decision/Waypoint manager ': '<S15>:1'
  // '<S15>:1:5' nPoints = size(waypoint, 2) ;
  //  Persitent variable used to keep trak of next waypoint
  //  Init. persistent variables
  // '<S15>:1:9' if isempty(wpointer)
  //  A waypoint is reached if the distance between the desired waypoint and
  //  the vehicle is less than 0.2 m in the XY plane, less than 0.2 m in height,  
  // '<S15>:1:14' if ( sqrt((x_e- waypoint(2, wpointer))^2+(y_e- waypoint(3, wpointer))^2 )< delta_p && ... 
  // '<S15>:1:15'         norm(z_e - waypoint(4, wpointer)) < 0.2  && ...
  // '<S15>:1:16'         norm(yaw_e - waypoint(5, wpointer) )< 10*pi/180 &&...
  // '<S15>:1:17'         wpointer ~= nPoints)
  a_tmp = ((int32_T)localDW->wpointer - 1) * 7;
  a = rtu_x_e - rtu_waypoint[a_tmp + 1];
  b_a = rtu_y_e - rtu_waypoint[a_tmp + 2];
  if ((sqrt(a * a + b_a * b_a) < rtu_delta_p) && (fabs(rtu_z_e -
        rtu_waypoint[a_tmp + 3]) < 0.2) && (fabs(rtu_yaw_e - rtu_waypoint[a_tmp
        + 4]) < 0.17453292519943295) && (localDW->wpointer != 253.0)) {
    // '<S15>:1:18' wpointer = wpointer+ 1;
    localDW->wpointer++;
  }

  //  Outputs:
  // '<S15>:1:23' x_d = waypoint(2, wpointer) ;
  a_tmp = ((int32_T)localDW->wpointer - 1) * 7;
  localB->x_d = rtu_waypoint[a_tmp + 1];

  // '<S15>:1:24' y_d = waypoint(3, wpointer) ;
  localB->y_d = rtu_waypoint[a_tmp + 2];

  // '<S15>:1:25' z_d = waypoint(4, wpointer)  ;
  localB->z_d = rtu_waypoint[a_tmp + 3];

  // '<S15>:1:26' yaw_d = waypoint(5, wpointer) ;
  localB->yaw_d = rtu_waypoint[a_tmp + 4];

  // '<S15>:1:27' vx_d = waypoint(6,wpointer);
  localB->vx_d = rtu_waypoint[a_tmp + 5];

  // '<S15>:1:28' vy_d = waypoint(7,wpointer);
  localB->vy_d = rtu_waypoint[a_tmp + 6];

  // '<S15>:1:29' waypointNumber = wpointer ;
  localB->waypointNumber = localDW->wpointer;
}

//
// Output and update for atomic system:
//    '<S3>/Coordinate trnasformation  from inertial frame to body frame '
//    '<S4>/Coordinate trnasformation  from inertial frame to body frame '
//
void Coordinatetrnasformationfromine(real_T rtu_Vec_i, real_T rtu_Vec_i_a,
  real_T rtu_psi, B_Coordinatetrnasformationfro_T *localB)
{
  real_T Vec_xy_tmp;
  real_T Vec_xy_tmp_0;

  // MATLAB Function 'Position Controller1/Coordinate trnasformation  from inertial frame to body frame ': '<S17>:1' 
  // '<S17>:1:3' T = [cos(psi) sin(psi) ; -sin(psi) cos(psi)] ;
  // '<S17>:1:4' Vec_xy = T*Vec_i(1:2,1);
  localB->Vec_xy[0] = 0.0;
  Vec_xy_tmp_0 = cos(rtu_psi);

  // SignalConversion: '<S17>/TmpSignal ConversionAt SFunction Inport1'
  localB->Vec_xy[0] += Vec_xy_tmp_0 * rtu_Vec_i;
  Vec_xy_tmp = sin(rtu_psi);

  // SignalConversion: '<S17>/TmpSignal ConversionAt SFunction Inport1'
  localB->Vec_xy[0] += Vec_xy_tmp * rtu_Vec_i_a;
  localB->Vec_xy[1] = 0.0;

  // SignalConversion: '<S17>/TmpSignal ConversionAt SFunction Inport1'
  localB->Vec_xy[1] += -Vec_xy_tmp * rtu_Vec_i;
  localB->Vec_xy[1] += Vec_xy_tmp_0 * rtu_Vec_i_a;
}

//
// System initialize for atomic system:
//    '<S3>/Integration '
//    '<S4>/Integration '
//
void r2016bSingleAR_Integration_Init(DW_Integration_r2016bSingleAR_T *localDW)
{
  // '<S18>:1:9' last_waypoint = 0;
  localDW->last_waypoint = 0.0;

  // '<S18>:1:13' sum_x = 0;
  localDW->sum_x = 0.0;

  // '<S18>:1:16' sum_y = 0;
  localDW->sum_y = 0.0;
}

//
// Output and update for atomic system:
//    '<S3>/Integration '
//    '<S4>/Integration '
//
void r2016bSingleARDrone_Integration(real_T rtu_x_e, real_T rtu_y_e, real_T
  rtu_x_d, real_T rtu_y_d, real_T rtu_waypoint_num,
  B_Integration_r2016bSingleARD_T *localB, DW_Integration_r2016bSingleAR_T
  *localDW)
{
  // MATLAB Function 'Position Controller1/Integration ': '<S18>:1'
  //  Init. persistent variables
  // '<S18>:1:8' if isempty(last_waypoint)
  // '<S18>:1:12' if isempty(sum_x)
  // '<S18>:1:15' if isempty(sum_y)
  // '<S18>:1:19' if waypoint_num>last_waypoint
  if (rtu_waypoint_num > localDW->last_waypoint) {
    // '<S18>:1:20' sum_x = 0;
    localDW->sum_x = 0.0;

    // '<S18>:1:21' sum_y = 0;
    localDW->sum_y = 0.0;

    // '<S18>:1:22' last_waypoint = last_waypoint +1;
    localDW->last_waypoint++;
  } else {
    if (localDW->last_waypoint == rtu_waypoint_num) {
      // '<S18>:1:23' elseif last_waypoint==waypoint_num
      // '<S18>:1:24' sum_x =sum_x +(x_d-x_e);
      localDW->sum_x += rtu_x_d - rtu_x_e;

      // '<S18>:1:25' sum_y =sum_y +(y_d-y_e);
      localDW->sum_y += rtu_y_d - rtu_y_e;
    }
  }

  //  Outputs:
  // '<S18>:1:29' accu_x = sum_x;
  localB->accu_x = localDW->sum_x;

  // '<S18>:1:30' accu_y = sum_y;
  localB->accu_y = localDW->sum_y;
}

//
// Output and update for atomic system:
//    '<S3>/MATLAB Function'
//    '<S4>/MATLAB Function'
//
void r2016bSingleARDr_MATLABFunction(const real_T rtu_u[2], real_T rtu_a,
  B_MATLABFunction_r2016bSingle_T *localB)
{
  real_T temp;
  real_T absx;
  int32_T k;
  boolean_T exitg1;

  // MATLAB Function 'Position Controller1/MATLAB Function': '<S19>:1'
  // '<S19>:1:2' temp = norm(u,Inf);
  temp = 0.0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    absx = fabs(rtu_u[k]);
    if (rtIsNaN(absx)) {
      temp = (rtNaN);
      exitg1 = true;
    } else {
      if (absx > temp) {
        temp = absx;
      }

      k++;
    }
  }

  // '<S19>:1:3' if  temp<=a
  if (temp <= rtu_a) {
    // '<S19>:1:4' y = u;
    localB->y[0] = rtu_u[0];
    localB->y[1] = rtu_u[1];
  } else {
    // '<S19>:1:5' else
    // '<S19>:1:6' y= a*u/temp;
    localB->y[0] = rtu_a * rtu_u[0] / temp;
    localB->y[1] = rtu_a * rtu_u[1] / temp;
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2((real_T)u0_0, (real_T)u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

//
// System initialize for enable system:
//    '<Root>/pose1'
//    '<Root>/pose2'
//
void r2016bSingleARDroneC_pose1_Init(B_pose1_r2016bSingleARDroneCt_T *localB,
  P_pose1_r2016bSingleARDroneCt_T *localP)
{
  // SystemInitialize for Outport: '<S7>/Out1'
  localB->x = localP->Out1_Y0;
  localB->y = localP->Out1_Y0;
  localB->z = localP->Out1_Y0;
  localB->yaw = localP->Out1_Y0;
}

//
// Output and update for enable system:
//    '<Root>/pose1'
//    '<Root>/pose2'
//
void r2016bSingleARDroneCtrl_pose1(boolean_T rtu_Enable, const
  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PoseStamped *rtu_In1,
  B_pose1_r2016bSingleARDroneCt_T *localB)
{
  // Outputs for Enabled SubSystem: '<Root>/pose1' incorporates:
  //   EnablePort: '<S7>/Enable'

  if (rtu_Enable) {
    // MATLAB Function: '<S7>/ '
    // MATLAB Function 'pose1/ ': '<S27>:1'
    // '<S27>:1:2' x =  -mocap_Y;
    localB->x = -rtu_In1->Pose.Position.Y;

    // '<S27>:1:3' y =  -mocap_X;
    localB->y = -rtu_In1->Pose.Position.X;

    // '<S27>:1:4' z =  mocap_Z;
    localB->z = rtu_In1->Pose.Position.Z;

    // MATLAB Function: '<S7>/ Function'
    // MATLAB Function 'pose1/ Function': '<S28>:1'
    // '<S28>:1:2' t0 = -2.0 * (y * y + z * z) + 1.0;
    // '<S28>:1:3' t1 = +2.0 * (x * y + w * z);
    // '<S28>:1:4' t2 = -2.0 * (x * z - w * y);
    // '<S28>:1:5' t3 = +2.0 * (y * z + w * x);
    // '<S28>:1:6' t4 = -2.0 * (x * x + y * y) + 1.0;
    // '<S28>:1:8' roll = -asin(t2);
    // '<S28>:1:9' pitch = -atan2(t3, t4);
    // '<S28>:1:10' yaw= -atan2(t1, t0);
    localB->yaw = -rt_atan2d_snf((rtu_In1->Pose.Orientation.X *
      rtu_In1->Pose.Orientation.Y + rtu_In1->Pose.Orientation.W *
      rtu_In1->Pose.Orientation.Z) * 2.0, (rtu_In1->Pose.Orientation.Y *
      rtu_In1->Pose.Orientation.Y + rtu_In1->Pose.Orientation.Z *
      rtu_In1->Pose.Orientation.Z) * -2.0 + 1.0);
  }

  // End of Outputs for SubSystem: '<Root>/pose1'
}

//
// System initialize for enable system:
//    '<Root>/vel'
//    '<Root>/vel1'
//
void r2016bSingleARDroneCtr_vel_Init(B_vel_r2016bSingleARDroneCtrl_T *localB,
  P_vel_r2016bSingleARDroneCtrl_T *localP)
{
  // SystemInitialize for Outport: '<S13>/Out1'
  localB->x = localP->Out1_Y0;
  localB->y = localP->Out1_Y0;
  localB->z = localP->Out1_Y0;
}

//
// Output and update for enable system:
//    '<Root>/vel'
//    '<Root>/vel1'
//
void r2016bSingleARDroneCtrl_vel(boolean_T rtu_Enable, const
  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PointStamped *rtu_In1,
  B_vel_r2016bSingleARDroneCtrl_T *localB)
{
  // Outputs for Enabled SubSystem: '<Root>/vel' incorporates:
  //   EnablePort: '<S13>/Enable'

  if (rtu_Enable) {
    // MATLAB Function: '<S13>/ '
    // MATLAB Function 'vel/ ': '<S35>:1'
    // '<S35>:1:2' x = - mocap_Y;
    localB->x = -rtu_In1->Point.Y;

    // '<S35>:1:3' y = - mocap_X;
    localB->y = -rtu_In1->Point.X;

    // '<S35>:1:4' z = mocap_Z;
    localB->z = rtu_In1->Point.Z;
  }

  // End of Outputs for SubSystem: '<Root>/vel'
}

// Model step function
void r2016bSingleARDroneCtrl_step(void)
{
  boolean_T b_varargout_1;

  // Outputs for Atomic SubSystem: '<Root>/subscribe pose2'
  // MATLABSystem: '<S10>/SourceBlock' incorporates:
  //   Inport: '<S32>/In1'

  b_varargout_1 = Sub_r2016bSingleARDroneCtrl_614.getLatestMessage
    (&r2016bSingleARDroneCtrl_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S10>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S32>/Enable'

  if (b_varargout_1) {
    r2016bSingleARDroneCtrl_B.In1 = r2016bSingleARDroneCtrl_B.b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S10>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<Root>/pose2'
  r2016bSingleARDroneCtrl_pose1(b_varargout_1, &r2016bSingleARDroneCtrl_B.In1,
    &r2016bSingleARDroneCtrl_B.pose2);

  // End of MATLABSystem: '<S10>/SourceBlock'

  // End of Outputs for SubSystem: '<Root>/pose2'

  // End of Outputs for SubSystem: '<Root>/subscribe pose2'

  // MATLAB Function: '<S1>/Waypoint manager ' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<Root>/Constant1'
  //   Gain: '<Root>/Gain'

  r2016bSingleARD_Waypointmanager(r2016bSingleARDroneCtrl_P.waypoints1,
    r2016bSingleARDroneCtrl_B.pose2.x, r2016bSingleARDroneCtrl_B.pose2.y,
    r2016bSingleARDroneCtrl_B.pose2.z, r2016bSingleARDroneCtrl_B.pose2.yaw,
    r2016bSingleARDroneCtrl_P.delta_p *
    r2016bSingleARDroneCtrl_P.Constant_Value_a,
    &r2016bSingleARDroneCtrl_B.sf_Waypointmanager,
    &r2016bSingleARDroneCtrl_DW.sf_Waypointmanager);

  // MATLAB Function: '<S3>/Integration '
  r2016bSingleARDrone_Integration(r2016bSingleARDroneCtrl_B.pose2.x,
    r2016bSingleARDroneCtrl_B.pose2.y,
    r2016bSingleARDroneCtrl_B.sf_Waypointmanager.x_d,
    r2016bSingleARDroneCtrl_B.sf_Waypointmanager.y_d,
    r2016bSingleARDroneCtrl_B.sf_Waypointmanager.waypointNumber,
    &r2016bSingleARDroneCtrl_B.sf_Integration,
    &r2016bSingleARDroneCtrl_DW.sf_Integration);

  // Outputs for Atomic SubSystem: '<Root>/subscribe pose3'
  // MATLABSystem: '<S11>/SourceBlock' incorporates:
  //   Inport: '<S33>/In1'

  b_varargout_1 = Sub_r2016bSingleARDroneCtrl_615.getLatestMessage
    (&r2016bSingleARDroneCtrl_B.b_varargout_2_m);

  // Outputs for Enabled SubSystem: '<S11>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S33>/Enable'

  if (b_varargout_1) {
    r2016bSingleARDroneCtrl_B.In1_a = r2016bSingleARDroneCtrl_B.b_varargout_2_m;
  }

  // End of Outputs for SubSystem: '<S11>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<Root>/vel'
  r2016bSingleARDroneCtrl_vel(b_varargout_1, &r2016bSingleARDroneCtrl_B.In1_a,
    &r2016bSingleARDroneCtrl_B.vel);

  // End of MATLABSystem: '<S11>/SourceBlock'

  // End of Outputs for SubSystem: '<Root>/vel'

  // End of Outputs for SubSystem: '<Root>/subscribe pose3'

  // MATLAB Function: '<S3>/Coordinate trnasformation  from inertial frame to body frame ' incorporates:
  //   Gain: '<S3>/Vx-d1'
  //   Gain: '<S3>/Vx-d2'
  //   Gain: '<S3>/kxp1'
  //   Gain: '<S3>/kxp2'
  //   Gain: '<S3>/kxp4'
  //   Gain: '<S3>/kxp5'
  //   Sum: '<S3>/Sum2'
  //   Sum: '<S3>/Sum4'
  //   Sum: '<S3>/Sum5'
  //   Sum: '<S3>/Sum7'
  //   Sum: '<S3>/Sum8'
  //   Sum: '<S3>/Sum9'

  Coordinatetrnasformationfromine((r2016bSingleARDroneCtrl_P.k_i_xy *
    r2016bSingleARDroneCtrl_B.sf_Integration.accu_x +
    r2016bSingleARDroneCtrl_P.k_p_xy *
    (r2016bSingleARDroneCtrl_B.sf_Waypointmanager.x_d -
     r2016bSingleARDroneCtrl_B.pose2.x)) + r2016bSingleARDroneCtrl_P.k_d_xy *
    (r2016bSingleARDroneCtrl_B.sf_Waypointmanager.vx_d -
     r2016bSingleARDroneCtrl_B.vel.x), (r2016bSingleARDroneCtrl_P.k_i_xy *
    r2016bSingleARDroneCtrl_B.sf_Integration.accu_y +
    r2016bSingleARDroneCtrl_P.k_p_xy *
    (r2016bSingleARDroneCtrl_B.sf_Waypointmanager.y_d -
     r2016bSingleARDroneCtrl_B.pose2.y)) + r2016bSingleARDroneCtrl_P.k_d_xy *
    (r2016bSingleARDroneCtrl_B.sf_Waypointmanager.vy_d -
     r2016bSingleARDroneCtrl_B.vel.y), r2016bSingleARDroneCtrl_B.pose2.yaw,
    &r2016bSingleARDroneCtrl_B.sf_Coordinatetrnasformationfrom);

  // MATLAB Function: '<S3>/MATLAB Function' incorporates:
  //   Constant: '<S3>/Constant'

  r2016bSingleARDr_MATLABFunction
    (r2016bSingleARDroneCtrl_B.sf_Coordinatetrnasformationfrom.Vec_xy,
     r2016bSingleARDroneCtrl_P.limit_cmd_xy,
     &r2016bSingleARDroneCtrl_B.sf_MATLABFunction);

  // BusAssignment: '<S5>/cmdBus' incorporates:
  //   Constant: '<S5>/Constant1'
  //   Gain: '<S3>/Vx-d3'
  //   Gain: '<S3>/kxp3'
  //   Gain: '<S3>/proportional control gain - yaw'
  //   Gain: '<S5>/K'
  //   Gain: '<S5>/K1'
  //   Sum: '<S3>/Sum1'
  //   Sum: '<S3>/Sum3'
  //   Sum: '<S3>/Sum6'

  r2016bSingleARDroneCtrl_B.cmdBus.Linear.X =
    r2016bSingleARDroneCtrl_B.sf_MATLABFunction.y[0];
  r2016bSingleARDroneCtrl_B.cmdBus.Linear.Y = r2016bSingleARDroneCtrl_P.k_sign *
    r2016bSingleARDroneCtrl_B.sf_MATLABFunction.y[1];
  r2016bSingleARDroneCtrl_B.cmdBus.Linear.Z =
    (r2016bSingleARDroneCtrl_B.sf_Waypointmanager.z_d -
     r2016bSingleARDroneCtrl_B.pose2.z) * r2016bSingleARDroneCtrl_P.k_p_z -
    r2016bSingleARDroneCtrl_P.k_d_z * r2016bSingleARDroneCtrl_B.vel.z;
  r2016bSingleARDroneCtrl_B.cmdBus.Angular.Z =
    (r2016bSingleARDroneCtrl_B.sf_Waypointmanager.yaw_d -
     r2016bSingleARDroneCtrl_B.pose2.yaw) * r2016bSingleARDroneCtrl_P.k_p_yaw *
    r2016bSingleARDroneCtrl_P.k_sign;
  r2016bSingleARDroneCtrl_B.cmdBus.Angular.X =
    r2016bSingleARDroneCtrl_P.Constant1_Value;
  r2016bSingleARDroneCtrl_B.cmdBus.Angular.Y =
    r2016bSingleARDroneCtrl_P.Constant1_Value;

  // Outputs for Atomic SubSystem: '<S5>/publish cmd'
  // MATLABSystem: '<S24>/SinkBlock'
  Pub_r2016bSingleARDroneCtrl_268.publish(&r2016bSingleARDroneCtrl_B.cmdBus);

  // End of Outputs for SubSystem: '<S5>/publish cmd'

  // Outputs for Atomic SubSystem: '<Root>/subscribe pose1'
  // MATLABSystem: '<S9>/SourceBlock' incorporates:
  //   Inport: '<S31>/In1'

  b_varargout_1 = Sub_r2016bSingleARDroneCtrl_631.getLatestMessage
    (&r2016bSingleARDroneCtrl_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S9>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S31>/Enable'

  if (b_varargout_1) {
    r2016bSingleARDroneCtrl_B.In1_j = r2016bSingleARDroneCtrl_B.b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S9>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<Root>/pose1'
  r2016bSingleARDroneCtrl_pose1(b_varargout_1, &r2016bSingleARDroneCtrl_B.In1_j,
    &r2016bSingleARDroneCtrl_B.pose1);

  // End of MATLABSystem: '<S9>/SourceBlock'

  // End of Outputs for SubSystem: '<Root>/pose1'

  // End of Outputs for SubSystem: '<Root>/subscribe pose1'

  // MATLAB Function: '<S2>/Waypoint manager ' incorporates:
  //   Constant: '<Root>/Constant2'
  //   Constant: '<Root>/Constant5'
  //   Gain: '<Root>/Gain1'

  r2016bSingleARD_Waypointmanager(r2016bSingleARDroneCtrl_P.waypoints2,
    r2016bSingleARDroneCtrl_B.pose1.x, r2016bSingleARDroneCtrl_B.pose1.y,
    r2016bSingleARDroneCtrl_B.pose1.z, r2016bSingleARDroneCtrl_B.pose1.yaw,
    r2016bSingleARDroneCtrl_P.delta_p *
    r2016bSingleARDroneCtrl_P.Constant2_Value,
    &r2016bSingleARDroneCtrl_B.sf_Waypointmanager_p,
    &r2016bSingleARDroneCtrl_DW.sf_Waypointmanager_p);

  // MATLAB Function: '<S4>/Integration '
  r2016bSingleARDrone_Integration(r2016bSingleARDroneCtrl_B.pose1.x,
    r2016bSingleARDroneCtrl_B.pose1.y,
    r2016bSingleARDroneCtrl_B.sf_Waypointmanager_p.x_d,
    r2016bSingleARDroneCtrl_B.sf_Waypointmanager_p.y_d,
    r2016bSingleARDroneCtrl_B.sf_Waypointmanager_p.waypointNumber,
    &r2016bSingleARDroneCtrl_B.sf_Integration_p,
    &r2016bSingleARDroneCtrl_DW.sf_Integration_p);

  // Outputs for Atomic SubSystem: '<Root>/subscribe pose4'
  // MATLABSystem: '<S12>/SourceBlock' incorporates:
  //   Inport: '<S34>/In1'

  b_varargout_1 = Sub_r2016bSingleARDroneCtrl_632.getLatestMessage
    (&r2016bSingleARDroneCtrl_B.b_varargout_2_m);

  // Outputs for Enabled SubSystem: '<S12>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S34>/Enable'

  if (b_varargout_1) {
    r2016bSingleARDroneCtrl_B.In1_p = r2016bSingleARDroneCtrl_B.b_varargout_2_m;
  }

  // End of Outputs for SubSystem: '<S12>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<Root>/vel1'
  r2016bSingleARDroneCtrl_vel(b_varargout_1, &r2016bSingleARDroneCtrl_B.In1_p,
    &r2016bSingleARDroneCtrl_B.vel1);

  // End of MATLABSystem: '<S12>/SourceBlock'

  // End of Outputs for SubSystem: '<Root>/vel1'

  // End of Outputs for SubSystem: '<Root>/subscribe pose4'

  // MATLAB Function: '<S4>/Coordinate trnasformation  from inertial frame to body frame ' incorporates:
  //   Gain: '<S4>/Vx-d1'
  //   Gain: '<S4>/Vx-d2'
  //   Gain: '<S4>/kxp1'
  //   Gain: '<S4>/kxp2'
  //   Gain: '<S4>/kxp4'
  //   Gain: '<S4>/kxp5'
  //   Sum: '<S4>/Sum2'
  //   Sum: '<S4>/Sum4'
  //   Sum: '<S4>/Sum5'
  //   Sum: '<S4>/Sum7'
  //   Sum: '<S4>/Sum8'
  //   Sum: '<S4>/Sum9'

  Coordinatetrnasformationfromine((r2016bSingleARDroneCtrl_P.k_i_xy *
    r2016bSingleARDroneCtrl_B.sf_Integration_p.accu_x +
    r2016bSingleARDroneCtrl_P.k_p_xy *
    (r2016bSingleARDroneCtrl_B.sf_Waypointmanager_p.x_d -
     r2016bSingleARDroneCtrl_B.pose1.x)) + r2016bSingleARDroneCtrl_P.k_d_xy *
    (r2016bSingleARDroneCtrl_B.sf_Waypointmanager_p.vx_d -
     r2016bSingleARDroneCtrl_B.vel1.x), (r2016bSingleARDroneCtrl_P.k_i_xy *
    r2016bSingleARDroneCtrl_B.sf_Integration_p.accu_y +
    r2016bSingleARDroneCtrl_P.k_p_xy *
    (r2016bSingleARDroneCtrl_B.sf_Waypointmanager_p.y_d -
     r2016bSingleARDroneCtrl_B.pose1.y)) + r2016bSingleARDroneCtrl_P.k_d_xy *
    (r2016bSingleARDroneCtrl_B.sf_Waypointmanager_p.vy_d -
     r2016bSingleARDroneCtrl_B.vel1.y), r2016bSingleARDroneCtrl_B.pose1.yaw,
    &r2016bSingleARDroneCtrl_B.sf_Coordinatetrnasformationfr_i);

  // MATLAB Function: '<S4>/MATLAB Function' incorporates:
  //   Constant: '<S4>/Constant'

  r2016bSingleARDr_MATLABFunction
    (r2016bSingleARDroneCtrl_B.sf_Coordinatetrnasformationfr_i.Vec_xy,
     r2016bSingleARDroneCtrl_P.limit_cmd_xy,
     &r2016bSingleARDroneCtrl_B.sf_MATLABFunction_a);

  // BusAssignment: '<S6>/cmdBus' incorporates:
  //   Constant: '<S6>/Constant1'
  //   Gain: '<S4>/Vx-d3'
  //   Gain: '<S4>/kxp3'
  //   Gain: '<S4>/proportional control gain - yaw'
  //   Gain: '<S6>/K'
  //   Gain: '<S6>/K1'
  //   Sum: '<S4>/Sum1'
  //   Sum: '<S4>/Sum3'
  //   Sum: '<S4>/Sum6'

  r2016bSingleARDroneCtrl_B.cmdBus_b.Linear.X =
    r2016bSingleARDroneCtrl_B.sf_MATLABFunction_a.y[0];
  r2016bSingleARDroneCtrl_B.cmdBus_b.Linear.Y = r2016bSingleARDroneCtrl_P.k_sign
    * r2016bSingleARDroneCtrl_B.sf_MATLABFunction_a.y[1];
  r2016bSingleARDroneCtrl_B.cmdBus_b.Linear.Z =
    (r2016bSingleARDroneCtrl_B.sf_Waypointmanager_p.z_d -
     r2016bSingleARDroneCtrl_B.pose1.z) * r2016bSingleARDroneCtrl_P.k_p_z -
    r2016bSingleARDroneCtrl_P.k_d_z * r2016bSingleARDroneCtrl_B.vel1.z;
  r2016bSingleARDroneCtrl_B.cmdBus_b.Angular.Z =
    (r2016bSingleARDroneCtrl_B.sf_Waypointmanager_p.yaw_d -
     r2016bSingleARDroneCtrl_B.pose1.yaw) * r2016bSingleARDroneCtrl_P.k_p_yaw *
    r2016bSingleARDroneCtrl_P.k_sign;
  r2016bSingleARDroneCtrl_B.cmdBus_b.Angular.X =
    r2016bSingleARDroneCtrl_P.Constant1_Value_m;
  r2016bSingleARDroneCtrl_B.cmdBus_b.Angular.Y =
    r2016bSingleARDroneCtrl_P.Constant1_Value_m;

  // Outputs for Atomic SubSystem: '<S6>/publish cmd'
  // MATLABSystem: '<S26>/SinkBlock'
  Pub_r2016bSingleARDroneCtrl_591.publish(&r2016bSingleARDroneCtrl_B.cmdBus_b);

  // End of Outputs for SubSystem: '<S6>/publish cmd'
}

// Model initialize function
void r2016bSingleARDroneCtrl_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  rtmSetErrorStatus(r2016bSingleARDroneCtrl_M, (NULL));

  // block I/O
  (void) memset(((void *) &r2016bSingleARDroneCtrl_B), 0,
                sizeof(B_r2016bSingleARDroneCtrl_T));

  // states (dwork)
  (void) memset((void *)&r2016bSingleARDroneCtrl_DW, 0,
                sizeof(DW_r2016bSingleARDroneCtrl_T));

  {
    static const char_T tmp[15] = { '/', 'b', 'e', 'b', 'o', 'p', '2', '/', 'c',
      'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp_0[12] = { '/', 'R', 'o', 'b', 'o', 't', '_', '2',
      '/', 'v', 'e', 'l' };

    static const char_T tmp_1[13] = { '/', 'R', 'o', 'b', 'o', 't', '_', '2',
      '/', 'p', 'o', 's', 'e' };

    static const char_T tmp_2[15] = { '/', 'b', 'e', 'b', 'o', 'p', '1', '/',
      'c', 'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp_3[12] = { '/', 'R', 'o', 'b', 'o', 't', '_', '1',
      '/', 'v', 'e', 'l' };

    static const char_T tmp_4[13] = { '/', 'R', 'o', 'b', 'o', 't', '_', '1',
      '/', 'p', 'o', 's', 'e' };

    char_T tmp_5[16];
    char_T tmp_6[13];
    char_T tmp_7[14];
    int32_T i;

    // Start for Atomic SubSystem: '<Root>/subscribe pose2'
    // Start for MATLABSystem: '<S10>/SourceBlock'
    r2016bSingleARDroneCtrl_DW.obj_p.isInitialized = 0;
    r2016bSingleARDroneCtrl_DW.obj_p.isInitialized = 1;
    for (i = 0; i < 13; i++) {
      tmp_7[i] = tmp_4[i];
    }

    tmp_7[13] = '\x00';
    Sub_r2016bSingleARDroneCtrl_614.createSubscriber(tmp_7,
      r2016bSingleARD_MessageQueueLen);

    // End of Start for MATLABSystem: '<S10>/SourceBlock'
    // End of Start for SubSystem: '<Root>/subscribe pose2'

    // Start for Atomic SubSystem: '<Root>/subscribe pose3'
    // Start for MATLABSystem: '<S11>/SourceBlock'
    r2016bSingleARDroneCtrl_DW.obj_k.isInitialized = 0;
    r2016bSingleARDroneCtrl_DW.obj_k.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      tmp_6[i] = tmp_3[i];
    }

    tmp_6[12] = '\x00';
    Sub_r2016bSingleARDroneCtrl_615.createSubscriber(tmp_6,
      r2016bSingleARD_MessageQueueLen);

    // End of Start for MATLABSystem: '<S11>/SourceBlock'
    // End of Start for SubSystem: '<Root>/subscribe pose3'

    // Start for Atomic SubSystem: '<S5>/publish cmd'
    // Start for MATLABSystem: '<S24>/SinkBlock'
    r2016bSingleARDroneCtrl_DW.obj_b.isInitialized = 0;
    r2016bSingleARDroneCtrl_DW.obj_b.isInitialized = 1;
    for (i = 0; i < 15; i++) {
      tmp_5[i] = tmp_2[i];
    }

    tmp_5[15] = '\x00';
    Pub_r2016bSingleARDroneCtrl_268.createPublisher(tmp_5,
      r2016bSingleARD_MessageQueueLen);

    // End of Start for MATLABSystem: '<S24>/SinkBlock'
    // End of Start for SubSystem: '<S5>/publish cmd'

    // Start for Atomic SubSystem: '<Root>/subscribe pose1'
    // Start for MATLABSystem: '<S9>/SourceBlock'
    r2016bSingleARDroneCtrl_DW.obj_m.isInitialized = 0;
    r2016bSingleARDroneCtrl_DW.obj_m.isInitialized = 1;
    for (i = 0; i < 13; i++) {
      tmp_7[i] = tmp_1[i];
    }

    tmp_7[13] = '\x00';
    Sub_r2016bSingleARDroneCtrl_631.createSubscriber(tmp_7,
      r2016bSingleARD_MessageQueueLen);

    // End of Start for MATLABSystem: '<S9>/SourceBlock'
    // End of Start for SubSystem: '<Root>/subscribe pose1'

    // Start for Atomic SubSystem: '<Root>/subscribe pose4'
    // Start for MATLABSystem: '<S12>/SourceBlock'
    r2016bSingleARDroneCtrl_DW.obj_bh.isInitialized = 0;
    r2016bSingleARDroneCtrl_DW.obj_bh.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      tmp_6[i] = tmp_0[i];
    }

    tmp_6[12] = '\x00';
    Sub_r2016bSingleARDroneCtrl_632.createSubscriber(tmp_6,
      r2016bSingleARD_MessageQueueLen);

    // End of Start for MATLABSystem: '<S12>/SourceBlock'
    // End of Start for SubSystem: '<Root>/subscribe pose4'

    // Start for Atomic SubSystem: '<S6>/publish cmd'
    // Start for MATLABSystem: '<S26>/SinkBlock'
    r2016bSingleARDroneCtrl_DW.obj.isInitialized = 0;
    r2016bSingleARDroneCtrl_DW.obj.isInitialized = 1;
    for (i = 0; i < 15; i++) {
      tmp_5[i] = tmp[i];
    }

    tmp_5[15] = '\x00';
    Pub_r2016bSingleARDroneCtrl_591.createPublisher(tmp_5,
      r2016bSingleARD_MessageQueueLen);

    // End of Start for MATLABSystem: '<S26>/SinkBlock'
    // End of Start for SubSystem: '<S6>/publish cmd'

    // SystemInitialize for Atomic SubSystem: '<Root>/subscribe pose2'
    // SystemInitialize for Enabled SubSystem: '<S10>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S32>/Out1'
    r2016bSingleARDroneCtrl_B.In1 = r2016bSingleARDroneCtrl_P.Out1_Y0_c;

    // End of SystemInitialize for SubSystem: '<S10>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/subscribe pose2'

    // SystemInitialize for Enabled SubSystem: '<Root>/pose2'
    r2016bSingleARDroneC_pose1_Init(&r2016bSingleARDroneCtrl_B.pose2,
      &r2016bSingleARDroneCtrl_P.pose2);

    // End of SystemInitialize for SubSystem: '<Root>/pose2'

    // SystemInitialize for MATLAB Function: '<S1>/Waypoint manager '
    r2016bSing_Waypointmanager_Init
      (&r2016bSingleARDroneCtrl_DW.sf_Waypointmanager);

    // SystemInitialize for MATLAB Function: '<S3>/Integration '
    r2016bSingleAR_Integration_Init(&r2016bSingleARDroneCtrl_DW.sf_Integration);

    // SystemInitialize for Atomic SubSystem: '<Root>/subscribe pose3'
    // SystemInitialize for Enabled SubSystem: '<S11>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S33>/Out1'
    r2016bSingleARDroneCtrl_B.In1_a = r2016bSingleARDroneCtrl_P.Out1_Y0_g;

    // End of SystemInitialize for SubSystem: '<S11>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/subscribe pose3'

    // SystemInitialize for Enabled SubSystem: '<Root>/vel'
    r2016bSingleARDroneCtr_vel_Init(&r2016bSingleARDroneCtrl_B.vel,
      &r2016bSingleARDroneCtrl_P.vel);

    // End of SystemInitialize for SubSystem: '<Root>/vel'

    // SystemInitialize for Atomic SubSystem: '<Root>/subscribe pose1'
    // SystemInitialize for Enabled SubSystem: '<S9>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S31>/Out1'
    r2016bSingleARDroneCtrl_B.In1_j = r2016bSingleARDroneCtrl_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S9>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/subscribe pose1'

    // SystemInitialize for Enabled SubSystem: '<Root>/pose1'
    r2016bSingleARDroneC_pose1_Init(&r2016bSingleARDroneCtrl_B.pose1,
      &r2016bSingleARDroneCtrl_P.pose1);

    // End of SystemInitialize for SubSystem: '<Root>/pose1'

    // SystemInitialize for MATLAB Function: '<S2>/Waypoint manager '
    r2016bSing_Waypointmanager_Init
      (&r2016bSingleARDroneCtrl_DW.sf_Waypointmanager_p);

    // SystemInitialize for MATLAB Function: '<S4>/Integration '
    r2016bSingleAR_Integration_Init(&r2016bSingleARDroneCtrl_DW.sf_Integration_p);

    // SystemInitialize for Atomic SubSystem: '<Root>/subscribe pose4'
    // SystemInitialize for Enabled SubSystem: '<S12>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S34>/Out1'
    r2016bSingleARDroneCtrl_B.In1_p = r2016bSingleARDroneCtrl_P.Out1_Y0_j;

    // End of SystemInitialize for SubSystem: '<S12>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/subscribe pose4'

    // SystemInitialize for Enabled SubSystem: '<Root>/vel1'
    r2016bSingleARDroneCtr_vel_Init(&r2016bSingleARDroneCtrl_B.vel1,
      &r2016bSingleARDroneCtrl_P.vel1);

    // End of SystemInitialize for SubSystem: '<Root>/vel1'
  }
}

// Model terminate function
void r2016bSingleARDroneCtrl_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/subscribe pose2'
  // Terminate for MATLABSystem: '<S10>/SourceBlock'
  if (r2016bSingleARDroneCtrl_DW.obj_p.isInitialized == 1) {
    r2016bSingleARDroneCtrl_DW.obj_p.isInitialized = 2;
  }

  // End of Terminate for MATLABSystem: '<S10>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/subscribe pose2'

  // Terminate for Atomic SubSystem: '<Root>/subscribe pose3'
  // Terminate for MATLABSystem: '<S11>/SourceBlock'
  if (r2016bSingleARDroneCtrl_DW.obj_k.isInitialized == 1) {
    r2016bSingleARDroneCtrl_DW.obj_k.isInitialized = 2;
  }

  // End of Terminate for MATLABSystem: '<S11>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/subscribe pose3'

  // Terminate for Atomic SubSystem: '<S5>/publish cmd'
  // Terminate for MATLABSystem: '<S24>/SinkBlock'
  if (r2016bSingleARDroneCtrl_DW.obj_b.isInitialized == 1) {
    r2016bSingleARDroneCtrl_DW.obj_b.isInitialized = 2;
  }

  // End of Terminate for MATLABSystem: '<S24>/SinkBlock'
  // End of Terminate for SubSystem: '<S5>/publish cmd'

  // Terminate for Atomic SubSystem: '<Root>/subscribe pose1'
  // Terminate for MATLABSystem: '<S9>/SourceBlock'
  if (r2016bSingleARDroneCtrl_DW.obj_m.isInitialized == 1) {
    r2016bSingleARDroneCtrl_DW.obj_m.isInitialized = 2;
  }

  // End of Terminate for MATLABSystem: '<S9>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/subscribe pose1'

  // Terminate for Atomic SubSystem: '<Root>/subscribe pose4'
  // Terminate for MATLABSystem: '<S12>/SourceBlock'
  if (r2016bSingleARDroneCtrl_DW.obj_bh.isInitialized == 1) {
    r2016bSingleARDroneCtrl_DW.obj_bh.isInitialized = 2;
  }

  // End of Terminate for MATLABSystem: '<S12>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/subscribe pose4'

  // Terminate for Atomic SubSystem: '<S6>/publish cmd'
  // Terminate for MATLABSystem: '<S26>/SinkBlock'
  if (r2016bSingleARDroneCtrl_DW.obj.isInitialized == 1) {
    r2016bSingleARDroneCtrl_DW.obj.isInitialized = 2;
  }

  // End of Terminate for MATLABSystem: '<S26>/SinkBlock'
  // End of Terminate for SubSystem: '<S6>/publish cmd'
}

//
// File trailer for generated code.
//
// [EOF]
//
