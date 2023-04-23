#include "particle.h"
#define DEBRY_UPDATE_AVAILABLE_FORCES
#include "ForceGenerator.h"

using namespace debry;

void Particle::Integrate(float dt)
{ 
	if (mass <= 0.0f) { /* Don't Simulate 
		Particle with Zero Mass */
		return;
	}

	ForceRegistry::UpdateAvailableForces(this);

	faccumulator += acceleration;
	res_acceleration = faccumulator * mass;

	// Semi-Explicit Euler
	velocity += res_acceleration * dt;
	position += velocity * dt;

	velocity *= std::pow(damping, dt);

	faccumulator.Zero();
}

Particle* Particle::setMass(const float& weight) {
	this->mass = { weight };
	if (mass > 0.0f) {
		this->invmass = { 1.0f / mass };
	}
	else { invmass = 0.0f; }
	return this;
}
