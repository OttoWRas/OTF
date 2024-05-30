// tvm target: c -keys=cpu -model=host
#define TVM_EXPORTS
#include "tvm/runtime/c_runtime_api.h"
#include "tvm/runtime/c_backend_api.h"
#include <math.h>
#include <stdbool.h>
#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_layout_transform_reshape(float* p0, float* T_reshape, uint8_t* global_const_workspace_14_var, uint8_t* global_workspace_15_var);
#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_nn_relu(float* p0, float* T_relu, uint8_t* global_const_workspace_4_var, uint8_t* global_workspace_5_var);
#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_nn_relu_1(float* p0, float* T_relu, uint8_t* global_const_workspace_10_var, uint8_t* global_workspace_11_var);
#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_dense_pack_add(float* p0, float* T_add, uint8_t* global_const_workspace_16_var, uint8_t* global_workspace_17_var);
#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_max_pool2d(float* p0, float* pool_max, uint8_t* global_const_workspace_6_var, uint8_t* global_workspace_7_var);
#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_max_pool2d_1(float* p0, float* pool_max, uint8_t* global_const_workspace_12_var, uint8_t* global_workspace_13_var);
#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_pad(float* p0, float* T_pad, uint8_t* global_const_workspace_8_var, uint8_t* global_workspace_9_var);
#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_pad_layout_transform(float* p0, float* T_layout_trans, uint8_t* global_const_workspace_2_var, uint8_t* global_workspace_3_var);
#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default___tvm_main__(float* Input3_buffer_var, float* output_buffer_var, uint8_t* global_const_workspace_0_var, uint8_t* global_workspace_1_var);
#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_layout_transform_reshape(float* p0, float* T_reshape, uint8_t* global_const_workspace_14_var, uint8_t* global_workspace_15_var) {
  for (int32_t ax1_outer = 0; ax1_outer < 16; ++ax1_outer) {
    for (int32_t ax1_inner = 0; ax1_inner < 16; ++ax1_inner) {
      T_reshape[((ax1_outer * 16) + ax1_inner)] = p0[((((ax1_outer >> 2) * 64) + (ax1_inner * 4)) + (ax1_outer & 3))];
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_nn_relu(float* p0, float* T_relu, uint8_t* global_const_workspace_4_var, uint8_t* global_workspace_5_var) {
  void* fused_nn_contrib_conv2d_NCHWc_constant_let = (&(global_const_workspace_4_var[23952]));
  void* fused_constant_let = (&(global_const_workspace_4_var[23040]));
  for (int32_t ax0_ax1_fused_ax2_fused = 0; ax0_ax1_fused_ax2_fused < 56; ++ax0_ax1_fused_ax2_fused) {
    void* conv2d_NCHWc_global_let = (&(global_workspace_5_var[29184]));
    for (int32_t oc_block_c_init = 0; oc_block_c_init < 4; ++oc_block_c_init) {
      ((float*)conv2d_NCHWc_global_let)[oc_block_c_init] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_1 = 0; oc_block_c_init_1 < 4; ++oc_block_c_init_1) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_1 + 4)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_2 = 0; oc_block_c_init_2 < 4; ++oc_block_c_init_2) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_2 + 8)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_3 = 0; oc_block_c_init_3 < 4; ++oc_block_c_init_3) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_3 + 12)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_4 = 0; oc_block_c_init_4 < 4; ++oc_block_c_init_4) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_4 + 16)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_5 = 0; oc_block_c_init_5 < 4; ++oc_block_c_init_5) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_5 + 20)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_6 = 0; oc_block_c_init_6 < 4; ++oc_block_c_init_6) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_6 + 24)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_7 = 0; oc_block_c_init_7 < 4; ++oc_block_c_init_7) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_7 + 28)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_8 = 0; oc_block_c_init_8 < 4; ++oc_block_c_init_8) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_8 + 32)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_9 = 0; oc_block_c_init_9 < 4; ++oc_block_c_init_9) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_9 + 36)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_10 = 0; oc_block_c_init_10 < 4; ++oc_block_c_init_10) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_10 + 40)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_11 = 0; oc_block_c_init_11 < 4; ++oc_block_c_init_11) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_11 + 44)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_12 = 0; oc_block_c_init_12 < 4; ++oc_block_c_init_12) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_12 + 48)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_13 = 0; oc_block_c_init_13 < 4; ++oc_block_c_init_13) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_13 + 52)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_14 = 0; oc_block_c_init_14 < 4; ++oc_block_c_init_14) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_14 + 56)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_15 = 0; oc_block_c_init_15 < 4; ++oc_block_c_init_15) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_15 + 60)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_16 = 0; oc_block_c_init_16 < 4; ++oc_block_c_init_16) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_16 + 64)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_17 = 0; oc_block_c_init_17 < 4; ++oc_block_c_init_17) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_17 + 68)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_18 = 0; oc_block_c_init_18 < 4; ++oc_block_c_init_18) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_18 + 72)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_19 = 0; oc_block_c_init_19 < 4; ++oc_block_c_init_19) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_19 + 76)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_20 = 0; oc_block_c_init_20 < 4; ++oc_block_c_init_20) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_20 + 80)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_21 = 0; oc_block_c_init_21 < 4; ++oc_block_c_init_21) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_21 + 84)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_22 = 0; oc_block_c_init_22 < 4; ++oc_block_c_init_22) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_22 + 88)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_23 = 0; oc_block_c_init_23 < 4; ++oc_block_c_init_23) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_23 + 92)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_24 = 0; oc_block_c_init_24 < 4; ++oc_block_c_init_24) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_24 + 96)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_25 = 0; oc_block_c_init_25 < 4; ++oc_block_c_init_25) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_25 + 100)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_26 = 0; oc_block_c_init_26 < 4; ++oc_block_c_init_26) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_26 + 104)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_27 = 0; oc_block_c_init_27 < 4; ++oc_block_c_init_27) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_27 + 108)] = 0.000000e+00f;
    }
    for (int32_t kh = 0; kh < 5; ++kh) {
      for (int32_t kw = 0; kw < 5; ++kw) {
        for (int32_t oc_block_c = 0; oc_block_c < 4; ++oc_block_c) {
          ((float*)conv2d_NCHWc_global_let)[oc_block_c] = (((float*)conv2d_NCHWc_global_let)[oc_block_c] + (p0[(((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c)]));
        }
        for (int32_t oc_block_c_1 = 0; oc_block_c_1 < 4; ++oc_block_c_1) {
          int32_t cse_var_1 = (oc_block_c_1 + 4);
          ((float*)conv2d_NCHWc_global_let)[cse_var_1] = (((float*)conv2d_NCHWc_global_let)[cse_var_1] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 1)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_1)]));
        }
        for (int32_t oc_block_c_2 = 0; oc_block_c_2 < 4; ++oc_block_c_2) {
          int32_t cse_var_2 = (oc_block_c_2 + 8);
          ((float*)conv2d_NCHWc_global_let)[cse_var_2] = (((float*)conv2d_NCHWc_global_let)[cse_var_2] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 2)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_2)]));
        }
        for (int32_t oc_block_c_3 = 0; oc_block_c_3 < 4; ++oc_block_c_3) {
          int32_t cse_var_3 = (oc_block_c_3 + 12);
          ((float*)conv2d_NCHWc_global_let)[cse_var_3] = (((float*)conv2d_NCHWc_global_let)[cse_var_3] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 3)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_3)]));
        }
        for (int32_t oc_block_c_4 = 0; oc_block_c_4 < 4; ++oc_block_c_4) {
          int32_t cse_var_4 = (oc_block_c_4 + 16);
          ((float*)conv2d_NCHWc_global_let)[cse_var_4] = (((float*)conv2d_NCHWc_global_let)[cse_var_4] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 4)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_4)]));
        }
        for (int32_t oc_block_c_5 = 0; oc_block_c_5 < 4; ++oc_block_c_5) {
          int32_t cse_var_5 = (oc_block_c_5 + 20);
          ((float*)conv2d_NCHWc_global_let)[cse_var_5] = (((float*)conv2d_NCHWc_global_let)[cse_var_5] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 5)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_5)]));
        }
        for (int32_t oc_block_c_6 = 0; oc_block_c_6 < 4; ++oc_block_c_6) {
          int32_t cse_var_6 = (oc_block_c_6 + 24);
          ((float*)conv2d_NCHWc_global_let)[cse_var_6] = (((float*)conv2d_NCHWc_global_let)[cse_var_6] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 6)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_6)]));
        }
        for (int32_t oc_block_c_7 = 0; oc_block_c_7 < 4; ++oc_block_c_7) {
          int32_t cse_var_7 = (oc_block_c_7 + 28);
          ((float*)conv2d_NCHWc_global_let)[cse_var_7] = (((float*)conv2d_NCHWc_global_let)[cse_var_7] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 7)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_7)]));
        }
        for (int32_t oc_block_c_8 = 0; oc_block_c_8 < 4; ++oc_block_c_8) {
          int32_t cse_var_8 = (oc_block_c_8 + 32);
          ((float*)conv2d_NCHWc_global_let)[cse_var_8] = (((float*)conv2d_NCHWc_global_let)[cse_var_8] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 8)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_8)]));
        }
        for (int32_t oc_block_c_9 = 0; oc_block_c_9 < 4; ++oc_block_c_9) {
          int32_t cse_var_9 = (oc_block_c_9 + 36);
          ((float*)conv2d_NCHWc_global_let)[cse_var_9] = (((float*)conv2d_NCHWc_global_let)[cse_var_9] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 9)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_9)]));
        }
        for (int32_t oc_block_c_10 = 0; oc_block_c_10 < 4; ++oc_block_c_10) {
          int32_t cse_var_10 = (oc_block_c_10 + 40);
          ((float*)conv2d_NCHWc_global_let)[cse_var_10] = (((float*)conv2d_NCHWc_global_let)[cse_var_10] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 10)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_10)]));
        }
        for (int32_t oc_block_c_11 = 0; oc_block_c_11 < 4; ++oc_block_c_11) {
          int32_t cse_var_11 = (oc_block_c_11 + 44);
          ((float*)conv2d_NCHWc_global_let)[cse_var_11] = (((float*)conv2d_NCHWc_global_let)[cse_var_11] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 11)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_11)]));
        }
        for (int32_t oc_block_c_12 = 0; oc_block_c_12 < 4; ++oc_block_c_12) {
          int32_t cse_var_12 = (oc_block_c_12 + 48);
          ((float*)conv2d_NCHWc_global_let)[cse_var_12] = (((float*)conv2d_NCHWc_global_let)[cse_var_12] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 12)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_12)]));
        }
        for (int32_t oc_block_c_13 = 0; oc_block_c_13 < 4; ++oc_block_c_13) {
          int32_t cse_var_13 = (oc_block_c_13 + 52);
          ((float*)conv2d_NCHWc_global_let)[cse_var_13] = (((float*)conv2d_NCHWc_global_let)[cse_var_13] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 13)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_13)]));
        }
        for (int32_t oc_block_c_14 = 0; oc_block_c_14 < 4; ++oc_block_c_14) {
          int32_t cse_var_14 = (oc_block_c_14 + 56);
          ((float*)conv2d_NCHWc_global_let)[cse_var_14] = (((float*)conv2d_NCHWc_global_let)[cse_var_14] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 14)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_14)]));
        }
        for (int32_t oc_block_c_15 = 0; oc_block_c_15 < 4; ++oc_block_c_15) {
          int32_t cse_var_15 = (oc_block_c_15 + 60);
          ((float*)conv2d_NCHWc_global_let)[cse_var_15] = (((float*)conv2d_NCHWc_global_let)[cse_var_15] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 15)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_15)]));
        }
        for (int32_t oc_block_c_16 = 0; oc_block_c_16 < 4; ++oc_block_c_16) {
          int32_t cse_var_16 = (oc_block_c_16 + 64);
          ((float*)conv2d_NCHWc_global_let)[cse_var_16] = (((float*)conv2d_NCHWc_global_let)[cse_var_16] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 16)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_16)]));
        }
        for (int32_t oc_block_c_17 = 0; oc_block_c_17 < 4; ++oc_block_c_17) {
          int32_t cse_var_17 = (oc_block_c_17 + 68);
          ((float*)conv2d_NCHWc_global_let)[cse_var_17] = (((float*)conv2d_NCHWc_global_let)[cse_var_17] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 17)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_17)]));
        }
        for (int32_t oc_block_c_18 = 0; oc_block_c_18 < 4; ++oc_block_c_18) {
          int32_t cse_var_18 = (oc_block_c_18 + 72);
          ((float*)conv2d_NCHWc_global_let)[cse_var_18] = (((float*)conv2d_NCHWc_global_let)[cse_var_18] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 18)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_18)]));
        }
        for (int32_t oc_block_c_19 = 0; oc_block_c_19 < 4; ++oc_block_c_19) {
          int32_t cse_var_19 = (oc_block_c_19 + 76);
          ((float*)conv2d_NCHWc_global_let)[cse_var_19] = (((float*)conv2d_NCHWc_global_let)[cse_var_19] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 19)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_19)]));
        }
        for (int32_t oc_block_c_20 = 0; oc_block_c_20 < 4; ++oc_block_c_20) {
          int32_t cse_var_20 = (oc_block_c_20 + 80);
          ((float*)conv2d_NCHWc_global_let)[cse_var_20] = (((float*)conv2d_NCHWc_global_let)[cse_var_20] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 20)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_20)]));
        }
        for (int32_t oc_block_c_21 = 0; oc_block_c_21 < 4; ++oc_block_c_21) {
          int32_t cse_var_21 = (oc_block_c_21 + 84);
          ((float*)conv2d_NCHWc_global_let)[cse_var_21] = (((float*)conv2d_NCHWc_global_let)[cse_var_21] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 21)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_21)]));
        }
        for (int32_t oc_block_c_22 = 0; oc_block_c_22 < 4; ++oc_block_c_22) {
          int32_t cse_var_22 = (oc_block_c_22 + 88);
          ((float*)conv2d_NCHWc_global_let)[cse_var_22] = (((float*)conv2d_NCHWc_global_let)[cse_var_22] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 22)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_22)]));
        }
        for (int32_t oc_block_c_23 = 0; oc_block_c_23 < 4; ++oc_block_c_23) {
          int32_t cse_var_23 = (oc_block_c_23 + 92);
          ((float*)conv2d_NCHWc_global_let)[cse_var_23] = (((float*)conv2d_NCHWc_global_let)[cse_var_23] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 23)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_23)]));
        }
        for (int32_t oc_block_c_24 = 0; oc_block_c_24 < 4; ++oc_block_c_24) {
          int32_t cse_var_24 = (oc_block_c_24 + 96);
          ((float*)conv2d_NCHWc_global_let)[cse_var_24] = (((float*)conv2d_NCHWc_global_let)[cse_var_24] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 24)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_24)]));
        }
        for (int32_t oc_block_c_25 = 0; oc_block_c_25 < 4; ++oc_block_c_25) {
          int32_t cse_var_25 = (oc_block_c_25 + 100);
          ((float*)conv2d_NCHWc_global_let)[cse_var_25] = (((float*)conv2d_NCHWc_global_let)[cse_var_25] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 25)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_25)]));
        }
        for (int32_t oc_block_c_26 = 0; oc_block_c_26 < 4; ++oc_block_c_26) {
          int32_t cse_var_26 = (oc_block_c_26 + 104);
          ((float*)conv2d_NCHWc_global_let)[cse_var_26] = (((float*)conv2d_NCHWc_global_let)[cse_var_26] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 26)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_26)]));
        }
        for (int32_t oc_block_c_27 = 0; oc_block_c_27 < 4; ++oc_block_c_27) {
          int32_t cse_var_27 = (oc_block_c_27 + 108);
          ((float*)conv2d_NCHWc_global_let)[cse_var_27] = (((float*)conv2d_NCHWc_global_let)[cse_var_27] + (p0[((((kh * 32) + ((ax0_ax1_fused_ax2_fused % 28) * 32)) + kw) + 27)] * ((float*)fused_constant_let)[(((((ax0_ax1_fused_ax2_fused / 28) * 100) + (kh * 20)) + (kw * 4)) + oc_block_c_27)]));
        }
      }
    }
    for (int32_t ax3_inner = 0; ax3_inner < 28; ++ax3_inner) {
      for (int32_t ax4 = 0; ax4 < 4; ++ax4) {
        int32_t cse_var_28 = (ax3_inner * 4);
        float v_ = ((float*)conv2d_NCHWc_global_let)[(cse_var_28 + ax4)] + ((float*)fused_nn_contrib_conv2d_NCHWc_constant_let)[(((ax0_ax1_fused_ax2_fused / 28) * 4) + ax4)];
        T_relu[(((ax0_ax1_fused_ax2_fused * 112) + cse_var_28) + ax4)] = ((v_) > (0.000000e+00f) ? (v_) : (0.000000e+00f));
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_nn_relu_1(float* p0, float* T_relu, uint8_t* global_const_workspace_10_var, uint8_t* global_workspace_11_var) {
  void* fused_nn_contrib_conv2d_NCHWc_constant_1_let = (&(global_const_workspace_10_var[23840]));
  void* fused_constant_1_let = (&(global_const_workspace_10_var[0]));
  for (int32_t ax0_ax1_fused_ax2_fused = 0; ax0_ax1_fused_ax2_fused < 56; ++ax0_ax1_fused_ax2_fused) {
    void* conv2d_NCHWc_global_let = (&(global_workspace_11_var[22912]));
    for (int32_t oc_block_c_init = 0; oc_block_c_init < 4; ++oc_block_c_init) {
      ((float*)conv2d_NCHWc_global_let)[oc_block_c_init] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_1 = 0; oc_block_c_init_1 < 4; ++oc_block_c_init_1) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_1 + 4)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_2 = 0; oc_block_c_init_2 < 4; ++oc_block_c_init_2) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_2 + 8)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_3 = 0; oc_block_c_init_3 < 4; ++oc_block_c_init_3) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_3 + 12)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_4 = 0; oc_block_c_init_4 < 4; ++oc_block_c_init_4) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_4 + 16)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_5 = 0; oc_block_c_init_5 < 4; ++oc_block_c_init_5) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_5 + 20)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_6 = 0; oc_block_c_init_6 < 4; ++oc_block_c_init_6) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_6 + 24)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_7 = 0; oc_block_c_init_7 < 4; ++oc_block_c_init_7) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_7 + 28)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_8 = 0; oc_block_c_init_8 < 4; ++oc_block_c_init_8) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_8 + 32)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_9 = 0; oc_block_c_init_9 < 4; ++oc_block_c_init_9) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_9 + 36)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_10 = 0; oc_block_c_init_10 < 4; ++oc_block_c_init_10) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_10 + 40)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_11 = 0; oc_block_c_init_11 < 4; ++oc_block_c_init_11) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_11 + 44)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_12 = 0; oc_block_c_init_12 < 4; ++oc_block_c_init_12) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_12 + 48)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init_13 = 0; oc_block_c_init_13 < 4; ++oc_block_c_init_13) {
      ((float*)conv2d_NCHWc_global_let)[(oc_block_c_init_13 + 52)] = 0.000000e+00f;
    }
    for (int32_t ic_outer = 0; ic_outer < 2; ++ic_outer) {
      for (int32_t kh = 0; kh < 5; ++kh) {
        for (int32_t kw = 0; kw < 5; ++kw) {
          for (int32_t ic_inner = 0; ic_inner < 4; ++ic_inner) {
            for (int32_t oc_block_c = 0; oc_block_c < 4; ++oc_block_c) {
              ((float*)conv2d_NCHWc_global_let)[oc_block_c] = (((float*)conv2d_NCHWc_global_let)[oc_block_c] + (p0[(((((ic_outer * 1296) + (kh * 72)) + ((ax0_ax1_fused_ax2_fused % 14) * 72)) + (kw * 4)) + ic_inner)] * ((float*)fused_constant_1_let)[(((((((ax0_ax1_fused_ax2_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c)]));
            }
            for (int32_t oc_block_c_1 = 0; oc_block_c_1 < 4; ++oc_block_c_1) {
              int32_t cse_var_1 = (oc_block_c_1 + 4);
              ((float*)conv2d_NCHWc_global_let)[cse_var_1] = (((float*)conv2d_NCHWc_global_let)[cse_var_1] + (p0[((((((ic_outer * 1296) + (kh * 72)) + ((ax0_ax1_fused_ax2_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 4)] * ((float*)fused_constant_1_let)[(((((((ax0_ax1_fused_ax2_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c_1)]));
            }
            for (int32_t oc_block_c_2 = 0; oc_block_c_2 < 4; ++oc_block_c_2) {
              int32_t cse_var_2 = (oc_block_c_2 + 8);
              ((float*)conv2d_NCHWc_global_let)[cse_var_2] = (((float*)conv2d_NCHWc_global_let)[cse_var_2] + (p0[((((((ic_outer * 1296) + (kh * 72)) + ((ax0_ax1_fused_ax2_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 8)] * ((float*)fused_constant_1_let)[(((((((ax0_ax1_fused_ax2_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c_2)]));
            }
            for (int32_t oc_block_c_3 = 0; oc_block_c_3 < 4; ++oc_block_c_3) {
              int32_t cse_var_3 = (oc_block_c_3 + 12);
              ((float*)conv2d_NCHWc_global_let)[cse_var_3] = (((float*)conv2d_NCHWc_global_let)[cse_var_3] + (p0[((((((ic_outer * 1296) + (kh * 72)) + ((ax0_ax1_fused_ax2_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 12)] * ((float*)fused_constant_1_let)[(((((((ax0_ax1_fused_ax2_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c_3)]));
            }
            for (int32_t oc_block_c_4 = 0; oc_block_c_4 < 4; ++oc_block_c_4) {
              int32_t cse_var_4 = (oc_block_c_4 + 16);
              ((float*)conv2d_NCHWc_global_let)[cse_var_4] = (((float*)conv2d_NCHWc_global_let)[cse_var_4] + (p0[((((((ic_outer * 1296) + (kh * 72)) + ((ax0_ax1_fused_ax2_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 16)] * ((float*)fused_constant_1_let)[(((((((ax0_ax1_fused_ax2_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c_4)]));
            }
            for (int32_t oc_block_c_5 = 0; oc_block_c_5 < 4; ++oc_block_c_5) {
              int32_t cse_var_5 = (oc_block_c_5 + 20);
              ((float*)conv2d_NCHWc_global_let)[cse_var_5] = (((float*)conv2d_NCHWc_global_let)[cse_var_5] + (p0[((((((ic_outer * 1296) + (kh * 72)) + ((ax0_ax1_fused_ax2_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 20)] * ((float*)fused_constant_1_let)[(((((((ax0_ax1_fused_ax2_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c_5)]));
            }
            for (int32_t oc_block_c_6 = 0; oc_block_c_6 < 4; ++oc_block_c_6) {
              int32_t cse_var_6 = (oc_block_c_6 + 24);
              ((float*)conv2d_NCHWc_global_let)[cse_var_6] = (((float*)conv2d_NCHWc_global_let)[cse_var_6] + (p0[((((((ic_outer * 1296) + (kh * 72)) + ((ax0_ax1_fused_ax2_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 24)] * ((float*)fused_constant_1_let)[(((((((ax0_ax1_fused_ax2_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c_6)]));
            }
            for (int32_t oc_block_c_7 = 0; oc_block_c_7 < 4; ++oc_block_c_7) {
              int32_t cse_var_7 = (oc_block_c_7 + 28);
              ((float*)conv2d_NCHWc_global_let)[cse_var_7] = (((float*)conv2d_NCHWc_global_let)[cse_var_7] + (p0[((((((ic_outer * 1296) + (kh * 72)) + ((ax0_ax1_fused_ax2_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 28)] * ((float*)fused_constant_1_let)[(((((((ax0_ax1_fused_ax2_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c_7)]));
            }
            for (int32_t oc_block_c_8 = 0; oc_block_c_8 < 4; ++oc_block_c_8) {
              int32_t cse_var_8 = (oc_block_c_8 + 32);
              ((float*)conv2d_NCHWc_global_let)[cse_var_8] = (((float*)conv2d_NCHWc_global_let)[cse_var_8] + (p0[((((((ic_outer * 1296) + (kh * 72)) + ((ax0_ax1_fused_ax2_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 32)] * ((float*)fused_constant_1_let)[(((((((ax0_ax1_fused_ax2_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c_8)]));
            }
            for (int32_t oc_block_c_9 = 0; oc_block_c_9 < 4; ++oc_block_c_9) {
              int32_t cse_var_9 = (oc_block_c_9 + 36);
              ((float*)conv2d_NCHWc_global_let)[cse_var_9] = (((float*)conv2d_NCHWc_global_let)[cse_var_9] + (p0[((((((ic_outer * 1296) + (kh * 72)) + ((ax0_ax1_fused_ax2_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 36)] * ((float*)fused_constant_1_let)[(((((((ax0_ax1_fused_ax2_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c_9)]));
            }
            for (int32_t oc_block_c_10 = 0; oc_block_c_10 < 4; ++oc_block_c_10) {
              int32_t cse_var_10 = (oc_block_c_10 + 40);
              ((float*)conv2d_NCHWc_global_let)[cse_var_10] = (((float*)conv2d_NCHWc_global_let)[cse_var_10] + (p0[((((((ic_outer * 1296) + (kh * 72)) + ((ax0_ax1_fused_ax2_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 40)] * ((float*)fused_constant_1_let)[(((((((ax0_ax1_fused_ax2_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c_10)]));
            }
            for (int32_t oc_block_c_11 = 0; oc_block_c_11 < 4; ++oc_block_c_11) {
              int32_t cse_var_11 = (oc_block_c_11 + 44);
              ((float*)conv2d_NCHWc_global_let)[cse_var_11] = (((float*)conv2d_NCHWc_global_let)[cse_var_11] + (p0[((((((ic_outer * 1296) + (kh * 72)) + ((ax0_ax1_fused_ax2_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 44)] * ((float*)fused_constant_1_let)[(((((((ax0_ax1_fused_ax2_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c_11)]));
            }
            for (int32_t oc_block_c_12 = 0; oc_block_c_12 < 4; ++oc_block_c_12) {
              int32_t cse_var_12 = (oc_block_c_12 + 48);
              ((float*)conv2d_NCHWc_global_let)[cse_var_12] = (((float*)conv2d_NCHWc_global_let)[cse_var_12] + (p0[((((((ic_outer * 1296) + (kh * 72)) + ((ax0_ax1_fused_ax2_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 48)] * ((float*)fused_constant_1_let)[(((((((ax0_ax1_fused_ax2_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c_12)]));
            }
            for (int32_t oc_block_c_13 = 0; oc_block_c_13 < 4; ++oc_block_c_13) {
              int32_t cse_var_13 = (oc_block_c_13 + 52);
              ((float*)conv2d_NCHWc_global_let)[cse_var_13] = (((float*)conv2d_NCHWc_global_let)[cse_var_13] + (p0[((((((ic_outer * 1296) + (kh * 72)) + ((ax0_ax1_fused_ax2_fused % 14) * 72)) + (kw * 4)) + ic_inner) + 52)] * ((float*)fused_constant_1_let)[(((((((ax0_ax1_fused_ax2_fused / 14) * 800) + (ic_outer * 400)) + (kh * 80)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c_13)]));
            }
          }
        }
      }
    }
    for (int32_t ax3_inner = 0; ax3_inner < 14; ++ax3_inner) {
      for (int32_t ax4 = 0; ax4 < 4; ++ax4) {
        int32_t cse_var_14 = (ax3_inner * 4);
        float v_ = ((float*)conv2d_NCHWc_global_let)[(cse_var_14 + ax4)] + ((float*)fused_nn_contrib_conv2d_NCHWc_constant_1_let)[(((ax0_ax1_fused_ax2_fused / 14) * 4) + ax4)];
        T_relu[(((ax0_ax1_fused_ax2_fused * 56) + cse_var_14) + ax4)] = ((v_) > (0.000000e+00f) ? (v_) : (0.000000e+00f));
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_dense_pack_add(float* p0, float* T_add, uint8_t* global_const_workspace_16_var, uint8_t* global_workspace_17_var) {
  void* fused_nn_contrib_dense_pack_constant_let = (&(global_const_workspace_16_var[23904]));
  void* fused_constant_2_let = (&(global_const_workspace_16_var[12800]));
  for (int32_t ax1_outer_ax0_outer_fused = 0; ax1_outer_ax0_outer_fused < 2; ++ax1_outer_ax0_outer_fused) {
    void* compute_global_let = (&(global_workspace_17_var[1024]));
    for (int32_t x_c_init = 0; x_c_init < 5; ++x_c_init) {
      ((float*)compute_global_let)[x_c_init] = 0.000000e+00f;
    }
    for (int32_t k_outer = 0; k_outer < 256; ++k_outer) {
      for (int32_t x_c = 0; x_c < 5; ++x_c) {
        ((float*)compute_global_let)[x_c] = (((float*)compute_global_let)[x_c] + (p0[k_outer] * ((float*)fused_constant_2_let)[(((ax1_outer_ax0_outer_fused * 1280) + (k_outer * 5)) + x_c)]));
      }
    }
    for (int32_t ax1_inner_inner = 0; ax1_inner_inner < 5; ++ax1_inner_inner) {
      int32_t cse_var_1 = ((ax1_outer_ax0_outer_fused * 5) + ax1_inner_inner);
      T_add[cse_var_1] = (((float*)compute_global_let)[ax1_inner_inner] + ((float*)fused_nn_contrib_dense_pack_constant_let)[cse_var_1]);
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_max_pool2d(float* p0, float* pool_max, uint8_t* global_const_workspace_6_var, uint8_t* global_workspace_7_var) {
  for (int32_t ax0_ax1_fused_ax2_fused = 0; ax0_ax1_fused_ax2_fused < 28; ++ax0_ax1_fused_ax2_fused) {
    for (int32_t ax3 = 0; ax3 < 14; ++ax3) {
      for (int32_t ax4_init = 0; ax4_init < 4; ++ax4_init) {
        pool_max[(((ax0_ax1_fused_ax2_fused * 56) + (ax3 * 4)) + ax4_init)] = -3.402823e+38f;
      }
      for (int32_t rv0_rv1_fused = 0; rv0_rv1_fused < 4; ++rv0_rv1_fused) {
        for (int32_t ax4 = 0; ax4 < 4; ++ax4) {
          int32_t cse_var_1 = (((ax0_ax1_fused_ax2_fused * 56) + (ax3 * 4)) + ax4);
          float v_ = pool_max[cse_var_1];
          float v__1 = p0[(((((ax0_ax1_fused_ax2_fused * 224) + ((rv0_rv1_fused >> 1) * 112)) + (ax3 * 8)) + ((rv0_rv1_fused & 1) * 4)) + ax4)];
          pool_max[cse_var_1] = ((v_) > (v__1) ? (v_) : (v__1));
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_max_pool2d_1(float* p0, float* pool_max, uint8_t* global_const_workspace_12_var, uint8_t* global_workspace_13_var) {
  for (int32_t ax0_ax1_fused_ax2_fused = 0; ax0_ax1_fused_ax2_fused < 16; ++ax0_ax1_fused_ax2_fused) {
    for (int32_t ax3 = 0; ax3 < 4; ++ax3) {
      for (int32_t ax4_init = 0; ax4_init < 4; ++ax4_init) {
        pool_max[(((ax0_ax1_fused_ax2_fused * 16) + (ax3 * 4)) + ax4_init)] = -3.402823e+38f;
      }
      for (int32_t rv0_rv1_fused = 0; rv0_rv1_fused < 9; ++rv0_rv1_fused) {
        for (int32_t ax4 = 0; ax4 < 4; ++ax4) {
          int32_t cse_var_1 = (((ax0_ax1_fused_ax2_fused * 16) + (ax3 * 4)) + ax4);
          float v_ = pool_max[cse_var_1];
          float v__1 = p0[(((((((ax0_ax1_fused_ax2_fused >> 2) * 784) + ((ax0_ax1_fused_ax2_fused & 3) * 168)) + ((rv0_rv1_fused / 3) * 56)) + (ax3 * 12)) + ((rv0_rv1_fused % 3) * 4)) + ax4)];
          pool_max[cse_var_1] = ((v_) > (v__1) ? (v_) : (v__1));
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_pad(float* p0, float* T_pad, uint8_t* global_const_workspace_8_var, uint8_t* global_workspace_9_var) {
  for (int32_t ax0_ax1_fused_ax2_fused = 0; ax0_ax1_fused_ax2_fused < 36; ++ax0_ax1_fused_ax2_fused) {
    for (int32_t ax3 = 0; ax3 < 18; ++ax3) {
      for (int32_t ax4_inner = 0; ax4_inner < 4; ++ax4_inner) {
        int32_t cse_var_2 = (ax0_ax1_fused_ax2_fused % 18);
        int32_t cse_var_1 = (ax3 * 4);
        float condval;
        if (((((2 <= cse_var_2) && (cse_var_2 < 16)) && (2 <= ax3)) && (ax3 < 16))) {
          condval = p0[((((((ax0_ax1_fused_ax2_fused / 18) * 784) + (cse_var_2 * 56)) + cse_var_1) + ax4_inner) - 120)];
        } else {
          condval = 0.000000e+00f;
        }
        T_pad[(((ax0_ax1_fused_ax2_fused * 72) + cse_var_1) + ax4_inner)] = condval;
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_pad_layout_transform(float* p0, float* T_layout_trans, uint8_t* global_const_workspace_2_var, uint8_t* global_workspace_3_var) {
  for (int32_t ax0_ax1_fused_ax2_fused = 0; ax0_ax1_fused_ax2_fused < 32; ++ax0_ax1_fused_ax2_fused) {
    for (int32_t ax3 = 0; ax3 < 32; ++ax3) {
      float condval;
      if (((((2 <= ax0_ax1_fused_ax2_fused) && (ax0_ax1_fused_ax2_fused < 30)) && (2 <= ax3)) && (ax3 < 30))) {
        condval = p0[(((ax0_ax1_fused_ax2_fused * 28) + ax3) - 58)];
      } else {
        condval = 0.000000e+00f;
      }
      T_layout_trans[((ax0_ax1_fused_ax2_fused * 32) + ax3)] = condval;
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default___tvm_main__(float* Input3_buffer_var, float* output_buffer_var, uint8_t* global_const_workspace_0_var, uint8_t* global_workspace_1_var) {
  void* sid_5_let = (&(global_workspace_1_var[0]));
  void* sid_6_let = (&(global_workspace_1_var[12544]));
  void* sid_1_let = (&(global_workspace_1_var[25088]));
  void* sid_4_let = (&(global_workspace_1_var[12544]));
  void* sid_2_let = (&(global_workspace_1_var[0]));
  void* sid_3_let = (&(global_workspace_1_var[25088]));
  void* sid_7_let = (&(global_workspace_1_var[0]));
  if (tvmgen_default_fused_nn_pad_layout_transform(Input3_buffer_var, sid_1_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_nn_relu(sid_1_let, sid_2_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_default_fused_nn_max_pool2d(sid_2_let, sid_3_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_default_fused_nn_pad(sid_3_let, sid_4_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_nn_relu_1(sid_4_let, sid_5_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_default_fused_nn_max_pool2d_1(sid_5_let, sid_6_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_default_fused_layout_transform_reshape(sid_6_let, sid_7_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_default_fused_nn_contrib_dense_pack_add(sid_7_let, output_buffer_var, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  return 0;
}

