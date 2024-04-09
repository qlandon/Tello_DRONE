#ifndef __c1_cameraudp_h__
#define __c1_cameraudp_h__

/* Forward Declarations */
#ifndef c1_typedef_c1_cell_0
#define c1_typedef_c1_cell_0

typedef struct c1_tag_lfyg79q6Kpk0jaJgYJuk8C c1_cell_0;

#endif                                 /* c1_typedef_c1_cell_0 */

#ifndef c1_typedef_c1_cell_wrap_1
#define c1_typedef_c1_cell_wrap_1

typedef struct c1_tag_uwJsGEKtvfiUxcdf0z0AYH c1_cell_wrap_1;

#endif                                 /* c1_typedef_c1_cell_wrap_1 */

#ifndef c1_typedef_c1_s_WSTEAPgNJmllMDXoFTifcF
#define c1_typedef_c1_s_WSTEAPgNJmllMDXoFTifcF

typedef struct c1_tag_WSTEAPgNJmllMDXoFTifcF c1_s_WSTEAPgNJmllMDXoFTifcF;

#endif                                 /* c1_typedef_c1_s_WSTEAPgNJmllMDXoFTifcF */

#ifndef c1_typedef_c1_s_MY3jsqmREaTzOC09vCGedD
#define c1_typedef_c1_s_MY3jsqmREaTzOC09vCGedD

typedef struct c1_tag_MY3jsqmREaTzOC09vCGedD c1_s_MY3jsqmREaTzOC09vCGedD;

#endif                                 /* c1_typedef_c1_s_MY3jsqmREaTzOC09vCGedD */

/* Type Definitions */
#ifndef c1_struct_c1_tag_lfyg79q6Kpk0jaJgYJuk8C
#define c1_struct_c1_tag_lfyg79q6Kpk0jaJgYJuk8C

struct c1_tag_lfyg79q6Kpk0jaJgYJuk8C
{
  char_T f1[5];
  char_T f2[6];
  char_T f3[6];
  char_T f4[6];
};

#endif                                 /* c1_struct_c1_tag_lfyg79q6Kpk0jaJgYJuk8C */

#ifndef c1_typedef_c1_cell_0
#define c1_typedef_c1_cell_0

typedef struct c1_tag_lfyg79q6Kpk0jaJgYJuk8C c1_cell_0;

#endif                                 /* c1_typedef_c1_cell_0 */

#ifndef c1_struct_c1_tag_uwJsGEKtvfiUxcdf0z0AYH
#define c1_struct_c1_tag_uwJsGEKtvfiUxcdf0z0AYH

struct c1_tag_uwJsGEKtvfiUxcdf0z0AYH
{
  char_T f1[4];
};

#endif                                 /* c1_struct_c1_tag_uwJsGEKtvfiUxcdf0z0AYH */

#ifndef c1_typedef_c1_cell_wrap_1
#define c1_typedef_c1_cell_wrap_1

typedef struct c1_tag_uwJsGEKtvfiUxcdf0z0AYH c1_cell_wrap_1;

#endif                                 /* c1_typedef_c1_cell_wrap_1 */

#ifndef c1_struct_c1_tag_WSTEAPgNJmllMDXoFTifcF
#define c1_struct_c1_tag_WSTEAPgNJmllMDXoFTifcF

struct c1_tag_WSTEAPgNJmllMDXoFTifcF
{
  c1_cell_0 _data;
};

#endif                                 /* c1_struct_c1_tag_WSTEAPgNJmllMDXoFTifcF */

#ifndef c1_typedef_c1_s_WSTEAPgNJmllMDXoFTifcF
#define c1_typedef_c1_s_WSTEAPgNJmllMDXoFTifcF

typedef struct c1_tag_WSTEAPgNJmllMDXoFTifcF c1_s_WSTEAPgNJmllMDXoFTifcF;

#endif                                 /* c1_typedef_c1_s_WSTEAPgNJmllMDXoFTifcF */

#ifndef c1_struct_c1_tag_MY3jsqmREaTzOC09vCGedD
#define c1_struct_c1_tag_MY3jsqmREaTzOC09vCGedD

struct c1_tag_MY3jsqmREaTzOC09vCGedD
{
  c1_cell_wrap_1 _data;
};

#endif                                 /* c1_struct_c1_tag_MY3jsqmREaTzOC09vCGedD */

#ifndef c1_typedef_c1_s_MY3jsqmREaTzOC09vCGedD
#define c1_typedef_c1_s_MY3jsqmREaTzOC09vCGedD

typedef struct c1_tag_MY3jsqmREaTzOC09vCGedD c1_s_MY3jsqmREaTzOC09vCGedD;

#endif                                 /* c1_typedef_c1_s_MY3jsqmREaTzOC09vCGedD */

#ifndef typedef_SFc1_cameraudpInstanceStruct
#define typedef_SFc1_cameraudpInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  int32_T c1_sfEvent;
  boolean_T c1_doneDoubleBufferReInit;
  void *c1_RuntimeVar;
  int32_T c1_IsDebuggerActive;
  int32_T c1_IsSequenceViewerPresent;
  int32_T c1_SequenceViewerOptimization;
  int32_T c1_IsHeatMapPresent;
  uint8_T c1_JITStateAnimation[1];
  uint8_T c1_JITTransitionAnimation[1];
  uint32_T c1_mlFcnLineNumber;
  void *c1_fcnDataPtrs[2];
  const char_T *c1_dataNames[2];
  uint32_T c1_numFcnVars;
  uint32_T c1_ssIds[2];
  uint32_T c1_statuses[2];
  void *c1_outMexFcns[2];
  void *c1_inMexFcns[2];
  uint8_T c1_uv[691200];
  uint8_T c1_b_uv[691200];
  CovrtStateflowInstance *c1_covrtInstance;
  void *c1_fEmlrtCtx;
  uint8_T (*c1_imageRGB)[2073600];
  uint8_T (*c1_grayImage)[691200];
} SFc1_cameraudpInstanceStruct;

#endif                                 /* typedef_SFc1_cameraudpInstanceStruct */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_cameraudp_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_cameraudp_get_check_sum(mxArray *plhs[]);
extern void c1_cameraudp_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
