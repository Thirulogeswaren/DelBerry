#ifndef DEBRY_FORCE_GENERATOR_H
#define DEBRY_FORCE_GENERATOR_H

#include "debrymath.h"
#include "particle.h"

namespace debry {
	class ForceGenerator
	{
	public:
		ForceGenerator() = default;
		virtual ~ForceGenerator() = default;
		void Update(Particle* particle) { UpdateForce(particle); }

	private:
		virtual void UpdateForce(Particle* particle) = 0;
	};

	class Gravity final : public ForceGenerator {
	public:
		Gravity() = delete;
		explicit Gravity(float y) : gravity{ 0.0f, y } { }

	private:
		Vector2f gravity;
		virtual void UpdateForce(Particle* particle) override {
			if (particle->getMass() <= 0.0f) { return; }

			particle->addForce(gravity);
		}
	};

	namespace ForceRegistry {
		void AddForce(Particle& particle, ForceGenerator& fGenerator);
		void RemoveForce(Particle& particle, ForceGenerator& fGenerator);
#ifdef DEBRY_UPDATE_AVAILABLE_FORCES
		void UpdateAvailableForces(Particle* this_inst);
#endif 

	}
}

#endif
