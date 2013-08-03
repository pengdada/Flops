/* flops.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 10/21/2011
 * Last Modified    : 01/25/2012
 * 
 * 
 * 
 * And of course... The typical copyright stuff...
 * 
 *      Redistribution of this program in both source or binary, regardless of
 *  form, with or without modification is permitted as long as the following
 *  conditions are met:
 *          1.  This copyright notice is maintained either inline in the source
 *              or distributed with the binary.
 *          2.  A list of all contributing authors along with their contributions
 *              is included either inline in the source or distributed with the
 *              binary.
 *          3.  The following disclaimer is maintained either inline in the
 *              source or distributed with the binary.
 * 
 *  Disclaimer:
 *  This software is provided "as is", without any guarantee made to its
 *  suitability or fitness for any particular use. It may contain bugs so use
 *  of this program is at your own risk. I take no responsibility for any
 *  damage that may unintentionally be caused through its use.
 */

#ifndef _flops_h
#define _flops_h
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#include "tools.h"
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  x86 vs. x64
#if (defined _M_X64) || (defined __x86_64)
#define arch_x64
#define arch_name0 "x64 "
#else
#define arch_name0 "x86 "
#endif
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  SIMD
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#ifdef x86_FMA4
#define arch_name (arch_name0 "FMA4")
void test_dp_add_AVX(int tds,size_t iterations);
void test_dp_mul_AVX(int tds,size_t iterations);
void test_dp_mac_AVX(int tds,size_t iterations);
void test_dp_fma_FMA4(int tds,size_t iterations);
#endif
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#ifdef x86_AVX
#define arch_name (arch_name0 "AVX")
void test_dp_add_AVX(int tds,size_t iterations);
void test_dp_mul_AVX(int tds,size_t iterations);
void test_dp_mac_AVX(int tds,size_t iterations);
#endif
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#ifdef x86_SSE2
#define arch_name (arch_name0 "SSE2")
void test_dp_add_SSE2(int tds,size_t iterations);
void test_dp_mul_SSE2(int tds,size_t iterations);
void test_dp_mac_SSE2(int tds,size_t iterations);
#endif
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#endif
