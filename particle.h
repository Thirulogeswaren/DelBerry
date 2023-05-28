#ifndef DEBRY_POINT_MASS_H
#define DEBRY_POINT_MASS_H

#include "vector2.h"

namespace debry {
	class Particle {
	public:
		Particle();

		Particle* setMass(const float mass);

		Particle* setDrag(const float drag);

		Particle* setPosition(const Vector2f& other) { position = other; return this; }

		Particle* setVelocity(const Vector2f& other) { velocity = other; return this; }

		Particle* setAcceleration(const Vector2f& other) { acceleration = other; return this; }

		[[nodiscard]] inline float getMass() const { return mass; }

		[[nodiscard]] inline float getInvMass() const { return invmass; }

		[[nodiscard]] inline float getDrag() const { return drag; }

		[[nodiscard]] Vector2f getPosition() const { return position; }

		[[nodiscard]] Vector2f getVelocity() const { return velocity; }

		[[nodiscard]] Vector2f getAcceleration() const { return acceleration; }

		inline void addForce(const Vector2f& force) { faccumulator += force; }
		
		inline void clearForces() { faccumulator.clear(); }
	protected:
		inline Particle* getInstance() { return this; }

	protected:
		float mass;
		float invmass;
		float drag;
		Vector2f position;
		Vector2f velocity;
		Vector2f acceleration;
		Vector2f faccumulator;

		Vector2f r_acceleration;
	};
}

#endif
