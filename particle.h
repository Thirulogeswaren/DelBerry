#ifndef DEBRY_POINT_MASS_H
#define DEBRY_POINT_MASS_H

#include "vector2.h"

namespace debry {
	/* point mass */
	class Particle {
	private:
		Vector2f position;
		Vector2f velocity;
		Vector2f acceleration;
		Vector2f AccumulatedForce;

		float mass;
		float invmass;
		float damping;
		Vector2f ResultingForce;
	public:
		Particle();

		void Integrate(float dt);

		[[nodiscard]] Vector2f getPosition() const { return position; }
		[[nodiscard]] Vector2f getVelocity() const { return velocity; }
		[[nodiscard]] Vector2f getAcceleration() const { return acceleration; }

		[[nodiscard]] float getMass() const { return mass; }
		[[nodiscard]] float getInvMass() const { return invmass; }

		Particle* setPosition(const Vector2f& other) { position = other; return this; }
		Particle* setAcceleration(const Vector2f& other) { acceleration = other; return this; }

		Particle* setMass(const float& weight);
		Particle* setDrag(const float& drag) { damping = drag; return this; }

		inline void addForce(const Vector2f& force) { AccumulatedForce += force; }
		inline void clearForces() { AccumulatedForce.Zero(); }
	};
}

#endif
