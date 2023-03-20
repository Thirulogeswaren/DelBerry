#ifndef DEBRY_POINT_MASSES
#define DEBRY_POINT_MASSES

#include "vector2.h"

namespace debry {
	/* point mass */
	class Particle {
		Vector2f position;
		Vector2f velocity;
		Vector2f acceleration;

		float mass;
		float invmass;
	public:
		Particle();
		~Particle();

	};
}

#endif
