#include "particle.h"
#include "particlebody.h"

using namespace debry;

Particle::Particle() :
	mass{ 0.0f },
	invmass{ 0.0f },
	drag{ 0.999f },
	position{ 0.0f },
	velocity{ 0.0f },
	acceleration{ 0.0f },
	faccumulator{ 0.0f },
	r_acceleration{ 0.0f } { }

Particle* Particle::setMass(const float mass) {
	if (mass > 0.0f) {
		this->mass = mass;
		this->invmass = { 1.0f / mass };
	}
	return this;
}

Particle* Particle::setDrag(const float drag) {
	if (drag > 0.0f && drag <= 0.999f) {
		this->drag = drag;
	}
	return this;
}
 
ParticleBody::ParticleBody(float mass, float damping, float x, float y) : ParticleBody { }
{
	this->addCollider(Circle{ x,y,30.0f });
	this->setMass(mass)->setDrag(damping);
	this->setPosition({ x,y });
}

void ParticleBody::Integrate(float dt)
{ 
	if (mass <= 0.0f) { return; }

	this->UpdateAddedForces(this->getInstance());

	r_acceleration = acceleration;
	r_acceleration += (faccumulator * invmass);

	// Semi-Explicit Euler
	velocity += r_acceleration * dt;
	position += velocity * dt;
	ColliderType.center = position;

	velocity *= std::pow(drag, dt);

	faccumulator.clear();
}
