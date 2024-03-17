#include "PhysicsModel.h"

PhysicsModel::PhysicsModel(Transform* t) : _transform(t)
{
}

PhysicsModel::PhysicsModel(Transform* t, float mass) : _transform(t), _mass(mass)
{
}

void PhysicsModel::Update(float deltaTime)
{
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
