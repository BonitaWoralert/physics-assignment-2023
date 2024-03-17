#pragma once
#include "PhysicsModel.h"
class ParticleModel : public PhysicsModel
{
public:
	ParticleModel(Transform* t) : PhysicsModel(t) {}; //default
	ParticleModel(Transform* t, float resetTime, Vector3 pertubation, bool invertGravity); //particle constructor

	void Update(float deltaTime) override;
};

