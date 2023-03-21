#include "ParticleModel.h"
#include "Debug.h"

ParticleModel::ParticleModel(Transform* transform, float mass, bool simulateGravity) : PhysicsModel(transform, mass, simulateGravity)
{
	_transform = transform;
	_mass = mass;
	_simulateGravity = simulateGravity;
}

void ParticleModel::Update(float deltaTime)
{
	//gravity
	if (_simulateGravity)
	{
		_netForce += GravityForce();
	}
	
	// velocity and position as done with constant acceleration
	_acceleration += _netForce / _mass;

	//constant acceleration
	Vector3 position = _transform->GetPosition();
	_velocity += _acceleration * deltaTime;
	position += _velocity * deltaTime;
	_transform->SetPosition(position);

	//reset netforce after movement - recalculated every frame
	_netForce = Vector3(0, 0, 0);
	_acceleration = Vector3(0, 0, 0);
}
