#pragma once

#include "Transform.h"

class PhysicsModel
{
protected:
	Transform* _transform;
	Vector3 _velocity;
	Vector3 _acceleration;
	Vector3 _netForce;
	float _mass = 1.0f;
public:
	PhysicsModel(Transform* transform, float mass);
	virtual void Update(float deltaTime) = 0;
	virtual void AddForce(Vector3 force) { _netForce += force; }

	//get and set
	virtual Vector3 GetVelocity() { return _velocity;}
	virtual void SetVelocity(Vector3 velocity) { _velocity = velocity; }
};

