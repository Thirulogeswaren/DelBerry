#include "ParticleBody.h"
#include "collision.h"
#include <vector>

using namespace debry;

namespace {
	float depth;
	Vector2f normal;
	// material type
	static constexpr float bounciness = 0.3f;
	// holds Particle Bodies 
	std::vector<ParticleBody*> ParticleList;

	void ImpulseSolver(ParticleBody* p1, ParticleBody* p2, Vector2f& normal, float depth)
	{
		static Vector2f rv;
		rv = p1->getVelocity();
		if (p2->isMovable()) {
			rv -= p2->getVelocity();
		}

		float realsv = math::DotProductF(rv, normal);

		if (realsv > 0) {
			return;
		}

		float new_sv = -(realsv * bounciness);

		float DeltaVelocity = new_sv - realsv;

		float TotalInverseMass = p1->getInvMass();
		if (p2->isMovable()) {
			TotalInverseMass += p2->getInvMass();
		}

		if (TotalInverseMass <= 0) { return; }

		float Impulse = DeltaVelocity / TotalInverseMass;

		Vector2f ImpulsePerInvMass = normal * Impulse;

		p1->setVelocity(p1->getVelocity() + ImpulsePerInvMass * p1->getInvMass());
		if (p2->isMovable()) {
			p2->setVelocity(p2->getVelocity() + ImpulsePerInvMass * (-p2->getInvMass()));
		}

	}

}

void ParticleBody::addCollider(Circle shape)
{
	this->position = shape.center;
	this->ColliderType = shape;
	ParticleList.emplace_back(this);
}

void ParticleBody::ParticleResolver() {
	for (int i{ 0 }; i < ParticleList.size() - 1; ++i) {
		for (int j{ 1 }; j < ParticleList.size(); ++j) {
			if (isIntersecting(ParticleList.at(i)->getCollider(), ParticleList.at(j)->getCollider())) {
				/* calculating depth */
				float distance = std::sqrt(math::DistanceF(ParticleList.at(i)->position, ParticleList.at(j)->position));
				// direction vector pointing from i to j
				normal = math::DistanceVectorF(ParticleList.at(i)->position, ParticleList.at(j)->position);
				normal.NormalizeIt();
				float radii = ParticleList.at(i)->getCollider().radius + ParticleList.at(j)->getCollider().radius;
				depth = radii - distance;
				// resolving position
				ParticleList.at(i)->setPosition(ParticleList.at(i)->getPosition() + normal * (depth / 2.0f));
				ParticleList.at(j)->setPosition(ParticleList.at(j)->getPosition() + normal * (-depth / 2.0f));
				
				ImpulseSolver(ParticleList[i], ParticleList[j], normal, depth);
			}
		}
	}
}
