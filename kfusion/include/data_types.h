/*

 Copyright (c) 2011-2013 Gerhard Reitmayr, TU Graz

 Copyright (c) 2014 University of Edinburgh, Imperial College, University of Manchester.
 Developed in the PAMELA project, EPSRC Programme Grant EP/K008730/1

 This code is licensed under the MIT License.

 */

#ifndef DATA_TYPES_H
#define DATA_TYPES_H
#include <type_traits>

/*******************************************************************************
 *
 * Vector 4
 *
*******************************************************************************/

template<typename T>
struct vector4 {
  T x; 
  T y; 
  T z; 
  T w; 

  vector4(){
    x = T(); 
    y = T(); 
    z = T(); 
    w = T(); 
  }


  template<typename S>
  vector4(const vector4<S> val){
    x = val.x; 
    y = val.y; 
    z = val.z; 
    w = val.w; 
  }

  vector4(T _x, T _y, T _z, T _w){
    x = _x; 
    y = _y; 
    z = _z; 
    w = _w; 
  }

  typename std::enable_if<std::is_arithmetic<T>::value>::type 
    operator-() const {
      vector4<T> ret;
      ret.x = -x;
      ret.y = -y;
      ret.z = -z;
      ret.w = -w;
      return ret;
    }

  // ADDITION

  typename std::enable_if<std::is_arithmetic<T>::value, vector4<T>&>::type 
    operator+=(const T rhs) {
      x += rhs;
      y += rhs;
      z += rhs;
      w += rhs;
      return *this;
    }

  typename std::enable_if<std::is_arithmetic<T>::value, vector4<T>&>::type 
    operator+=(const vector4<T>& rhs) {
      x += rhs.x;
      y += rhs.y;
      z += rhs.z;
      w += rhs.w;
      return *this;
    }

  friend 
    typename std::enable_if<std::is_arithmetic<T>::value, vector4<T>>::type 
    operator+(vector4<T> lhs, const T& rhs) {
      lhs += rhs;
      return lhs;
    }

  friend
    typename std::enable_if<std::is_arithmetic<T>::value, vector4<T>>::type 
    operator+(vector4<T> lhs, const vector4<T>& rhs){
      lhs += rhs;
      return lhs;
    }

  // SUBTRACTION

  typename std::enable_if<std::is_arithmetic<T>::value, vector4<T>&>::type 
    operator-=(const T& rhs) {
      x -= rhs;
      y -= rhs;
      z -= rhs;
      w -= rhs;
      return *this;
    }

  typename std::enable_if<std::is_arithmetic<T>::value, vector4<T>&>::type 
    operator-=(const vector4<T>& rhs) {
      x -= rhs.x;
      y -= rhs.y;
      z -= rhs.z;
      w -= rhs.w;
      return *this;
    }

  friend
    typename std::enable_if<std::is_arithmetic<T>::value, vector4<T>>::type 
    operator-(vector4<T> lhs, const vector4<T>& rhs) {
      lhs -= rhs;
      return lhs;
    }

  friend
    typename std::enable_if<std::is_arithmetic<T>::value, vector4<T>>::type 
    operator-(vector4<T> lhs, const T& rhs) {
      lhs -= rhs;
      return lhs;
    }

  // MULTIPLICATION

  typename std::enable_if<std::is_arithmetic<T>::value, vector4<T>&>::type 
    operator*=(const T& rhs) {
      x *= rhs;
      y *= rhs;
      z *= rhs;
      w *= rhs;
      return *this;
    }

  typename std::enable_if<std::is_arithmetic<T>::value, vector4<T>&>::type 
    operator*=(const vector4<T>& rhs) {
      x *= rhs.x;
      y *= rhs.y;
      z *= rhs.z;
      w *= rhs.w;
      return *this;
    }

  friend
    typename std::enable_if<std::is_arithmetic<T>::value, vector4<T>>::type 
    operator*(vector4<T> lhs, const vector4<T>& rhs) {
      lhs *= rhs;
      return lhs;
    }

  friend
    typename std::enable_if<std::is_arithmetic<T>::value, vector4<T>>::type 
    operator*(vector4<T> lhs, const T& rhs) {
      lhs *= rhs;
      return lhs;
    }

  // DIVISION

  typename std::enable_if<std::is_arithmetic<T>::value, vector4<T>&>::type 
    operator/=(const T& rhs) {
      x /= rhs;
      y /= rhs;
      z /= rhs;
      w /= rhs;
      return *this;
    }

  typename std::enable_if<std::is_arithmetic<T>::value, vector4<T>&>::type 
    operator/=(const vector4<T>& rhs) {
      x /= rhs.x;
      y /= rhs.y;
      z /= rhs.z;
      w /= rhs.w;
      return *this;
    }

  friend
    typename std::enable_if<std::is_arithmetic<T>::value, vector4<T>>::type 
    operator/(vector4<T> lhs, const vector4<T>& rhs) {
      lhs /= rhs;
      return lhs;
    }

  friend
    typename std::enable_if<std::is_arithmetic<T>::value, vector4<T>>::type 
    operator/(vector4<T> lhs, const T& rhs) {
      lhs /= rhs;
      return lhs;
    }
};

/*******************************************************************************
 *
 * Vector 3
 *
*******************************************************************************/

template<typename T>
struct vector3 {
  T x; 
  T y; 
  T z; 

  vector3(){
    x = T(); 
    y = T(); 
    z = T(); 
  }

  template<typename S>
  vector3(const vector3<S> val){
    x = val.x; 
    y = val.y; 
    z = val.z; 
  }

  vector3(T _x, T _y, T _z){
    x = _x; 
    y = _y; 
    z = _z; 
  }

  typename std::enable_if<std::is_arithmetic<T>::value, vector3<T>>::type 
    operator-() const {
      vector3<T> ret;
      ret.x = -x;
      ret.y = -y;
      ret.z = -z;
      return ret;
    }

  // ADDITION

  typename std::enable_if<std::is_arithmetic<T>::value>::type 
    operator+=(const T& rhs) {
      x += rhs;
      y += rhs;
      z += rhs;
    }

  typename std::enable_if<std::is_arithmetic<T>::value, vector3<T>&>::type 
    operator+=(const vector3<T>& rhs) {
      x += rhs.x;
      y += rhs.y;
      z += rhs.z;
    }

  friend
    typename std::enable_if<std::is_arithmetic<T>::value, vector3<T>>::type 
    operator+(vector3<T> lhs, const T& rhs) {
      lhs += rhs;
      return lhs;
    }

  friend
    typename std::enable_if<std::is_arithmetic<T>::value, vector3<T>>::type 
    operator+(vector3<T> lhs, const vector3<T>& rhs) {
      lhs += rhs;
      return lhs;
    }

  // SUBTRACTION

  typename std::enable_if<std::is_arithmetic<T>::value, vector3<T>&>::type 
    operator-=(const T& rhs) {
      x -= rhs;
      y -= rhs;
      z -= rhs;
      return *this;
    }

  typename std::enable_if<std::is_arithmetic<T>::value, vector3<T>&>::type 
    operator-=(const vector3<T>& rhs) {
      x -= rhs.x;
      y -= rhs.y;
      z -= rhs.z;
      return *this;
    }

  friend 
    typename std::enable_if<std::is_arithmetic<T>::value, vector3<T>>::type 
    operator-(vector3<T> lhs, const vector3<T>& rhs) {
      lhs -= rhs;
      return lhs;
    }

  friend 
    typename std::enable_if<std::is_arithmetic<T>::value, vector3<T>>::type 
    operator-(vector3<T> lhs, const T& rhs) {
      lhs -= rhs;
      return lhs;
    }

  // MULTIPLICATION

  typename std::enable_if<std::is_arithmetic<T>::value, vector3<T>&>::type 
    operator*=(const T& rhs) {
      x *= rhs;
      y *= rhs;
      z *= rhs;
      return *this;
    }

  typename std::enable_if<std::is_arithmetic<T>::value, vector3<T>&>::type 
    operator*=(const vector3<T>& rhs) {
      x *= rhs.x;
      y *= rhs.y;
      z *= rhs.z;
      return *this;
    }

  friend
    typename std::enable_if<std::is_arithmetic<T>::value, vector3<T>>::type 
    operator*(vector3<T> lhs, const vector3<T>& rhs) {
      lhs *= rhs;
      return lhs;
    }

  friend
    typename std::enable_if<std::is_arithmetic<T>::value, vector3<T>>::type 
    operator*(vector3<T> lhs, const T& rhs) {
      lhs *= rhs;
      return lhs;
    }

  // DIVISION

  typename std::enable_if<std::is_arithmetic<T>::value, vector3<T>&>::type 
    operator/=(const T& rhs) {
      x /= rhs;
      y /= rhs;
      z /= rhs;
      return *this;
    }

  typename std::enable_if<std::is_arithmetic<T>::value, vector3<T>&>::type 
    operator/=(const vector3<T>& rhs) {
      x /= rhs.x;
      y /= rhs.y;
      z /= rhs.z;
      return *this;
    }

  friend
    typename std::enable_if<std::is_arithmetic<T>::value, vector3<T>>::type 
    operator/(vector3<T> lhs, const vector3<T>& rhs) {
      lhs /= rhs;
      return lhs;
    }

  friend
    typename std::enable_if<std::is_arithmetic<T>::value, vector3<T>>::type 
    operator/(vector3<T> lhs, const T& rhs) {
      lhs /= rhs;
      return lhs;
    }

};

/*******************************************************************************
 *
 * Vector 2
 *
*******************************************************************************/

template<typename T>
struct vector2 {
  T x; 
  T y; 

  vector2(){
    x = T();
  }

  template<typename S>
  vector2(const vector2<S> val){
    x = val.x; 
    y = val.y; 
  }

  vector2(T _x, T _y){
    x = _x; 
    y = _y; 
  }


  typename std::enable_if<std::is_arithmetic<T>::value, vector2<T>>::type 
    operator-() const {
      vector2<T> ret;
      ret.x = -x;
      ret.y = -y;
      return ret;
    }

  // ADDITION

  typename std::enable_if<std::is_arithmetic<T>::value, vector2<T>&>::type 
    operator+=(const T rhs) {
      x += rhs;
      y += rhs;
      return *this;
    }

  typename std::enable_if<std::is_arithmetic<T>::value, vector2<T>&>::type 
    operator+=(const vector2<T> rhs) {
      x += rhs.x;
      y += rhs.y;
      return *this;
    }

  friend
  typename std::enable_if<std::is_arithmetic<T>::value, vector2<T>>::type 
    operator+(vector2<T> lhs, const T rhs) {
      lhs += rhs;
      return lhs;
    }

  friend
    typename std::enable_if<std::is_arithmetic<T>::value, vector2<T>>::type 
    operator+(vector2<T> lhs, const vector2<T> rhs) {
      lhs += rhs;
      return lhs;
    }

  // SUBTRACTION

  typename std::enable_if<std::is_arithmetic<T>::value, vector2<T>&>::type 
    operator-=(const T rhs) {
      x -= rhs;
      y -= rhs;
      return *this;
    }

  typename std::enable_if<std::is_arithmetic<T>::value, vector2<T>&>::type 
    operator-=(const vector2<T> rhs) {
      x -= rhs.x;
      y -= rhs.y;
      return *this;
    }

  friend
    typename std::enable_if<std::is_arithmetic<T>::value, vector2<T>>::type 
    operator-(vector2<T> lhs, const vector2<T> rhs) {
      lhs -= rhs;
      return lhs;
    }

  friend
    typename std::enable_if<std::is_arithmetic<T>::value, vector2<T>>::type 
    operator-(vector2<T> lhs, const T rhs) {
      lhs -= rhs;
      return lhs;
    }

  // MULTIPLICATION

  typename std::enable_if<std::is_arithmetic<T>::value, vector2<T>&>::type 
    operator*=(const T rhs) {
      x *= rhs;
      y *= rhs;
      return *this;
    }

  typename std::enable_if<std::is_arithmetic<T>::value, vector2<T>&>::type 
    operator*=(const vector2<T> rhs) {
      x *= rhs.x;
      y *= rhs.y;
      return *this;
    }

  friend
    typename std::enable_if<std::is_arithmetic<T>::value, vector2<T>>::type 
    operator*(vector2<T> lhs, const vector2<T> rhs) {
      lhs *= rhs;
      return lhs;
    }

  friend
    typename std::enable_if<std::is_arithmetic<T>::value, vector2<T>>::type 
    operator*(vector2<T> lhs, const T rhs) {
      lhs *= rhs;
      return lhs;
    }

  // DIVISION

  typename std::enable_if<std::is_arithmetic<T>::value, vector2<T>&>::type 
    operator/=(const T rhs) {
      x /= rhs;
      y /= rhs;
      return *this;
    }

  typename std::enable_if<std::is_arithmetic<T>::value, vector2<T>&>::type 
    operator/=(const vector2<T> rhs) {
      x /= rhs.x;
      y /= rhs.y;
      return *this;
    }

  friend
    typename std::enable_if<std::is_arithmetic<T>::value, vector2<T>>::type 
    operator/(vector2<T> lhs, const vector2<T> rhs) {
      lhs /= rhs;
      return lhs;
    }

  friend
    typename std::enable_if<std::is_arithmetic<T>::value, vector2<T>>::type 
    operator/(vector2<T> lhs, const T rhs) {
      lhs /= rhs;
      return lhs;
    }
};

/*******************************************************************************
 *
 * Additional operators. 
 *
*******************************************************************************/

template<typename Scalar, typename T>
typename std::enable_if<std::is_scalar<Scalar>::value, vector3<T>>::type 
operator*(const Scalar b, const vector3<T> a){
  return vector3<T>(b * a.x, b * a.y, b * a.z);
}

template<typename Scalar, typename T>
typename std::enable_if<std::is_scalar<Scalar>::value, vector4<T>>::type 
operator*(const Scalar b, const vector4<T> a){
  return vector4<T>(b * a.x, b * a.y, b * a.z, b * a.w);
}

template<typename T>
inline vector3<T> toVec3(const vector4<T>& vec){
  return vector3<T>(vec.x, vec.y, vec.z);
}

/*******************************************************************************
 *
 * typedefs
 *
 * This follows the Open CL C lang and CUDA cutil naming convention. 
 *
*******************************************************************************/

typedef unsigned char uchar;
typedef struct vector2<char> char2;
typedef struct vector2<unsigned char> uchar2;
typedef struct vector3<char> char3;
typedef struct vector3<unsigned char> uchar3;
typedef struct vector4<char> char4;
typedef struct vector4<unsigned char> uchar4;
typedef struct vector2<short> short2;
typedef struct vector2<ushort> ushort2;
typedef struct vector3<short> short3;
typedef struct vector3<ushort> ushort3;
typedef struct vector4<short> short4;
typedef struct vector4<ushort> ushort4;
typedef struct vector2<int> int2;
typedef struct vector2<uint> uint2;
typedef struct vector3<int> int3;
typedef struct vector3<uint> uint3;
typedef struct vector4<int> int4;
typedef struct vector4<uint> uint4;
typedef struct vector2<long> long2;
typedef struct vector2<ulong> ulong2;
typedef struct vector3<long> long3;
typedef struct vector3<ulong> ulong3;
typedef struct vector4<long> long4;
typedef struct vector4<ulong> ulong4;
typedef struct vector2<float> float2;
typedef struct vector3<float> float3;
typedef struct vector4<float> float4;
typedef struct vector2<double> double2;
typedef struct vector3<double> double3;
typedef struct vector4<double> double4;

#endif
