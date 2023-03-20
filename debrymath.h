#ifndef DEBRY_MATH_H
#define DEBRY_MATH_H

#include "Vector2.h"

namespace debry {
	constexpr float PI{ 3.1415927f };

	constexpr float toDegreeF(float radian) { return radian * 180.0f / PI; }
	constexpr float toRadianF(float degree) { return degree * PI / 180.0f; }
	
	template<class ctype>
	ctype DotProduct(const Vector2<ctype>& w, const Vector2<ctype>& v) {
		return { w.getX() * v.getX() + w.getY() * v.getY() };
	}


}

#endif
