#ifndef DEBRY_MATH_H
#define DEBRY_MATH_H

#include "vector2.h"

namespace debry::math {
	static constexpr float DEBRY_PI{ 3.1415927f };

	[[nodiscard]] inline constexpr float toDegreeF(float radian) {
		return radian * 180.0f / DEBRY_PI;
	}

	[[nodiscard]] inline constexpr float toRadianF(float degree) {
		return degree * DEBRY_PI / 180.0f;
	}
	
	[[nodiscard]] inline float DotProductF(const Vector2f& w, const Vector2f& v) {
		return { w.x * v.x + w.y * v.y };
	}

	[[nodiscard]] inline Vector2f DistanceVectorF(const Vector2f& P1, const Vector2f& P2) {
		return Vector2f{ P1 - P2 };
	}

	[[nodiscard]] inline float DistanceF(const Vector2f& P1, const Vector2f& P2) {
		return Vector2f{ P1 - P2 }.Magnitude();
	}
		
	[[nodiscard]] inline float RotateWrtMousePosition(const Vector2f& MousePosition, const Vector2f& PlayerPosition) {
		const auto& [x, y] = MousePosition - PlayerPosition;
		return toDegreeF(std::atan2(y, x));
	}

	[[nodiscard]] inline Vector2f RotateAndApplyForce(const float& AngleInDegree, const float& Speed) {
		return { std::sin(toRadianF(AngleInDegree)) * Speed, -(std::cos(toRadianF(AngleInDegree)) * Speed) };
	}

}

#endif
