#include "particle.h"

using namespace debry;

Particle::Particle() : position{ }, velocity{ }, acceleration{ }, AccumulatedForce{ },
mass{ 0.0f }, invmass{ 0.0f }, damping{ 0.9f }, ResultingForce{ } { }

void Particle::Integrate(float dt)
{ 
	if (mass <= 0.0f) { /* Don't Simulate 
		Particle with Zero Mass */
		return;
	}

	AccumulatedForce += acceleration;
	ResultingForce = AccumulatedForce * invmass;

	// Semi-Explicit Euler
	velocity += ResultingForce * dt;
	position += velocity * dt;

	velocity *= std::pow(damping, dt);

	clearForces();
}

Particle* Particle::setMass(const float& weight) {
	this->mass = { weight };
	if (mass > 0.0f) {
		this->invmass = { 1.0f / mass };
	}
	return this;
}
