#include "ParticleModel.h"
#include "Debug.h"

ParticleModel::ParticleModel(Transform* transform, float mass) : PhysicsModel(transform, mass)
{
	_transform = transform;
	_mass = mass;
}

void ParticleModel::Update(float deltaTime)
{
	_acceleration += _netForce / _mass;
	// velocity and position as done with constant acceleration

	//constant acceleration
	
	Vector3 position = _transform->GetPosition();
	_velocity += _acceleration * deltaTime;
	position += _velocity * deltaTime;
	_transform->SetPosition(position);

	//reset netforce after movement - recalculated every frame
	_netForce = Vector3(0, 0, 0);
	_acceleration = Vector3(0, 0, 0);
}
