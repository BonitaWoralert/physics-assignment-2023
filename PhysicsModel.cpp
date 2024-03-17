#include "PhysicsModel.h"

PhysicsModel::PhysicsModel(Transform* t) : _transform(t)
{
}

void PhysicsModel::Update(float deltaTime)
{
	Vector3 position = _transform->GetPosition();
	position += _velocity * deltaTime;
	_transform->SetPosition(position);
}
