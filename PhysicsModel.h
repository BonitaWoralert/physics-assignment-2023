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
	virtual void Update(float deltaTime) = 0;

	//get and set
	virtual Vector3 GetVelocity() { return _velocity;}
	virtual void SetVelocity(Vector3 velocity) { _velocity = velocity; }
};

