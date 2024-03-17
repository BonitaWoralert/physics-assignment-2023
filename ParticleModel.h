#pragma once
#include "PhysicsModel.h"
class ParticleModel : public PhysicsModel
{
public:
	ParticleModel() : PhysicsModel() {}; //default
	ParticleModel(float mass, bool grav) : PhysicsModel(mass, grav) {}; //default

	ParticleModel(float resetTime, Vector3 pertubation, bool invertGravity); //particle constructor

	void Update(float deltaTime) override;
};

