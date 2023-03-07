#pragma once

#include "Transform.h"

class PhysicsModel
{
protected:
	Transform* _transform;
	Vector3 _velocity;
	Vector3 _acceleration;
public:
	PhysicsModel(Transform* transform);
	void Update(float deltaTime);

	//get and set
	Vector3 GetVelocity() { return _velocity; }
	Vector3 SetVelocity(Vector3 velocity) { _velocity = velocity; }
};

