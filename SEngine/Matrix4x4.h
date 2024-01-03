#pragma once

#include <array>

#include "Vector4.h"

/// <summary>
/// Transform <-> Matrix4x4 ��ȯ
/// float 16�� 4�ٷ� 4���� 
/// 
/// https://docs.unity3d.com/ScriptReference/Matrix4x4.html
/// transformation matrix�� ������ 3D transformations(��: �̵�, ȸ��, ������, ���� ��)�� homogenous coordinates�� ����� perspective transformations�� ������ �� �ֽ��ϴ�. 
/// ��ũ��Ʈ���� ����� ����ϴ� ���� ���� ������, ��κ� Vector3, ���ʹϾ� �� Transform Ŭ������ ����� ����ϴ� ���� �� �����մϴ�. �Ϲ� ����� nonstandard camera projection ������ ���� Ư���� ��쿡 ���˴ϴ�.
/// 240103 �̼���
/// </summary>
struct Matrix4x4
{
	// Static Properties
	static const Matrix4x4 Identity;
	static const Matrix4x4 Zero;
	static constexpr unsigned int RowCount = 4;

	// Properties
	std::array<Vector4, RowCount> Rows;
};

