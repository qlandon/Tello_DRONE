/* Include files */

#include "Drone_NAV_SLAM_sfun.h"
#include "c1_Drone_NAV_SLAM.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtRSInfo c1_emlrtRSI = { 2,  /* lineNo */
  "MATLAB Function1",                  /* fcnName */
  "#Drone_NAV_SLAM:41"                 /* pathName */
};

static emlrtRSInfo c1_b_emlrtRSI = { 49,/* lineNo */
  "rgb2gray",                          /* fcnName */
  "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/images/rgb2gray.m"/* pathName */
};

/* Function Declarations */
static void initialize_c1_Drone_NAV_SLAM(SFc1_Drone_NAV_SLAMInstanceStruct
  *chartInstance);
static void initialize_params_c1_Drone_NAV_SLAM
  (SFc1_Drone_NAV_SLAMInstanceStruct *chartInstance);
static void mdl_start_c1_Drone_NAV_SLAM(SFc1_Drone_NAV_SLAMInstanceStruct
  *chartInstance);
static void mdl_terminate_c1_Drone_NAV_SLAM(SFc1_Drone_NAV_SLAMInstanceStruct
  *chartInstance);
static void mdl_setup_runtime_resources_c1_Drone_NAV_SLAM
  (SFc1_Drone_NAV_SLAMInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c1_Drone_NAV_SLAM
  (SFc1_Drone_NAV_SLAMInstanceStruct *chartInstance);
static void enable_c1_Drone_NAV_SLAM(SFc1_Drone_NAV_SLAMInstanceStruct
  *chartInstance);
static void disable_c1_Drone_NAV_SLAM(SFc1_Drone_NAV_SLAMInstanceStruct
  *chartInstance);
static void sf_gateway_c1_Drone_NAV_SLAM(SFc1_Drone_NAV_SLAMInstanceStruct
  *chartInstance);
static void ext_mode_exec_c1_Drone_NAV_SLAM(SFc1_Drone_NAV_SLAMInstanceStruct
  *chartInstance);
static void c1_update_jit_animation_c1_Drone_NAV_SLAM
  (SFc1_Drone_NAV_SLAMInstanceStruct *chartInstance);
static void c1_do_animation_call_c1_Drone_NAV_SLAM
  (SFc1_Drone_NAV_SLAMInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_Drone_NAV_SLAM
  (SFc1_Drone_NAV_SLAMInstanceStruct *chartInstance);
static void set_sim_state_c1_Drone_NAV_SLAM(SFc1_Drone_NAV_SLAMInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void c1_emlrt_marshallIn(SFc1_Drone_NAV_SLAMInstanceStruct *chartInstance,
  const mxArray *c1_nullptr, const char_T *c1_identifier, uint8_T c1_y[691200]);
static void c1_b_emlrt_marshallIn(SFc1_Drone_NAV_SLAMInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  uint8_T c1_y[691200]);
static void c1_slStringInitializeDynamicBuffers
  (SFc1_Drone_NAV_SLAMInstanceStruct *chartInstance);
static void c1_chart_data_browse_helper(SFc1_Drone_NAV_SLAMInstanceStruct
  *chartInstance, int32_T c1_ssIdNumber, const mxArray **c1_mxData, uint8_T
  *c1_isValueTooBig);
static void init_dsm_address_info(SFc1_Drone_NAV_SLAMInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc1_Drone_NAV_SLAMInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_Drone_NAV_SLAM(SFc1_Drone_NAV_SLAMInstanceStruct
  *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c1_doneDoubleBufferReInit = false;
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c1_Drone_NAV_SLAM
  (SFc1_Drone_NAV_SLAMInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c1_Drone_NAV_SLAM(SFc1_Drone_NAV_SLAMInstanceStruct
  *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c1_Drone_NAV_SLAM(SFc1_Drone_NAV_SLAMInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c1_Drone_NAV_SLAM
  (SFc1_Drone_NAV_SLAMInstanceStruct *chartInstance)
{
  static const uint32_T c1_decisionTxtEndIdx = 0U;
  static const uint32_T c1_decisionTxtStartIdx = 0U;
  setDataBrowseFcn(chartInstance->S, (void *)&c1_chart_data_browse_helper);
  chartInstance->c1_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c1_RuntimeVar,
    &chartInstance->c1_IsDebuggerActive,
    &chartInstance->c1_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c1_mlFcnLineNumber, &chartInstance->c1_IsHeatMapPresent, 0);
  sfSetAnimationVectors(chartInstance->S, &chartInstance->c1_JITStateAnimation[0],
                        &chartInstance->c1_JITTransitionAnimation[0]);
  covrtCreateStateflowInstanceData(chartInstance->c1_covrtInstance, 1U, 0U, 1U,
    8U);
  covrtChartInitFcn(chartInstance->c1_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c1_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c1_decisionTxtStartIdx, &c1_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c1_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U,
                     "c1_Drone_NAV_SLAM", 0, -1, 80);
}

static void mdl_cleanup_runtime_resources_c1_Drone_NAV_SLAM
  (SFc1_Drone_NAV_SLAMInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c1_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c1_covrtInstance);
}

static void enable_c1_Drone_NAV_SLAM(SFc1_Drone_NAV_SLAMInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_Drone_NAV_SLAM(SFc1_Drone_NAV_SLAMInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c1_Drone_NAV_SLAM(SFc1_Drone_NAV_SLAMInstanceStruct
  *chartInstance)
{
  int32_T c1_i;
  int32_T c1_i1;
  for (c1_i = 0; c1_i < 2073600; c1_i++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 0U, (real_T)
                      (*chartInstance->c1_imageRGB)[c1_i]);
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_JITTransitionAnimation[0] = 0U;
  chartInstance->c1_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c1_covrtInstance, 4U, 0, 0);
  rgb2gray_tbb_uint8(&(*chartInstance->c1_imageRGB)[0], 691200.0,
                     &(*chartInstance->c1_grayImage)[0], true);
  for (c1_i1 = 0; c1_i1 < 691200; c1_i1++) {
    covrtSigUpdateFcn(chartInstance->c1_covrtInstance, 1U, (real_T)
                      (*chartInstance->c1_grayImage)[c1_i1]);
  }
}

static void ext_mode_exec_c1_Drone_NAV_SLAM(SFc1_Drone_NAV_SLAMInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_update_jit_animation_c1_Drone_NAV_SLAM
  (SFc1_Drone_NAV_SLAMInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_do_animation_call_c1_Drone_NAV_SLAM
  (SFc1_Drone_NAV_SLAMInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_Drone_NAV_SLAM
  (SFc1_Drone_NAV_SLAMInstanceStruct *chartInstance)
{
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_st = NULL;
  const mxArray *c1_y = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(1, 1), false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", *chartInstance->c1_grayImage, 3, 0U,
    1, 0U, 2, 720, 960), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_Drone_NAV_SLAM(SFc1_Drone_NAV_SLAMInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  int32_T c1_i;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                      "grayImage", chartInstance->c1_uv);
  for (c1_i = 0; c1_i < 691200; c1_i++) {
    (*chartInstance->c1_grayImage)[c1_i] = chartInstance->c1_uv[c1_i];
  }

  sf_mex_destroy(&c1_u);
  sf_mex_destroy(&c1_st);
}

const mxArray *sf_c1_Drone_NAV_SLAM_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static void c1_emlrt_marshallIn(SFc1_Drone_NAV_SLAMInstanceStruct *chartInstance,
  const mxArray *c1_nullptr, const char_T *c1_identifier, uint8_T c1_y[691200])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nullptr), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_nullptr);
}

static void c1_b_emlrt_marshallIn(SFc1_Drone_NAV_SLAMInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  uint8_T c1_y[691200])
{
  int32_T c1_i;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), chartInstance->c1_b_uv, 1, 3, 0U,
                1, 0U, 2, 720, 960);
  for (c1_i = 0; c1_i < 691200; c1_i++) {
    c1_y[c1_i] = chartInstance->c1_b_uv[c1_i];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_slStringInitializeDynamicBuffers
  (SFc1_Drone_NAV_SLAMInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_chart_data_browse_helper(SFc1_Drone_NAV_SLAMInstanceStruct
  *chartInstance, int32_T c1_ssIdNumber, const mxArray **c1_mxData, uint8_T
  *c1_isValueTooBig)
{
  (void)chartInstance;
  *c1_mxData = NULL;
  *c1_isValueTooBig = 0U;
  switch (c1_ssIdNumber) {
   case 4U:
    *c1_isValueTooBig = 1U;
    break;

   case 5U:
    *c1_isValueTooBig = 1U;
    break;
  }
}

static void init_dsm_address_info(SFc1_Drone_NAV_SLAMInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_Drone_NAV_SLAMInstanceStruct
  *chartInstance)
{
  chartInstance->c1_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c1_imageRGB = (uint8_T (*)[2073600])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c1_grayImage = (uint8_T (*)[691200])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c1_Drone_NAV_SLAM_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1352817881U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4126984301U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1721097078U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2412736074U);
}

mxArray *sf_c1_Drone_NAV_SLAM_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Rgb2grayBuildable"));
  return(mxcell3p);
}

mxArray *sf_c1_Drone_NAV_SLAM_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("rgb2gray_tbb_uint8");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c1_Drone_NAV_SLAM_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_Drone_NAV_SLAM(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiDWYGRgYAPSHEDMxAABrFA+IxKGiLPAxRWAuKSyIBUkXlyU7JkCpPMSc8H8xNI"
    "Kz7y0fLD5FgwI89kImM8JFYeAD/aU6RdxAOl3QNLPgkU/J5J+ASg/vSix0jM3MT0VKs4HpQFLKh"
    "AB"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_Drone_NAV_SLAM_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sjOxj1ISA0khFP34XdyIpxC";
}

static void sf_opaque_initialize_c1_Drone_NAV_SLAM(void *chartInstanceVar)
{
  initialize_params_c1_Drone_NAV_SLAM((SFc1_Drone_NAV_SLAMInstanceStruct*)
    chartInstanceVar);
  initialize_c1_Drone_NAV_SLAM((SFc1_Drone_NAV_SLAMInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_Drone_NAV_SLAM(void *chartInstanceVar)
{
  enable_c1_Drone_NAV_SLAM((SFc1_Drone_NAV_SLAMInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_Drone_NAV_SLAM(void *chartInstanceVar)
{
  disable_c1_Drone_NAV_SLAM((SFc1_Drone_NAV_SLAMInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_Drone_NAV_SLAM(void *chartInstanceVar)
{
  sf_gateway_c1_Drone_NAV_SLAM((SFc1_Drone_NAV_SLAMInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_Drone_NAV_SLAM(SimStruct* S)
{
  return get_sim_state_c1_Drone_NAV_SLAM((SFc1_Drone_NAV_SLAMInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_Drone_NAV_SLAM(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c1_Drone_NAV_SLAM((SFc1_Drone_NAV_SLAMInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c1_Drone_NAV_SLAM(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_Drone_NAV_SLAMInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Drone_NAV_SLAM_optimization_info();
    }

    mdl_cleanup_runtime_resources_c1_Drone_NAV_SLAM
      ((SFc1_Drone_NAV_SLAMInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c1_Drone_NAV_SLAM(void *chartInstanceVar)
{
  mdl_start_c1_Drone_NAV_SLAM((SFc1_Drone_NAV_SLAMInstanceStruct*)
    chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc1_Drone_NAV_SLAMInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c1_Drone_NAV_SLAM(void *chartInstanceVar)
{
  mdl_terminate_c1_Drone_NAV_SLAM((SFc1_Drone_NAV_SLAMInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_Drone_NAV_SLAM(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_Drone_NAV_SLAM((SFc1_Drone_NAV_SLAMInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c1_Drone_NAV_SLAM_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [20] = {
    "eNrdWMtu20YUHRmOURdtkAAFkkWBdpFFNwUcuAsvijYKJbUErFgoZTfIxhiRV+REwyEzD1kq0K/",
    "oNzRfkj/IJssu+gFdFV32DkXJgqzIHAqI3RKgqEvqzH3MuQ+KNPwuweMuns8fELKH14/w3CGz40",
    "4pN5bO2f1d8m0p9z4mJEyo1L4YZsT9CLMIYhCBGQ7ZxBErTNqjkqaqhl5BU/gJVMaNZplwM56JI",
    "UgQIS6QZ1I76VUsNZyJUceI0GpWPycsTIIkMzx6igvS6ETw6fv05kb3UGOLSQh1ByDSicxMnHQ4",
    "jTdHQeoLL4FwpEzqHCsFOjC5dVV1Ddcs59CeQOgLpSlGQV3jb6CpBk9PnBnCVDBHZ2nOGRXVY51",
    "QFUCO7NBwmkf4eWI0Rq+iXtQ3YILqTDLK2yn3LMMrYnsc7ewirblznHWqWzAwccxEbKMrTQoC/U",
    "eeVIjV0MvGIGkMJ8IxB6137UmxwQteVs9B39KyVg6adLYrqha20NseY4RUTb2dUHiUc+WG7Wf5M",
    "YyBF/pbVNMa2Jl+B7BSLOpnZ1TaLHDMJCPYKwMl1stExKrv8HgFVRTcZ1g8K8BZaikFEYZ5Yfpi",
    "oes4aZTOUg/TqHV8XFHfVawvNMghDaFy7ZOUKUCDC1456o2YogNu0RglXXhZeQUQtaFEDY1oXWR",
    "yhDF2LbKXsbKZ4IaGKIYWaCgKRhvZfUa5qWhzqrDCWXqcKqxYbnoRa/OnFjikYQKR7SeMQxeUXU",
    "BVrs/YR5ro7ZjpaQtUKFleNZOMgggbiY1Sf5rDqRiJ7EJ0ZJYG5USwgVcAWDWoFNgWnmJbktMOG",
    "l/Nagmv+pZZdcazlGpOB5YbP4DAzmJ9tZ2QhphVbYGjGxq0DTZgv2BrF4opjePUtF3kQFTMow8b",
    "bvPo/VI+XOSSr/oSd4piGxY4KTUHxbAHfZZCcSOgOFPMxPKweg/Ipd79nc16d/BboyaObIn7cQm",
    "3uyY+95dw90o5fHzekpmA82fNs/PguNl9j9+fVIh3FRy5grvUN79+tYRvrNFLlq7b7M+TJdynK3",
    "p2V3B7Zcwe/fHb6Pe3O3+/zl/8GQ7e/LqN/neOfL5byp/P57NFBxtfKfJV+PBghQ9WVi9PJi8f+",
    "0HzYJR0eoffPI+mfj7xZvviaO/8/pd4aixwRb2UoR+V71pWpmb2DmDXP1qyd++a9feX+ETIX99v",
    "h//sySof1sVrfyVeVo4lnfopNow1PL7tdeOm6tRN2lmljjU+MI58YNy2/rnW5//67w821AWy8vt",
    "7t9iPTfXJpU/fNr/eEbe+9EUpf7d4h/YSxqM1U3z5GAft4bqn/xN+/+MYv/nc0LbxK/8EfHHYFJ",
    "RPcWyfvRaVt3vS/v+0eCSBqvXvRjfRh+bXo2v6/p2V/Lbyab/z9dEW/exfoHj+0g==",
    ""
  };

  static char newstr [1417] = "";
  newstr[0] = '\0';
  for (i = 0; i < 20; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c1_Drone_NAV_SLAM(SimStruct *S)
{
  const char* newstr = sf_c1_Drone_NAV_SLAM_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1804853284U));
  ssSetChecksum1(S,(4127380389U));
  ssSetChecksum2(S,(3831132326U));
  ssSetChecksum3(S,(2110022243U));
}

static void mdlRTW_c1_Drone_NAV_SLAM(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c1_Drone_NAV_SLAM(SimStruct *S)
{
  SFc1_Drone_NAV_SLAMInstanceStruct *chartInstance;
  chartInstance = (SFc1_Drone_NAV_SLAMInstanceStruct *)utMalloc(sizeof
    (SFc1_Drone_NAV_SLAMInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_Drone_NAV_SLAMInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_Drone_NAV_SLAM;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_Drone_NAV_SLAM;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c1_Drone_NAV_SLAM;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c1_Drone_NAV_SLAM;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c1_Drone_NAV_SLAM;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_Drone_NAV_SLAM;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_Drone_NAV_SLAM;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_Drone_NAV_SLAM;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_Drone_NAV_SLAM;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_Drone_NAV_SLAM;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_Drone_NAV_SLAM;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_Drone_NAV_SLAM;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c1_Drone_NAV_SLAM(chartInstance);
}

void c1_Drone_NAV_SLAM_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c1_Drone_NAV_SLAM(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_Drone_NAV_SLAM(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_Drone_NAV_SLAM(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_Drone_NAV_SLAM_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
