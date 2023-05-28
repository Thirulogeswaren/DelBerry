#ifndef DEBRY_COLLISION_H
#define DEBRY_COLLISION_H

#include "debrymath.h"

namespace debry {
	
	struct Circle {
		Vector2f center;
		float radius;

		Circle() : center{ 0.0f }, radius{ 10.0f } { }
		Circle(float x, float y, float r) : center{ x, y }, radius{ r } { }
	};

	[[nodiscard]] inline bool isIntersecting(const Circle& C1, const Circle& C2) {
		Vector2f dist = math::DistanceVectorF(C1.center, C2.center);
		float radii = C1.radius + C2.radius;
		return { math::DotProductF(dist, dist) <= (radii * radii) };
	}

}

#endif
