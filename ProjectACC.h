/*
 * File: ProjectACC.h
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

#ifndef RTW_HEADER_ProjectACC_h_
#define RTW_HEADER_ProjectACC_h_
#include <math.h>
#ifndef ProjectACC_COMMON_INCLUDES_
#define ProjectACC_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ProjectACC_COMMON_INCLUDES_ */

#include "ProjectACC_types.h"

/* Includes for objects with custom storage classes. */
#include "Adaptive_Cruise_Control_Function.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_ProjectACC;     /* '<S1>/Adaptive_Cruise_Control' */
  uint8_T is_c3_ProjectACC;            /* '<S1>/Adaptive_Cruise_Control' */
  uint8_T is_ACC_ON_MODE;              /* '<S1>/Adaptive_Cruise_Control' */
} DW_ProjectACC_T;

/* Real-time Model Data Structure */
struct tag_RTM_ProjectACC_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_ProjectACC_T ProjectACC_DW;

/* Model entry point functions */
extern void ProjectACC_initialize(void);
extern void ProjectACC_step(void);
extern void ProjectACC_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ProjectACC_T *const ProjectACC_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Signal Conversion' : Eliminate redundant signal conversion block
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ProjectACC'
 * '<S1>'   : 'ProjectACC/Adaptive_Cruise_Control_System'
 * '<S2>'   : 'ProjectACC/Adaptive_Cruise_Control_System/Adaptive_Cruise_Control'
 * '<S3>'   : 'ProjectACC/Adaptive_Cruise_Control_System/Drive_Vehicle'
 * '<S4>'   : 'ProjectACC/Adaptive_Cruise_Control_System/Lead_Vehicle'
 */
#endif                                 /* RTW_HEADER_ProjectACC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
