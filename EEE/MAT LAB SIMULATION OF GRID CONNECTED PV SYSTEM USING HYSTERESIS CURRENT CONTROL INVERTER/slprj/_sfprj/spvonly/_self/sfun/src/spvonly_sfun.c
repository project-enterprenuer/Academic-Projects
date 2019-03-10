/* Include files */

#include "spvonly_sfun.h"
#include "c1_spvonly.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint8_T _sfEvent_;
uint32_T _spvonlyMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void spvonly_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void spvonly_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_spvonly_method_dispatcher(SimStruct *simstructPtr, unsigned int
  chartFileNumber, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_spvonly_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_spvonly_process_check_sum_call( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2956151691U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3261870028U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3293647648U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3769270108U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2617799376U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(887070970U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2510623385U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2569076099U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_spvonly_get_check_sum(mxArray *plhs[]);
          sf_c1_spvonly_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3901255494U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3502312195U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(312011709U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2399046860U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3625848131U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1775122284U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1402974142U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1181796662U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_spvonly_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  if (nrhs<2 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern mxArray *sf_c1_spvonly_get_autoinheritance_info(void);
        plhs[0] = sf_c1_spvonly_get_autoinheritance_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_spvonly_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray *sf_c1_spvonly_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_spvonly_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void spvonly_debug_initialize(void)
{
  _spvonlyMachineNumber_ = sf_debug_initialize_machine("spvonly","sfun",0,1,0,0,
    0);
  sf_debug_set_machine_event_thresholds(_spvonlyMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_spvonlyMachineNumber_,0);
}

void spvonly_register_exported_symbols(SimStruct* S)
{
}
