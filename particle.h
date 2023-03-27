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
		Vector2f ForceAccum;

		float mass;
		float invmass;
		float damping;
		Vector2f res_acceleration;
	public:
		Particle();

		void Integrate(float dt);

		float GetMass() const { return mass; }
		float GetInvMass() const { return invmass; }

		float GetPositionX() const { return position.getX(); }
		float GetPositionY() const { return position.getY(); }
		Vector2f PositionVector() const { return position; }

		float GetVelocityX() const { return velocity.getX(); }
		float GetVelocityY() const { return velocity.getY(); }
		Vector2f VelocityVector() const { return velocity; }

		float GetAccelerationX() const { return acceleration.getX(); }
		float GetAccelerationY() const { return acceleration.getY(); }
		Vector2f AccelerationVector() const { return acceleration; }

		Particle* SetPosition(const Vector2f& position_);
		Particle* SetVelocity(const Vector2f& velocity_);
		Particle* SetAcceleration(const Vector2f& acceleration_);

		Particle* SetMass(const float& mass_);
		Particle* SetDrag(const float& drag);

		void AddForce(const Vector2f& force);
		void ClearForces();
	};
}

#endif
