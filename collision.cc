#include "collision.h"

using namespace debry;

#include <vector>

namespace {
	struct ParticleBody {
		Particle* particle;
		Circle* collider;
	};

	std::vector<ParticleBody> CBodyList;
}

void Circle::AddParticle(Particle& particle)
{
	CBodyList.push_back({ &particle, this });
}

// temporary test 
void ctester::CollisionTester()
{
	for (int i{ 0 }; i < CBodyList.size() - 1; ++i) {
		for (int j{ 1 }; j < CBodyList.size(); ++j) {
			if (float sum{ 0.0f }, distance{ 0.0f }, depth{ 5.0f }; CBodyList.at(i).collider->TestCircle(*CBodyList.at(j).collider)) {
				/* calculate depth */
				distance = math::DistanceF(CBodyList[j].collider->center, CBodyList[i].collider->center);
				static Vector2f cnormal;
				cnormal = math::DistanceVectorF(CBodyList[j].collider->center, CBodyList[i].collider->center).NormalizedVector();
				sum = CBodyList[i].collider->radius + CBodyList[j].collider->radius;
				depth = sum - distance;
				std::printf("penetration: %f\n", depth);

				CBodyList[i].collider->center += cnormal * (-depth / 2.0f);
				CBodyList[j].collider->center += cnormal * (depth / 2.0f);
			}
		}
	}
}

