#define DEBRY_UPDATE_AVAILABLE_FORCES
#include "ForceGenerator.h"

using namespace debry;

#include <map>

namespace {
	std::map<Particle*, ForceGenerator*> InForces;
}

void ForceRegistry::AddForce(Particle& particle, ForceGenerator& fGenerator)
{
	InForces.emplace(&particle, &fGenerator);
}
// FIXME: removes all forces acting on particle, if available 
void ForceRegistry::RemoveForce(Particle& particle, ForceGenerator& fGenerator)
{
	InForces.erase(&particle);
}

void ForceRegistry::UpdateAvailableForces(Particle* this_inst)
{
	for (const auto& [particle, FGenerator] : InForces) {
		if (particle == this_inst) {
			FGenerator->Update(particle);
		}
	}
}
