#ifndef DEBRY_PARTICLE_BODY_H
#define DEBRY_PARTICLE_BODY_H

#include "particle.h"
#include "collision.h"

namespace debry {

	class ParticleBody final : public Particle {
	public:
		static void ParticleResolver();

		ParticleBody() : Particle{ } { }

		ParticleBody(float mass, float damping, float x, float y);

		void Integrate(float dt);

		void addCollider(Circle shape);
		
		[[nodiscard]] Circle getCollider() const { return this->ColliderType; }

		[[nodiscard]] inline bool isMovable() const { return (mass <= 0.0f || mass >= 10000.0f) ? false : true; }

	private:
		void UpdateAddedForces(Particle* this_inst);
		
		Circle ColliderType;
	};

}

#endif // !DEBRY_PARTICLE_BODY_H
