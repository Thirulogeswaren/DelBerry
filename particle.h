#ifndef DEBRY_POINT_MASS_H
#define DEBRY_POINT_MASS_H

#include "vector2.h"

namespace debry {
	class Particle {
	public:
		Particle() = default;
		explicit Particle(float s) : Particle{ { s, s } } { }
		explicit Particle(Vector2f ParticlePosition) : position{ ParticlePosition } { }

		void Integrate(float dt);

		[[nodiscard]] Vector2f getPosition() const { return position; }
		[[nodiscard]] Vector2f getVelocity() const { return velocity; }
		[[nodiscard]] Vector2f getAcceleration() const { return res_acceleration; }

		[[nodiscard]] float getMass() const { return mass; }
		[[nodiscard]] float getInvMass() const { return invmass; }

		Particle* setPosition(const Vector2f& other) { position = other; return this; }
		Particle* setVelocity(const Vector2f& other) { velocity = other; return this; }
		Particle* setAcceleration(const Vector2f& other) { res_acceleration = other; return this; }

		Particle* setMass(const float& weight);
		Particle* setDrag(const float& drag) { damping = drag; return this; }

		inline void addForce(const Vector2f& force) { faccumulator += force; }
		inline void clearForces() { faccumulator.Zero(); }

	private:
		Vector2f position{ 0.0f }, velocity{ 0.0f }, acceleration{ 0.0f };
		Vector2f faccumulator{ 0.0f }; /* holds net force */

		float mass{ 0.0f }, invmass{ 0.0f };
		float damping{ 0.9f };
		Vector2f res_acceleration{ 0.0f };
	};
}

#endif
