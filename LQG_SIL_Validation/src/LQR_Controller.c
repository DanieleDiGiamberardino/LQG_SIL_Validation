/*
 * LQR_Controller.c
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

#include "LQR_Controller.h"
#include <emmintrin.h>
#include "rtwtypes.h"
#include "LQR_Controller_private.h"
#include <string.h>

/* Block signals (default storage) */
B_LQR_Controller_T LQR_Controller_B;

/* Block states (default storage) */
DW_LQR_Controller_T LQR_Controller_DW;

/* External inputs (root inport signals with default storage) */
ExtU_LQR_Controller_T LQR_Controller_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_LQR_Controller_T LQR_Controller_Y;

/* Real-time model */
static RT_MODEL_LQR_Controller_T LQR_Controller_M_;
RT_MODEL_LQR_Controller_T *const LQR_Controller_M = &LQR_Controller_M_;

/* Model step function */
void LQR_Controller_step(void)
{
  __m128d tmp_0;
  real_T rtb_Sum;
  real_T tmp;

  /* Outputs for Atomic SubSystem: '<Root>/LQR_Controller' */
  /* Delay: '<S2>/MemoryX' incorporates:
   *  Constant: '<S2>/X0'
   */
  if (LQR_Controller_DW.icLoad) {
    LQR_Controller_DW.MemoryX_DSTATE[0] = 0.0;
    LQR_Controller_DW.MemoryX_DSTATE[1] = 0.0;
  }

  /* Outputs for Enabled SubSystem: '<S24>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S55>/Enable'
   */
  LQR_Controller_DW.MeasurementUpdate_MODE = true;

  /* End of Outputs for SubSystem: '<S24>/MeasurementUpdate' */

  /* Saturate: '<S1>/Saturation' incorporates:
   *  Constant: '<S1>/K_discrete'
   *  Delay: '<S2>/MemoryX'
   *  MATLAB Function: '<S1>/MATLAB Function'
   */
  LQR_Controller_Y.u = -20.326109795709726 * LQR_Controller_DW.MemoryX_DSTATE[0]
    + -6.3387909654367736 * LQR_Controller_DW.MemoryX_DSTATE[1];

  /* Saturate: '<S1>/Saturation' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function'
   */
  if (LQR_Controller_Y.u > 10.0) {
    /* Saturate: '<S1>/Saturation' */
    LQR_Controller_Y.u = 10.0;
  } else if (LQR_Controller_Y.u < -10.0) {
    /* Saturate: '<S1>/Saturation' */
    LQR_Controller_Y.u = -10.0;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Outputs for Enabled SubSystem: '<S24>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S55>/Enable'
   */
  /* Sum: '<S55>/Sum' incorporates:
   *  Constant: '<S1>/K_discrete'
   *  Constant: '<S2>/C'
   *  Constant: '<S2>/D'
   *  Delay: '<S2>/MemoryX'
   *  Inport: '<Root>/y'
   *  MATLAB Function: '<S1>/MATLAB Function'
   *  Product: '<S55>/C[k]*xhat[k|k-1]'
   *  Product: '<S55>/D[k]*u[k]'
   *  Sum: '<S55>/Add1'
   */
  rtb_Sum = LQR_Controller_U.y - ((0.0 * LQR_Controller_DW.MemoryX_DSTATE[1] +
    LQR_Controller_DW.MemoryX_DSTATE[0]) + 0.0 * LQR_Controller_Y.u);

  /* End of Outputs for SubSystem: '<S24>/MeasurementUpdate' */

  /* Update for Delay: '<S2>/MemoryX' */
  LQR_Controller_DW.icLoad = false;

  /* Outputs for Enabled SubSystem: '<S24>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S55>/Enable'
   */
  /* Product: '<S55>/Product3' incorporates:
   *  Constant: '<S4>/KalmanGainL'
   */
  LQR_Controller_B.Product3[0] = 0.004689533852170343 * rtb_Sum;

  /* End of Outputs for SubSystem: '<S24>/MeasurementUpdate' */

  /* Product: '<S24>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S2>/A'
   *  Delay: '<S2>/MemoryX'
   */
  tmp = 0.99508638500304725 * LQR_Controller_DW.MemoryX_DSTATE[0] +
    0.097378670446967311 * LQR_Controller_DW.MemoryX_DSTATE[1];

  /* Outputs for Enabled SubSystem: '<S24>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S55>/Enable'
   */
  /* Product: '<S55>/Product3' incorporates:
   *  Constant: '<S4>/KalmanGainL'
   */
  LQR_Controller_B.Product3[1] = -0.00035120136554093318 * rtb_Sum;

  /* End of Outputs for SubSystem: '<S24>/MeasurementUpdate' */

  /* Product: '<S24>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S2>/A'
   *  Delay: '<S2>/MemoryX'
   */
  rtb_Sum = -0.097378670446967311 * LQR_Controller_DW.MemoryX_DSTATE[0] +
    0.94639704977956363 * LQR_Controller_DW.MemoryX_DSTATE[1];

  /* Product: '<S24>/B[k]*u[k]' incorporates:
   *  Constant: '<S2>/B'
   *  Product: '<S24>/A[k]*xhat[k|k-1]'
   *  Product: '<S55>/Product3'
   *  Sum: '<S24>/Add'
   */
  tmp_0 = _mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_set_pd(0.097378670446967325,
    0.0049136149969527237), _mm_set1_pd(LQR_Controller_Y.u)), _mm_set_pd(rtb_Sum,
    tmp)), _mm_loadu_pd(&LQR_Controller_B.Product3[0]));

  /* Update for Delay: '<S2>/MemoryX' incorporates:
   *  Constant: '<S2>/B'
   *  Product: '<S24>/B[k]*u[k]'
   */
  _mm_storeu_pd(&LQR_Controller_DW.MemoryX_DSTATE[0], tmp_0);

  /* End of Outputs for SubSystem: '<Root>/LQR_Controller' */

  /* Matfile logging */
  rt_UpdateTXYLogVars(LQR_Controller_M->rtwLogInfo,
                      (&LQR_Controller_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(LQR_Controller_M)!=-1) &&
        !((rtmGetTFinal(LQR_Controller_M)-LQR_Controller_M->Timing.taskTime0) >
          LQR_Controller_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(LQR_Controller_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++LQR_Controller_M->Timing.clockTick0)) {
    ++LQR_Controller_M->Timing.clockTickH0;
  }

  LQR_Controller_M->Timing.taskTime0 = LQR_Controller_M->Timing.clockTick0 *
    LQR_Controller_M->Timing.stepSize0 + LQR_Controller_M->Timing.clockTickH0 *
    LQR_Controller_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void LQR_Controller_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)LQR_Controller_M, 0,
                sizeof(RT_MODEL_LQR_Controller_T));
  rtmSetTFinal(LQR_Controller_M, 25.0);
  LQR_Controller_M->Timing.stepSize0 = 0.1;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    LQR_Controller_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(LQR_Controller_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(LQR_Controller_M->rtwLogInfo, (NULL));
    rtliSetLogT(LQR_Controller_M->rtwLogInfo, "tout");
    rtliSetLogX(LQR_Controller_M->rtwLogInfo, "");
    rtliSetLogXFinal(LQR_Controller_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(LQR_Controller_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(LQR_Controller_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(LQR_Controller_M->rtwLogInfo, 0);
    rtliSetLogDecimation(LQR_Controller_M->rtwLogInfo, 1);
    rtliSetLogY(LQR_Controller_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(LQR_Controller_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(LQR_Controller_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &LQR_Controller_B), 0,
                sizeof(B_LQR_Controller_T));

  /* states (dwork) */
  (void) memset((void *)&LQR_Controller_DW, 0,
                sizeof(DW_LQR_Controller_T));

  /* external inputs */
  LQR_Controller_U.y = 0.0;

  /* external outputs */
  LQR_Controller_Y.u = 0.0;

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(LQR_Controller_M->rtwLogInfo, 0.0,
    rtmGetTFinal(LQR_Controller_M), LQR_Controller_M->Timing.stepSize0,
    (&rtmGetErrorStatus(LQR_Controller_M)));

  /* SystemInitialize for Atomic SubSystem: '<Root>/LQR_Controller' */
  /* InitializeConditions for Delay: '<S2>/MemoryX' */
  LQR_Controller_DW.icLoad = true;

  /* SystemInitialize for Enabled SubSystem: '<S24>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S55>/Product3' incorporates:
   *  Outport: '<S55>/L*(y[k]-yhat[k|k-1])'
   */
  LQR_Controller_B.Product3[0] = 0.0;
  LQR_Controller_B.Product3[1] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S24>/MeasurementUpdate' */
  /* End of SystemInitialize for SubSystem: '<Root>/LQR_Controller' */
}

/* Model terminate function */
void LQR_Controller_terminate(void)
{
  /* (no terminate code required) */
}
