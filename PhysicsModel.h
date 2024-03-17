#pragma once
#include "Transform.h"

//abstract class
class PhysicsModel
{
public:
	//constructors
	PhysicsModel(Transform* t);
	PhysicsModel(Transform* t, float mass);

	//physics functions
	virtual void Update(float deltaTime) = 0;
	void AddForce(Vector3 force) { _netForce += force; }

	//getters and setters
	void SetVelocity(Vector3 newVelocity) { _velocity = newVelocity; }
	Vector3 GetVelocity() { return _velocity; }
	
	void SetAcceleration(Vector3 newAcceleration) { _acceleration = newAcceleration; }
	Vector3 GetAcceleration() { return _acceleration; }
protected:
	Transform* _transform = nullptr;
	Vector3 _velocity;
	Vector3 _acceleration;
	Vector3 _netForce;
	float _mass = 1.0f;
};

