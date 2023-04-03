#include "PhysicsModel.h"
#include "Debug.h"
PhysicsModel::PhysicsModel(Transform* transform) : _transform(transform)
{
	//_transform = transform;
}

void PhysicsModel::Update(float deltaTime)
{
	Vector3 position = _transform->GetPosition();

	//gravity
	if (_simulateGravity && (position.y > 0.0f))
	{
		_netForce += GravityForce();
	}

	// velocity and position as done with constant acceleration
	_acceleration += _netForce / _mass;

	//constant acceleration
	_velocity += _acceleration * deltaTime;
	position += _velocity * deltaTime;
	_transform->SetPosition(position);

	//reset netforce after movement - recalculated every frame
	_netForce = Vector3(0, 0, 0);
	_acceleration = Vector3(0, 0, 0);
}
