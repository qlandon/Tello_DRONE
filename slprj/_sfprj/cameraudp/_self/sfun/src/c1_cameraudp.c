/* Include files */

#include "cameraudp_sfun.h"
#include "c1_cameraudp.h"
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
  "#cameraudp:41"                      /* pathName */
};

static emlrtRSInfo c1_b_emlrtRSI = { 49,/* lineNo */
  "rgb2gray",                          /* fcnName */
  "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/images/rgb2gray.m"/* pathName */
};

/* Function Declarations */
static void initialize_c1_cameraudp(SFc1_cameraudpInstanceStruct *chartInstance);
static void initialize_params_c1_cameraudp(SFc1_cameraudpInstanceStruct
  *chartInstance);
static void mdl_start_c1_cameraudp(SFc1_cameraudpInstanceStruct *chartInstance);
static void mdl_terminate_c1_cameraudp(SFc1_cameraudpInstanceStruct
  *chartInstance);
static void mdl_setup_runtime_resources_c1_cameraudp
  (SFc1_cameraudpInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c1_cameraudp
  (SFc1_cameraudpInstanceStruct *chartInstance);
static void enable_c1_cameraudp(SFc1_cameraudpInstanceStruct *chartInstance);
static void disable_c1_cameraudp(SFc1_cameraudpInstanceStruct *chartInstance);
static void sf_gateway_c1_cameraudp(SFc1_cameraudpInstanceStruct *chartInstance);
static void ext_mode_exec_c1_cameraudp(SFc1_cameraudpInstanceStruct
  *chartInstance);
static void c1_update_jit_animation_c1_cameraudp(SFc1_cameraudpInstanceStruct
  *chartInstance);
static void c1_do_animation_call_c1_cameraudp(SFc1_cameraudpInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_cameraudp(SFc1_cameraudpInstanceStruct
  *chartInstance);
static void set_sim_state_c1_cameraudp(SFc1_cameraudpInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void c1_emlrt_marshallIn(SFc1_cameraudpInstanceStruct *chartInstance,
  const mxArray *c1_nullptr, const char_T *c1_identifier, uint8_T c1_y[691200]);
static void c1_b_emlrt_marshallIn(SFc1_cameraudpInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, uint8_T c1_y
  [691200]);
static void c1_slStringInitializeDynamicBuffers(SFc1_cameraudpInstanceStruct
  *chartInstance);
static void c1_chart_data_browse_helper(SFc1_cameraudpInstanceStruct
  *chartInstance, int32_T c1_ssIdNumber, const mxArray **c1_mxData, uint8_T
  *c1_isValueTooBig);
static void init_dsm_address_info(SFc1_cameraudpInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc1_cameraudpInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_cameraudp(SFc1_cameraudpInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c1_doneDoubleBufferReInit = false;
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c1_cameraudp(SFc1_cameraudpInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c1_cameraudp(SFc1_cameraudpInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c1_cameraudp(SFc1_cameraudpInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c1_cameraudp
  (SFc1_cameraudpInstanceStruct *chartInstance)
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
    4U);
  covrtChartInitFcn(chartInstance->c1_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c1_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c1_decisionTxtStartIdx, &c1_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c1_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U, "c1_cameraudp",
                     0, -1, 80);
}

static void mdl_cleanup_runtime_resources_c1_cameraudp
  (SFc1_cameraudpInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c1_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c1_covrtInstance);
}

static void enable_c1_cameraudp(SFc1_cameraudpInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_cameraudp(SFc1_cameraudpInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c1_cameraudp(SFc1_cameraudpInstanceStruct *chartInstance)
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

static void ext_mode_exec_c1_cameraudp(SFc1_cameraudpInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_update_jit_animation_c1_cameraudp(SFc1_cameraudpInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_do_animation_call_c1_cameraudp(SFc1_cameraudpInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_cameraudp(SFc1_cameraudpInstanceStruct
  *chartInstance)
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

static void set_sim_state_c1_cameraudp(SFc1_cameraudpInstanceStruct
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

const mxArray *sf_c1_cameraudp_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static void c1_emlrt_marshallIn(SFc1_cameraudpInstanceStruct *chartInstance,
  const mxArray *c1_nullptr, const char_T *c1_identifier, uint8_T c1_y[691200])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nullptr), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_nullptr);
}

static void c1_b_emlrt_marshallIn(SFc1_cameraudpInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, uint8_T c1_y
  [691200])
{
  int32_T c1_i;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), chartInstance->c1_b_uv, 1, 3, 0U,
                1, 0U, 2, 720, 960);
  for (c1_i = 0; c1_i < 691200; c1_i++) {
    c1_y[c1_i] = chartInstance->c1_b_uv[c1_i];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_slStringInitializeDynamicBuffers(SFc1_cameraudpInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_chart_data_browse_helper(SFc1_cameraudpInstanceStruct
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

static void init_dsm_address_info(SFc1_cameraudpInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_cameraudpInstanceStruct *chartInstance)
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
void sf_c1_cameraudp_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1352817881U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4126984301U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1721097078U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2412736074U);
}

mxArray *sf_c1_cameraudp_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Rgb2grayBuildable"));
  return(mxcell3p);
}

mxArray *sf_c1_cameraudp_jit_fallback_info(void)
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

mxArray *sf_c1_cameraudp_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_cameraudp(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiDWYGRgYAPSHEDMxAABrFA+IxKGiLPAxRWAuKSyIBUkXlyU7JkCpPMSc8H8xNI"
    "Kz7y0fLD5FgwI89kImM8JFYeAD/aU6RdxAOl3QNLPgkU/J5J+ASg/vSix0jM3MT0VKs4HpQFLKh"
    "AB"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_cameraudp_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sjOxj1ISA0khFP34XdyIpxC";
}

static void sf_opaque_initialize_c1_cameraudp(void *chartInstanceVar)
{
  initialize_params_c1_cameraudp((SFc1_cameraudpInstanceStruct*)
    chartInstanceVar);
  initialize_c1_cameraudp((SFc1_cameraudpInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_cameraudp(void *chartInstanceVar)
{
  enable_c1_cameraudp((SFc1_cameraudpInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_cameraudp(void *chartInstanceVar)
{
  disable_c1_cameraudp((SFc1_cameraudpInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_cameraudp(void *chartInstanceVar)
{
  sf_gateway_c1_cameraudp((SFc1_cameraudpInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_cameraudp(SimStruct* S)
{
  return get_sim_state_c1_cameraudp((SFc1_cameraudpInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_cameraudp(SimStruct* S, const mxArray *st)
{
  set_sim_state_c1_cameraudp((SFc1_cameraudpInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c1_cameraudp(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_cameraudpInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_cameraudp_optimization_info();
    }

    mdl_cleanup_runtime_resources_c1_cameraudp((SFc1_cameraudpInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c1_cameraudp(void *chartInstanceVar)
{
  mdl_start_c1_cameraudp((SFc1_cameraudpInstanceStruct*) chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc1_cameraudpInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c1_cameraudp(void *chartInstanceVar)
{
  mdl_terminate_c1_cameraudp((SFc1_cameraudpInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_cameraudp(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_cameraudp((SFc1_cameraudpInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c1_cameraudp_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [20] = {
    "eNrdWE9v40QUn1TdiqJltUhIuwckOHDggtRVOfSAYLtOApZaGuF0QXtBE/vFns147J0/aYLEp+A",
    "zwCfhG3DZIwc+ACfEkTeOk0ZpSGYcaVuw5LrP9m/ee795/xzSCs8JHg/w7D0i5ACvb+G5R2bHvV",
    "puLZ2z+/vks1ruvU1InFGpQzEsiP8RFwmkICIzHLKJJ1aYvEclzVUDvYLm8A2oghvNCuFnPBNDk",
    "CBiXKAspPbSq1huOBOjrhGx1ay+zVicRVlhePIMF6TJheDTf9NbGt1DjW0mIdZdgERnsjBp1uU0",
    "3cyC1FdBBvFImdybKwU6MqV1VZ0brlnJoTOBOBRKU2RBbfE30lRDoCfeEcJUNEcXeckZFe5cZ1R",
    "FUGJ0aLgsE/x7YTSy56gX9Q2YoLqQjPJOzgMb4Y7YHkc7zzGsuTfPOtdtGJg0ZSK17EqTg0D/MU",
    "4cuBoGxRgkTeFCeOag9a4zqTZ4EZfuORjasGyUgyaf7YpqhK30dsbIkGqotxuLgHKu/LD9ojyDM",
    "fBKf5tq2gA70+8BVool/eI5lTYLPDPJCPbKQI0NCpEw9x0er6Cqgvs1Fk8HOMttSEGCNC9MXyy0",
    "LSaN0kUeYBq1z84c9d3EhkKDHNIYnGufpEwBGlzFlafehCk64BaNLOnKS+cVQDSGEjU0on1VyBF",
    "y7Ftkr7mymeCHhiSFNmioCkYHo/s55cbR5lxhhbPhcamwYvnpRazNn0bgmMYZJLafMA7noOwCyr",
    "k+Yx85RW/HTE/boGLJStdMMgoSbCSWpf60hEsxEsWV6Moij+qJYENcAWDVoFJgW3iGbUlOu2i8m",
    "9USXvVtZDUZz3KqOR3Y2PgSBHYW66vthDTGrOoIHN3QoF2wEfsBW7tQTGkcp6adKgeSah593PKb",
    "R9+t5eNFLoWqL3GnKLZhgZPS6aAa9qDPcqhuRBRniplYH1bvEbnWe7i3We8e/tdqiCM74p4u4fb",
    "X8HN/CfewluMn38dYVCQ1SblO/30Hnl1w5Abumt/59eMlfGuNXrJ03WVflnl6Z0XP/gruoObqo9",
    "9/Gv38295fv5Qv/ogHv/64i/7XnnH8oJbfn89li841vlHc7btfbYmDRytxYGX18mLy8kkYnR6Ns",
    "m7v+NPvkmlYToLZvnjaO7//IZ4aC1tVJ2UcJvU3lpWpmc3+dv2TJXsPtqx/uBRPhPz5xW749566",
    "5M3hCl9WTiWdhjk2ijVxfNfrxW3Vp9u006WOtd4wjrxh3K7++dbn//r7RxvqAll5/+Ed9mNTffL",
    "p03fNr9fEry99UMufL76dg4zxZM30Xj/GAXu47un/JL7/9uRvPjd0LH/1j38vjk8F5VMc12efQ/",
    "XtnrS/Oy0eSaBq/TfRbfSh+fVkS9+/t5LfVr7sdz852aGf/QMSjf2i",
    ""
  };

  static char newstr [1405] = "";
  newstr[0] = '\0';
  for (i = 0; i < 20; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c1_cameraudp(SimStruct *S)
{
  const char* newstr = sf_c1_cameraudp_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1804853284U));
  ssSetChecksum1(S,(4127380389U));
  ssSetChecksum2(S,(3831132326U));
  ssSetChecksum3(S,(2110022243U));
}

static void mdlRTW_c1_cameraudp(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c1_cameraudp(SimStruct *S)
{
  SFc1_cameraudpInstanceStruct *chartInstance;
  chartInstance = (SFc1_cameraudpInstanceStruct *)utMalloc(sizeof
    (SFc1_cameraudpInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_cameraudpInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_cameraudp;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_cameraudp;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c1_cameraudp;
  chartInstance->chartInfo.mdlTerminate = sf_opaque_mdl_terminate_c1_cameraudp;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c1_cameraudp;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_cameraudp;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_cameraudp;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_cameraudp;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_cameraudp;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_cameraudp;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_cameraudp;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_cameraudp;
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

  mdl_setup_runtime_resources_c1_cameraudp(chartInstance);
}

void c1_cameraudp_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c1_cameraudp(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_cameraudp(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_cameraudp(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_cameraudp_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
