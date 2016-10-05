/*

 Copyright (c) 2011-2013 Gerhard Reitmayr, TU Graz

 Copyright (c) 2014 University of Edinburgh, Imperial College, University of Manchester.
 Developed in the PAMELA project, EPSRC Programme Grant EP/K008730/1

 This code is licensed under the MIT License.

 */

#ifndef DATA_CONSTRUCTORS_H
#define DATA_CONSTRUCTORS_H

/*******************************************************************************
 * 
 * Data constructors
 *
*******************************************************************************/

inline uint4 get_uint4(unsigned int x, unsigned int y, unsigned int z,
		unsigned int w) {

	uint4 val;
	val.x = x;
	val.y = y;
	val.z = z;
	val.w = w;
	return val;
}

inline int4 get_int4(int x, int y, int z, int w) {

	int4 val;
	val.x = x;
	val.y = y;
	val.z = z;
	val.w = w;
	return val;
}
inline uint3 get_uint3(unsigned int x, unsigned int y, unsigned int z) {

	uint3 val;
	val.x = x;
	val.y = y;
	val.z = z;
	return val;
}
inline short2 get_short2(short x, short y) {
	short2 val;
	val.x = x;
	val.y = y;
	return val;
}

inline int3 get_int3(int x, int y, int z) {

	int3 val;
	val.x = x;
	val.y = y;
	val.z = z;
	return val;
}

inline float4 get_float4(float x, float y, float z, float w) {

	float4 val;
	val.x = x;
	val.y = y;
	val.z = z;
	val.w = w;
	return val;
}
inline float3 get_float3(float x, float y, float z) {

	float3 val;
	val.x = x;
	val.y = y;
	val.z = z;
	return val;
}
inline float2 get_float2(float x, float y) {
	float2 val;
	val.x = x;
	val.y = y;
	return val;
}
inline int2 get_int2(int x, int y) {
	int2 val;
	val.x = x;
	val.y = y;
	return val;
}
inline uint2 get_uint2(unsigned int x, unsigned int y) {
	uint2 val;
	val.x = x;
	val.y = y;
	return val;
}
inline uchar3 get_uchar3(unsigned char x, unsigned char y, unsigned char z) {
	uchar3 val;
	val.x = x;
	val.y = y;
	val.z = z;
	return val;
}
inline uchar4 get_uchar4(unsigned char x, unsigned char y, unsigned char z,
		unsigned char w) {
	uchar4 val;
	val.x = x;
	val.y = y;
	val.z = z;
	val.w = w;
	return val;
}
inline  float2 get_float2(float s) {
	return get_float2(s, s);
}
inline  float2 get_float2(float3 a) {
	return get_float2(a.x, a.y);
}
inline  float2 get_float2(int2 a) {
	return get_float2(float(a.x), float(a.y));
}
inline  float2 get_float2(uint2 a) {
	return get_float2(float(a.x), float(a.y));
}

inline  int2 get_int2(int s) {
	return get_int2(s, s);
}
inline  int2 get_int2(int3 a) {
	return get_int2(a.x, a.y);
}
inline  int2 get_int2(uint2 a) {
	return get_int2(int(a.x), int(a.y));
}
inline  int2 get_int2(float2 a) {
	return get_int2(int(a.x), int(a.y));
}

inline  uint2 get_uint2(uint s) {
	return get_uint2(s, s);
}
inline  uint2 get_uint2(uint3 a) {
	return get_uint2(a.x, a.y);
}
inline  uint2 get_uint2(int2 a) {
	return get_uint2(uint(a.x), uint(a.y));
}

inline  float3 get_float3(float s) {
	return get_float3(s, s, s);
}
inline  float3 get_float3(float2 a) {
	return get_float3(a.x, a.y, 0.0f);
}
inline  float3 get_float3(float2 a, float s) {
	return get_float3(a.x, a.y, s);
}
inline  float3 get_float3(float4 a) {
	return get_float3(a.x, a.y, a.z);
}
inline  float3 get_float3(int3 a) {
	return get_float3(float(a.x), float(a.y), float(a.z));
}
inline  float3 get_float3(uint3 a) {
	return get_float3(float(a.x), float(a.y), float(a.z));
}

inline  int3 get_int3(int s) {
	return get_int3(s, s, s);
}
inline  int3 get_int3(int2 a) {
	return get_int3(a.x, a.y, 0);
}
inline  int3 get_int3(int2 a, int s) {
	return get_int3(a.x, a.y, s);
}
inline  int3 get_int3(uint3 a) {
	return get_int3(int(a.x), int(a.y), int(a.z));
}
inline  int3 get_int3(float3 a) {
	return get_int3(int(a.x), int(a.y), int(a.z));
}

inline  uint3 get_uint3(uint s) {
	return get_uint3(s, s, s);
}
inline  uint3 get_uint3(uint2 a) {
	return get_uint3(a.x, a.y, 0);
}
inline  uint3 get_uint3(uint2 a, uint s) {
	return get_uint3(a.x, a.y, s);
}
inline  uint3 get_uint3(uint4 a) {
	return get_uint3(a.x, a.y, a.z);
}
inline  uint3 get_uint3(int3 a) {
	return get_uint3(uint(a.x), uint(a.y), uint(a.z));
}

inline  float4 get_float4(float s) {
	return get_float4(s, s, s, s);
}
inline  float4 get_float4(float3 a) {
	return get_float4(a.x, a.y, a.z, 0.0f);
}
inline  float4 get_float4(float3 a, float w) {
	return get_float4(a.x, a.y, a.z, w);
}
inline  float4 get_float4(int4 a) {
	return get_float4(float(a.x), float(a.y), float(a.z), float(a.w));
}
inline  float4 get_float4(uint4 a) {
	return get_float4(float(a.x), float(a.y), float(a.z), float(a.w));
}

inline  int4 get_int4(int s) {
	return get_int4(s, s, s, s);
}
inline  int4 get_int4(int3 a) {
	return get_int4(a.x, a.y, a.z, 0);
}
inline  int4 get_int4(int3 a, int w) {
	return get_int4(a.x, a.y, a.z, w);
}
inline  int4 get_int4(uint4 a) {
	return get_int4(int(a.x), int(a.y), int(a.z), int(a.w));
}
inline  int4 get_int4(float4 a) {
	return get_int4(int(a.x), int(a.y), int(a.z), int(a.w));
}

inline  uint4 get_uint4(uint s) {
	return get_uint4(s, s, s, s);
}
inline  uint4 get_uint4(uint3 a) {
	return get_uint4(a.x, a.y, a.z, 0);
}
inline  uint4 get_uint4(uint3 a, uint w) {
	return get_uint4(a.x, a.y, a.z, w);
}
inline  uint4 get_uint4(int4 a) {
	return get_uint4(uint(a.x), uint(a.y), uint(a.z), uint(a.w));
}
#endif
