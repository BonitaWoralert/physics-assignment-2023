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
	bool _simulateGravity;
public:
	PhysicsModel(Transform* transform, float mass, bool simulateGravity);
	virtual void Update(float deltaTime) = 0;

	//forces
	virtual void AddForce(Vector3 force) { _netForce += force; }
	virtual Vector3 GravityForce() { return _mass * Vector3(0, -9.81, 0); }


	//get and set
	virtual Vector3 GetVelocity() { return _velocity;}
	virtual void SetVelocity(Vector3 velocity) { _velocity = velocity; }

};

