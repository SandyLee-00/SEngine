#pragma once

#include <xmmintrin.h>

/// <summary>
/// Math::__ �ؼ� ��� 
/// static ����, �Լ�, ���ø� �Լ��� ��Ƶд� 
/// 
/// 240103 �̼���
/// </summary>
struct Math
{
	static constexpr float PI = { 3.14159265358979323846f };

	// Linear Interpolation: �� �� ������ ���� ���������� �������ִ� �Լ�
	template<class T>
	static constexpr T Lerp(const T& start, const T& end, float alpha)
	{
		return (T)(start + alpha * (end - start));
	}

	// Degree -> Radian: ������ �������� ��ȯ���ִ� �Լ�
	static constexpr float ToRadian(float degree)
	{
		return degree * PI / 180.0f;
	}

	// Radian -> Degree: ������ ������ ��ȯ���ִ� �Լ�
	static constexpr float ToDegree(float radian)
	{
		return radian * 180.0f / PI;
	}

	// �𸮾� ���� �ڵ忡�� ������. ��� �������� ����
	// Inverse Square Root: �������� ������ ���ϴ� �Լ�
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
};