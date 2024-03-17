#include "PhysicsModel.h"

PhysicsModel::PhysicsModel()
{
}

PhysicsModel::PhysicsModel(float mass, bool grav) : _mass(mass), _simulateGravity(grav)
{
}

void PhysicsModel::Update(float deltaTime)
{
	if (_simulateGravity)
	{
		_netForce += GravityForce();
	}

	Vector3 position = _transform->GetPosition();
	
	//calculate acceleration using F = M * A
	_acceleration = _netForce / _mass;

	//calculate velocity using V = A * dt
	_velocity += _acceleration * deltaTime;

	//position is updated based on constant velocity
	position += _velocity * deltaTime;
	_transform->SetPosition(position);

	//velo and pos calculations complete, reset force and acceleration
	_netForce = Vector3(0, 0, 0);
	_acceleration = Vector3(0, 0, 0);
}

Vector3 PhysicsModel::GravityForce()
{
	//gravity strength * mass
	return Vector3(0, -9.81 * _mass, 0);
}
