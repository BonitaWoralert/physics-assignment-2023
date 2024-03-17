#include "PhysicsModel.h"

PhysicsModel::PhysicsModel(Transform* t) : _transform(t)
{
}

void PhysicsModel::Update(float deltaTime)
{
	Vector3 position = _transform->GetPosition();

	//velocity constant acceleration
	_velocity += _acceleration * deltaTime;

	//position is updated based on constant velocity
	position += _velocity * deltaTime;
	_transform->SetPosition(position);
}
