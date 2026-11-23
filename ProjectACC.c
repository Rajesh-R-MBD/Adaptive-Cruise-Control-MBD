/*
 * File: ProjectACC.c
 *
 * Code generated for Simulink model 'ProjectACC'.
 *
 * Model version                  : 1.53
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Tue Sep 27 20:09:56 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ProjectACC.h"
#include "ProjectACC_private.h"

/* Named constants for Chart: '<S1>/Adaptive_Cruise_Control' */
#define IN_LeadVehicle_Detected_Follow ((uint8_T)1U)
#define IN_LeadVehicle_Detected_Resume ((uint8_T)2U)
#define IN_LeadVehicle_Not_Detected_Res ((uint8_T)4U)
#define IN_LeadVehicle_Speed_Lessthan_S ((uint8_T)5U)
#define IN_LeadVehicle_Speed_equal_Set_ ((uint8_T)6U)
#define Pro_IN_LeadVehicle_Not_Detected ((uint8_T)3U)
#define ProjectACC_IN_ACC_OFFMODE      ((uint8_T)1U)
#define ProjectACC_IN_ACC_ON_MODE      ((uint8_T)2U)
#define ProjectACC_IN_ACC_STANDBYMODE  ((uint8_T)3U)
#define ProjectACC_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)

/* Block states (default storage) */
DW_ProjectACC_T ProjectACC_DW;

/* Real-time model */
static RT_MODEL_ProjectACC_T ProjectACC_M_;
RT_MODEL_ProjectACC_T *const ProjectACC_M = &ProjectACC_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void ProjectACC_step(void)
{
  int32_T tmp;
  int32_T tmp_0;
  uint8_T rtb_Add;
  uint8_T rtb_DriveVehicle_Speed;
  uint8_T tmp_1;
  uint8_T tmp_2;

  /* Sum: '<S4>/Add' incorporates:
   *  Inport: '<Root>/CameraInput_LeadVehicle'
   *  Inport: '<Root>/RadarInput_LeadVehicle'
   */
  rtb_Add = (uint8_T)((uint32_T)CameraInput_LeadVehicle + RadarInput_LeadVehicle);

  /* Sum: '<S3>/Add' incorporates:
   *  Delay: '<S1>/Delay'
   *  Inport: '<Root>/CameraInput_DriveVehicle'
   *  Inport: '<Root>/RadarInput_DriveVehicle'
   */
  rtb_DriveVehicle_Speed = (uint8_T)((uint32_T)(uint8_T)((uint32_T)
    Acceleration_Mode + CameraInput_DriveVehicle) + RadarInput_DriveVehicle);

  /* Chart: '<S1>/Adaptive_Cruise_Control' incorporates:
   *  Inport: '<Root>/CruiseSwitch'
   *  Inport: '<Root>/RadarInput_DriveVehicle'
   *  Inport: '<Root>/SetSwitch'
   *  Inport: '<Root>/Set_Gap'
   *  Inport: '<Root>/Set_Speed'
   *  Inport: '<Root>/Time_Gap'
   */
  if (ProjectACC_DW.is_active_c3_ProjectACC == 0U) {
    ProjectACC_DW.is_active_c3_ProjectACC = 1U;
    ProjectACC_DW.is_c3_ProjectACC = ProjectACC_IN_ACC_OFFMODE;
    Acceleration_Mode = 0U;
  } else {
    switch (ProjectACC_DW.is_c3_ProjectACC) {
     case ProjectACC_IN_ACC_OFFMODE:
      if (CruiseSwitch) {
        ProjectACC_DW.is_c3_ProjectACC = ProjectACC_IN_ACC_STANDBYMODE;
        Acceleration_Mode = 1U;
      }
      break;

     case ProjectACC_IN_ACC_ON_MODE:
      if (!CruiseSwitch) {
        ProjectACC_DW.is_ACC_ON_MODE = ProjectACC_IN_NO_ACTIVE_CHILD;
        ProjectACC_DW.is_c3_ProjectACC = ProjectACC_IN_ACC_OFFMODE;
        Acceleration_Mode = 0U;
      } else if (!SetSwitch) {
        ProjectACC_DW.is_ACC_ON_MODE = ProjectACC_IN_NO_ACTIVE_CHILD;
        ProjectACC_DW.is_c3_ProjectACC = ProjectACC_IN_ACC_STANDBYMODE;
        Acceleration_Mode = 1U;
      } else {
        switch (ProjectACC_DW.is_ACC_ON_MODE) {
         case IN_LeadVehicle_Detected_Follow:
          if (RadarInput_DriveVehicle == 0) {
            ProjectACC_DW.is_ACC_ON_MODE = Pro_IN_LeadVehicle_Not_Detected;
            Acceleration_Mode = 1U;
          } else if (((RadarInput_DriveVehicle == 1) && (rtb_Add < Set_Speed)) ||
                     (Time_Gap < Set_Gap)) {
            ProjectACC_DW.is_ACC_ON_MODE = IN_LeadVehicle_Speed_Lessthan_S;
            Acceleration_Mode = 4U;
          }
          break;

         case IN_LeadVehicle_Detected_Resume:
          if ((rtb_DriveVehicle_Speed == Set_Speed) && (rtb_Add >= Set_Speed) &&
              (Time_Gap >= Set_Gap)) {
            ProjectACC_DW.is_ACC_ON_MODE = IN_LeadVehicle_Detected_Follow;
            Acceleration_Mode = 2U;
          } else if (RadarInput_DriveVehicle == 0) {
            ProjectACC_DW.is_ACC_ON_MODE = IN_LeadVehicle_Not_Detected_Res;
            Acceleration_Mode = 1U;
          } else if ((rtb_DriveVehicle_Speed < Set_Speed) && (rtb_Add >
                      rtb_DriveVehicle_Speed) && (Time_Gap >= Set_Gap)) {
            ProjectACC_DW.is_ACC_ON_MODE = IN_LeadVehicle_Speed_equal_Set_;
            Acceleration_Mode = 5U;
          }
          break;

         case Pro_IN_LeadVehicle_Not_Detected:
          if (((RadarInput_DriveVehicle == 1) && (rtb_Add < Set_Speed)) ||
              (Time_Gap < Set_Gap)) {
            ProjectACC_DW.is_ACC_ON_MODE = IN_LeadVehicle_Speed_Lessthan_S;
            Acceleration_Mode = 4U;
          } else if ((RadarInput_DriveVehicle == 1) && (rtb_DriveVehicle_Speed ==
                      Set_Speed) && (rtb_Add >= Set_Speed) && (Time_Gap >=
                      Set_Gap)) {
            ProjectACC_DW.is_ACC_ON_MODE = IN_LeadVehicle_Detected_Follow;
            Acceleration_Mode = 2U;
          }
          break;

         case IN_LeadVehicle_Not_Detected_Res:
          break;

         case IN_LeadVehicle_Speed_Lessthan_S:
          if ((RadarInput_DriveVehicle == 0) && (rtb_DriveVehicle_Speed ==
               Set_Speed)) {
            ProjectACC_DW.is_ACC_ON_MODE = Pro_IN_LeadVehicle_Not_Detected;
            Acceleration_Mode = 1U;
          } else {
            tmp = (int32_T)rt_roundd_snf((real_T)rtb_Add * 1.25);
            tmp_0 = (int32_T)rt_roundd_snf(1.25 * (real_T)Set_Gap);
            if (tmp < 256) {
              tmp_1 = (uint8_T)tmp;
            } else {
              tmp_1 = MAX_uint8_T;
            }

            if (tmp_0 < 256) {
              tmp_2 = (uint8_T)tmp_0;
            } else {
              tmp_2 = MAX_uint8_T;
            }

            tmp = (int32_T)rt_roundd_snf(0.75 * (real_T)Set_Gap);
            if (((tmp_1 >= rtb_DriveVehicle_Speed) && ((int32_T)rt_roundd_snf
                  ((real_T)rtb_Add * 0.75) <= rtb_DriveVehicle_Speed) &&
                 (rtb_DriveVehicle_Speed < Set_Speed) && (Time_Gap <= tmp_2) &&
                 (Time_Gap >= tmp)) || (((rtb_Add < Set_Speed) && (rtb_Add <
                   rtb_DriveVehicle_Speed)) || (tmp == Time_Gap))) {
              ProjectACC_DW.is_ACC_ON_MODE = IN_LeadVehicle_Speed_equal_Set_;
              Acceleration_Mode = 5U;
            }
          }
          break;

         default:
          /* case IN_LeadVehicle_Speed_equal_Set_Speed: */
          if ((RadarInput_DriveVehicle == 0) || (rtb_DriveVehicle_Speed <=
               Set_Speed)) {
            ProjectACC_DW.is_ACC_ON_MODE = IN_LeadVehicle_Not_Detected_Res;
            Acceleration_Mode = 1U;
          } else if (((rtb_DriveVehicle_Speed < Set_Speed) && (rtb_Add >
                       rtb_DriveVehicle_Speed)) || (Time_Gap >= Set_Gap)) {
            ProjectACC_DW.is_ACC_ON_MODE = IN_LeadVehicle_Detected_Resume;
            Acceleration_Mode = 3U;
          }
          break;
        }
      }
      break;

     default:
      /* case IN_ACC_STANDBYMODE: */
      if (!CruiseSwitch) {
        ProjectACC_DW.is_c3_ProjectACC = ProjectACC_IN_ACC_OFFMODE;
        Acceleration_Mode = 0U;
      } else if (SetSwitch) {
        ProjectACC_DW.is_c3_ProjectACC = ProjectACC_IN_ACC_ON_MODE;
        ProjectACC_DW.is_ACC_ON_MODE = IN_LeadVehicle_Detected_Follow;
        Acceleration_Mode = 2U;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Adaptive_Cruise_Control' */
}

/* Model initialize function */
void ProjectACC_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void ProjectACC_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
