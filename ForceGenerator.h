#ifndef DEBRY_FORCE_GENERATOR_H
#define DEBRY_FORCE_GENERATOR_H

#include "debrymath.h"
#include "particlebody.h"

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

			particle->addForce(gravity * particle->getMass());
		}
	};

	namespace ForceRegistry {
		void AddForce(ParticleBody& particle, ForceGenerator& fGenerator);
	}
}

#endif
