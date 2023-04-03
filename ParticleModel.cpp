#include "ParticleModel.h"

ParticleModel::ParticleModel(Transform* tf, float resetTime, Vector3 pertubation, bool invertGravity) : PhysicsModel(tf)
{

}

void ParticleModel::Update(float deltaTime)
{
	//particle alive time

	PhysicsModel::Update(deltaTime);
}
