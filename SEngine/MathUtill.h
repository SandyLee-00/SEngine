#pragma once

#include <xmmintrin.h>
#include <cmath>

/// <summary>
/// Math::__ 해서 사용 
/// static 변수, 함수, 템플릿 함수를 담아둔다 
/// 
/// https://docs.unrealengine.com/4.26/en-US/API/Runtime/Core/GenericPlatform/FGenericPlatformMath/
/// 
/// 240103 이서영
/// </summary>
struct Math
{
	static constexpr float PI = { 3.14159265358979323846f };
	static constexpr float SMALL_NUMBER = { 1.e-8f };

	/// <summary>
	///  Linear Interpolation: 두 값 사이의 값을 선형적으로 보간
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="start"></param>
	/// <param name="end"></param>
	/// <param name="alpha"></param>
	/// <returns></returns>
	template<class T>
	static constexpr T Lerp(const T& start, const T& end, float alpha)
	{
		return (T)(start + alpha * (end - start));
	}

	/// <summary>
	/// Degree -> Radian: 각도를 라디안으로 변환
	/// </summary>
	/// <param name="degree"></param>
	/// <returns></returns>
	static constexpr float ToRadian(float degree)
	{
		return degree * PI / 180.0f;
	}
	
	/// <summary>
	/// Radian -> Degree: 라디안을 각도로 변환
	/// </summary>
	/// <param name="radian"></param>
	/// <returns></returns>
	static constexpr float ToDegree(float radian)
	{
		return radian * 180.0f / PI;
	}

	/// <summary>
	/// X % Y: float형의 나머지 연산
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <returns></returns>
	static float FModuler(float x, float y)
	{
		if (fabsf(y) <= SMALL_NUMBER)
		{
			return 0.f;
		}
		const float quotient = (float)TruncToInt(x / y);
		float intPortion = y * quotient;
		if (fabsf(intPortion) > fabsf(x))
		{
			intPortion = x;
		}

		return (x - intPortion);
	}

	/// <summary>
	/// 언리얼 엔진 코드에서 가져옴. 고속 역제곱근 공식
	/// Inverse Square Root: 제곱근의 역수를 구하기
	/// </summary>
	/// <param name="InFloat"></param>
	/// <returns></returns>
	static float InvSqrt(float InFloat)
	{
		// Performs two passes of Newton-Raphson iteration on the hardware estimate
		//    v^-0.5 = x
		// => x^2 = v^-1
		// => 1/(x^2) = v
		// => F(x) = x^-2 - v
		//    F'(x) = -2x^-3

		//    x1 = x0 - F(x0)/F'(x0)
		// => x1 = x0 + 0.5 * (x0^-2 - Vec) * x0^3
		// => x1 = x0 + 0.5 * (x0 - Vec * x0^3)
		// => x1 = x0 + x0 * (0.5 - 0.5 * Vec * x0^2)
		//
		// This final form has one more operation than the legacy factorization (X1 = 0.5*X0*(3-(Y*X0)*X0)
		// but retains better accuracy (namely InvSqrt(1) = 1 exactly).

		const __m128 fOneHalf = _mm_set_ss(0.5f);
		__m128 Y0, X0, X1, X2, FOver2;
		float temp;

		Y0 = _mm_set_ss(InFloat);
		X0 = _mm_rsqrt_ss(Y0);	// 1/sqrt estimate (12 bits)
		FOver2 = _mm_mul_ss(Y0, fOneHalf);

		// 1st Newton-Raphson iteration
		X1 = _mm_mul_ss(X0, X0);
		X1 = _mm_sub_ss(fOneHalf, _mm_mul_ss(FOver2, X1));
		X1 = _mm_add_ss(X0, _mm_mul_ss(X0, X1));

		// 2nd Newton-Raphson iteration
		X2 = _mm_mul_ss(X1, X1);
		X2 = _mm_sub_ss(fOneHalf, _mm_mul_ss(FOver2, X2));
		X2 = _mm_add_ss(X1, _mm_mul_ss(X1, X2));

		_mm_store_ss(&temp, X2);
		return temp;
	}

	/// <summary>
	/// float -> 소수점 뒤자리 잘린 int 반환
	/// </summary>
	/// <param name="inFloat"></param>
	/// <returns></returns>
	static constexpr int TruncToInt(float inFloat)
	{
		return (int)inFloat;
	}

	/// <summary>
	/// float1 == float2: 두 값이 같은지 비교
	/// </summary>
	/// <param name="InFloat1"></param>
	/// <param name="InFloat2"></param>
	/// <param name="InTolerance"></param>
	/// <returns></returns>
	static bool EqualsInTolerance(float InFloat1, float InFloat2, float InTolerance = SMALL_NUMBER)
	{
		return abs(InFloat1 - InFloat2) <= InTolerance;
	}
};