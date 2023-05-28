#include "ForceGenerator.h"
#include <vector>

using namespace debry;

namespace {
	struct ForceList {
		ParticleBody* particle;
		ForceGenerator* generator;
	};
	std::vector<ForceList> InForces;
}

void ForceRegistry::AddForce(ParticleBody& particle, ForceGenerator& fGenerator)
{
	InForces.push_back(ForceList{&particle, &fGenerator});
}

void ParticleBody::UpdateAddedForces(Particle* this_inst)
{
	for (const auto& [particle, FGenerator] : InForces) {
		if (particle->getInstance() == this_inst) {
			FGenerator->Update(particle->getInstance());
		}
	}
}
