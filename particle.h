#ifndef DEBRY_POINT_MASSES_H
#define DEBRY_POINT_MASSES_H

#include "vector2.h"

namespace debry {
	/* point mass */
	class Particle {
		Vector2f position;
		Vector2f velocity;
		Vector2f acceleration;
		Vector2f ForceAccum;

		float mass;
		float invmass;
		float damping;
	public:
		Particle();
		~Particle();

		void Integrate(float dt);

		float GetMass() const { return mass; }
		float GetInvMass() const { return invmass; }

		float GetPositionX() const { return position.getX(); }
		float GetPositionY() const { return position.getY(); }

		float GetVelocityX() const { return velocity.getX(); }
		float GetVelocityY() const { return velocity.getY(); }

		float GetAccelerationX() const { return acceleration.getX(); }
		float GetAccelerationY() const { return acceleration.getY(); }

		void AddForce(const Vector2f& force) {
			this->ForceAccum += force;
		}
		void ClearForces() {
			ForceAccum.Clear();
		}

		Particle* SetMass(const float& mass) {
			this->mass = { mass };
			if (mass > 0.0f) {
				this->invmass = { 1.0f / mass };
			}
			return this;
		}

		Particle* SetDrag(const float& drag) {
			damping = drag;
			return this;
		}

		Particle* SetAcceleration(const Vector2f& acc) {
			this->acceleration = { acc };
			return this;
		}
	};
}

#endif
