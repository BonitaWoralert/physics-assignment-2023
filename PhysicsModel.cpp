#include "PhysicsModel.h"

PhysicsModel::PhysicsModel(Transform* transform, float mass)
{
	_transform = transform;
	_mass = mass;
}

void PhysicsModel::Update(float deltaTime)
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
}
