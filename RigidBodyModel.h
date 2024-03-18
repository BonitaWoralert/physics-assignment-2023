#pragma once
#include "PhysicsModel.h"
class RigidBodyModel : public PhysicsModel
{
public:
	RigidBodyModel() : PhysicsModel() {}; //default
	RigidBodyModel(float mass, bool grav) : PhysicsModel(mass, grav) {}; //default

	void Update(float deltaTime) override;
};

