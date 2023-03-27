#ifndef DEBRY_MATH_H
#define DEBRY_MATH_H

#include "vector2.h"

namespace debry {
	constexpr float PI{ 3.1415927f };

	constexpr float toDegreeF(float radian) { return radian * 180.0f / PI; }
	constexpr float toRadianF(float degree) { return degree * PI / 180.0f; }
	
	template<typename vectype>
	inline vectype DotProduct(const Vector2<vectype>& w, const Vector2<vectype>& v) {
		return { w.getX() * v.getX() + w.getY() * v.getY() };
	}
	
	template<typename vectype = float> 
	inline float RotateWrtMousePosition(const Vector2<vectype>& mouse_position, const Vector2<vectype>& object_position) {
		static Vector2<vectype> tmp{ 0.0f };
		tmp = mouse_position - object_position;
		return toDegreeF(atan2f(tmp.getY(), tmp.getX()));
	}

	inline Vector2f ShipRotation(float AngleInRadian, float speed) {
		return { sinf(AngleInRadian) * speed, -(cosf(AngleInRadian) * speed) };
	}

}

#endif
