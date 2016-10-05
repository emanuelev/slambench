/*

 Copyright (c) 2011-2013 Gerhard Reitmayr, TU Graz

 Copyright (c) 2014 University of Edinburgh, Imperial College, University of Manchester.
 Developed in the PAMELA project, EPSRC Programme Grant EP/K008730/1

 This code is licensed under the MIT License.

 */

#ifndef MATH_HELPER_H
#define MATH_HELPER_H
#include <math.h>
#include <data_types.h>
#include <data_constructors.h>

inline int max(int a, int b) {
  return a > b ? a : b;
}

inline int min(int a, int b) {
  return a < b ? a : b;
}

inline float rsqrtf(float x) {
	return 1.0f / sqrtf(x);
}

/*******************************************************************************
 * 
 * Min functions
 *
*******************************************************************************/

inline float2 fminf(float2 a, float2 b) {
	return get_float2(fminf(a.x, b.x), fminf(a.y, b.y));
}
inline float3 fminf(float3 a, float3 b) {
	return get_float3(fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z));
}
inline float4 fminf(float4 a, float4 b) {
	return get_float4(fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z),
			fminf(a.w, b.w));
}

inline int2 min(int2 a, int2 b) {
	return get_int2(min(a.x, b.x), min(a.y, b.y));
}
inline int3 min(int3 a, int3 b) {
	return get_int3(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
}
inline int4 min(int4 a, int4 b) {
	return get_int4(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z), min(a.w, b.w));
}

inline uint2 min(uint2 a, uint2 b) {
	return get_uint2(min(a.x, b.x), min(a.y, b.y));
}
inline uint3 min(uint3 a, uint3 b) {
	return get_uint3(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
}
inline uint4 min(uint4 a, uint4 b) {
	return get_uint4(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z),
			min(a.w, b.w));
}

inline uint min(uint2 a) {
	return min(a.x, a.y);
}
inline uint min(uint3 a) {
	return min(a.x, min(a.y, a.z));
}
inline uint min(uint4 a) {
	return min(min(a.x, a.y), min(a.z, a.w));
}

inline float min(float2 a) {
	return fminf(a.x, a.y);
}
inline float min(float3 a) {
	return fminf(a.x, fminf(a.y, a.z));
}
inline float min(float4 a) {
	return fminf(fminf(a.x, a.y), fminf(a.z, a.w));
}

/*******************************************************************************
 * 
 * Max functions
 *
*******************************************************************************/

inline float2 fmaxf(float2 a, float2 b) {
	return get_float2(fmaxf(a.x, b.x), fmaxf(a.y, b.y));
}
inline float3 fmaxf(float3 a, float3 b) {
	return get_float3(fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z));
}
inline float4 fmaxf(float4 a, float4 b) {
	return get_float4(fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z),
			fmaxf(a.w, b.w));
}

inline int2 max(int2 a, int2 b) {
	return get_int2(max(a.x, b.x), max(a.y, b.y));
}
inline int3 max(int3 a, int3 b) {
	return get_int3(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
}
inline int4 max(int4 a, int4 b) {
	return get_int4(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z), max(a.w, b.w));
}

inline uint2 max(uint2 a, uint2 b) {
	return get_uint2(max(a.x, b.x), max(a.y, b.y));
}
inline uint3 max(uint3 a, uint3 b) {
	return get_uint3(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
}
inline uint4 max(uint4 a, uint4 b) {
	return get_uint4(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z),
			max(a.w, b.w));
}

inline uint max(uint2 a) {
	return max(a.x, a.y);
}
inline uint max(uint3 a) {
	return max(a.x, max(a.y, a.z));
}
inline uint max(uint4 a) {
	return max(max(a.x, a.y), max(a.z, a.w));
}

inline float max(float2 a) {
	return fmaxf(a.x, a.y);
}
inline float max(float3 a) {
	return fmaxf(a.x, fmaxf(a.y, a.z));
}
inline float max(float4 a) {
	return fmaxf(fmaxf(a.x, a.y), fmaxf(a.z, a.w));
}

/*******************************************************************************
 * 
 * clamp(T val, T min, T max):
 *  val if min <= val <= max
 *  min if val < min
 *  max if val > max
 *
*******************************************************************************/

inline  float clamp(float f, float a, float b) {
	return fmaxf(a, fminf(f, b));
}
inline  int clamp(int f, int a, int b) {
	return max(a, min(f, b));
}
inline  uint clamp(uint f, uint a, uint b) {
	return max(a, min(f, b));
}

inline  float2 clamp(float2 v, float a, float b) {
	return get_float2(clamp(v.x, a, b), clamp(v.y, a, b));
}
inline  float2 clamp(float2 v, float2 a, float2 b) {
	return get_float2(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y));
}
inline  float3 clamp(float3 v, float a, float b) {
	return get_float3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
}
inline  float3 clamp(float3 v, float3 a, float3 b) {
	return get_float3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y),
			clamp(v.z, a.z, b.z));
}
inline  float4 clamp(float4 v, float a, float b) {
	return get_float4(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b),
			clamp(v.w, a, b));
}
inline  float4 clamp(float4 v, float4 a, float4 b) {
	return get_float4(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y),
			clamp(v.z, a.z, b.z), clamp(v.w, a.w, b.w));
}

inline  int2 clamp(int2 v, int a, int b) {
	return get_int2(clamp(v.x, a, b), clamp(v.y, a, b));
}
inline  int2 clamp(int2 v, int2 a, int2 b) {
	return get_int2(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y));
}
inline  int3 clamp(int3 v, int a, int b) {
	return get_int3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
}
inline  int3 clamp(int3 v, int3 a, int3 b) {
	return get_int3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y),
			clamp(v.z, a.z, b.z));
}
inline  int4 clamp(int4 v, int a, int b) {
	return get_int4(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b),
			clamp(v.w, a, b));
}
inline  int4 clamp(int4 v, int4 a, int4 b) {
	return get_int4(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y),
			clamp(v.z, a.z, b.z), clamp(v.w, a.w, b.w));
}

inline  uint2 clamp(uint2 v, uint a, uint b) {
	return get_uint2(clamp(v.x, a, b), clamp(v.y, a, b));
}
inline  uint2 clamp(uint2 v, uint2 a, uint2 b) {
	return get_uint2(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y));
}
inline  uint3 clamp(uint3 v, uint a, uint b) {
	return get_uint3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
}
inline  uint3 clamp(uint3 v, uint3 a, uint3 b) {
	return get_uint3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y),
			clamp(v.z, a.z, b.z));
}
inline  uint4 clamp(uint4 v, uint a, uint b) {
	return get_uint4(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b),
			clamp(v.w, a, b));
}
inline  uint4 clamp(uint4 v, uint4 a, uint4 b) {
	return get_uint4(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y),
			clamp(v.z, a.z, b.z), clamp(v.w, a.w, b.w));
}

/*******************************************************************************
 * 
 * absolute value
 *
*******************************************************************************/

inline float2 fabs(float2 v) {
	return get_float2(fabs(v.x), fabs(v.y));
}
inline float3 fabs(float3 v) {
	return get_float3(fabs(v.x), fabs(v.y), fabs(v.z));
}
inline float4 fabs(float4 v) {
	return get_float4(fabs(v.x), fabs(v.y), fabs(v.z), fabs(v.w));
}

inline int2 abs(int2 v) {
	return get_int2(abs(v.x), abs(v.y));
}
inline int3 abs(int3 v) {
	return get_int3(abs(v.x), abs(v.y), abs(v.z));
}
inline int4 abs(int4 v) {
	return get_int4(abs(v.x), abs(v.y), abs(v.z), abs(v.w));
}

/*******************************************************************************
 * 
 * dot product 
 *
*******************************************************************************/

template<typename T>
inline float dot(vector2<T> a, vector2<T> b) {
	return a.x * b.x + a.y * b.y;
}
template<typename T>
inline float dot(vector3<T> a, vector3<T> b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
template<typename T>
inline float dot(vector4<T> a, vector4<T> b) {
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

/*******************************************************************************
 * 
 * norm2 length 
 *
*******************************************************************************/

template<typename T>
inline float length(T v) {
	return sqrtf(dot(v, v));
}

/*******************************************************************************
 * 
 * normalization 
 *
*******************************************************************************/

template<typename T>
inline T normalize(T v) {
	float invLen = rsqrtf(dot(v, v));
	return v * invLen;
}

/*******************************************************************************
 * 
 * floor
 *
*******************************************************************************/

template<typename T>
inline float2 floorf(float2 v) {
	return get_float2(floorf(v.x), floorf(v.y));
}
inline float3 floorf(float3 v) {
	return get_float3(floorf(v.x), floorf(v.y), floorf(v.z));
}
inline float4 floorf(float4 v) {
	return get_float4(floorf(v.x), floorf(v.y), floorf(v.z), floorf(v.w));
}

/*******************************************************************************
 * 
 * fracf: it returns the fractional part of a floating point number
 *
*******************************************************************************/

inline float fracf(float v) {
	return v - floorf(v);
}
inline float2 fracf(float2 v) {
	return get_float2(fracf(v.x), fracf(v.y));
}
inline float3 fracf(float3 v) {
	return get_float3(fracf(v.x), fracf(v.y), fracf(v.z));
}
inline float4 fracf(float4 v) {
	return get_float4(fracf(v.x), fracf(v.y), fracf(v.z), fracf(v.w));
}

/*******************************************************************************
 * 
 * cross product 
 *
*******************************************************************************/


inline float3 cross(float3 a, float3 b) {
	return get_float3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x);
}

#endif
