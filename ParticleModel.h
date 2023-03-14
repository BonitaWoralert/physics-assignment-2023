#pragma once
#include "PhysicsModel.h"

class ParticleModel : public PhysicsModel
{
protected:
	Transform* _transform;
	float _mass = 1.0f;
public:
	ParticleModel(Transform* transform);
	void Update(float deltaTime);
};

