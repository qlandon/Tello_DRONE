/* Include files */

#include "cameraudp_sfun.h"
#include "c2_cameraudp.h"
#include <string.h>
#include "mwmathutil.h"
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
static emlrtMCInfo c2_emlrtMCI = { 87, /* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtRSInfo c2_emlrtRSI = { 3,  /* lineNo */
  "MATLAB Function",                   /* fcnName */
  "#cameraudp:42"                      /* pathName */
};

static emlrtRSInfo c2_b_emlrtRSI = { 44,/* lineNo */
  "wiener2",                           /* fcnName */
  "/Applications/MATLAB_R2024a.app/toolbox/images/images/eml/wiener2.m"/* pathName */
};

static emlrtRSInfo c2_c_emlrtRSI = { 47,/* lineNo */
  "wiener2",                           /* fcnName */
  "/Applications/MATLAB_R2024a.app/toolbox/images/images/eml/wiener2.m"/* pathName */
};

static emlrtRSInfo c2_d_emlrtRSI = { 69,/* lineNo */
  "wiener2",                           /* fcnName */
  "/Applications/MATLAB_R2024a.app/toolbox/images/images/eml/wiener2.m"/* pathName */
};

static emlrtRSInfo c2_e_emlrtRSI = { 55,/* lineNo */
  "filter2",                           /* fcnName */
  "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/datafun/filter2.m"/* pathName */
};

static emlrtRSInfo c2_f_emlrtRSI = { 42,/* lineNo */
  "conv2",                             /* fcnName */
  "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/datafun/conv2.m"/* pathName */
};

static emlrtRSInfo c2_g_emlrtRSI = { 265,/* lineNo */
  "conv2",                             /* fcnName */
  "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/datafun/conv2.m"/* pathName */
};

static emlrtRSInfo c2_h_emlrtRSI = { 229,/* lineNo */
  "conv2",                             /* fcnName */
  "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/datafun/conv2.m"/* pathName */
};

static emlrtRSInfo c2_i_emlrtRSI = { 53,/* lineNo */
  "xaxpy",                             /* fcnName */
  "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/+blas/xaxpy.m"/* pathName */
};

static emlrtRSInfo c2_j_emlrtRSI = { 65,/* lineNo */
  "xaxpy",                             /* fcnName */
  "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/+blas/xaxpy.m"/* pathName */
};

static emlrtRSInfo c2_k_emlrtRSI = { 14,/* lineNo */
  "changeClass",                       /* fcnName */
  "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+internal/changeClass.m"/* pathName */
};

static emlrtRSInfo c2_l_emlrtRSI = { 41,/* lineNo */
  "im2uint8",                          /* fcnName */
  "/Applications/MATLAB_R2024a.app/toolbox/images/images/eml/im2uint8.m"/* pathName */
};

static emlrtRSInfo c2_m_emlrtRSI = { 197,/* lineNo */
  "im2uint8",                          /* fcnName */
  "/Applications/MATLAB_R2024a.app/toolbox/images/images/eml/im2uint8.m"/* pathName */
};

static emlrtRSInfo c2_n_emlrtRSI = { 19,/* lineNo */
  "grayto8",                           /* fcnName */
  "/Applications/MATLAB_R2024a.app/toolbox/images/images/eml/private/grayto8.m"/* pathName */
};

static emlrtRTEInfo c2_emlrtRTEI = { 44,/* lineNo */
  34,                                  /* colNo */
  "vAllOrAny",                         /* fName */
  "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/vAllOrAny.m"/* pName */
};

/* Function Declarations */
static void initialize_c2_cameraudp(SFc2_cameraudpInstanceStruct *chartInstance);
static void initialize_params_c2_cameraudp(SFc2_cameraudpInstanceStruct
  *chartInstance);
static void mdl_start_c2_cameraudp(SFc2_cameraudpInstanceStruct *chartInstance);
static void mdl_terminate_c2_cameraudp(SFc2_cameraudpInstanceStruct
  *chartInstance);
static void mdl_setup_runtime_resources_c2_cameraudp
  (SFc2_cameraudpInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c2_cameraudp
  (SFc2_cameraudpInstanceStruct *chartInstance);
static void enable_c2_cameraudp(SFc2_cameraudpInstanceStruct *chartInstance);
static void disable_c2_cameraudp(SFc2_cameraudpInstanceStruct *chartInstance);
static void sf_gateway_c2_cameraudp(SFc2_cameraudpInstanceStruct *chartInstance);
static void ext_mode_exec_c2_cameraudp(SFc2_cameraudpInstanceStruct
  *chartInstance);
static void c2_update_jit_animation_c2_cameraudp(SFc2_cameraudpInstanceStruct
  *chartInstance);
static void c2_do_animation_call_c2_cameraudp(SFc2_cameraudpInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_cameraudp(SFc2_cameraudpInstanceStruct
  *chartInstance);
static void set_sim_state_c2_cameraudp(SFc2_cameraudpInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void c2_filter2(SFc2_cameraudpInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, real_T c2_b_x[691200], real_T c2_b_y[691200]);
static void c2_conv2(SFc2_cameraudpInstanceStruct *chartInstance, real_T
                     c2_b_varargin_1[691200], real_T c2_c[691200]);
static void c2_xaxpy(SFc2_cameraudpInstanceStruct *chartInstance, int32_T c2_n,
                     real_T c2_a, real_T c2_b_x[691200], int32_T c2_ix0, real_T
                     c2_b_y[691200], int32_T c2_iy0, real_T c2_c_y[691200]);
static real_T c2_sumColumnB4(SFc2_cameraudpInstanceStruct *chartInstance, real_T
  c2_b_x[691200]);
static real_T c2_b_sumColumnB4(SFc2_cameraudpInstanceStruct *chartInstance,
  real_T c2_b_x[691200], int32_T c2_vstart);
static real_T c2_sumColumnB(SFc2_cameraudpInstanceStruct *chartInstance, real_T
  c2_b_x[691200]);
static void c2_emlrt_marshallIn(SFc2_cameraudpInstanceStruct *chartInstance,
  const mxArray *c2_nullptr, const char_T *c2_identifier, uint8_T c2_b_y[691200]);
static void c2_b_emlrt_marshallIn(SFc2_cameraudpInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, uint8_T c2_b_y
  [691200]);
static void c2_slStringInitializeDynamicBuffers(SFc2_cameraudpInstanceStruct
  *chartInstance);
static void c2_chart_data_browse_helper(SFc2_cameraudpInstanceStruct
  *chartInstance, int32_T c2_ssIdNumber, const mxArray **c2_mxData, uint8_T
  *c2_isValueTooBig);
static void c2_b_xaxpy(SFc2_cameraudpInstanceStruct *chartInstance, int32_T c2_n,
  real_T c2_a, real_T c2_b_x[691200], int32_T c2_ix0, real_T c2_b_y[691200],
  int32_T c2_iy0);
static void c2_array_real_T_2D_SetSize(SFc2_cameraudpInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_coder_array_real_T_2D
  *c2_coderArray, const emlrtRTEInfo *c2_srcLocation, int32_T c2_size0, int32_T
  c2_size1);
static void c2_array_real_T_2D_Constructor(SFc2_cameraudpInstanceStruct
  *chartInstance, c2_coder_array_real_T_2D *c2_coderArray);
static void c2_array_real_T_2D_Destructor(SFc2_cameraudpInstanceStruct
  *chartInstance, c2_coder_array_real_T_2D *c2_coderArray);
static void init_dsm_address_info(SFc2_cameraudpInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc2_cameraudpInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_cameraudp(SFc2_cameraudpInstanceStruct *chartInstance)
{
  emlrtStack c2_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c2_st.tls = chartInstance->c2_fEmlrtCtx;
  emlrtLicenseCheckR2022a(&c2_st, "EMLRT:runTime:MexFunctionNeedsLicense",
    "image_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c2_doneDoubleBufferReInit = false;
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c2_cameraudp(SFc2_cameraudpInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c2_cameraudp(SFc2_cameraudpInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c2_cameraudp(SFc2_cameraudpInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c2_cameraudp
  (SFc2_cameraudpInstanceStruct *chartInstance)
{
  static const uint32_T c2_decisionTxtEndIdx = 0U;
  static const uint32_T c2_decisionTxtStartIdx = 0U;
  setDataBrowseFcn(chartInstance->S, (void *)&c2_chart_data_browse_helper);
  chartInstance->c2_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c2_RuntimeVar,
    &chartInstance->c2_IsDebuggerActive,
    &chartInstance->c2_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c2_mlFcnLineNumber, &chartInstance->c2_IsHeatMapPresent, 0);
  sfSetAnimationVectors(chartInstance->S, &chartInstance->c2_JITStateAnimation[0],
                        &chartInstance->c2_JITTransitionAnimation[0]);
  covrtCreateStateflowInstanceData(chartInstance->c2_covrtInstance, 1U, 0U, 1U,
    6U);
  covrtChartInitFcn(chartInstance->c2_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c2_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c2_decisionTxtStartIdx, &c2_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c2_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c2_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U, "c2_cameraudp",
                     0, -1, 137);
}

static void mdl_cleanup_runtime_resources_c2_cameraudp
  (SFc2_cameraudpInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c2_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c2_covrtInstance);
}

static void enable_c2_cameraudp(SFc2_cameraudpInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_cameraudp(SFc2_cameraudpInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c2_cameraudp(SFc2_cameraudpInstanceStruct *chartInstance)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c2_a;
  real_T c2_b;
  real_T c2_b_a;
  real_T c2_b_ex;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_c_x;
  real_T c2_c_y;
  real_T c2_d_x;
  real_T c2_d_y;
  real_T c2_e_x;
  real_T c2_e_y;
  real_T c2_ex;
  real_T c2_f_y;
  real_T c2_g_y;
  real_T c2_h_y;
  real_T c2_i_y;
  real_T c2_j_y;
  real_T c2_k_y;
  real_T c2_noise;
  real_T c2_s;
  real_T c2_varargin_2;
  int32_T c2_b_k;
  int32_T c2_c_k;
  int32_T c2_d_k;
  int32_T c2_e_k;
  int32_T c2_f_k;
  int32_T c2_g_k;
  int32_T c2_h_k;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_ib;
  int32_T c2_k;
  c2_st.tls = chartInstance->c2_fEmlrtCtx;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  for (c2_i = 0; c2_i < 691200; c2_i++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 0U, (real_T)
                      (*chartInstance->c2_grayImage)[c2_i]);
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_JITTransitionAnimation[0] = 0U;
  chartInstance->c2_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 4U, 0, 0);
  c2_b_st.site = &c2_emlrtRSI;
  for (c2_i1 = 0; c2_i1 < 691200; c2_i1++) {
    chartInstance->c2_gOne[c2_i1] = (real_T)(*chartInstance->c2_grayImage)[c2_i1]
      / 255.0;
  }

  c2_c_st.site = &c2_b_emlrtRSI;
  c2_filter2(chartInstance, &c2_c_st, chartInstance->c2_gOne,
             chartInstance->c2_localMean);
  for (c2_i2 = 0; c2_i2 < 691200; c2_i2++) {
    chartInstance->c2_localMean[c2_i2] /= 9.0;
  }

  for (c2_k = 0; c2_k < 691200; c2_k++) {
    c2_c_k = c2_k;
    c2_a = chartInstance->c2_gOne[c2_c_k];
    c2_b_y = c2_a * c2_a;
    chartInstance->c2_y[c2_c_k] = c2_b_y;
  }

  for (c2_b_k = 0; c2_b_k < 691200; c2_b_k++) {
    c2_d_k = c2_b_k;
    c2_b_a = chartInstance->c2_localMean[c2_d_k];
    c2_c_y = c2_b_a * c2_b_a;
    chartInstance->c2_fOne[c2_d_k] = c2_c_y;
  }

  c2_c_st.site = &c2_c_emlrtRSI;
  c2_filter2(chartInstance, &c2_c_st, chartInstance->c2_y,
             chartInstance->c2_localVar);
  for (c2_i3 = 0; c2_i3 < 691200; c2_i3++) {
    chartInstance->c2_localVar[c2_i3] = chartInstance->c2_localVar[c2_i3] / 9.0
      - chartInstance->c2_fOne[c2_i3];
  }

  for (c2_i4 = 0; c2_i4 < 691200; c2_i4++) {
    chartInstance->c2_y[c2_i4] = chartInstance->c2_localVar[c2_i4];
  }

  c2_s = c2_sumColumnB4(chartInstance, chartInstance->c2_y);
  for (c2_ib = 0; c2_ib < 167; c2_ib++) {
    c2_s += c2_b_sumColumnB4(chartInstance, chartInstance->c2_y, 1 + ((c2_ib + 1)
      << 12));
  }

  c2_s += c2_sumColumnB(chartInstance, chartInstance->c2_y);
  c2_d_y = c2_s;
  c2_noise = c2_d_y / 691200.0;
  for (c2_i5 = 0; c2_i5 < 691200; c2_i5++) {
    chartInstance->c2_fOne[c2_i5] = chartInstance->c2_gOne[c2_i5] -
      chartInstance->c2_localMean[c2_i5];
  }

  for (c2_i6 = 0; c2_i6 < 691200; c2_i6++) {
    chartInstance->c2_y[c2_i6] = chartInstance->c2_localVar[c2_i6] - c2_noise;
  }

  for (c2_e_k = 0; c2_e_k < 691200; c2_e_k++) {
    c2_f_k = c2_e_k;
    c2_b_x = chartInstance->c2_y[c2_f_k];
    c2_c_x = c2_b_x;
    c2_ex = muDoubleScalarMax(c2_c_x, 0.0);
    chartInstance->c2_gOne[c2_f_k] = c2_ex;
  }

  c2_varargin_2 = c2_noise;
  c2_e_y = c2_varargin_2;
  c2_f_y = c2_e_y;
  c2_g_y = c2_f_y;
  c2_b = c2_g_y;
  c2_h_y = c2_b;
  for (c2_i7 = 0; c2_i7 < 691200; c2_i7++) {
    chartInstance->c2_y[c2_i7] = chartInstance->c2_localVar[c2_i7];
  }

  c2_i_y = c2_h_y;
  for (c2_g_k = 0; c2_g_k < 691200; c2_g_k++) {
    c2_h_k = c2_g_k;
    c2_d_x = chartInstance->c2_y[c2_h_k];
    c2_j_y = c2_i_y;
    c2_e_x = c2_d_x;
    c2_k_y = c2_j_y;
    c2_b_ex = muDoubleScalarMax(c2_e_x, c2_k_y);
    chartInstance->c2_localVar[c2_h_k] = c2_b_ex;
  }

  for (c2_i8 = 0; c2_i8 < 691200; c2_i8++) {
    chartInstance->c2_fOne[c2_i8] = chartInstance->c2_fOne[c2_i8] /
      chartInstance->c2_localVar[c2_i8] * chartInstance->c2_gOne[c2_i8] +
      chartInstance->c2_localMean[c2_i8];
  }

  grayto8_real64(&chartInstance->c2_fOne[0], &(*chartInstance->c2_filteredImage)
                 [0], 691200.0);
  for (c2_i9 = 0; c2_i9 < 691200; c2_i9++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 1U, (real_T)
                      (*chartInstance->c2_filteredImage)[c2_i9]);
  }
}

static void ext_mode_exec_c2_cameraudp(SFc2_cameraudpInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_update_jit_animation_c2_cameraudp(SFc2_cameraudpInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_do_animation_call_c2_cameraudp(SFc2_cameraudpInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_cameraudp(SFc2_cameraudpInstanceStruct
  *chartInstance)
{
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_st = NULL;
  c2_st = NULL;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createcellmatrix(1, 1), false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", *chartInstance->c2_filteredImage, 3,
    0U, 1, 0U, 2, 720, 960), false);
  sf_mex_setcell(c2_b_y, 0, c2_c_y);
  sf_mex_assign(&c2_st, c2_b_y, false);
  return c2_st;
}

static void set_sim_state_c2_cameraudp(SFc2_cameraudpInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  int32_T c2_i;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
                      "filteredImage", chartInstance->c2_uv);
  for (c2_i = 0; c2_i < 691200; c2_i++) {
    (*chartInstance->c2_filteredImage)[c2_i] = chartInstance->c2_uv[c2_i];
  }

  sf_mex_destroy(&c2_u);
  sf_mex_destroy(&c2_st);
}

static void c2_filter2(SFc2_cameraudpInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, real_T c2_b_x[691200], real_T c2_b_y[691200])
{
  c2_coder_array_real_T_2D c2_c_x;
  real_T c2_c_y;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  int32_T c2_b_k;
  int32_T c2_c_k;
  int32_T c2_d_k;
  int32_T c2_i;
  int32_T c2_k;
  boolean_T c2_exitg1;
  boolean_T c2_p;
  c2_conv2(chartInstance, c2_b_x, c2_b_y);
  c2_array_real_T_2D_Constructor(chartInstance, &c2_c_x);
  c2_array_real_T_2D_SetSize(chartInstance, c2_sp, &c2_c_x, &c2_emlrtRTEI, 720,
    960);
  for (c2_i = 0; c2_i < 691200; c2_i++) {
    c2_c_x.vector.data[c2_i] = c2_b_x[c2_i];
  }

  c2_p = true;
  c2_k = 1;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_k - 1 < 691200)) {
    c2_b_k = c2_k - 1;
    if (!c2_p) {
      c2_exitg1 = true;
    } else {
      c2_d_x = c2_c_x.vector.data[c2_b_k];
      c2_e_x = c2_d_x;
      c2_f_x = c2_e_x;
      c2_c_y = c2_f_x;
      c2_c_y = muDoubleScalarFloor(c2_c_y);
      c2_p = (c2_c_y == c2_d_x);
      c2_k++;
    }
  }

  c2_array_real_T_2D_Destructor(chartInstance, &c2_c_x);
  if (c2_p) {
    for (c2_c_k = 0; c2_c_k < 691200; c2_c_k++) {
      c2_d_k = c2_c_k;
      c2_g_x = c2_b_y[c2_d_k];
      c2_h_x = c2_g_x;
      c2_h_x = muDoubleScalarRound(c2_h_x);
      c2_b_y[c2_d_k] = c2_h_x;
    }
  }
}

static void c2_conv2(SFc2_cameraudpInstanceStruct *chartInstance, real_T
                     c2_b_varargin_1[691200], real_T c2_c[691200])
{
  static real_T c2_hcol[3] = { 0.99999999999999989, 1.0, 1.0 };

  static real_T c2_hrow[3] = { 0.99999999999999989, 1.0, 0.99999999999999989 };

  real_T c2_wc;
  real_T c2_wr;
  int32_T c2_N;
  int32_T c2_b_j;
  int32_T c2_b_k;
  int32_T c2_c_k;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_ihi;
  int32_T c2_ilo;
  int32_T c2_j;
  int32_T c2_jhi;
  int32_T c2_jlo;
  int32_T c2_k;
  int32_T c2_ko;
  int32_T c2_kom1;
  for (c2_i = 0; c2_i < 691200; c2_i++) {
    c2_c[c2_i] = 0.0;
  }

  for (c2_i1 = 0; c2_i1 < 691200; c2_i1++) {
    chartInstance->c2_work[c2_i1] = 0.0;
  }

  for (c2_k = 0; c2_k < 3; c2_k++) {
    c2_c_k = c2_k;
    c2_ko = c2_c_k;
    c2_kom1 = c2_ko;
    if (c2_ko > 0) {
      c2_ilo = c2_ko;
    } else {
      c2_ilo = 1;
    }

    c2_ihi = c2_kom1;
    if (c2_ihi + 719 > 720) {
      c2_ihi = 1;
    }

    c2_wc = c2_hcol[c2_c_k];
    c2_N = c2_ihi - c2_ilo;
    for (c2_j = 0; c2_j < 960; c2_j++) {
      c2_b_j = c2_j;
      for (c2_i3 = 0; c2_i3 < 691200; c2_i3++) {
        chartInstance->c2_varargin_1[c2_i3] = c2_b_varargin_1[c2_i3];
      }

      c2_b_xaxpy(chartInstance, c2_N + 720, c2_wc, chartInstance->c2_varargin_1,
                 ((c2_b_j * 720 + c2_ilo) - c2_kom1) + 1, chartInstance->c2_work,
                 c2_b_j * 720 + c2_ilo);
    }
  }

  for (c2_b_k = 0; c2_b_k < 3; c2_b_k++) {
    c2_c_k = c2_b_k;
    c2_ko = c2_c_k;
    c2_kom1 = c2_ko;
    if (c2_ko > 0) {
      c2_jlo = c2_ko - 1;
    } else {
      c2_jlo = 0;
    }

    c2_jhi = 959 + c2_kom1;
    if (c2_jhi > 960) {
      c2_jhi = 960;
    }

    c2_wr = c2_hrow[c2_c_k];
    c2_N = 720 * (c2_jhi - c2_jlo);
    for (c2_i2 = 0; c2_i2 < 691200; c2_i2++) {
      chartInstance->c2_b_work[c2_i2] = chartInstance->c2_work[c2_i2];
    }

    c2_b_xaxpy(chartInstance, c2_N, c2_wr, chartInstance->c2_b_work, ((c2_jlo -
      c2_kom1) + 1) * 720 + 1, c2_c, c2_jlo * 720 + 1);
  }
}

static void c2_xaxpy(SFc2_cameraudpInstanceStruct *chartInstance, int32_T c2_n,
                     real_T c2_a, real_T c2_b_x[691200], int32_T c2_ix0, real_T
                     c2_b_y[691200], int32_T c2_iy0, real_T c2_c_y[691200])
{
  int32_T c2_i;
  int32_T c2_i1;
  for (c2_i = 0; c2_i < 691200; c2_i++) {
    c2_c_y[c2_i] = c2_b_y[c2_i];
  }

  for (c2_i1 = 0; c2_i1 < 691200; c2_i1++) {
    chartInstance->c2_x[c2_i1] = c2_b_x[c2_i1];
  }

  c2_b_xaxpy(chartInstance, c2_n, c2_a, chartInstance->c2_x, c2_ix0, c2_c_y,
             c2_iy0);
}

static real_T c2_sumColumnB4(SFc2_cameraudpInstanceStruct *chartInstance, real_T
  c2_b_x[691200])
{
  real_T c2_psum1;
  real_T c2_psum2;
  real_T c2_psum3;
  real_T c2_psum4;
  int32_T c2_b_k;
  int32_T c2_k;
  (void)chartInstance;
  c2_psum1 = c2_b_x[0];
  c2_psum2 = c2_b_x[1024];
  c2_psum3 = c2_b_x[2048];
  c2_psum4 = c2_b_x[3072];
  for (c2_k = 0; c2_k < 1023; c2_k++) {
    c2_b_k = c2_k;
    c2_psum1 += c2_b_x[c2_b_k + 1];
    c2_psum2 += c2_b_x[c2_b_k + 1025];
    c2_psum3 += c2_b_x[c2_b_k + 2049];
    c2_psum4 += c2_b_x[c2_b_k + 3073];
  }

  return (c2_psum1 + c2_psum2) + (c2_psum3 + c2_psum4);
}

static real_T c2_b_sumColumnB4(SFc2_cameraudpInstanceStruct *chartInstance,
  real_T c2_b_x[691200], int32_T c2_vstart)
{
  real_T c2_psum1;
  real_T c2_psum2;
  real_T c2_psum3;
  real_T c2_psum4;
  int32_T c2_b_k;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_k;
  (void)chartInstance;
  c2_i2 = c2_vstart + 1023;
  c2_i3 = c2_vstart + 2047;
  c2_i4 = c2_vstart + 3071;
  c2_psum1 = c2_b_x[c2_vstart - 1];
  c2_psum2 = c2_b_x[c2_i2];
  c2_psum3 = c2_b_x[c2_i3];
  c2_psum4 = c2_b_x[c2_i4];
  for (c2_k = 0; c2_k < 1023; c2_k++) {
    c2_b_k = c2_k + 1;
    c2_psum1 += c2_b_x[(c2_vstart + c2_b_k) - 1];
    c2_psum2 += c2_b_x[c2_i2 + c2_b_k];
    c2_psum3 += c2_b_x[c2_i3 + c2_b_k];
    c2_psum4 += c2_b_x[c2_i4 + c2_b_k];
  }

  return (c2_psum1 + c2_psum2) + (c2_psum3 + c2_psum4);
}

static real_T c2_sumColumnB(SFc2_cameraudpInstanceStruct *chartInstance, real_T
  c2_b_x[691200])
{
  real_T c2_b_y;
  real_T c2_c_y;
  int32_T c2_b_k;
  int32_T c2_c_k;
  int32_T c2_d_k;
  int32_T c2_e_k;
  int32_T c2_k;
  int32_T c2_vstart;
  (void)chartInstance;
  c2_b_y = c2_b_x[688128];
  for (c2_k = 0; c2_k < 1023; c2_k++) {
    c2_c_k = c2_k;
    c2_b_y += c2_b_x[c2_c_k + 688129];
  }

  for (c2_b_k = 0; c2_b_k < 2; c2_b_k++) {
    c2_vstart = 688128 + ((c2_b_k + 1) << 10);
    c2_c_y = c2_b_x[c2_vstart];
    for (c2_d_k = 0; c2_d_k < 1023; c2_d_k++) {
      c2_e_k = c2_d_k;
      c2_c_y += c2_b_x[(c2_vstart + c2_e_k) + 1];
    }

    c2_b_y += c2_c_y;
  }

  return c2_b_y;
}

const mxArray *sf_c2_cameraudp_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static void c2_emlrt_marshallIn(SFc2_cameraudpInstanceStruct *chartInstance,
  const mxArray *c2_nullptr, const char_T *c2_identifier, uint8_T c2_b_y[691200])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char_T *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nullptr), &c2_thisId,
                        c2_b_y);
  sf_mex_destroy(&c2_nullptr);
}

static void c2_b_emlrt_marshallIn(SFc2_cameraudpInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, uint8_T c2_b_y
  [691200])
{
  int32_T c2_i;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), chartInstance->c2_b_uv, 1, 3, 0U,
                1, 0U, 2, 720, 960);
  for (c2_i = 0; c2_i < 691200; c2_i++) {
    c2_b_y[c2_i] = chartInstance->c2_b_uv[c2_i];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_slStringInitializeDynamicBuffers(SFc2_cameraudpInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_chart_data_browse_helper(SFc2_cameraudpInstanceStruct
  *chartInstance, int32_T c2_ssIdNumber, const mxArray **c2_mxData, uint8_T
  *c2_isValueTooBig)
{
  (void)chartInstance;
  *c2_mxData = NULL;
  *c2_isValueTooBig = 0U;
  switch (c2_ssIdNumber) {
   case 4U:
    *c2_isValueTooBig = 1U;
    break;

   case 5U:
    *c2_isValueTooBig = 1U;
    break;
  }
}

static void c2_b_xaxpy(SFc2_cameraudpInstanceStruct *chartInstance, int32_T c2_n,
  real_T c2_a, real_T c2_b_x[691200], int32_T c2_ix0, real_T c2_b_y[691200],
  int32_T c2_iy0)
{
  ptrdiff_t c2_incx_t;
  ptrdiff_t c2_incy_t;
  ptrdiff_t c2_n_t;
  real_T c2_b_a;
  real_T c2_c_a;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_b_n;
  int32_T c2_c_ix0;
  int32_T c2_c_iy0;
  int32_T c2_c_n;
  int32_T c2_var;
  (void)chartInstance;
  c2_b_n = c2_n;
  c2_b_a = c2_a;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  c2_c_n = c2_b_n;
  c2_c_a = c2_b_a;
  c2_c_ix0 = c2_b_ix0 - 1;
  c2_c_iy0 = c2_b_iy0 - 1;
  c2_var = c2_c_n;
  c2_n_t = (ptrdiff_t)c2_var;
  c2_incx_t = (ptrdiff_t)1;
  c2_incy_t = (ptrdiff_t)1;
  daxpy(&c2_n_t, &c2_c_a, &c2_b_x[c2_c_ix0], &c2_incx_t, &c2_b_y[c2_c_iy0],
        &c2_incy_t);
}

static void c2_array_real_T_2D_SetSize(SFc2_cameraudpInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_coder_array_real_T_2D
  *c2_coderArray, const emlrtRTEInfo *c2_srcLocation, int32_T c2_size0, int32_T
  c2_size1)
{
  real_T *c2_newData;
  int32_T c2_newCapacity;
  int32_T c2_newNumel;
  (void)chartInstance;
  c2_coderArray->size[0] = c2_size0;
  c2_coderArray->size[1] = c2_size1;
  c2_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c2_coderArray->size[0],
                       c2_srcLocation, (void *)c2_sp), (size_t)(uint32_T)
    c2_coderArray->size[1], c2_srcLocation, (void *)c2_sp);
  if (c2_newNumel > c2_coderArray->vector.allocated) {
    c2_newCapacity = c2_coderArray->vector.allocated;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = (real_T *)emlrtMallocMex(sizeof(real_T) * (uint32_T)
      c2_newCapacity);
    if ((void *)c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if ((void *)c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if (c2_coderArray->vector.data != NULL) {
      memcpy(c2_newData, c2_coderArray->vector.data, sizeof(real_T) * (uint32_T)
             c2_coderArray->vector.numel);
      if (c2_coderArray->vector.owner) {
        emlrtFreeMex(c2_coderArray->vector.data);
      }
    }

    c2_coderArray->vector.data = c2_newData;
    c2_coderArray->vector.allocated = c2_newCapacity;
    c2_coderArray->vector.owner = true;
  }

  c2_coderArray->vector.numel = c2_newNumel;
}

static void c2_array_real_T_2D_Constructor(SFc2_cameraudpInstanceStruct
  *chartInstance, c2_coder_array_real_T_2D *c2_coderArray)
{
  (void)chartInstance;
  c2_coderArray->vector.data = (real_T *)NULL;
  c2_coderArray->vector.numel = 0;
  c2_coderArray->vector.allocated = 0;
  c2_coderArray->vector.owner = true;
  c2_coderArray->size[0] = 0;
  c2_coderArray->size[1] = 0;
}

static void c2_array_real_T_2D_Destructor(SFc2_cameraudpInstanceStruct
  *chartInstance, c2_coder_array_real_T_2D *c2_coderArray)
{
  (void)chartInstance;
  if (c2_coderArray->vector.owner && (c2_coderArray->vector.data != (real_T *)
       NULL)) {
    emlrtFreeMex(c2_coderArray->vector.data);
  }
}

static void init_dsm_address_info(SFc2_cameraudpInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_cameraudpInstanceStruct *chartInstance)
{
  chartInstance->c2_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c2_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c2_grayImage = (uint8_T (*)[691200])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c2_filteredImage = (uint8_T (*)[691200])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c2_cameraudp_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(850920300U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3276628449U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3166018037U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(118586098U);
}

mxArray *sf_c2_cameraudp_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,2);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.blas.BLASApi"));
  mxSetCell(mxcell3p, 1, mxCreateString(
             "images.internal.coder.buildable.Grayto8Buildable"));
  return(mxcell3p);
}

mxArray *sf_c2_cameraudp_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("grayto8_real64");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c2_cameraudp_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c2_cameraudp(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiDWYGRgYAPSHEDMxAABrFA+IxKGiLPAxRWAuKSyIBUkXlyU7JkCpPMSc8H8xNI"
    "Kz7y0fLD5FgwI89kImM8JFYeAD/aU6RdxAOl3QNLPgkU/L5J+ASg/LTOnJLUoNcUzNzE9FRpOIA"
    "AAYngRpQ=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_cameraudp_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sLIl9f6kO3HS7YzjVVzCwjC";
}

static void sf_opaque_initialize_c2_cameraudp(void *chartInstanceVar)
{
  initialize_params_c2_cameraudp((SFc2_cameraudpInstanceStruct*)
    chartInstanceVar);
  initialize_c2_cameraudp((SFc2_cameraudpInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_cameraudp(void *chartInstanceVar)
{
  enable_c2_cameraudp((SFc2_cameraudpInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_cameraudp(void *chartInstanceVar)
{
  disable_c2_cameraudp((SFc2_cameraudpInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_cameraudp(void *chartInstanceVar)
{
  sf_gateway_c2_cameraudp((SFc2_cameraudpInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_cameraudp(SimStruct* S)
{
  return get_sim_state_c2_cameraudp((SFc2_cameraudpInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_cameraudp(SimStruct* S, const mxArray *st)
{
  set_sim_state_c2_cameraudp((SFc2_cameraudpInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c2_cameraudp(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_cameraudpInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_cameraudp_optimization_info();
    }

    mdl_cleanup_runtime_resources_c2_cameraudp((SFc2_cameraudpInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c2_cameraudp(void *chartInstanceVar)
{
  mdl_start_c2_cameraudp((SFc2_cameraudpInstanceStruct*) chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc2_cameraudpInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c2_cameraudp(void *chartInstanceVar)
{
  mdl_terminate_c2_cameraudp((SFc2_cameraudpInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_cameraudp(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_cameraudp((SFc2_cameraudpInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c2_cameraudp_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [20] = {
    "eNrdWF9v21QUv6m6iqFtGhLSEEKwR15AgwpWJDTWOQmz1NIIp0Xwgm7sY/su19fe/ZM25dvsZZ+",
    "Ab7APMd4QnwDeeORcx0mjNCS+jrQWLLnusf2755zfPf8c0vIPCR538OzdI2QHr2/huUUmx41Kbs",
    "2dk/vb5OtK7r1NSJhSqX0R58T9CPMIEhCBiWN25ogVJutRSTPVQK+gGXwPKudGs1y4Gc9EDBJEi",
    "AsUudROehXLDGdi2DUitJrVDykL0yDNDY+e4II0OhJ8/G96C6N7qLHNJIS6CxDpVOYmSbucJqtZ",
    "kPrUSyEcKpM5c6VAB6awrqpDwzUrOHTOIPSF0hRZUGv8DTTV4Okz5whhKpii86zgjIr6XKdUBVB",
    "gdGg4LiL8e2Q0sldTL+obMEF1LhnlnYx7NsJrYnsc7TzEsObOPOtMt2FgkoSJxLIrTQYC/cc4qc",
    "FV7OUjkDSBI+GYg9a7zlm5wbO4rJ+Dvg3LRjlossmuqEbYUm9nhAyphnq7ofAo58oN28+LAxgBL",
    "/W3qaYNsBP9DmClWNTPT6i0WeCYSUaw5wYqrJeLiNXf4dECqiy432HxrAFnmQ0piJDmmemzhdbF",
    "pFE6zzxMo/bBQU19l7G+0CBjGkLt2icpU4AGl3HlqDdiig64RSNLuvSy9gogGkOJio1on+ZyiBy",
    "7FtkLrmwmuKEhSqANGsqC0cHoPqHc1LQ5U1jhbHgcK6xYbnoRa/OnETikYQqR7SeMwyEou4CqXZ",
    "+xj+yjtyOmx21QoWRF3UwyCiJsJJal/riAYzEU+anoyjwLqolgRVwBYNWgUmBbeIJtSY67aHw9q",
    "yU879vIajKeZVRzOrCx8S0I7CzWV9sJaYhZ1RE4uqFBm2ADdo6tXSimNI5T406ZA1E5j77XcptH",
    "36nk3Vku+aovcacotmGBk9L+oBz2oM8yKG8EFGeKiVgdVu8DcqH35tZqvVv4X6shjmyIezyH217",
    "Cz6053N1KDj//OcSiIqmJimX6b9XguQ6OXMJd8Du9fjyHby3RS+aum+zLPE+3F/RsL+B2Kq5e/f",
    "rbyxfJH4/e/+uzD3/5/dMvNtH/2jGO71TyB9O5bNa5RpeKu3336Zo4uLcQB1ZWBz7/Kv5yeLT7N",
    "Hj44/mzk5Nz7/SZN9kXR3un9+/jqbGwlXVShn5UfWNZmZrJ7G/X35uzd2fN+jfn4omQP7/ZDP/u",
    "4zp5c3uBLyvHjGPRgsjPsFksxPF1rxdXVZ+u0s46daz1hnHkDeM29c+1Pv/X33+woi6QhffvXmM",
    "/yIr65NKnr5tfr4lbX/qokh/Nvp29lPFoyfRePcYBO1729H8S33878jedGzqWv+rHv5929wXlYx",
    "zXJ59D1e2etL87zR5JoGr5N9FV9KHpdW9N37+xkN9WPu53P9nboJ/9AzP2/sI=",
    ""
  };

  static char newstr [1413] = "";
  newstr[0] = '\0';
  for (i = 0; i < 20; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c2_cameraudp(SimStruct *S)
{
  const char* newstr = sf_c2_cameraudp_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(2816062916U));
  ssSetChecksum1(S,(1055025058U));
  ssSetChecksum2(S,(506589466U));
  ssSetChecksum3(S,(892264571U));
}

static void mdlRTW_c2_cameraudp(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c2_cameraudp(SimStruct *S)
{
  SFc2_cameraudpInstanceStruct *chartInstance;
  chartInstance = (SFc2_cameraudpInstanceStruct *)utMalloc(sizeof
    (SFc2_cameraudpInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_cameraudpInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_cameraudp;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_cameraudp;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c2_cameraudp;
  chartInstance->chartInfo.mdlTerminate = sf_opaque_mdl_terminate_c2_cameraudp;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c2_cameraudp;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_cameraudp;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_cameraudp;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_cameraudp;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_cameraudp;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_cameraudp;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_cameraudp;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_cameraudp;
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

  mdl_setup_runtime_resources_c2_cameraudp(chartInstance);
}

void c2_cameraudp_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c2_cameraudp(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_cameraudp(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_cameraudp(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_cameraudp_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
