#pragma once
#include "PhysicsModel.h"

class ParticleModel : public PhysicsModel
{
protected:

public:
	ParticleModel(Transform* transform, float mass, bool simulateGravity);
	void Update(float deltaTime);
};

