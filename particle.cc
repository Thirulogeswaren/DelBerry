#include "particle.h"
using namespace debry;

Particle::Particle() : position{ 0.0f }, velocity{ 0.0f }, acceleration{ 0.0f },
mass{ 0.0f }, invmass{ 0.0f }, ForceAccum{ 0.0f }, damping{ 0.9f }
{

}

Particle::~Particle()
{

}

void Particle::Integrate(float dt)
{ 
	if (mass <= 0.0f) { /* Don't Simulate 
		Particle with Zero Mass */
		return;
	}

	acceleration = ForceAccum * invmass;

	// Semi-Explicit Euler
	velocity += acceleration * dt;
	position += velocity * dt;

	velocity *= powf(damping, dt);

	acceleration.Clear();
}

