//
// File: r2016bSingleARDroneCtrl.h
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
#ifndef RTW_HEADER_r2016bSingleARDroneCtrl_h_
#define RTW_HEADER_r2016bSingleARDroneCtrl_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef r2016bSingleARDroneCtrl_COMMON_INCLUDES_
# define r2016bSingleARDroneCtrl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#endif                                 // r2016bSingleARDroneCtrl_COMMON_INCLUDES_ 

#include "r2016bSingleARDroneCtrl_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals for system '<S1>/Waypoint manager '
typedef struct {
  real_T x_d;                          // '<S1>/Waypoint manager '
  real_T y_d;                          // '<S1>/Waypoint manager '
  real_T z_d;                          // '<S1>/Waypoint manager '
  real_T yaw_d;                        // '<S1>/Waypoint manager '
  real_T vx_d;                         // '<S1>/Waypoint manager '
  real_T vy_d;                         // '<S1>/Waypoint manager '
  real_T waypointNumber;               // '<S1>/Waypoint manager '
} B_Waypointmanager_r2016bSingl_T;

// Block states (auto storage) for system '<S1>/Waypoint manager '
typedef struct {
  real_T wpointer;                     // '<S1>/Waypoint manager '
} DW_Waypointmanager_r2016bSing_T;

// Block signals for system '<S3>/Coordinate trnasformation  from inertial frame to body frame ' 
typedef struct {
  real_T Vec_xy[2];                    // '<S3>/Coordinate trnasformation  from inertial frame to body frame ' 
} B_Coordinatetrnasformationfro_T;

// Block signals for system '<S3>/Integration '
typedef struct {
  real_T accu_x;                       // '<S3>/Integration '
  real_T accu_y;                       // '<S3>/Integration '
} B_Integration_r2016bSingleARD_T;

// Block states (auto storage) for system '<S3>/Integration '
typedef struct {
  real_T last_waypoint;                // '<S3>/Integration '
  real_T sum_x;                        // '<S3>/Integration '
  real_T sum_y;                        // '<S3>/Integration '
} DW_Integration_r2016bSingleAR_T;

// Block signals for system '<S3>/MATLAB Function'
typedef struct {
  real_T y[2];                         // '<S3>/MATLAB Function'
} B_MATLABFunction_r2016bSingle_T;

// Block signals for system '<Root>/pose1'
typedef struct {
  real_T yaw;                          // '<S7>/ Function'
  real_T x;                            // '<S7>/ '
  real_T y;                            // '<S7>/ '
  real_T z;                            // '<S7>/ '
} B_pose1_r2016bSingleARDroneCt_T;

// Block signals for system '<Root>/vel'
typedef struct {
  real_T x;                            // '<S13>/ '
  real_T y;                            // '<S13>/ '
  real_T z;                            // '<S13>/ '
} B_vel_r2016bSingleARDroneCtrl_T;

// Block signals (auto storage)
typedef struct {
  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PoseStamped In1;// '<S32>/In1'
  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PoseStamped In1_j;// '<S31>/In1'
  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PoseStamped b_varargout_2;
  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PointStamped In1_p;// '<S34>/In1' 
  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PointStamped In1_a;// '<S33>/In1' 
  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PointStamped b_varargout_2_m;
  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Twist cmdBus_b;// '<S6>/cmdBus'
  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Twist cmdBus;// '<S5>/cmdBus'
  B_vel_r2016bSingleARDroneCtrl_T vel1;// '<Root>/vel1'
  B_vel_r2016bSingleARDroneCtrl_T vel; // '<Root>/vel'
  B_pose1_r2016bSingleARDroneCt_T pose2;// '<Root>/pose2'
  B_pose1_r2016bSingleARDroneCt_T pose1;// '<Root>/pose1'
  B_MATLABFunction_r2016bSingle_T sf_MATLABFunction_a;// '<S4>/MATLAB Function'
  B_Integration_r2016bSingleARD_T sf_Integration_p;// '<S4>/Integration '
  B_Coordinatetrnasformationfro_T sf_Coordinatetrnasformationfr_i;// '<S4>/Coordinate trnasformation  from inertial frame to body frame ' 
  B_MATLABFunction_r2016bSingle_T sf_MATLABFunction;// '<S3>/MATLAB Function'
  B_Integration_r2016bSingleARD_T sf_Integration;// '<S3>/Integration '
  B_Coordinatetrnasformationfro_T sf_Coordinatetrnasformationfrom;// '<S3>/Coordinate trnasformation  from inertial frame to body frame ' 
  B_Waypointmanager_r2016bSingl_T sf_Waypointmanager_p;// '<S2>/Waypoint manager ' 
  B_Waypointmanager_r2016bSingl_T sf_Waypointmanager;// '<S1>/Waypoint manager ' 
} B_r2016bSingleARDroneCtrl_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  robotics_slros_internal_block_T obj; // '<S26>/SinkBlock'
  robotics_slros_internal_block_T obj_b;// '<S24>/SinkBlock'
  robotics_slros_internal_blo_i_T obj_bh;// '<S12>/SourceBlock'
  robotics_slros_internal_blo_i_T obj_k;// '<S11>/SourceBlock'
  robotics_slros_internal_blo_i_T obj_p;// '<S10>/SourceBlock'
  robotics_slros_internal_blo_i_T obj_m;// '<S9>/SourceBlock'
  DW_Integration_r2016bSingleAR_T sf_Integration_p;// '<S4>/Integration '
  DW_Integration_r2016bSingleAR_T sf_Integration;// '<S3>/Integration '
  DW_Waypointmanager_r2016bSing_T sf_Waypointmanager_p;// '<S2>/Waypoint manager ' 
  DW_Waypointmanager_r2016bSing_T sf_Waypointmanager;// '<S1>/Waypoint manager ' 
} DW_r2016bSingleARDroneCtrl_T;

// Parameters for system: '<Root>/pose1'
struct P_pose1_r2016bSingleARDroneCt_T_ {
  real_T Out1_Y0;                      // Computed Parameter: Out1_Y0
                                       //  Referenced by: '<S7>/Out1'

};

// Parameters for system: '<Root>/vel'
struct P_vel_r2016bSingleARDroneCtrl_T_ {
  real_T Out1_Y0;                      // Computed Parameter: Out1_Y0
                                       //  Referenced by: '<S13>/Out1'

};

// Parameters (auto storage)
struct P_r2016bSingleARDroneCtrl_T_ {
  real_T delta_p;                      // Variable: delta_p
                                       //  Referenced by:
                                       //    '<Root>/Gain'
                                       //    '<Root>/Gain1'

  real_T k_d_xy;                       // Variable: k_d_xy
                                       //  Referenced by:
                                       //    '<S3>/Vx-d1'
                                       //    '<S3>/Vx-d2'
                                       //    '<S4>/Vx-d1'
                                       //    '<S4>/Vx-d2'

  real_T k_d_z;                        // Variable: k_d_z
                                       //  Referenced by:
                                       //    '<S3>/Vx-d3'
                                       //    '<S4>/Vx-d3'

  real_T k_i_xy;                       // Variable: k_i_xy
                                       //  Referenced by:
                                       //    '<S3>/kxp4'
                                       //    '<S3>/kxp5'
                                       //    '<S4>/kxp4'
                                       //    '<S4>/kxp5'

  real_T k_p_xy;                       // Variable: k_p_xy
                                       //  Referenced by:
                                       //    '<S3>/kxp1'
                                       //    '<S3>/kxp2'
                                       //    '<S4>/kxp1'
                                       //    '<S4>/kxp2'

  real_T k_p_yaw;                      // Variable: k_p_yaw
                                       //  Referenced by:
                                       //    '<S3>/proportional control gain - yaw'
                                       //    '<S4>/proportional control gain - yaw'

  real_T k_p_z;                        // Variable: k_p_z
                                       //  Referenced by:
                                       //    '<S3>/kxp3'
                                       //    '<S4>/kxp3'

  real_T k_sign;                       // Variable: k_sign
                                       //  Referenced by:
                                       //    '<S5>/K'
                                       //    '<S5>/K1'
                                       //    '<S6>/K'
                                       //    '<S6>/K1'

  real_T limit_cmd_xy;                 // Variable: limit_cmd_xy
                                       //  Referenced by:
                                       //    '<S3>/Constant'
                                       //    '<S4>/Constant'

  real_T waypoints1[1771];             // Variable: waypoints1
                                       //  Referenced by: '<Root>/Constant1'

  real_T waypoints2[1771];             // Variable: waypoints2
                                       //  Referenced by: '<Root>/Constant5'

  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PoseStamped Out1_Y0;// Computed Parameter: Out1_Y0
                                                                   //  Referenced by: '<S31>/Out1'

  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PoseStamped Constant_Value;// Computed Parameter: Constant_Value
                                                                      //  Referenced by: '<S9>/Constant'

  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PoseStamped Out1_Y0_c;// Computed Parameter: Out1_Y0_c
                                                                     //  Referenced by: '<S32>/Out1'

  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PoseStamped Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                                      //  Referenced by: '<S10>/Constant'

  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PointStamped Out1_Y0_g;// Computed Parameter: Out1_Y0_g
                                                                      //  Referenced by: '<S33>/Out1'

  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PointStamped Constant_Value_p;// Computed Parameter: Constant_Value_p
                                                                      //  Referenced by: '<S11>/Constant'

  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PointStamped Out1_Y0_j;// Computed Parameter: Out1_Y0_j
                                                                      //  Referenced by: '<S34>/Out1'

  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_PointStamped Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                                      //  Referenced by: '<S12>/Constant'

  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Twist Constant_Value_c;// Computed Parameter: Constant_Value_c
                                                                      //  Referenced by: '<S23>/Constant'

  SL_Bus_r2016bSingleARDroneCtrl_geometry_msgs_Twist Constant_Value_e;// Computed Parameter: Constant_Value_e
                                                                      //  Referenced by: '<S25>/Constant'

  real_T Constant_Value_a;             // Expression: 1
                                       //  Referenced by: '<Root>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                       //  Referenced by: '<S5>/Constant1'

  real_T Constant2_Value;              // Expression: 1
                                       //  Referenced by: '<Root>/Constant2'

  real_T Constant1_Value_m;            // Expression: 0
                                       //  Referenced by: '<S6>/Constant1'

  P_vel_r2016bSingleARDroneCtrl_T vel1;// '<Root>/vel1'
  P_vel_r2016bSingleARDroneCtrl_T vel; // '<Root>/vel'
  P_pose1_r2016bSingleARDroneCt_T pose2;// '<Root>/pose2'
  P_pose1_r2016bSingleARDroneCt_T pose1;// '<Root>/pose1'
};

// Real-time Model Data Structure
struct tag_RTM_r2016bSingleARDroneCt_T {
  const char_T *errorStatus;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_r2016bSingleARDroneCtrl_T r2016bSingleARDroneCtrl_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_r2016bSingleARDroneCtrl_T r2016bSingleARDroneCtrl_B;

// Block states (auto storage)
extern DW_r2016bSingleARDroneCtrl_T r2016bSingleARDroneCtrl_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void r2016bSingleARDroneCtrl_initialize(void);
  extern void r2016bSingleARDroneCtrl_step(void);
  extern void r2016bSingleARDroneCtrl_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_r2016bSingleARDroneC_T *const r2016bSingleARDroneCtrl_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Display' : Unused code path elimination
//  Block '<Root>/Display1' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'r2016bSingleARDroneCtrl'
//  '<S1>'   : 'r2016bSingleARDroneCtrl/Decision'
//  '<S2>'   : 'r2016bSingleARDroneCtrl/Decision1'
//  '<S3>'   : 'r2016bSingleARDroneCtrl/Position Controller1'
//  '<S4>'   : 'r2016bSingleARDroneCtrl/Position Controller2'
//  '<S5>'   : 'r2016bSingleARDroneCtrl/Send Command 1'
//  '<S6>'   : 'r2016bSingleARDroneCtrl/Send Command 2'
//  '<S7>'   : 'r2016bSingleARDroneCtrl/pose1'
//  '<S8>'   : 'r2016bSingleARDroneCtrl/pose2'
//  '<S9>'   : 'r2016bSingleARDroneCtrl/subscribe pose1'
//  '<S10>'  : 'r2016bSingleARDroneCtrl/subscribe pose2'
//  '<S11>'  : 'r2016bSingleARDroneCtrl/subscribe pose3'
//  '<S12>'  : 'r2016bSingleARDroneCtrl/subscribe pose4'
//  '<S13>'  : 'r2016bSingleARDroneCtrl/vel'
//  '<S14>'  : 'r2016bSingleARDroneCtrl/vel1'
//  '<S15>'  : 'r2016bSingleARDroneCtrl/Decision/Waypoint manager '
//  '<S16>'  : 'r2016bSingleARDroneCtrl/Decision1/Waypoint manager '
//  '<S17>'  : 'r2016bSingleARDroneCtrl/Position Controller1/Coordinate trnasformation  from inertial frame to body frame '
//  '<S18>'  : 'r2016bSingleARDroneCtrl/Position Controller1/Integration '
//  '<S19>'  : 'r2016bSingleARDroneCtrl/Position Controller1/MATLAB Function'
//  '<S20>'  : 'r2016bSingleARDroneCtrl/Position Controller2/Coordinate trnasformation  from inertial frame to body frame '
//  '<S21>'  : 'r2016bSingleARDroneCtrl/Position Controller2/Integration '
//  '<S22>'  : 'r2016bSingleARDroneCtrl/Position Controller2/MATLAB Function'
//  '<S23>'  : 'r2016bSingleARDroneCtrl/Send Command 1/ Message'
//  '<S24>'  : 'r2016bSingleARDroneCtrl/Send Command 1/publish cmd'
//  '<S25>'  : 'r2016bSingleARDroneCtrl/Send Command 2/ Message'
//  '<S26>'  : 'r2016bSingleARDroneCtrl/Send Command 2/publish cmd'
//  '<S27>'  : 'r2016bSingleARDroneCtrl/pose1/ '
//  '<S28>'  : 'r2016bSingleARDroneCtrl/pose1/ Function'
//  '<S29>'  : 'r2016bSingleARDroneCtrl/pose2/ '
//  '<S30>'  : 'r2016bSingleARDroneCtrl/pose2/ Function'
//  '<S31>'  : 'r2016bSingleARDroneCtrl/subscribe pose1/Enabled Subsystem'
//  '<S32>'  : 'r2016bSingleARDroneCtrl/subscribe pose2/Enabled Subsystem'
//  '<S33>'  : 'r2016bSingleARDroneCtrl/subscribe pose3/Enabled Subsystem'
//  '<S34>'  : 'r2016bSingleARDroneCtrl/subscribe pose4/Enabled Subsystem'
//  '<S35>'  : 'r2016bSingleARDroneCtrl/vel/ '
//  '<S36>'  : 'r2016bSingleARDroneCtrl/vel1/ '

#endif                                 // RTW_HEADER_r2016bSingleARDroneCtrl_h_

//
// File trailer for generated code.
//
// [EOF]
//
