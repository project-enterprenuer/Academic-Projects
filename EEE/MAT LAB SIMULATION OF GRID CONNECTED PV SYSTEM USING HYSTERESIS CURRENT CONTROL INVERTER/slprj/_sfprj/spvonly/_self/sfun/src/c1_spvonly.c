/* Include files */

#include "blascompat32.h"
#include "spvonly_sfun.h"
#include "c1_spvonly.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "spvonly_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c1_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc1_spvonlyInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c1_spvonly(void);
static void initialize_params_c1_spvonly(void);
static void enable_c1_spvonly(void);
static void disable_c1_spvonly(void);
static void c1_update_debugger_state_c1_spvonly(void);
static const mxArray *get_sim_state_c1_spvonly(void);
static void set_sim_state_c1_spvonly(const mxArray *c1_st);
static void finalize_c1_spvonly(void);
static void sf_c1_spvonly(void);
static void c1_c1_spvonly(void);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static void c1_eml_warning(void);
static void c1_eml_error(void);
static const mxArray *c1_sf_marshall(void *c1_chartInstance, void *c1_u);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[40]);
static const mxArray *c1_emlrt_marshallOut(uint8_T c1_u);
static real_T c1_emlrt_marshallIn(const mxArray *c1_Ia, char *c1_name);
static uint8_T c1_b_emlrt_marshallIn(const mxArray *c1_b_is_active_c1_spvonly,
  char *c1_name);
static void init_io_bus_offset(void);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c1_spvonly(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c1_is_active_c1_spvonly = 0U;
}

static void initialize_params_c1_spvonly(void)
{
}

static void enable_c1_spvonly(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c1_spvonly(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c1_update_debugger_state_c1_spvonly(void)
{
}

static const mxArray *get_sim_state_c1_spvonly(void)
{
  const mxArray *c1_st = NULL;
  const mxArray *c1_y = NULL;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T *c1_Ia;
  c1_Ia = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2));
  c1_u = *c1_Ia;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 0, c1_b_y);
  sf_mex_setcell(c1_y, 1, c1_emlrt_marshallOut
                 (chartInstance.c1_is_active_c1_spvonly));
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_spvonly(const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_Ia;
  c1_Ia = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  chartInstance.c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  *c1_Ia = c1_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u, 0)), "Ia");
  chartInstance.c1_is_active_c1_spvonly = c1_b_emlrt_marshallIn(sf_mex_dup
    (sf_mex_getcell(c1_u, 1)), "is_active_c1_spvonly");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_spvonly();
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_spvonly(void)
{
}

static void sf_c1_spvonly(void)
{
  uint8_T c1_previousEvent;
  real_T *c1_Va;
  real_T *c1_Ia;
  real_T *c1_G;
  real_T *c1_TaC;
  c1_Ia = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c1_Va = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c1_TaC = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
  c1_G = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  _SFD_DATA_RANGE_CHECK(*c1_Va, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_Ia, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_G, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_TaC, 3U);
  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c1_c1_spvonly();
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency(_spvonlyMachineNumber_,
    chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void c1_c1_spvonly(void)
{
  real_T c1_Va;
  real_T c1_G;
  real_T c1_TaC;
  real_T c1_nargout = 1.0;
  real_T c1_nargin = 3.0;
  real_T c1_j;
  real_T c1_Vc;
  real_T c1_Vt_Ta;
  real_T c1_Rs;
  real_T c1_Xv;
  real_T c1_dVdI_Voc;
  real_T c1_Ir;
  real_T c1_Ir_TrK;
  real_T c1_b;
  real_T c1_Vt_TrK;
  real_T c1_Iph;
  real_T c1_Isc;
  real_T c1_TaK;
  real_T c1_a;
  real_T c1_Isc_TrK;
  real_T c1_Voc_TrK;
  real_T c1_TrK;
  real_T c1_Ns;
  real_T c1_Eg;
  real_T c1_n;
  real_T c1_q;
  real_T c1_k;
  real_T c1_Ia;
  real_T c1_b_b;
  real_T c1_y;
  real_T c1_c_b;
  real_T c1_b_a;
  real_T c1_d_b;
  real_T c1_A;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_c_a;
  real_T c1_d_a;
  real_T c1_ak;
  real_T c1_e_b;
  real_T c1_e_a;
  real_T c1_B;
  real_T c1_b_y;
  real_T c1_c_y;
  real_T c1_d_y;
  real_T c1_e_y;
  real_T c1_f_b;
  real_T c1_d_x;
  real_T c1_g_b;
  real_T c1_e_x;
  real_T c1_h_b;
  real_T c1_b_A;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_c_A;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_k_x;
  real_T c1_b_j;
  real_T c1_l_x;
  real_T c1_f_y;
  real_T c1_m_x;
  real_T c1_g_y;
  real_T c1_n_x;
  real_T c1_h_y;
  real_T c1_o_x;
  real_T c1_p_x;
  real_T c1_q_x;
  real_T c1_r_x;
  real_T c1_s_x;
  real_T c1_i_y;
  real_T c1_t_x;
  real_T c1_j_y;
  real_T c1_u_x;
  real_T c1_k_y;
  real_T c1_v_x;
  real_T c1_w_x;
  real_T c1_x_x;
  real_T c1_f_a;
  real_T c1_l_y;
  real_T c1_m_y;
  real_T c1_n_y;
  real_T c1_i_b;
  real_T c1_o_y;
  real_T c1_p_y;
  real_T c1_y_x;
  real_T c1_q_y;
  real_T c1_ab_x;
  real_T c1_r_y;
  real_T c1_z;
  real_T *c1_b_Ia;
  real_T *c1_b_TaC;
  real_T *c1_b_G;
  real_T *c1_b_Va;
  c1_b_Ia = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c1_b_Va = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c1_b_TaC = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
  c1_b_G = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  c1_Va = *c1_b_Va;
  c1_G = *c1_b_G;
  c1_TaC = *c1_b_TaC;
  sf_debug_symbol_scope_push(28U, 0U);
  sf_debug_symbol_scope_add("nargout", &c1_nargout, c1_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c1_nargin, c1_sf_marshall);
  sf_debug_symbol_scope_add("j", &c1_j, c1_sf_marshall);
  sf_debug_symbol_scope_add("Vc", &c1_Vc, c1_sf_marshall);
  sf_debug_symbol_scope_add("Vt_Ta", &c1_Vt_Ta, c1_sf_marshall);
  sf_debug_symbol_scope_add("Rs", &c1_Rs, c1_sf_marshall);
  sf_debug_symbol_scope_add("Xv", &c1_Xv, c1_sf_marshall);
  sf_debug_symbol_scope_add("dVdI_Voc", &c1_dVdI_Voc, c1_sf_marshall);
  sf_debug_symbol_scope_add("Ir", &c1_Ir, c1_sf_marshall);
  sf_debug_symbol_scope_add("Ir_TrK", &c1_Ir_TrK, c1_sf_marshall);
  sf_debug_symbol_scope_add("b", &c1_b, c1_sf_marshall);
  sf_debug_symbol_scope_add("Vt_TrK", &c1_Vt_TrK, c1_sf_marshall);
  sf_debug_symbol_scope_add("Iph", &c1_Iph, c1_sf_marshall);
  sf_debug_symbol_scope_add("Isc", &c1_Isc, c1_sf_marshall);
  sf_debug_symbol_scope_add("TaK", &c1_TaK, c1_sf_marshall);
  sf_debug_symbol_scope_add("a", &c1_a, c1_sf_marshall);
  sf_debug_symbol_scope_add("Isc_TrK", &c1_Isc_TrK, c1_sf_marshall);
  sf_debug_symbol_scope_add("Voc_TrK", &c1_Voc_TrK, c1_sf_marshall);
  sf_debug_symbol_scope_add("TrK", &c1_TrK, c1_sf_marshall);
  sf_debug_symbol_scope_add("Ns", &c1_Ns, c1_sf_marshall);
  sf_debug_symbol_scope_add("Eg", &c1_Eg, c1_sf_marshall);
  sf_debug_symbol_scope_add("n", &c1_n, c1_sf_marshall);
  sf_debug_symbol_scope_add("q", &c1_q, c1_sf_marshall);
  sf_debug_symbol_scope_add("k", &c1_k, c1_sf_marshall);
  sf_debug_symbol_scope_add("Ia", &c1_Ia, c1_sf_marshall);
  sf_debug_symbol_scope_add("TaC", &c1_TaC, c1_sf_marshall);
  sf_debug_symbol_scope_add("G", &c1_G, c1_sf_marshall);
  sf_debug_symbol_scope_add("Va", &c1_Va, c1_sf_marshall);
  CV_EML_FCN(0, 0);

  /* function bp_sx150s.m models the BP SX !%)S PV module */
  /*  calculates module current under given voltage, irradiance and temperature */
  /*  Ia= bp_sx150s(Va,G,T) */
  /*   */
  /* out: Ia= Module operating current (A), vector or scalar */
  _SFD_EML_CALL(0,9);
  c1_k = 1.381E-023;
  _SFD_EML_CALL(0,10);
  c1_q = 1.602E-019;
  _SFD_EML_CALL(0,11);
  c1_n = 1.62;
  _SFD_EML_CALL(0,12);
  c1_Eg = 1.12;
  _SFD_EML_CALL(0,13);
  c1_Ns = 72.0;
  _SFD_EML_CALL(0,14);
  c1_TrK = 298.0;
  _SFD_EML_CALL(0,15);
  c1_Voc_TrK = 6.0416666666666663E-001;
  _SFD_EML_CALL(0,16);
  c1_Isc_TrK = 4.75;
  _SFD_EML_CALL(0,17);
  c1_a = 0.00065;
  _SFD_EML_CALL(0,18);
  c1_TaK = 273.0 + c1_TaC;
  _SFD_EML_CALL(0,19);
  c1_b_b = c1_TaK - c1_TrK;
  c1_y = 0.00065 * c1_b_b;
  c1_c_b = 1.0 + c1_y;
  c1_Isc = 4.75 * c1_c_b;
  _SFD_EML_CALL(0,20);
  c1_b_a = c1_G;
  c1_d_b = c1_Isc;
  c1_Iph = c1_b_a * c1_d_b;
  _SFD_EML_CALL(0,21);
  c1_Vt_TrK = 4.1616202247191016E-002;
  _SFD_EML_CALL(0,22);
  c1_b = 8.0199533349424737E+003;
  _SFD_EML_CALL(0,23);
  c1_Ir_TrK = 2.3538981899976838E-006;
  _SFD_EML_CALL(0,24);
  c1_A = c1_TaK;
  c1_x = c1_A;
  c1_b_x = c1_x;
  c1_c_x = c1_b_x;
  c1_c_a = c1_c_x / 298.0;
  c1_d_a = c1_c_a;
  c1_ak = c1_d_a;
  if (c1_ak < 0.0) {
    c1_eml_error();
  }

  c1_e_b = muDoubleScalarPower(c1_ak, 1.8518518518518516E+000);
  c1_e_a = 2.3538981899976838E-006 * c1_e_b;
  c1_B = c1_TaK;
  c1_b_y = c1_B;
  if (c1_b_y == 0.0) {
    c1_eml_warning();
  }

  c1_c_y = c1_b_y;
  c1_d_y = c1_c_y;
  c1_e_y = 1.0 / c1_d_y;
  c1_f_b = c1_e_y - 3.3557046979865771E-003;
  c1_d_x = -8.0199533349424737E+003 * c1_f_b;
  c1_g_b = c1_d_x;
  c1_e_x = c1_g_b;
  c1_g_b = c1_e_x;
  c1_g_b = muDoubleScalarExp(c1_g_b);
  c1_Ir = c1_e_a * c1_g_b;
  _SFD_EML_CALL(0,25);
  c1_dVdI_Voc = -1.3888888888888888E-002;
  _SFD_EML_CALL(0,26);
  c1_Xv = 1.1413829464025162E+002;
  _SFD_EML_CALL(0,27);
  c1_Rs = 5.1275874943668837E-003;
  _SFD_EML_CALL(0,28);
  c1_h_b = c1_TaK;
  c1_b_A = 2.2372200000000001E-023 * c1_h_b;
  c1_f_x = c1_b_A;
  c1_g_x = c1_f_x;
  c1_h_x = c1_g_x;
  c1_Vt_Ta = c1_h_x / 1.602E-019;

  /* Va1=linspace(0,Va,50); */
  /* for i=1:length(Va1) */
  _SFD_EML_CALL(0,31);
  c1_c_A = c1_Va;
  c1_i_x = c1_c_A;
  c1_j_x = c1_i_x;
  c1_k_x = c1_j_x;
  c1_Vc = c1_k_x / 72.0;
  _SFD_EML_CALL(0,32);
  c1_Ia = 0.0;
  c1_j = 1.0;
  c1_b_j = 1.0;
  while (c1_b_j <= 5.0) {
    c1_j = c1_b_j;
    CV_EML_FOR(0, 0, 1);
    _SFD_EML_CALL(0,34);
    c1_l_x = c1_Vc + c1_Ia * c1_Rs;
    c1_f_y = c1_Vt_Ta;
    if (c1_f_y == 0.0) {
      c1_eml_warning();
    }

    c1_m_x = c1_l_x;
    c1_g_y = c1_f_y;
    c1_n_x = c1_m_x;
    c1_h_y = c1_g_y;
    c1_o_x = c1_n_x / c1_h_y;
    c1_p_x = c1_o_x;
    c1_q_x = c1_p_x;
    c1_p_x = c1_q_x;
    c1_p_x = muDoubleScalarExp(c1_p_x);
    c1_r_x = (c1_Iph - c1_Ia) - c1_Ir * (c1_p_x - 1.0);
    c1_s_x = c1_Vc + c1_Ia * c1_Rs;
    c1_i_y = c1_Vt_Ta;
    if (c1_i_y == 0.0) {
      c1_eml_warning();
    }

    c1_t_x = c1_s_x;
    c1_j_y = c1_i_y;
    c1_u_x = c1_t_x;
    c1_k_y = c1_j_y;
    c1_v_x = c1_u_x / c1_k_y;
    c1_w_x = c1_v_x;
    c1_x_x = c1_w_x;
    c1_w_x = c1_x_x;
    c1_w_x = muDoubleScalarExp(c1_w_x);
    c1_f_a = c1_Ir;
    c1_l_y = c1_Vt_Ta;
    if (c1_l_y == 0.0) {
      c1_eml_warning();
    }

    c1_m_y = c1_l_y;
    c1_n_y = c1_m_y;
    c1_i_b = 5.1275874943668837E-003 / c1_n_y;
    c1_o_y = c1_f_a * c1_i_b;
    c1_p_y = -1.0 - c1_o_y * c1_w_x;
    if (c1_p_y == 0.0) {
      c1_eml_warning();
    }

    c1_y_x = c1_r_x;
    c1_q_y = c1_p_y;
    c1_ab_x = c1_y_x;
    c1_r_y = c1_q_y;
    c1_z = c1_ab_x / c1_r_y;
    c1_Ia = c1_Ia - c1_z;
    c1_b_j = c1_b_j + 1.0;
    sf_mex_listen_for_ctrl_c(chartInstance.S);
  }

  CV_EML_FOR(0, 0, 0);
  _SFD_EML_CALL(0,-34);
  sf_debug_symbol_scope_pop();
  *c1_b_Ia = c1_Ia;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static void c1_eml_warning(void)
{
  int32_T c1_i0;
  static char_T c1_cv0[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b', 'y', ' ',
    'z', 'e', 'r', 'o', '.' };

  char_T c1_u[15];
  const mxArray *c1_y = NULL;
  int32_T c1_i1;
  static char_T c1_cv1[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'v',
    'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c1_b_u[19];
  const mxArray *c1_b_y = NULL;
  for (c1_i0 = 0; c1_i0 < 15; c1_i0 = c1_i0 + 1) {
    c1_u[c1_i0] = c1_cv0[c1_i0];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 10, 0U, 1U, 0U, 2, 1, 15));
  for (c1_i1 = 0; c1_i1 < 19; c1_i1 = c1_i1 + 1) {
    c1_b_u[c1_i1] = c1_cv1[c1_i1];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 10, 0U, 1U, 0U, 2, 1, 19));
  sf_mex_call_debug("warning", 0U, 2U, 14, c1_b_y, 14, c1_y);
}

static void c1_eml_error(void)
{
  int32_T c1_i2;
  static char_T c1_cv2[102] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm',
    'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e',
    's', 'u', 'l', 't', 's',
    ',', ' ', 'm', 'a', 'k', 'e', ' ', 'a', 't', ' ', 'l', 'e', 'a', 's', 't',
    ' ', 'o', 'n', 'e', ' ',
    'i', 'n', 'p', 'u', 't', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ',', ' ',
    'e', '.', 'g', '.', ' ',
    '\'', 'p', 'o', 'w', 'e', 'r', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(',
    'a', ')', ',', 'b', ')',
    '\'', '.' };

  char_T c1_u[102];
  const mxArray *c1_y = NULL;
  int32_T c1_i3;
  static char_T c1_cv3[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e', 'r', ':'
    , 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c1_b_u[32];
  const mxArray *c1_b_y = NULL;
  for (c1_i2 = 0; c1_i2 < 102; c1_i2 = c1_i2 + 1) {
    c1_u[c1_i2] = c1_cv2[c1_i2];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 10, 0U, 1U, 0U, 2, 1, 102));
  for (c1_i3 = 0; c1_i3 < 32; c1_i3 = c1_i3 + 1) {
    c1_b_u[c1_i3] = c1_cv3[c1_i3];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 10, 0U, 1U, 0U, 2, 1, 32));
  sf_mex_call_debug("error", 0U, 2U, 14, c1_b_y, 14, c1_y);
}

static const mxArray *c1_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

const mxArray *sf_c1_spvonly_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_ResolvedFunctionInfo c1_info[40];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i4;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 40));
  for (c1_i4 = 0; c1_i4 < 40; c1_i4 = c1_i4 + 1) {
    c1_r0 = &c1_info[c1_i4];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context",
                    "nameCaptureInfo", c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name",
                    "nameCaptureInfo", c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c1_i4);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[40])
{
  c1_info[0].context = "";
  c1_info[0].name = "plus";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved = "[B]plus";
  c1_info[0].fileLength = 0U;
  c1_info[0].fileTime1 = 0U;
  c1_info[0].fileTime2 = 0U;
  c1_info[1].context = "";
  c1_info[1].name = "mrdivide";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c1_info[1].fileLength = 771U;
  c1_info[1].fileTime1 = 1219740336U;
  c1_info[1].fileTime2 = 0U;
  c1_info[2].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c1_info[2].name = "nargin";
  c1_info[2].dominantType = "";
  c1_info[2].resolved = "[B]nargin";
  c1_info[2].fileLength = 0U;
  c1_info[2].fileTime1 = 0U;
  c1_info[2].fileTime2 = 0U;
  c1_info[3].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c1_info[3].name = "ge";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved = "[B]ge";
  c1_info[3].fileLength = 0U;
  c1_info[3].fileTime1 = 0U;
  c1_info[3].fileTime2 = 0U;
  c1_info[4].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c1_info[4].name = "isscalar";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved = "[B]isscalar";
  c1_info[4].fileLength = 0U;
  c1_info[4].fileTime1 = 0U;
  c1_info[4].fileTime2 = 0U;
  c1_info[5].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c1_info[5].name = "rdivide";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[5].fileLength = 620U;
  c1_info[5].fileTime1 = 1213914166U;
  c1_info[5].fileTime2 = 0U;
  c1_info[6].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[6].name = "gt";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved = "[B]gt";
  c1_info[6].fileLength = 0U;
  c1_info[6].fileTime1 = 0U;
  c1_info[6].fileTime2 = 0U;
  c1_info[7].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[7].name = "isa";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved = "[B]isa";
  c1_info[7].fileLength = 0U;
  c1_info[7].fileTime1 = 0U;
  c1_info[7].fileTime2 = 0U;
  c1_info[8].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[8].name = "isempty";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved = "[B]isempty";
  c1_info[8].fileLength = 0U;
  c1_info[8].fileTime1 = 0U;
  c1_info[8].fileTime2 = 0U;
  c1_info[9].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[9].name = "not";
  c1_info[9].dominantType = "logical";
  c1_info[9].resolved = "[B]not";
  c1_info[9].fileLength = 0U;
  c1_info[9].fileTime1 = 0U;
  c1_info[9].fileTime2 = 0U;
  c1_info[10].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[10].name = "strcmp";
  c1_info[10].dominantType = "char";
  c1_info[10].resolved = "[B]strcmp";
  c1_info[10].fileLength = 0U;
  c1_info[10].fileTime1 = 0U;
  c1_info[10].fileTime2 = 0U;
  c1_info[11].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[11].name = "eq";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved = "[B]eq";
  c1_info[11].fileLength = 0U;
  c1_info[11].fileTime1 = 0U;
  c1_info[11].fileTime2 = 0U;
  c1_info[12].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[12].name = "eml_warning";
  c1_info[12].dominantType = "char";
  c1_info[12].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c1_info[12].fileLength = 274U;
  c1_info[12].fileTime1 = 1227597196U;
  c1_info[12].fileTime2 = 0U;
  c1_info[13].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[13].name = "eml_div";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[13].fileLength = 4269U;
  c1_info[13].fileTime1 = 1227597186U;
  c1_info[13].fileTime2 = 0U;
  c1_info[14].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[14].name = "isinteger";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved = "[B]isinteger";
  c1_info[14].fileLength = 0U;
  c1_info[14].fileTime1 = 0U;
  c1_info[14].fileTime2 = 0U;
  c1_info[15].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  c1_info[15].name = "isreal";
  c1_info[15].dominantType = "double";
  c1_info[15].resolved = "[B]isreal";
  c1_info[15].fileLength = 0U;
  c1_info[15].fileTime1 = 0U;
  c1_info[15].fileTime2 = 0U;
  c1_info[16].context = "";
  c1_info[16].name = "minus";
  c1_info[16].dominantType = "double";
  c1_info[16].resolved = "[B]minus";
  c1_info[16].fileLength = 0U;
  c1_info[16].fileTime1 = 0U;
  c1_info[16].fileTime2 = 0U;
  c1_info[17].context = "";
  c1_info[17].name = "mtimes";
  c1_info[17].dominantType = "double";
  c1_info[17].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[17].fileLength = 2408U;
  c1_info[17].fileTime1 = 1227597202U;
  c1_info[17].fileTime2 = 0U;
  c1_info[18].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[18].name = "size";
  c1_info[18].dominantType = "double";
  c1_info[18].resolved = "[B]size";
  c1_info[18].fileLength = 0U;
  c1_info[18].fileTime1 = 0U;
  c1_info[18].fileTime2 = 0U;
  c1_info[19].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[19].name = "class";
  c1_info[19].dominantType = "double";
  c1_info[19].resolved = "[B]class";
  c1_info[19].fileLength = 0U;
  c1_info[19].fileTime1 = 0U;
  c1_info[19].fileTime2 = 0U;
  c1_info[20].context = "";
  c1_info[20].name = "exp";
  c1_info[20].dominantType = "double";
  c1_info[20].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c1_info[20].fileLength = 324U;
  c1_info[20].fileTime1 = 1203431820U;
  c1_info[20].fileTime2 = 0U;
  c1_info[21].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c1_info[21].name = "eml_scalar_exp";
  c1_info[21].dominantType = "double";
  c1_info[21].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_exp.m";
  c1_info[21].fileLength = 243U;
  c1_info[21].fileTime1 = 1203431792U;
  c1_info[21].fileTime2 = 0U;
  c1_info[22].context = "";
  c1_info[22].name = "mpower";
  c1_info[22].dominantType = "double";
  c1_info[22].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[22].fileLength = 3623U;
  c1_info[22].fileTime1 = 1227597202U;
  c1_info[22].fileTime2 = 0U;
  c1_info[23].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[23].name = "ndims";
  c1_info[23].dominantType = "double";
  c1_info[23].resolved = "[B]ndims";
  c1_info[23].fileLength = 0U;
  c1_info[23].fileTime1 = 0U;
  c1_info[23].fileTime2 = 0U;
  c1_info[24].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[24].name = "power";
  c1_info[24].dominantType = "double";
  c1_info[24].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[24].fileLength = 5380U;
  c1_info[24].fileTime1 = 1227597202U;
  c1_info[24].fileTime2 = 0U;
  c1_info[25].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[25].name = "eml_scalar_eg";
  c1_info[25].dominantType = "double";
  c1_info[25].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[25].fileLength = 3524U;
  c1_info[25].fileTime1 = 1227597194U;
  c1_info[25].fileTime2 = 0U;
  c1_info[26].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c1_info[26].name = "false";
  c1_info[26].dominantType = "";
  c1_info[26].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c1_info[26].fileLength = 238U;
  c1_info[26].fileTime1 = 1192454120U;
  c1_info[26].fileTime2 = 0U;
  c1_info[27].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c1_info[27].name = "logical";
  c1_info[27].dominantType = "double";
  c1_info[27].resolved = "[B]logical";
  c1_info[27].fileLength = 0U;
  c1_info[27].fileTime1 = 0U;
  c1_info[27].fileTime2 = 0U;
  c1_info[28].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[28].name = "isstruct";
  c1_info[28].dominantType = "double";
  c1_info[28].resolved = "[B]isstruct";
  c1_info[28].fileLength = 0U;
  c1_info[28].fileTime1 = 0U;
  c1_info[28].fileTime2 = 0U;
  c1_info[29].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c1_info[29].name = "cast";
  c1_info[29].dominantType = "double";
  c1_info[29].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c1_info[29].fileLength = 889U;
  c1_info[29].fileTime1 = 1225973242U;
  c1_info[29].fileTime2 = 0U;
  c1_info[30].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c1_info[30].name = "ischar";
  c1_info[30].dominantType = "char";
  c1_info[30].resolved = "[B]ischar";
  c1_info[30].fileLength = 0U;
  c1_info[30].fileTime1 = 0U;
  c1_info[30].fileTime2 = 0U;
  c1_info[31].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c1_info[31].name = "double";
  c1_info[31].dominantType = "double";
  c1_info[31].resolved = "[B]double";
  c1_info[31].fileLength = 0U;
  c1_info[31].fileTime1 = 0U;
  c1_info[31].fileTime2 = 0U;
  c1_info[32].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[32].name = "eml_scalexp_alloc";
  c1_info[32].dominantType = "double";
  c1_info[32].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[32].fileLength = 794U;
  c1_info[32].fileTime1 = 1227597194U;
  c1_info[32].fileTime2 = 0U;
  c1_info[33].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[33].name = "lt";
  c1_info[33].dominantType = "double";
  c1_info[33].resolved = "[B]lt";
  c1_info[33].fileLength = 0U;
  c1_info[33].fileTime1 = 0U;
  c1_info[33].fileTime2 = 0U;
  c1_info[34].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[34].name = "eml_scalar_floor";
  c1_info[34].dominantType = "double";
  c1_info[34].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[34].fileLength = 260U;
  c1_info[34].fileTime1 = 1209318190U;
  c1_info[34].fileTime2 = 0U;
  c1_info[35].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[35].name = "ne";
  c1_info[35].dominantType = "double";
  c1_info[35].resolved = "[B]ne";
  c1_info[35].fileLength = 0U;
  c1_info[35].fileTime1 = 0U;
  c1_info[35].fileTime2 = 0U;
  c1_info[36].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[36].name = "eml_error";
  c1_info[36].dominantType = "char";
  c1_info[36].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[36].fileLength = 315U;
  c1_info[36].fileTime1 = 1213914146U;
  c1_info[36].fileTime2 = 0U;
  c1_info[37].context = "";
  c1_info[37].name = "uminus";
  c1_info[37].dominantType = "double";
  c1_info[37].resolved = "[B]uminus";
  c1_info[37].fileLength = 0U;
  c1_info[37].fileTime1 = 0U;
  c1_info[37].fileTime2 = 0U;
  c1_info[38].context = "";
  c1_info[38].name = "zeros";
  c1_info[38].dominantType = "double";
  c1_info[38].resolved = "[B]zeros";
  c1_info[38].fileLength = 0U;
  c1_info[38].fileTime1 = 0U;
  c1_info[38].fileTime2 = 0U;
  c1_info[39].context = "";
  c1_info[39].name = "times";
  c1_info[39].dominantType = "double";
  c1_info[39].resolved = "[B]times";
  c1_info[39].fileLength = 0U;
  c1_info[39].fileTime1 = 0U;
  c1_info[39].fileTime2 = 0U;
}

static const mxArray *c1_emlrt_marshallOut(uint8_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0));
  return c1_y;
}

static real_T c1_emlrt_marshallIn(const mxArray *c1_Ia, char *c1_name)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_name, sf_mex_dup(c1_Ia), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_Ia);
  return c1_y;
}

static uint8_T c1_b_emlrt_marshallIn(const mxArray *c1_b_is_active_c1_spvonly,
  char *c1_name)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_is_active_c1_spvonly), &c1_u0, 1, 3, 0U,
                0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_b_is_active_c1_spvonly);
  return c1_y;
}

static void init_io_bus_offset(void)
{
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c1_spvonly_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(135765021U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2787571288U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2090273300U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(479997565U);
}

mxArray *sf_c1_spvonly_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2549240270U);
    pr[1] = (double)(1519853011U);
    pr[2] = (double)(3021941029U);
    pr[3] = (double)(1129664865U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c1_spvonly(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Ia\",},{M[8],M[0],T\"is_active_c1_spvonly\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_spvonly_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_spvonlyMachineNumber_,
          1,
          1,
          1,
          4,
          0,
          0,
          0,
          0,
          0,
          &(chartInstance.chartNumber),
          &(chartInstance.instanceNumber),
          ssGetPath(S),
          (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_spvonlyMachineNumber_,
            chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_spvonlyMachineNumber_,
            chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_spvonlyMachineNumber_,
            chartInstance.chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Va",0,
                              c1_sf_marshall);
          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Ia",0,
                              NULL);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"G",0,
                              NULL);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"TaC",0,
                              NULL);
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",1,-1,815);
        _SFD_CV_INIT_EML_FOR(0,0,696,706,814);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c1_Va;
          real_T *c1_Ia;
          real_T *c1_G;
          real_T *c1_TaC;
          c1_Ia = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c1_Va = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c1_TaC = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
          c1_G = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_Va);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_Ia);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_G);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_TaC);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_spvonlyMachineNumber_,
        chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_spvonly(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c1_spvonly();
  initialize_c1_spvonly();
}

static void sf_opaque_enable_c1_spvonly(void *chartInstanceVar)
{
  enable_c1_spvonly();
}

static void sf_opaque_disable_c1_spvonly(void *chartInstanceVar)
{
  disable_c1_spvonly();
}

static void sf_opaque_gateway_c1_spvonly(void *chartInstanceVar)
{
  sf_c1_spvonly();
}

static mxArray* sf_opaque_get_sim_state_c1_spvonly(void *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c1_spvonly();
  return st;
}

static void sf_opaque_set_sim_state_c1_spvonly(void *chartInstanceVar, const
  mxArray *st)
{
  set_sim_state_c1_spvonly(sf_mex_dup(st));
}

static void sf_opaque_terminate_c1_spvonly(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c1_spvonly();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_spvonly(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_spvonly();
  }
}

static void mdlSetWorkWidths_c1_spvonly(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("spvonly","spvonly",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("spvonly","spvonly",1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("spvonly","spvonly",1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"spvonly","spvonly",1,3);
      sf_mark_chart_reusable_outputs(S,"spvonly","spvonly",1,1);
    }

    sf_set_rtw_dwork_info(S,"spvonly","spvonly",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(3030121437U));
  ssSetChecksum1(S,(633782788U));
  ssSetChecksum2(S,(2718388108U));
  ssSetChecksum3(S,(2439961959U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_spvonly(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "spvonly", "spvonly",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_spvonly(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway = sf_opaque_gateway_c1_spvonly;
  chartInstance.chartInfo.initializeChart = sf_opaque_initialize_c1_spvonly;
  chartInstance.chartInfo.terminateChart = sf_opaque_terminate_c1_spvonly;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c1_spvonly;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c1_spvonly;
  chartInstance.chartInfo.getSimState = sf_opaque_get_sim_state_c1_spvonly;
  chartInstance.chartInfo.setSimState = sf_opaque_set_sim_state_c1_spvonly;
  chartInstance.chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_spvonly;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c1_spvonly;
  chartInstance.chartInfo.mdlStart = mdlStart_c1_spvonly;
  chartInstance.chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_spvonly;
  chartInstance.chartInfo.extModeExec = NULL;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo)));/* register the chart instance with simstruct */
  if (!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }

  chart_debug_initialization(S,1);
}

void c1_spvonly_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_spvonly(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_spvonly(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_spvonly(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_spvonly_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
