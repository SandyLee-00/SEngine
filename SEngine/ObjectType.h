#pragma once

enum class ObjectType
{
	Background, // 가장 밑 레이어
	BackgroundObject, // 배경 오브젝트
	Object, // 일반 오브젝트
	Enemy, // 적
	Player, // 플레이어
	Effect, // 이펙트
	UI, // UI
	End = 32 // 가장 위 레이어
};