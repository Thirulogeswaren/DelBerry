#include "particle.h"

debry::Particle::Particle() :
	position{ 0.0f }, velocity{ 0.0f }, acceleration{ 0.0f },
	mass{ 0.0f }, invmass{ 0.0f }
{

}

debry::Particle::~Particle()
{
}
