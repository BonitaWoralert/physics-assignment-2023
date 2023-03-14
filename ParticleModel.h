#pragma once
#include "PhysicsModel.h"

class ParticleModel : public PhysicsModel
{
protected:

public:
	ParticleModel(Transform* transform, float mass);
	void Update(float deltaTime);
};

