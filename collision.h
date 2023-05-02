#ifndef DEBRY_COLLISION_H
#define DEBRY_COLLISION_H

#include "debrymath.h"
#include "particle.h"

namespace debry {

	struct Circle {
		Vector2f center;
		float radius;
		
		Circle(float x, float y, float r) : center{ x, y }, radius{ r } { }
		void AddParticle(Particle& particle);

		inline bool TestCircle(Circle& C2) {
			Vector2f dist = math::DistanceVectorF(center, C2.center);
			float radii = radius + C2.radius;
			return { math::DotProductF(dist, dist) <= (radii * radii) };
		}
	};

	namespace ctester {
		void CollisionTester();
	}

}

#endif
