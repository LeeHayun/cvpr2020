// Copyright The Fast Sparse ConvNets Authors.
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

void f32_spmm_ukernel_8x1__scalar(
    uint32_t m,
    uint32_t n,
    const float*restrict a,
    const float*restrict weights,
    const int32_t*restrict widx_dmap,
    const uint32_t*restrict nidx_nnzmap,
    float*restrict c,
    const union f32_output_params params[restrict static 1])
{
  assert(m != 0);

  const float vmin = params->scalar.min;
  const float vmax = params->scalar.max;
  size_t i = m;
  while (i >= 8) {
    const float*restrict w = weights;
    const int32_t* dmap = widx_dmap;
    const uint32_t* nnzmap = nidx_nnzmap;
    size_t j = n;
    do {
      uint32_t nnz = *nnzmap++;
      float vacc0 = *w++;
      float vacc1 = vacc0;
      float vacc2 = vacc0;
      float vacc3 = vacc0;
      float vacc4 = vacc0;
      float vacc5 = vacc0;
      float vacc6 = vacc0;
      float vacc7 = vacc0;
      if (nnz != 0) {
        do {
          const intptr_t diff = *dmap++;
          const float va0 = a[0];
          const float va1 = a[1];
          const float va2 = a[2];
          const float va3 = a[3];
          const float va4 = a[4];
          const float va5 = a[5];
          const float va6 = a[6];
          const float va7 = a[7];
          a = (const float*restrict) ((uintptr_t) a + (uintptr_t) diff);
          const float vb = *w++;
          vacc0 += va0 * vb;
          vacc1 += va1 * vb;
          vacc2 += va2 * vb;
          vacc3 += va3 * vb;
          vacc4 += va4 * vb;
          vacc5 += va5 * vb;
          vacc6 += va6 * vb;
          vacc7 += va7 * vb;
        } while (--nnz != 0);
      }
      float vout0 = math_min_f32(vacc0, vmax);
      float vout1 = math_min_f32(vacc1, vmax);
      float vout2 = math_min_f32(vacc2, vmax);
      float vout3 = math_min_f32(vacc3, vmax);
      float vout4 = math_min_f32(vacc4, vmax);
      float vout5 = math_min_f32(vacc5, vmax);
      float vout6 = math_min_f32(vacc6, vmax);
      float vout7 = math_min_f32(vacc7, vmax);
      vout0 = math_max_f32(vout0, vmin);
      vout1 = math_max_f32(vout1, vmin);
      vout2 = math_max_f32(vout2, vmin);
      vout3 = math_max_f32(vout3, vmin);
      vout4 = math_max_f32(vout4, vmin);
      vout5 = math_max_f32(vout5, vmin);
      vout6 = math_max_f32(vout6, vmin);
      vout7 = math_max_f32(vout7, vmin);
      c[0] = vout0;
      c[1] = vout1;
      c[2] = vout2;
      c[3] = vout3;
      c[4] = vout4;
      c[5] = vout5;
      c[6] = vout6;
      c[7] = vout7;
      c += m;
    } while (--j != 0);
    c -= m * n;
    c += 8;
    a += 8;
    i -= 8;
  }
  if (i != 0) {
    if (i & 4) {
      const float*restrict w = weights;
      const int32_t* dmap = widx_dmap;
      const uint32_t* nnzmap = nidx_nnzmap;
      size_t j = n;
      do {
        uint32_t nnz = *nnzmap++;
        float vacc0 = *w++;
        float vacc1 = vacc0;
        float vacc2 = vacc0;
        float vacc3 = vacc0;
        if (nnz != 0) {
          do {
            const intptr_t diff = *dmap++;
            const float va0 = a[0];
            const float va1 = a[1];
            const float va2 = a[2];
            const float va3 = a[3];
            a = (const float*restrict) ((uintptr_t) a + (uintptr_t) diff);
            const float vb = *w++;
            vacc0 += va0 * vb;
            vacc1 += va1 * vb;
            vacc2 += va2 * vb;
            vacc3 += va3 * vb;
          } while (--nnz != 0);
        }
        float vout0 = math_min_f32(vacc0, vmax);
        float vout1 = math_min_f32(vacc1, vmax);
        float vout2 = math_min_f32(vacc2, vmax);
        float vout3 = math_min_f32(vacc3, vmax);
        vout0 = math_max_f32(vout0, vmin);
        vout1 = math_max_f32(vout1, vmin);
        vout2 = math_max_f32(vout2, vmin);
        vout3 = math_max_f32(vout3, vmin);
        c[0] = vout0;
        c[1] = vout1;
        c[2] = vout2;
        c[3] = vout3;
        c += m;
      } while (--j != 0);
      c -= m * n;
      c += 4;
      a += 4;
    }
    if (i & 2) {
      const float*restrict w = weights;
      const int32_t* dmap = widx_dmap;
      const uint32_t* nnzmap = nidx_nnzmap;
      size_t j = n;
      do {
        uint32_t nnz = *nnzmap++;
        float vacc0 = *w++;
        float vacc1 = vacc0;
        if (nnz != 0) {
          do {
            const intptr_t diff = *dmap++;
            const float va0 = a[0];
            const float va1 = a[1];
            a = (const float*restrict) ((uintptr_t) a + (uintptr_t) diff);
            const float vb = *w++;
            vacc0 += va0 * vb;
            vacc1 += va1 * vb;
          } while (--nnz != 0);
        }
        float vout0 = math_min_f32(vacc0, vmax);
        float vout1 = math_min_f32(vacc1, vmax);
        vout0 = math_max_f32(vout0, vmin);
        vout1 = math_max_f32(vout1, vmin);
        c[0] = vout0;
        c[1] = vout1;
        c += m;
      } while (--j != 0);
      c -= m * n;
      c += 2;
      a += 2;
    }
    if (i & 1) {
      const float*restrict w = weights;
      const int32_t* dmap = widx_dmap;
      const uint32_t* nnzmap = nidx_nnzmap;
      size_t j = n;
      do {
        uint32_t nnz = *nnzmap++;
        float vacc0 = *w++;
        if (nnz != 0) {
          do {
            const intptr_t diff = *dmap++;
            const float va0 = a[0];
            a = (const float*restrict) ((uintptr_t) a + (uintptr_t) diff);
            const float vb = *w++;
            vacc0 += va0 * vb;
          } while (--nnz != 0);
        }
        float vout0 = math_min_f32(vacc0, vmax);
        vout0 = math_max_f32(vout0, vmin);
        c[0] = vout0;
        c += m;
      } while (--j != 0);
      c -= m * n;
      c += 1;
      a += 1;
    }
  }
}
