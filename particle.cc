#include "particle.h"

using namespace debry;

Particle::Particle() : position{ 0.0f }, velocity{ 0.0f }, acceleration{ 0.0f },
ForceAccum{ 0.0f }, mass{ 0.0f }, invmass{ 0.0f }, damping{ 0.9f }, res_acceleration{ 0.0f }
{

}

void Particle::Integrate(float dt)
{ 
	if (mass <= 0.0f) { /* Don't Simulate 
		Particle with Zero Mass */
		return;
	}

	res_acceleration = { acceleration };
	res_acceleration += ForceAccum * invmass;

	// Semi-Explicit Euler
	velocity += res_acceleration * dt;
	position += velocity * dt;

	velocity *= powf(damping, dt);

	ForceAccum.Clear();
}

Particle* Particle::SetMass(const float& mass_) {
	this->mass = { mass_ };
	if (mass > 0.0f) {
		this->invmass = { 1.0f / mass };
	}
	return this;
}

Particle* Particle::SetDrag(const float& drag) {
	damping = drag;
	return this;
}

Particle* Particle::SetPosition(const Vector2f& position_) {
	this->position = { position_ };
	return this;
}

Particle* Particle::SetVelocity(const Vector2f& velocity_) {
	this->velocity = { velocity_ };
	return this;
}

Particle* Particle::SetAcceleration(const Vector2f& acceleration_) {
	this->acceleration = { acceleration_ };
	return this;
}

void Particle::AddForce(const Vector2f& force) {
	this->ForceAccum += force;
}

void Particle::ClearForces() {
	ForceAccum.Clear();
}
