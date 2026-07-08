/*
 * LQR_Controller.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "LQR_Controller".
 *
 * Model version              : 1.3
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Mon Jul  6 16:43:26 2026
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef LQR_Controller_h_
#define LQR_Controller_h_
#ifndef LQR_Controller_COMMON_INCLUDES_
#define LQR_Controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* LQR_Controller_COMMON_INCLUDES_ */

#include "LQR_Controller_types.h"
#include <float.h>
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Product3[2];                  /* '<S55>/Product3' */
} B_LQR_Controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T MemoryX_DSTATE[2];            /* '<S2>/MemoryX' */
  boolean_T icLoad;                    /* '<S2>/MemoryX' */
  boolean_T MeasurementUpdate_MODE;    /* '<S24>/MeasurementUpdate' */
} DW_LQR_Controller_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T y;                            /* '<Root>/y' */
} ExtU_LQR_Controller_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T u;                            /* '<Root>/u' */
} ExtY_LQR_Controller_T;

/* Real-time Model Data Structure */
struct tag_RTM_LQR_Controller_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (default storage) */
extern B_LQR_Controller_T LQR_Controller_B;

/* Block states (default storage) */
extern DW_LQR_Controller_T LQR_Controller_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_LQR_Controller_T LQR_Controller_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_LQR_Controller_T LQR_Controller_Y;

/* Model entry point functions */
extern void LQR_Controller_initialize(void);
extern void LQR_Controller_step(void);
extern void LQR_Controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_LQR_Controller_T *const LQR_Controller_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S47>/Data Type Duplicate' : Unused code path elimination
 * Block '<S48>/Conversion' : Unused code path elimination
 * Block '<S48>/Data Type Duplicate' : Unused code path elimination
 * Block '<S49>/Conversion' : Unused code path elimination
 * Block '<S49>/Data Type Duplicate' : Unused code path elimination
 * Block '<S50>/Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/KalmanGainM' : Unused code path elimination
 * Block '<S7>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Conversion' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/G' : Unused code path elimination
 * Block '<S2>/H' : Unused code path elimination
 * Block '<S2>/N' : Unused code path elimination
 * Block '<S2>/P0' : Unused code path elimination
 * Block '<S2>/Q' : Unused code path elimination
 * Block '<S2>/R' : Unused code path elimination
 * Block '<S45>/CheckSignalProperties' : Unused code path elimination
 * Block '<S46>/CheckSignalProperties' : Unused code path elimination
 * Block '<S47>/Conversion' : Eliminate redundant data type conversion
 * Block '<S50>/Conversion' : Eliminate redundant data type conversion
 * Block '<S20>/Conversion' : Eliminate redundant data type conversion
 * Block '<S24>/Reshape' : Reshape block reduction
 * Block '<S2>/ReshapeX0' : Reshape block reduction
 * Block '<S2>/Reshapeu' : Reshape block reduction
 * Block '<S2>/Reshapexhat' : Reshape block reduction
 * Block '<S2>/Reshapey' : Reshape block reduction
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('LQG_Discrete/LQR_Controller')    - opens subsystem LQG_Discrete/LQR_Controller
 * hilite_system('LQG_Discrete/LQR_Controller/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'LQG_Discrete'
 * '<S1>'   : 'LQG_Discrete/LQR_Controller'
 * '<S2>'   : 'LQG_Discrete/LQR_Controller/Kalman Filter'
 * '<S3>'   : 'LQG_Discrete/LQR_Controller/MATLAB Function'
 * '<S4>'   : 'LQG_Discrete/LQR_Controller/Kalman Filter/CalculatePL'
 * '<S5>'   : 'LQG_Discrete/LQR_Controller/Kalman Filter/CalculateYhat'
 * '<S6>'   : 'LQG_Discrete/LQR_Controller/Kalman Filter/CovarianceOutputConfigurator'
 * '<S7>'   : 'LQG_Discrete/LQR_Controller/Kalman Filter/DataTypeConversionA'
 * '<S8>'   : 'LQG_Discrete/LQR_Controller/Kalman Filter/DataTypeConversionB'
 * '<S9>'   : 'LQG_Discrete/LQR_Controller/Kalman Filter/DataTypeConversionC'
 * '<S10>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/DataTypeConversionD'
 * '<S11>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/DataTypeConversionEnable'
 * '<S12>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/DataTypeConversionG'
 * '<S13>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/DataTypeConversionH'
 * '<S14>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/DataTypeConversionN'
 * '<S15>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/DataTypeConversionP'
 * '<S16>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/DataTypeConversionP0'
 * '<S17>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/DataTypeConversionQ'
 * '<S18>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/DataTypeConversionR'
 * '<S19>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/DataTypeConversionReset'
 * '<S20>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/DataTypeConversionX'
 * '<S21>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/DataTypeConversionX0'
 * '<S22>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/DataTypeConversionu'
 * '<S23>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/MemoryP'
 * '<S24>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/Observer'
 * '<S25>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/ReducedQRN'
 * '<S26>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/Reset'
 * '<S27>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/Reshapeyhat'
 * '<S28>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/ScalarExpansionP0'
 * '<S29>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/ScalarExpansionQ'
 * '<S30>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/ScalarExpansionR'
 * '<S31>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/UseCurrentEstimator'
 * '<S32>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/checkA'
 * '<S33>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/checkB'
 * '<S34>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/checkC'
 * '<S35>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/checkD'
 * '<S36>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/checkEnable'
 * '<S37>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/checkG'
 * '<S38>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/checkH'
 * '<S39>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/checkN'
 * '<S40>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/checkP0'
 * '<S41>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/checkQ'
 * '<S42>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/checkR'
 * '<S43>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/checkReset'
 * '<S44>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/checkX0'
 * '<S45>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/checku'
 * '<S46>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/checky'
 * '<S47>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S48>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S49>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S50>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S51>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/CalculatePL/Ground'
 * '<S52>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/CalculateYhat/Ground'
 * '<S53>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/CovarianceOutputConfigurator/decideOutput'
 * '<S54>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
 * '<S55>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/Observer/MeasurementUpdate'
 * '<S56>'  : 'LQG_Discrete/LQR_Controller/Kalman Filter/ReducedQRN/Ground'
 */
#endif                                 /* LQR_Controller_h_ */
