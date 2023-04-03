#pragma once
#define GRAVITYSTRENGTH -9.81
#include "Transform.h"

class PhysicsModel
{
protected:
	Transform* _transform;
	Vector3 _velocity;
	Vector3 _acceleration;
	Vector3 _netForce;
	float _mass;
	bool _simulateGravity = false;
public:
	PhysicsModel(Transform* tf);

	//OLD
	//instead, make get and set for mass / grav
	//PhysicsModel(Transform* transform, float mass, bool simulateGravity);

	virtual void Update(float deltaTime);

	//forces
	virtual void AddForce(Vector3 force) { _netForce += force; }
	virtual Vector3 GravityForce() { return Vector3(0, GRAVITYSTRENGTH*_mass, 0); }

	//get and set
	virtual Vector3 GetVelocity() { return _velocity;}
	virtual void SetVelocity(Vector3 velocity) { _velocity = velocity; }

	virtual void SetMass(float mass) { _mass = mass; }
	virtual void SetGravity(bool grav) { _simulateGravity = grav; }
};

