#pragma once
#include "PhysicsModel.h"

class ParticleModel : public PhysicsModel
{
public:
	ParticleModel(Transform* tf) : PhysicsModel(tf) {}; //default
	ParticleModel(Transform* tf, float resetTime, Vector3 pertubation, bool invertGravity);

	void Update(float deltaTime) override;
};

