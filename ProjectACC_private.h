/*
 * File: ProjectACC_private.h
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

#ifndef RTW_HEADER_ProjectACC_private_h_
#define RTW_HEADER_ProjectACC_private_h_
#include "rtwtypes.h"

/* Imported (extern) block signals */
extern uint8_T CameraInput_LeadVehicle;/* '<Root>/CameraInput_LeadVehicle' */
extern uint8_T RadarInput_LeadVehicle; /* '<Root>/RadarInput_LeadVehicle' */
extern uint8_T CameraInput_DriveVehicle;/* '<Root>/CameraInput_DriveVehicle' */
extern uint8_T RadarInput_DriveVehicle;/* '<Root>/RadarInput_DriveVehicle' */
extern uint8_T Time_Gap;               /* '<Root>/Time_Gap' */
extern uint8_T Set_Speed;              /* '<Root>/Set_Speed' */
extern uint8_T Set_Gap;                /* '<Root>/Set_Gap' */
extern boolean_T CruiseSwitch;         /* '<Root>/CruiseSwitch' */
extern boolean_T SetSwitch;            /* '<Root>/SetSwitch' */
extern real_T rt_roundd_snf(real_T u);

#endif                                 /* RTW_HEADER_ProjectACC_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
